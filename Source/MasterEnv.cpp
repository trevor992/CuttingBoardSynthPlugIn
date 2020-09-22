/*
  ==============================================================================

    MasterEnv.cpp
    Created: 18 Sep 2020 11:37:22am
    Author:  Trevor

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MasterEnv.h"

//==============================================================================
MasterEnv::MasterEnv(CuttingBoardSynthPluginAudioProcessor& p) : audioProcessor(p)
{
    initSliders();
    initLabels();
    setSize(275, 50);
}

MasterEnv::~MasterEnv()
{
}

void MasterEnv::paint (juce::Graphics& g)
{
    juce::Rectangle<int> border = getLocalBounds();

    //g.setColour(juce::Colours::yellow);
    //g.drawRect(border);

 

   
}

void MasterEnv::resized()
{
    const int totalHeight = getHeight();
    const int totalWidth = getWidth();
    const int adsrKnobWidth = 50;
    const int adsrKnobHeight = 50;
    const int padding = 25;
    int adsrXPos = 0;
    int adsrYPos = 0;
    juce::Rectangle<int> rotarySliderDims = { 0,0, 40, 40 };
    juce::Rectangle<int> textBoxDims = { 0,40, 50, 10 };
    
    for (int i = 0; i < adsrKnobs.size(); i++)
    {
        adsrKnobs[i].setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colours::transparentWhite);
        adsrKnobs[i].setBounds(adsrXPos, adsrYPos, adsrKnobWidth, adsrKnobHeight);
        adsrKnobs[i].setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, adsrKnobWidth, 10);
        adsrXPos += padding + adsrKnobWidth;
    }

}

void MasterEnv::initLabels()
{
    for (int i = 0; i < adsrLabels.size(); i++)
    {
        adsrLabels[i].setText(adsrText[i], juce::dontSendNotification);
        adsrLabels[i].setJustificationType(juce::Justification::centred);
        adsrLabels[i].attachToComponent(&adsrKnobs[i], false);
        addAndMakeVisible(&adsrLabels[i]);
    }

}

void MasterEnv::initSliders()
{
    for (int i = 0; i < adsrKnobs.size(); i++)
    {
        //allocating memory on heap
        adsrAttachments[i] = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getProcessorTree(), audioProcessor.adsrAPVTIdentifiers[i], adsrKnobs[i]);
        adsrKnobs[i].setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
        adsrKnobs[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 130, 12);
        addAndMakeVisible(&adsrKnobs[i]);
        //sustain knob
        if (i == 2)
        {
            adsrKnobs[i].setNumDecimalPlacesToDisplay(1);
        }
        else
        {
            adsrKnobs[i].setTextValueSuffix("s");
            adsrKnobs[i].setNumDecimalPlacesToDisplay(2);
        }


    }
}