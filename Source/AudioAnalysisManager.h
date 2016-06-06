/*==============================================================================
//  AudioAnalysisManager.h
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

#ifndef AUDIOANALYSISMANAGER_H_INCLUDE
#define AUDIOANALYSISMANAGER_H_INCLUDE
#include "JuceHeader.h"
#include "libKeyFinder/keyfinder.h"
#include "SingleAudioFileForAnalysis.h"
#include "KeyAnalysisThread.h"


class AudioAnalysisManager
{
public:
	AudioAnalysisManager();

	~AudioAnalysisManager();
	void addAudioFileForAnalysis(File inAudioFile);
	void addAudioFileForAnalysis(String inAudioFilePath);
	bool analyzeAudioFiles();
	void analyzeSingleAudioFile(SingleAudioFileForAnalysis* currentFile);
	
	std::vector<String> getAnalyzedKeyResults() const;

	OwnedArray<SingleAudioFileForAnalysis>* getFileList();;

private:
	AudioFormatManager audioFormatManager;
	KeyFinder::AudioData audioData;
	//ScopedPointer<AudioFormatReader> audioFormatReader;
	OwnedArray<KeyAnalysisThread> keyAnalysisThreadArray;
	OwnedArray<SingleAudioFileForAnalysis> loadedAudioFilesList;
	//std::vector<SingleAudioFileForAnalysis> loadedAudioFilesList;

	//JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AudioAnalysisManager);
};


#endif //AUDIOANALYSISMANAGER_H_INCLUDE


