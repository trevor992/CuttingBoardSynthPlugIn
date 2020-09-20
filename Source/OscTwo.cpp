/*
  ==============================================================================

    OscTwo.cpp
    Created: 18 Sep 2020 11:38:00am
    Author:  Trevor

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscTwo.h"

//==============================================================================
OscTwo::OscTwo(CuttingBoardSynthPluginAudioProcessor& p) : oscList({ "Sine Wave", "Saw Wave", "Square Wave", "User Wav"}), audioProcessor(p)
{
    initComboBoxes();
    initLabels();
    setSize(625, 100);

}

OscTwo::~OscTwo()
{
}

void OscTwo::paint (juce::Graphics& g)
{
    juce::Rectangle<int> border = getLocalBounds();

    g.setColour(juce::Colours::yellow);

    g.drawRect(border);

    g.setColour(juce::Colours::white);
    g.setFont(14.0f);
    g.drawText("Osc Two Component", getLocalBounds(),
        juce::Justification::centred, true);

}

void OscTwo::resized()
{
    const int oscCompHeight = getHeight();
    const int oscCompWidth = getWidth();
    const int comboBoxWidth = 150;
    const int comboBoxHeight = 25;
    const int padding = 25;

    oscSelectComboBox.setBounds(0, padding, comboBoxWidth, comboBoxHeight);

}

void OscTwo::initComboBoxes()
{
    oscComboBoxAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.getProcessorTree(), "waveTypeTwo", oscSelectComboBox);

    for (int i = 0; i < oscList.size(); i++) {
        oscSelectComboBox.addItem(oscList[i], i + 1);
        oscSelectComboBox.setJustificationType(juce::Justification::centred);
        addAndMakeVisible(&oscSelectComboBox);
    }

}

void OscTwo::initLabels() 
{
    oscLabel.setText("Osc 2 Select", juce::dontSendNotification);

    oscLabel.attachToComponent(&oscSelectComboBox, false);

    oscLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(oscLabel);
}
