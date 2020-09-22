/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

MasterLookAndFeel::MasterLookAndFeel() 
{
   
    juce::uint32 colorCode = 0xff2f5073;

    juce::Colour backgroundColour(colorCode);
    juce::LookAndFeel_V4::setColour(juce::ResizableWindow::ColourIds::backgroundColourId, backgroundColour);
    //406e18
    //a85a00
}

MasterLookAndFeel::~MasterLookAndFeel()
{
   
}
//not sure that this is doing anything really...
juce::Label* MasterLookAndFeel::createSliderTextBox(juce::Slider& slider)
{
    juce::Label* l = juce::LookAndFeel_V4::createSliderTextBox(slider);
    juce::Font f(10.0f, juce::Font::bold);
    l->setColour(juce::Label::ColourIds::outlineColourId, juce::Colours::red);


    return l;
}

void MasterLookAndFeel::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider)
{
    //sets colour for outer edge
    juce::uint32 currColour = 0xff7a1f36;


    juce::Rectangle<int> knobArea(x, y, width, height);
    juce::Path knobOuter;

    float thumbPos;
    juce::Point<float> thumbCoOrdinates;

    int centerX = width / 2;
    int centerY = height / 2;
    float radiusX = centerX - 4;
    float radiusY = centerY - 4;
    float pathLength;
    
    knobOuter.addCentredArc(centerX, centerY, radiusX, radiusY, 0, rotaryStartAngle, rotaryEndAngle, true);
    pathLength = knobOuter.getLength();
    thumbPos = sliderPos * pathLength;
    thumbCoOrdinates = knobOuter.getPointAlongPath(thumbPos);
    juce::Rectangle<float> thumbBorder(juce::Rectangle<float>(8.f, 8.f).withCentre(thumbCoOrdinates));

    //stokes the outer edge of the knob
    g.setColour(juce::Colour(currColour));
    g.strokePath(knobOuter, juce::PathStrokeType(5, juce::PathStrokeType::JointStyle::curved, juce::PathStrokeType::EndCapStyle::rounded));

    //sets color for inner path
    currColour = 0xf9173859;
 
    //strokes inner path
    g.setColour(juce::Colour(currColour));
    g.strokePath(knobOuter, juce::PathStrokeType(3, juce::PathStrokeType::JointStyle::curved, juce::PathStrokeType::EndCapStyle::rounded));


    //colour for thumb
    currColour = 0xfff2e943;
    g.setColour(juce::Colour(currColour));
    g.fillEllipse(thumbBorder);

    

   




}
//==============================================================================
CuttingBoardSynthPluginAudioProcessorEditor::CuttingBoardSynthPluginAudioProcessorEditor (CuttingBoardSynthPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), oscOneGuiContainer(p), oscTwoGuiContainer(p), masterOutGuiComponent(p)
{
    setLookAndFeel(dynamic_cast<MasterLookAndFeel*>(&masterLookAndFeel));
    addAndMakeVisible(&oscOneGuiContainer);
    addAndMakeVisible(&oscTwoGuiContainer);
    addAndMakeVisible(&masterOutGuiComponent);

    setSize (675, 600);
    setResizable(false, false);
    
}

CuttingBoardSynthPluginAudioProcessorEditor::~CuttingBoardSynthPluginAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
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
    const int height = getHeight();
    const int width = getWidth();
    const int padding = 25;

    const int componentWidth = 625;
    const int oscComponentHeight = 100;
    const int oscMasterOutComponentHeight = 125;

    oscOneGuiContainer.setBounds(padding, padding, componentWidth, oscComponentHeight);

    oscTwoGuiContainer.setBounds(padding, (padding * 2) + oscComponentHeight, componentWidth, oscComponentHeight); 

    masterOutGuiComponent.setBounds(padding, height - padding - oscMasterOutComponentHeight, componentWidth, oscMasterOutComponentHeight);    
 
    
}

