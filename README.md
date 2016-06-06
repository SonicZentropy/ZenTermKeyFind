# ZenTermKeyFind
JUCE-based Command line wrapper for libKeyFinder.  

Currently just a quick dump for command line purposes by request.  It's highly possible it is full of problems and slightly possible your computer will spontaneously combust.  It supports WAV, FLAC, OGG, MP3, AIFF at the moment.

I'm not actually sure what the use case is for this, so it's pretty minimal. Example use:

```
ZenTermKeyFind.exe -s "D:\Music\TestFile.wav"
```

Only supports a single file per execution, but someone else can enable multiple files at once if desired pretty easily.  Just repeatedly call p.addAudioFileForAnalysis passing in each filename and add whatever output you want in Processor.analyzeAllFiles.

There's a Windows binary under releases and OSX/Linux exporters already configured in the Jucer file.  If you want to compile it yourself, you'll need JUCE.  Just open the ZenTermKeyFind.jucer file via ProJucer and save the project, then build the saved project in the normal manner.  There's nothing I am aware of that'll be a problem to build in OSX or Linux, but I haven't actually tried either.
