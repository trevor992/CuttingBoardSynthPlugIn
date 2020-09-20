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
    void initComboBoxes();
    void initLabels();

    CuttingBoardSynthPluginAudioProcessor& audioProcessor;

    juce::ComboBox oscSelectComboBox;

    juce::Label oscLabel;

    const std::array<std::string, 4> oscList;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> oscComboBoxAttachment;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTwo)
};
