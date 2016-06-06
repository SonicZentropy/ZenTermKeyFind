/*==============================================================================
//  SingleFileForAnalysis.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2016/02/09
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: A Single audio file to be analyzed
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "SingleAudioFileForAnalysis.h"
#include "KeyNotationConversions.hpp"


SingleAudioFileForAnalysis::SingleAudioFileForAnalysis(String inFilePath)
	
{
	fileToAnalyze = File::getCurrentWorkingDirectory().getChildFile(inFilePath);
	instanceUUID = boost::uuids::random_generator()();
	DBG("Generated UUID in Path ctor: " << boost::uuids::to_string(instanceUUID) << " With name: " << fileToAnalyze.getFileName());
}

SingleAudioFileForAnalysis::SingleAudioFileForAnalysis(File& inFile)
	:fileToAnalyze(inFile)
{
	instanceUUID = boost::uuids::random_generator()();
	DBG("Generated UUID in File ctor: " << boost::uuids::to_string(instanceUUID) << " With name: " << inFile.getFileName());
}


SingleAudioFileForAnalysis::~SingleAudioFileForAnalysis()
{}

String SingleAudioFileForAnalysis::getFullFilePath() const
{
	return fileToAnalyze.getFullPathName();
}

key_t SingleAudioFileForAnalysis::getDetectedKey() const
{
	return detectedKey;
}

void SingleAudioFileForAnalysis::setDetectedKey(key_t newKey)
{
	detectedKey = newKey;
	fileAnalyzed = "Yes";

	
}

String SingleAudioFileForAnalysis::getDetectedKeyAsString() const
{
	return KeyNotationConversions::getMusicalKeyFromKeyT(detectedKey);
}

String SingleAudioFileForAnalysis::getDetectedKeyAsCamelot() const
{
	return KeyNotationConversions::getCamelotKeyFromKeyT(detectedKey);
}

String SingleAudioFileForAnalysis::getDetectedKeyAsOpenKey() const
{
	return KeyNotationConversions::getOpenKeyFromKeyT(detectedKey);
}

File& SingleAudioFileForAnalysis::getFileToBeAnalyzed()
{
	return fileToAnalyze;
}
