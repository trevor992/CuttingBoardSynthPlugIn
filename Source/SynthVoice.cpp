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
    env1.noteOff();
    allowTailOff = true;
    if (velocity == 0)
    {
        clearCurrentNote();
    }
}

void SynthVoice::startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    env1.noteOn();
    level = velocity;
    frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
   
    
}

void SynthVoice::applyMasterGain(float gain)
{
    masterGainFactor = gain;
}

double SynthVoice::setOscType()
{
  
    
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
    env1.setParameters(adsrParams);
    for (int sample = 0; sample < numSamples; ++sample)
    {        
        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
        {
            outputBuffer.addSample(channel, startSample, env1.getNextSample() * setOscType() * masterGainFactor);
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
    
    adsrParams.attack = atk;
    adsrParams.decay = dec;
    adsrParams.sustain = sus;
    adsrParams.release = rel;
    
}

void SynthVoice::getOscType(int sel1, int sel2){
    wavForm1 = sel1;
    wavForm2 = sel2;

}

void SynthVoice::setADSRSampleRate(double sampleRate)
{
    env1.setSampleRate(sampleRate);
}
