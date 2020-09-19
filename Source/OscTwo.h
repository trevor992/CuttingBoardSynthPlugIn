/*
  ==============================================================================

    OscTwo.h
    Created: 18 Sep 2020 11:38:00am
    Author:  Trevor

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class OscTwo  : public juce::Component
{
public:
    OscTwo(CuttingBoardSynthPluginAudioProcessor& p);
    ~OscTwo() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    CuttingBoardSynthPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTwo)
};
