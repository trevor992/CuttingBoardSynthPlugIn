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
    setSize(50, 275);
}

MasterEnv::~MasterEnv()
{
}

void MasterEnv::paint (juce::Graphics& g)
{
    juce::Rectangle<int> border = getLocalBounds();

    g.setColour(juce::Colours::yellow);
    g.drawRect(border);

    g.setColour(juce::Colours::white);
    g.setFont(14.0f);
    g.drawText("Master Amp Envelope", getLocalBounds(),
        juce::Justification::centred, true);

   
}

void MasterEnv::resized()
{
    const int totalHeight = getHeight();
    const int totalWidth = getWidth();
    const int adsrKnobWidth = totalWidth / 4 - 8;
    const int adsrKnobHeight = adsrKnobWidth;
    const int padding = 4;
    int adsrXPos = 4;
    int adsrYPos = 24;

    for (int i = 0; i < adsrKnobs.size(); i++)
    {
        adsrKnobs[i].setBounds(adsrXPos, adsrYPos, adsrKnobWidth, adsrKnobHeight);
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
        adsrKnobs[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 130, 20);
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