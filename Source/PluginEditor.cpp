/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CuttingBoardSynthPluginAudioProcessorEditor::CuttingBoardSynthPluginAudioProcessorEditor (CuttingBoardSynthPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    initSliders();
    initLabels();
    //sliderTree = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.processorTree, "AmpAtk",  adsrKnobs[0]);
    setSize (675, 600);
    setResizable(false, false);
    
}

CuttingBoardSynthPluginAudioProcessorEditor::~CuttingBoardSynthPluginAudioProcessorEditor()
{
}

//==============================================================================
void CuttingBoardSynthPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    
}

void CuttingBoardSynthPluginAudioProcessorEditor::resized()
{
    const int totalHeight = getHeight();
    const int totalWidth = getWidth();
    const int adsrKnobWidth = totalWidth/4 - 8;
    const int adsrKnobHeight = adsrKnobWidth;
    const int padding = 4;
    int adsrXPos = 4;
    int adsrYPos = 24;
    const int masterGainYPos = adsrKnobHeight + adsrYPos;
    const int masterGainWidth = adsrKnobWidth / 2;
    const int masterGainHeight = adsrKnobHeight;
    
    //position the ADSR Knobs
    for (int i = 0; i < adsrKnobs.size();i++)
    {
        adsrKnobs[i].setBounds(adsrXPos, adsrYPos, adsrKnobWidth, adsrKnobHeight);
        adsrXPos += padding + adsrKnobWidth;
    }
    adsrXPos -= padding + adsrKnobWidth;
    masterGain.setBounds(adsrXPos, masterGainYPos, masterGainWidth, masterGainHeight);
    
}
void CuttingBoardSynthPluginAudioProcessorEditor::initSliders()
{
    masterGainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getProcessorTree(),"MasterGain", masterGain);
    masterGain.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    masterGain.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);
    
    addAndMakeVisible(&masterGain);
    masterGain.setNumDecimalPlacesToDisplay(2);
    
    for (int i = 0; i < adsrKnobs.size(); i++)
    {
        //allocating memory on heap
        adsrAttachments[i] = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getProcessorTree(), audioProcessor.adsrAPVTIdentifiers[i],adsrKnobs[i]);
        
        adsrKnobs[i].setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        adsrKnobs[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 130, 20);
        addAndMakeVisible(&adsrKnobs[i]);
        //sustain knob
        if (i == 2)
        {
            adsrKnobs[i].setNumDecimalPlacesToDisplay(1);
        }else
        {
            adsrKnobs[i].setTextValueSuffix("ms");
            adsrKnobs[i].setNumDecimalPlacesToDisplay(2);
        }
        
        
    }
}

void CuttingBoardSynthPluginAudioProcessorEditor::initLabels()
{
    for (int i = 0; i < adsrLabels.size(); i++)
    {
        adsrLabels[i].setText(adsrText[i], juce::dontSendNotification);
        adsrLabels[i].setJustificationType(juce::Justification::centred);
        adsrLabels[i].attachToComponent(&adsrKnobs[i], false);
        addAndMakeVisible(&adsrLabels[i]);
    }
}
