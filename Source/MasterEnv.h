/*
  ==============================================================================

    MasterEnv.h
    Created: 18 Sep 2020 11:37:22am
    Author:  Trevor

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MasterEnv  : public juce::Component
{
public:
    MasterEnv();
    ~MasterEnv() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    std::array<juce::Slider, 4> adsrKnobs;
    std::array<juce::Label, 4> adsrLabels;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterEnv)
};
