/*==============================================================================
//  FILENAME
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date DATE
//  Copyright (C) 2016 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic Console App
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioAnalysisManager.h"

using std::cout;
using std::cin;
using std::endl;

class Processor
{
public:
	void analyzeAllFiles()
	{
		aaMgr.analyzeAudioFiles();
		std::vector<String> results = aaMgr.getAnalyzedKeyResults();
		for (String i : results)
		{
			DBG(i);
			cout << "Detected key: " << i;
			
#ifdef JUCE_DEBUG
			int k;
			cin >> k;
#endif
		}
	}

	void addAudioFileForAnalysis(String file)
	{
		aaMgr.addAudioFileForAnalysis(file);
	}

	Processor() {};

	~Processor() {};

private:
	AudioAnalysisManager aaMgr;

};

//==============================================================================
int main (int argc, char* argv[])
{

	//DBG( argc);
	for (int i = 0; i < argc; ++i)
	{
		DBG(argv[i]);
	}	

	if (String(argv[1]) != "-s")
	{
		DBG("NOPE");
		cout << "Unknown command!  Proper format is -s \"filename.ext\"";
		return -1;

	} else
	{
		DBG("YEP");		
	}

	String filename = argv[2];
	//filename.append("ERROR", 5);  // test basic file check
	
	Processor p;

	//Test stuff
	//filename = "D:\\Workspace\\Cpp\\JUCE\\ZenTermKeyFind\\TestAudioMono16bitShortEb.wav";
	//p.addAudioFileForAnalysis(filename);

	//filename = "D:\\Workspace\\Cpp\\JUCE\\ZenTermKeyFind\\TestAudioMono16bitShortEb.flac";
	//p.addAudioFileForAnalysis(filename);
	
	//filename = "D:\\Workspace\\Cpp\\JUCE\\ZenTermKeyFind\\TestAudioMono16bitShortEb.ogg";
	//p.addAudioFileForAnalysis(filename);
	//
	//filename = "D:\\Workspace\\Cpp\\JUCE\\ZenTermKeyFind\\TestAudioMono16bitShortEb.mp3";
	//p.addAudioFileForAnalysis(filename);
	//
	//filename = "D:\\Workspace\\Cpp\\JUCE\\ZenTermKeyFind\\TestAudioMono16bitShortEb.aiff";
	DBG("Filename to add: " << filename);
	cout << "Analyzing..." << endl;
	p.addAudioFileForAnalysis(filename);

	p.analyzeAllFiles();

    return 0;
}


