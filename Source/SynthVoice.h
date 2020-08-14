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
    bool canPlaySound(juce::SynthesiserSound* sound);
    //called to start a new note
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPos);
    //called to stop a note
    void stopNote(float velocity,bool allowTailOff);
    //called to let the voice know the pitch wheel has been moved
    void pitchWheelMoved(int newPitchWheelValue);
    //called to let the voice know a midi controller has moved
    void controllerMoved(int controllerNumber, int newControllerValue);
    //called ot let the voice know the aftertouch has changed
    void rendersNextBlock(juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples);
    
private:
    
    
};
