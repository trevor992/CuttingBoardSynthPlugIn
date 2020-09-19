/*
  ==============================================================================

    Osc.h
    Created: 30 Aug 2020 1:11:29pm
    Author:  Trevor

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class OscOne  : public juce::Component
{
public:
    OscOne(CuttingBoardSynthPluginAudioProcessor&);
    ~OscOne() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    

private:
    void initComboBoxes();
    void initLabels();
    juce::ComboBox oscSelectComboBox;
    juce::ComboBox mOscTwoSelect;
    
    juce::Label mOscOneLabel;
    juce::Label mOscTwoLabel;
    
    
    const std::array<std::string, 4> cOscList;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mpOscOneSelectAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mpOscTwoSelectAttachment;
    
    CuttingBoardSynthPluginAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscOne)
};
