/*
  ==============================================================================

    SynthVoice.cpp
    Created: 14 Aug 2020 12:10:20pm
    Author:  Trevor

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound (juce::SynthesiserSound* sound)
{
    // from the JUCE synth essentially we are trying to cast the sound as class SynthSound. If it is succesful it will return
    // true
    return dynamic_cast<SynthSound*>(sound) != nullptr;
}
void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    clearCurrentNote();
}

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    DBG(frequency);
    
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
{
    
    
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
    
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
    
}
