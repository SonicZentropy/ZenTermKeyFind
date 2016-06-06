#pragma once

/*==============================================================================
//  SingleAudioFileForAnalysis.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2016/02/09
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Single audio file to be analyzed
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#pragma once
#ifndef SINGLEAUDIOFILEFORANALYSIS_H_INCLUDED
#define SINGLEAUDIOFILEFORANALYSIS_H_INCLUDED
#include <JuceHeader.h>
#include "libKeyFinder/constants.h"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"

using KeyFinder::key_t;

class SingleAudioFileForAnalysis
{
public:

	explicit SingleAudioFileForAnalysis(String filePath);
	explicit SingleAudioFileForAnalysis(File& inFile);
	~SingleAudioFileForAnalysis();

	String getFullFilePath() const;

	key_t getDetectedKey() const;

	void setDetectedKey(key_t newKey);

	String getDetectedKeyAsString() const;

	String getDetectedKeyAsCamelot() const;

	String getDetectedKeyAsOpenKey() const;

	File& getFileToBeAnalyzed();

	String getFileName() const
	{		
		return fileToAnalyze.getFileName();
	}

	String isFileAnalyzed() const
	{
		return (detectedKey == KeyFinder::UNANALYZED) ? "No" : "Yes";
	}

	String getUUID() const
	{
		// #TODO: fix UUID generation to use random seed
		return boost::uuids::to_string(instanceUUID);
	}

private:
	key_t detectedKey = key_t::UNANALYZED;

	File fileToAnalyze;

	String fileAnalyzed = "No";
	std::deque<double> myDQ;
	
	boost::uuids::uuid instanceUUID;


	//JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SingleAudioFileForAnalysis);
};


#endif // SINGLEAUDIOFILEFORANALYSIS_H_INCLUDED