//
//  AudioEngine.cpp
//  GranularSynth
//
//  Created by djst on 5/8/17.
//
//

#include <stdio.h>
#include "AudioEngine.h"

using namespace ci;
using namespace ci::app;

void AudioEngine::setup() {
    // Init audio context
    auto ctx = audio::Context::master();
    
    
    //Signal path goes here
    
    //1. Load sample and get buffer from sampler (wrap this in Cinder::Node?
    audio::BufferRef buffer = mSampleLoader.loadSample( this->getSampleRate() );
    
    
    //2. Init granular engine wrapped in a Cinder::Node and pass the audio buffer to it
    
    
    //3. Connect granular engine node to other effect nodes
    
    
    //4. Pass output to output node
     
    
    //5. Enable audio context
    ctx->enable();
}

size_t getSampleRate() {
    return audio::Context::master()->getSampleRate();
}

void AudioEngine::noteOn(int midiNote)
{
    /*
    
    double midiAsRate = calculateMidiNoteRatio(midiNote);
    NoteMsg msg = makeNoteMsg( Command::NOTE_ON, midiNote, midiAsRate );
    
    mPGranularNodes[waveIdx]->getNoteRingBuffer().write( &msg, 1 );
     */
}

void AudioEngine::noteOff(int midiNote)
{
    /*
    NoteMsg msg = makeNoteMsg( Command::NOTE_OFF, midiNote, 0.0 );
    mPGranularNodes[waveIdx]->getNoteRingBuffer().write( &msg, 1 );
    */
}

void AudioEngine::setSelectionSize( size_t size )
{
    //mPGranularNodes[waveIdx]->setSelectionSize( size );
}

void AudioEngine::setSelectionStart( size_t start )
{
    //mPGranularNodes[waveIdx]->setSelectionStart( start );
}

void AudioEngine::loadSample( std::string path) {
    mSampleLoader.loadSample(path, this->getSampleRate());
}
