/*==============================================================================
//  AudioAnalysisManager.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2016/02/09
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Manages source audio file to be analyzed
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "AudioAnalysisManager.h"

AudioAnalysisManager::AudioAnalysisManager()
{
	audioFormatManager.registerBasicFormats();
	
	//audioFormatManager.registerFormat(new OggVorbisAudioFormat, false);
}

AudioAnalysisManager::~AudioAnalysisManager()
{

}

void AudioAnalysisManager::addAudioFileForAnalysis(File inAudioFile)
{	
	//DBG("In AudioAnalysisManager::addAudioFileForAnalysis(inAudioFile) ");

//	SingleAudioFileForAnalysis analysisFile(inAudioFile);
	loadedAudioFilesList.add(new SingleAudioFileForAnalysis(inAudioFile));
}

void AudioAnalysisManager::addAudioFileForAnalysis(String inAudioFilePath)
{
	//DBG("In AudioAnalysisManager::addAudioFileForAnalysis(inAudioFilePath) ");
	File childFile(File::getCurrentWorkingDirectory().getChildFile(inAudioFilePath));
	SingleAudioFileForAnalysis* analysisFile = new SingleAudioFileForAnalysis(childFile);
	loadedAudioFilesList.add(analysisFile);

}

bool AudioAnalysisManager::analyzeAudioFiles()
{
	//DBG("In AudioAnalysisManager::analyzeAudioFiles() ");

	if (loadedAudioFilesList.size() == 0)
	{
		DBG("In AudioAnalysisManager::analyzeAudioFiles()- loaded list empty ");
		return false;
	}

	for (auto& currentFile : loadedAudioFilesList)
	{
		analyzeSingleAudioFile(currentFile);
	}
	
	return true;

}

void AudioAnalysisManager::analyzeSingleAudioFile(SingleAudioFileForAnalysis* currentFile)
{	
	std::stringstream ss;
	ss << &currentFile;
	//DBG("In analysisMgr creating thread for UUID: " << currentFile->getUUID() << " addr: " << ss.str());
	//keyAnalysisThreadArray.add(new KeyAnalysisThread(currentFile, audioFormatManager));
	//skip already-analyzed files
	if (currentFile->isFileAnalyzed() == "Yes")
	{
		DBG("Skipping analysis of " << currentFile->getFileName() << " : Already analyzed.");
		return;
	}
	DBG("File being analyzed: " << currentFile->getFileToBeAnalyzed().getFileName());
	ScopedPointer<AudioFormatReader> audioFormatReader = audioFormatManager.createReaderFor(currentFile->getFileToBeAnalyzed());

	if (nullptr == audioFormatReader)
	{
		DBG("File not found!");
		std::cout << "File not found!" << std::endl;
		return;
	}

	size_t numSamples = audioFormatReader->lengthInSamples;
	size_t numChannels = audioFormatReader->numChannels;
	size_t sampleRate = audioFormatReader->sampleRate;
	size_t numFrames = numSamples / numChannels;
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

	currentFile->setDetectedKey(key);

	String foundKey(currentFile->getDetectedKeyAsString());

	//DBG("Detected key in analyzeAudioFiles: " + foundKey);
}

std::vector<String> AudioAnalysisManager::getAnalyzedKeyResults() const
{
	std::vector<String> theStrings;
	for (auto currFile : loadedAudioFilesList)
	{
		theStrings.push_back(currFile->getDetectedKeyAsString());
	}
	return theStrings;
}

OwnedArray<SingleAudioFileForAnalysis>* AudioAnalysisManager::getFileList()
{
	return &loadedAudioFilesList;
}

//juce_ImplementSingleton(AudioAnalysisManager)