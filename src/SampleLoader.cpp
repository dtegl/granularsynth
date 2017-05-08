//
//  SampleLoader.cpp
//  GranularSynth
//
//  Created by djst on 5/5/17.
//
//

#include <stdio.h>
#include "SampleLoader.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/*
    Loads the default sample
*/
audio::BufferRef SampleLoader::loadSample( size_t sampleRate ) {
    // create a SourceFile and set its output samplerate to match the Context.
    audio::SourceFileRef sourceFile = audio::load( loadAsset( "DrainMagic.ogg" ), sampleRate );
    
    // load the entire sound file into a BufferRef
    return sourceFile->loadBuffer();

}

/* 
    Load sample by given filename (all samples must be in the ./assets folder)
*/
audio::BufferRef SampleLoader::loadSample( std::string fileName, size_t sampleRate ) {
    // create a SourceFile and set its output samplerate to match the Context.
    audio::SourceFileRef sourceFile = audio::load( loadAsset( fileName ), sampleRate );
    
    // load the entire sound file into a BufferRef
    return sourceFile->loadBuffer();
}
