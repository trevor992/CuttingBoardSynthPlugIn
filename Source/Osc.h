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
class Osc  : public juce::Component, public juce::ComboBox::Listener
{
public:
    Osc(CuttingBoardSynthPluginAudioProcessor&);
    ~Osc() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(juce::ComboBox* comboBox) override;
    void initComboBoxes();
    

private:
    juce::ComboBox mOscOneSelect;
    juce::ComboBox mOscTwoSelect;
    const std::array<std::string, 4> cOscList;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mpOscOneSelectAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mpOscTwoSelectAttachment;
    
    CuttingBoardSynthPluginAudioProcessor& audioProcessor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Osc)
};
