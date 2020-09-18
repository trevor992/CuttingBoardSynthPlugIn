/*
  ==============================================================================

    SynthVoice.h
    Created: 14 Aug 2020 12:10:20pm
    Author:  Trevor

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Maximilian/src/maximilian.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    //The following comments are descriptions directly from the JUCE API
    
    //Must return true if the voice object is capable of playing the given sound
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    //called to start a new note
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPos) override;
    //called to stop a note
    void stopNote(float velocity,bool allowTailOff) override;
    //called to let the voice know the pitch wheel has been moved
    void pitchWheelMoved(int newPitchWheelValue) override;
    //called to let the voice know a midi controller has moved
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    //called ot let the voice know the aftertouch has changed
    void renderNextBlock(juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    
    //must use load function from std::atomic class to get this as a float value
    void applyMasterGain(float gain);
    //must use load function from the std::atomic class to get the float value
    void applyAdsrParams(float atk ,float dec, float sus,float rel);
    
    double setAmpEnv();
    
    double setOscType();
    //must use load function in the std::atomic class to get the int value from
    void getOscType(int sel1, int sel2);
    void setADSRSampleRate(double sampleRate);
private:
    float frequency;
    float level;
    int wavForm1, wavForm2, recWavForm = 1;
    float masterGainFactor = 0.0;
    
    
    // as I add more voices I may want to store these in an array of MaxiOsc's and MaxiEnv's respectively 
    maxiOsc osc1;
    maxiOsc osc2;
    juce::ADSR env1;
    juce::ADSR::Parameters adsrParams;
    
    maxiFilter filter1;
    
};
