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
OscOne::OscOne(CuttingBoardSynthPluginAudioProcessor& p): oscList({"Sine Wave", "Saw Wave", "Square Wave", "User Wav"}), audioProcessor(p)
{   
    
    setSize(625, 100);
    initComboBoxes();
    initLabels();
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

    oscSelectComboBox.setBounds(0, padding, comboBoxWidth, comboBoxHeight);
    
    
}

void OscOne::initComboBoxes(){
    oscComboBoxAttachement = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getProcessorTree(),"waveTypeOne", oscSelectComboBox );
    
    for (int i = 0; i < oscList.size(); i++){
        oscSelectComboBox.addItem(oscList[i], i+1);
        oscSelectComboBox.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(&oscSelectComboBox);        
    }
    
}

void OscOne::initLabels()
{
    oscLabel.setText("Osc 1 Select", juce::dontSendNotification);
    
    oscLabel.attachToComponent(&oscSelectComboBox, false);

    oscLabel.setJustificationType(juce::Justification::centred);
    
    addAndMakeVisible(oscLabel);   
    
}
