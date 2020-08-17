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
    env1.trigger = 0;
    allowTailOff = true;
    if (velocity == 0)
    {
        clearCurrentNote();
    }
}

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    env1.trigger = 1;
    level = velocity;
    frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
   
    
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
{
    // probably not the best place for these.
    // will have to move thse at some point and also add them controls
    env1.setAttack(1000);
    env1.setDecay(500);
    env1.setSustain(0.5);
    env1.setRelease(1000);
    
    for (int sample = 0; sample < numSamples; ++sample)
    {
        float theWave = osc1.saw(frequency);
        float theSound = env1.adsr(theWave, env1.trigger) * level;
        float filteredSound = filter1.lores(theSound, 250, 5);
        
        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            outputBuffer.addSample(channel, startSample, filteredSound);
        }
        ++startSample;
    }
    
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
    
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
    
}
