/*
  ==============================================================================

    Osc.cpp
    Created: 30 Aug 2020 1:11:29pm
    Author:  Trevor

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscOne.h"

//==============================================================================
OscOne::OscOne(CuttingBoardSynthPluginAudioProcessor& p): cOscList({"Sine Wave", "Saw Wave", "Square Wave", "User Wav"}), audioProcessor(p)
{   
    
    setSize(625, 100);
    initComboBoxes();
}

OscOne::~OscOne()
{
}

void OscOne::paint (juce::Graphics& g)
{
    juce::Rectangle<int> border = getLocalBounds();

    g.setColour(juce::Colours::yellow);

    g.drawRect(border);

    g.setColour(juce::Colours::white);
    g.setFont(14.0f);
    g.drawText("Osc One Component", getLocalBounds(),
        juce::Justification::centred, true);


}

void OscOne::resized()
{
    const int oscCompHeight = getHeight();
    const int oscCompWidth = getWidth();
    const int comboBoxWidth = 150;
    const int comboBoxHeight = 25;
    const int padding = 25;

    oscSelectComboBox.setBounds(0, 0, comboBoxWidth, comboBoxHeight);
    
    
}

void OscOne::initComboBoxes(){
    mpOscOneSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getProcessorTree(),"waveTypeOne", oscSelectComboBox );
    mpOscTwoSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getProcessorTree(), "waveTypeTwo", mOscTwoSelect);
    
    for (int i = 0; i < cOscList.size(); i++){
        oscSelectComboBox.addItem(cOscList[i], i+1);
        mOscTwoSelect.addItem(cOscList[i], i+1);
        oscSelectComboBox.setJustificationType(juce::Justification::centred);
        mOscTwoSelect.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(&oscSelectComboBox);
        addAndMakeVisible(&mOscTwoSelect);
        
    }
    
}

void OscOne::initLabels()
{
    mOscOneLabel.setText("Osc 1 Select", juce::dontSendNotification);
    mOscTwoLabel.setText("Osc 2 Select", juce::dontSendNotification);
    
    mOscOneLabel.attachToComponent(&oscSelectComboBox, false);
    mOscTwoLabel.attachToComponent(&mOscTwoSelect, false);
    
    addAndMakeVisible(mOscOneLabel);
    addAndMakeVisible(mOscTwoLabel);
    
    
    
    
}
