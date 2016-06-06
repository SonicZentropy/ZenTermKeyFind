/*==============================================================================
//  JUCEAudioFormatReader.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2016/02/22
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Reads Audio Format via JUCE's Audio Format class - slower than
//  libSndFile, should only be used for MP3 currently, as libSndFile does not
//  support that format
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#pragma once
#ifndef JUCEAUDIOFORMATREADER_H_INCLUDED
#define JUCEAUDIOFORMATREADER_H_INCLUDED
#include <JuceHeader.h>

class JUCEAudioFormatReader
{
public:
	
	JUCEAudioFormatReader();
	~JUCEAudioFormatReader();

private:
	
};

#endif // JUCEAUDIOFORMATREADER_H_INCLUDED
