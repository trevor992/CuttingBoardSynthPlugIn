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

double SynthVoice::setAmpEnv()
{
    return env1.adsr(setOscType(), env1.trigger);
}

void SynthVoice::applyMasterGain(float gain)
{
    assert(gain >= 0 && gain <= 1.0);
    masterGainFactor = gain;
}

double SynthVoice::setOscType()
{
    assert(wavForm1 >= 0 && wavForm1 <= 3);
    assert(wavForm2 >= 0 && wavForm2 <= 3);
    
    double sample1, sample2;
    //case three will be for user recorded wav's at some point.
    switch(wavForm1)
    {
        case 0:
            sample1 = osc1.sinewave(frequency);
            break;
        case 1:
            sample1 = osc1.saw(frequency);
        case 2:
            sample1 = osc1.square(frequency);
        case 3:
            sample1 = osc1.saw(frequency);
    }
    
    switch (wavForm2) {
        case 0:
            sample2 = osc2.sinewave(frequency);
            break;
        case 1:
            sample2 = osc2.saw(frequency);
        case 2:
            sample2 = osc2.square(frequency);
        case 3:
            sample2 = osc2.saw(frequency);
    }
    
    return sample1;
    
    
}
void SynthVoice::renderNextBlock(juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
{
    // probably not the best place for these.
    // will have to move thse at some point and also add them controls
    
    
    for (int sample = 0; sample < numSamples; ++sample)
    {        
        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            outputBuffer.addSample(channel, startSample, setAmpEnv() * masterGainFactor);
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
void SynthVoice::applyAdsrParams(float atk, float dec, float sus, float rel)
{
    //strange bug occurs when sustain knob is set to 0 and decay knob is greater than 5ms
    assert(sus <= 1.0f && sus >= 0.0f);
    env1.setAttack(atk);
    env1.setDecay(dec);
    env1.setSustain(sus);
    env1.setRelease(rel);
    
}

void SynthVoice::getOscType(int sel1, int sel2){
    assert( (sel1 >= 0 && sel1 <= 3) && (sel2 >= 0 && sel2 <= 3));
    
}
