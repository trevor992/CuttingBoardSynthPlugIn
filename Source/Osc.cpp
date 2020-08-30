/*
  ==============================================================================

    Osc.cpp
    Created: 30 Aug 2020 1:11:29pm
    Author:  Trevor

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Osc.h"

//==============================================================================
Osc::Osc(CuttingBoardSynthPluginAudioProcessor& p): cOscList({"Sine Wave", "Saw Wave", "Square Wave", "User Wav"}), audioProcessor(p)
{
    initComboBoxes();
}

Osc::~Osc()
{
}

void Osc::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

}

void Osc::resized()
{
    const int oscCompHeight = getHeight();
    const int oscCompWidth = getWidth();
    
    
    
}

void Osc::initComboBoxes(){
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

void Osc::comboBoxChanged(juce::ComboBox *comboBox){
    
}
