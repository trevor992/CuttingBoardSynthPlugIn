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
OscTwo::OscTwo(CuttingBoardSynthPluginAudioProcessor& p) : audioProcessor(p)
{
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
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
