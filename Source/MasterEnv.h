/*
  ==============================================================================

    MasterEnv.h
    Created: 18 Sep 2020 11:37:22am
    Author:  Trevor

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class MasterEnv  : public juce::Component
{
public:
    MasterEnv(CuttingBoardSynthPluginAudioProcessor&);
    ~MasterEnv() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    CuttingBoardSynthPluginAudioProcessor& audioProcessor;


    void initSliders();
    void initLabels();

    std::array<juce::Slider, 4> adsrKnobs;
    std::array<juce::Label, 4> adsrLabels;

    std::array<std::string, 4> const adsrText = { "attack", "decay", "sustain", "release" };

    std::array<std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>, 4> adsrAttachments;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterEnv)
};
