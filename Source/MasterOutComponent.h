/*
  ==============================================================================

    MasterOutComponent.h
    Created: 18 Sep 2020 11:43:22am
    Author:  Trevor

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class MasterOutComponent  : public juce::Component
{
public:
    MasterOutComponent(CuttingBoardSynthPluginAudioProcessor&);
    ~MasterOutComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    CuttingBoardSynthPluginAudioProcessor& audioProcessor;

    void initSliders();
    void initLabels();

    juce::Slider masterGain;
    juce::Label masterGainLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> masterGainAttachment;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterOutComponent)
};
