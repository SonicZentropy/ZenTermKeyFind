/*==============================================================================
//  KeyAnalysisThread.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 3/4/2016 3:12:22 AM
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Thread class for asynchronously analyzing a single
//     audio file's key in the background
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "KeyAnalysisThread.h"
#include "libKeyFinder/keyfinder.h"

/*

KeyAnalysisThread::KeyAnalysisThread()
{
	
}*/

KeyAnalysisThread::KeyAnalysisThread(SingleAudioFileForAnalysis* _fileToAnalyze, AudioFormatManager& _audioFormatManager)
	: Thread("Key Analysis Thread" + _fileToAnalyze->getFileName()),
	fileToAnalyze(_fileToAnalyze)
	//audioFormatManager(_audioFormatManager)
{
	audioFormatReader = _audioFormatManager.createReaderFor(_fileToAnalyze->getFileToBeAnalyzed());
	DBG("Creating thread: " << getThreadName());
	interval = Random::getSystemRandom().nextInt(50) + 8;
	startThread();
}

KeyAnalysisThread::~KeyAnalysisThread()
{
	stopThread(2000);
}

void KeyAnalysisThread::run()
{
	
	//while (! threadShouldExit() )
	//{
		//sleep a tiny amount so a bunch of threads at once don't kill the CPU
		wait(interval);

		//analyze song key
		analyzeSingleKey();
	//}
}

void KeyAnalysisThread::analyzeSingleKey()
{
	DBG("Thread: " << this->getThreadName() << " analyzing single key of: " << fileToAnalyze->getUUID());
	//skip already-analyzed files
	if (fileToAnalyze->isFileAnalyzed() == "Yes")
	{
		DBG("Skipping analysis of " << fileToAnalyze->getFileName() << " : Already analyzed.");
		return;
	}
	//DBG("File being analyzed: " << fileToAnalyze.getFileToBeAnalyzed().getFileName());
//	r> audioFormatReader = audioFormatManager.createReaderFor(fileToAnalyze.getFileToBeAnalyzed());

	size_t numSamples = audioFormatReader->lengthInSamples;
	size_t numChannels = audioFormatReader->numChannels;
	size_t sampleRate = audioFormatReader->sampleRate;
	//size_t numFrames = numSamples / numChannels;
	//DBG("Samples:" + String(numSamples) + " Channels:" + String(numChannels) + " Frames:" + String(numFrames));
	audioData.addToSampleCount(numSamples*numChannels);
	audioData.setChannels(numChannels);
	audioData.setFrameRate(sampleRate);

	AudioBuffer<float> audioBuffer(numChannels, numSamples);

	// #TODO(Casey): Fix either audiobuffer or audioData to allow direct move of sample array (Performance)
	// #TODO(Casey): integrate libsndfile as primary choice

	//DBG("Reading wav to buffer");
	audioFormatReader->read(&audioBuffer, 0, numSamples, 0, true, true);


	//DBG("Copying buffer samples to audioData");
	for (size_t i = 0; i < numSamples; ++i)
	{
		//DBG("On sample " + String(i) + " of " + String(numSamples));
		for (size_t currChannel = 0; currChannel < numChannels; ++currChannel)
		{
			audioData.setSampleByFrame(i, currChannel, audioBuffer.getSample(currChannel, i));
		}
		//audioData.setSampleByFrame(i, 1, audioBuffer.getSample(1, i));
	}

	//DBG("Detecting key...");

	static KeyFinder::KeyFinder keyFinder;

	KeyFinder::key_t key = keyFinder.keyOfAudio(audioData);

	//KeyFinder::key_t key = KeyFinder::key_t::C_MAJOR;

	fileToAnalyze->setDetectedKey(key);

	String foundKey(fileToAnalyze->getDetectedKeyAsString());

	DBG("Detected key in analyzeAudioFiles: " + foundKey);
}