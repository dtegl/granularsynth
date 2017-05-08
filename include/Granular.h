//
//  Granulator.h
//  GranularSynth
//
//  Created by djst on 5/8/17.
//
//

#ifndef Granular_h
#define Granular_h

#include <stdio.h>

template <typename T, typename RandOffsetFunc, typename TriggerCallbackFunc>
class Granular {
public:
    Granular( const T* buffer, size_t bufferLen, size_t sampleRate, TriggerCallbackFunc & triggerCallback );
    
    void setSelectionStart( size_t start );
    void setSelectionSize( size_t size );
    
    /** Sets multiplier of duration of grains in seconds */
    void setGrainsDuration( double coeff );
    /** Sets rate of grains. e.g rate = 2 means one octave higer */
    void setGrainsRate( double rate );
    
    /** Sets the attenuation of the grains with respect to the level of the recorded sample
     *  attenuation is in amp value and defaule value is 0.25118864315096 (-12dB) */
    void setAttenuation( T attenuation );
    
    /** Starts the synthesis engine */
    void noteOn( double rate );
    
    /** Stops the synthesis engine */
    void noteOff();
    
    /** Whether the synthesis engine is active or not. After noteOff is called the synth stays active until the envelope decays to 0 */
    bool isIdle();
    
    /**
     * Runs the granular engine and stores the output in \a audioOut
     *
     * \param pointer to an array of T. This will be filled with the output of PGranular. It needs to be at least \a numSamples long
     * \param tempBuffer a temporary buffer used to store the envelope value. It needs to be at least \a numSamples long
     * \param numSamples number of samples to be processed
     */
    void process( T* audioOut, T* tempBuffer, size_t numSamples );
    
    
private:
    // pointer to (mono) buffer, where the underlying sample is recorder
    const T* mBuffer;
    // length of mBuffer in samples
    const size_t mBufferLen;
    
    // offset in the buffer where the grains start. a.k.a. selection start
    size_t mGrainsStart;
    
    // attenuates signal prevents clipping of grains (to some degree)
    T mAttenuation;
    
    // grain duration in samples
    double mGrainsDurationCoeff;
    // duration of grains is selection size * duration coeff
    size_t mGrainsDuration;
    // rate of grain, affects pitch
    double mGrainsRate;
    
    size_t mTrigger;       // next onset
    size_t mTriggerRate;   // inter onset
    
    /* the array of grains
    //std::array<PGrain, kMaxGrains> mGrains;
    // number of alive grains
    */
    size_t mNumAliveGrains;
    
    RandOffsetFunc &mRand;
    TriggerCallbackFunc &mTriggerCallback;
    
    
    void processGrains( T* audioOut, T* envelopeValues, size_t numSamples );
    /* synthesize a single grain
     audioOut = pointer to audio block to fill
     numSamples = number of samples to process for this block
    */
    //void synthesizeGrain( PGrain &grain, T* audioOut, T* envelopeValues, size_t numSamples );
    
};

#endif /* Granular_h */
