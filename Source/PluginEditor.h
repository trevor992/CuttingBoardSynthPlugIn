/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Osc.h"

//==============================================================================
/**
*/
class CuttingBoardSynthPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    void extracted();
    
CuttingBoardSynthPluginAudioProcessorEditor (CuttingBoardSynthPluginAudioProcessor&);
    ~CuttingBoardSynthPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void initSliders();
    void initLabels();
    //likely will get rid of the Sliderlisten class
   

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    

    CuttingBoardSynthPluginAudioProcessor& audioProcessor;
    std::array<juce::Slider, 4> adsrKnobs;
    std::array<juce::Label, 4> adsrLabels;
    juce::Slider masterGain;
    juce::Label masterGainLabel;
    Osc mOscGui;
    std::array<std::string , 4> const adsrText = {"attack", "decay", "sustain", "release"};
    std::array<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>, 4> adsrAttachments;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> masterGainAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CuttingBoardSynthPluginAudioProcessorEditor)
};
