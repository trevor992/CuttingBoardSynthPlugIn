/*
  ==============================================================================

    MasterOutComponent.cpp
    Created: 18 Sep 2020 11:43:22am
    Author:  Trevor

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MasterOutComponent.h"

//==============================================================================
MasterOutComponent::MasterOutComponent(CuttingBoardSynthPluginAudioProcessor& p) : audioProcessor(p), masterEnvelopeGuiComponent(p)
{
    addAndMakeVisible(&masterEnvelopeGuiComponent);
    setSize(550, 125);

}

MasterOutComponent::~MasterOutComponent()
{
}

void MasterOutComponent::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
    juce::Rectangle<int> border = getLocalBounds();


    g.setColour (juce::Colours::yellow);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (juce::Colours::white);
    g.setFont (14.0f);
    g.drawText ("MasterOutComponent", getLocalBounds(),
                juce::Justification::centred, true);   // draw some placeholder text
}

void MasterOutComponent::resized()
{
    const int height = getHeight();
    const int width = getWidth();
    const int masterEnvelopeXPos = 325;
    const int masterEnvelopeYPos = 0;
    const int masterEnvelopeHeight = 50;
    const int masterEnvelopeWidth = 275;



    masterEnvelopeGuiComponent.setBounds(masterEnvelopeXPos, masterEnvelopeYPos, masterEnvelopeWidth, masterEnvelopeHeight);

    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void MasterOutComponent::initSliders()
{
    masterGainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getProcessorTree(), "MasterGain", masterGain);
    masterGain.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    masterGain.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 20);

    addAndMakeVisible(&masterGain);
    masterGain.setNumDecimalPlacesToDisplay(2);
}