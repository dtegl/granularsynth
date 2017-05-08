//
//  AudioEngine.h
//  GranularSynth
//
//  Created by djst on 5/5/17.
//
//

#ifndef AudioEngine_h
#define AudioEngine_h

#pragma once

#include "cinder/app/App.h"
#include "cinder/Cinder.h"
#include "cinder/audio/audio.h"
#include "SampleLoader.h"
#include "Resources.h"

using namespace ci;

class AudioEngine {
public:
    AudioEngine();
    ~AudioEngine();
    
    // no copies
    AudioEngine( const AudioEngine &copy ) = delete;
    AudioEngine & operator=(const AudioEngine &copy) = delete;
    
    // Setup function
    void setup(/*Config config*/);
    
    // Interface functions for controlling parameters of the Granular Engine
    void noteOn( int midiNote );
    void noteOff( int midiNote );
    
    void setSelectionStart( size_t );
    void setSelectionSize( size_t );
    // setGrainDuration( size_t);
    // etc...
    
    // Interface functions for controlling parameters of other effects (filters, envs, delay, distortion etc.)
    void setFilterCutoff( double cutoff );
    void setFilterRes( double res );
    //void setDistortionWetDry( double );
    // etc...
    
    // SampleLoader interface functions
    void loadSample( std::string path );
    
    // Getters and setters
    size_t getSampleRate();
    const audio::Buffer& getAudioOutputBuffer() const;
    
private:
    SampleLoader mSampleLoader;
    
};

#endif /* AudioEngine_h */
