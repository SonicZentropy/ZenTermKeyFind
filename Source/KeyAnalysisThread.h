/*==============================================================================
//  KeyAnalysisThread.h
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

#pragma once
#ifndef KeyAnalysisThread_H_INCLUDED
#define KeyAnalysisThread_H_INCLUDED
#include <JuceHeader.h>
#include "SingleAudioFileForAnalysis.h"
#include "libKeyFinder/audiodata.h"

/// <summary>
/// Analyzes a given song in the background
/// </summary>
/// <seealso cref="Thread" />
class KeyAnalysisThread : public Thread
{
public:
	
	explicit KeyAnalysisThread(SingleAudioFileForAnalysis* _fileToAnalyze, AudioFormatManager& _audioFormatManager);
	~KeyAnalysisThread();

	void run() override;

	void analyzeSingleKey();
private:
	SingleAudioFileForAnalysis* fileToAnalyze;
	int interval;
	AudioFormatManager audioFormatManager;
	KeyFinder::AudioData audioData;
	ScopedPointer<AudioFormatReader> audioFormatReader;
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KeyAnalysisThread)
};

#endif // KeyAnalysisThread_H_INCLUDED
