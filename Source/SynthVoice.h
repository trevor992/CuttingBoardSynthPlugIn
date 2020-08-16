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
    
private:
    float frequency;
    
};
