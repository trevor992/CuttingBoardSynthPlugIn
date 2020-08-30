/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "SynthVoice.h"

//==============================================================================
/**
*/
class CuttingBoardSynthPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    CuttingBoardSynthPluginAudioProcessor();
    ~CuttingBoardSynthPluginAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    
    //getter for the AudioProcessorValueTreeState i.e. processorTree
    juce::AudioProcessorValueTreeState& getProcessorTree() { return processorTree; }
    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    const std::array<std::string, 4> adsrAPVTIdentifiers = {"AmpAtk", "AmpDec", "AmpSus", "AmpRel"};
    

private:
    //==============================================================================
    juce::Synthesiser synth;
    SynthVoice* voice;
    const float minEnvTime;
    const float maxEnvTime;
    const float defEnvtime;
    const float minVolEnvTime;
    const float maxVolEnvTime;
    const float defVolEnvTime;
    const int cNumTypesOscs;
    juce::AudioProcessorValueTreeState processorTree;
    double lastSampleRate;
    
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CuttingBoardSynthPluginAudioProcessor)
};
