//
//  SampleLoader.h
//  GranularSynth
//
//  Created by djst on 5/5/17.
//
//

#ifndef SampleLoader_h
#define SampleLoader_h

#pragma once

#include "cinder/app/App.h"
#include "cinder/Cinder.h"
#include "cinder/audio/audio.h"
#include "cinder/Filesystem.h"
#include "Resources.h"

using namespace ci;

/*
    Handles loading of samples to use for granulization. 
 
    Note to self: Might be a good idea to wrap this in a Cinder::Node
 
    Later this can be used as a sample browser with graphical interface etc.
*/
class SampleLoader {
public:
    audio::BufferRef loadSample( size_t sampleRate );
    audio::BufferRef loadSample( std::string path, size_t sampleRate);
    
private:
    // Disallow creating an instance of this object
    SampleLoader() {};
    
    // Buffer containing audio file data
    
    
    
};


#endif /* SampleLoader_h */
