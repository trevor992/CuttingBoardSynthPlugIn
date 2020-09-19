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
    
    
    setSize(675, 300);
    initComboBoxes();
}

OscOne::~OscOne()
{
}

void OscOne::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

}

void OscOne::resized()
{
    const int oscCompHeight = getHeight();
    const int oscCompWidth = getWidth();
    const int comboBoxWidth = 100;
    const int comboBoxHeight = 25;
    const int padding = 16;
    
    mOscOneSelect.setBounds(0, 0, comboBoxWidth, comboBoxHeight);
    mOscTwoSelect.setBounds(comboBoxWidth + padding, 0, comboBoxWidth, comboBoxHeight);        
    
    
}

void OscOne::initComboBoxes(){
    mpOscOneSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getProcessorTree(),"waveTypeOne", mOscOneSelect );
    mpOscTwoSelectAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getProcessorTree(), "waveTypeTwo", mOscTwoSelect);
    
    for (int i = 0; i < cOscList.size(); i++){
        mOscOneSelect.addItem(cOscList[i], i+1);
        mOscTwoSelect.addItem(cOscList[i], i+1);
        mOscOneSelect.setJustificationType(juce::Justification::centred);
        mOscTwoSelect.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(&mOscOneSelect);
        addAndMakeVisible(&mOscTwoSelect);
        
    }
    
}

void OscOne::initLabels()
{
    mOscOneLabel.setText("Osc 1 Select", juce::dontSendNotification);
    mOscTwoLabel.setText("Osc 2 Select", juce::dontSendNotification);
    
    mOscOneLabel.attachToComponent(&mOscOneSelect, false);
    mOscTwoLabel.attachToComponent(&mOscTwoSelect, false);
    
    addAndMakeVisible(mOscOneLabel);
    addAndMakeVisible(mOscTwoLabel);
    
    
    
    
}
