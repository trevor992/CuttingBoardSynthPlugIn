/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "OscOne.h"
#include "OscTwo.h"
#include "MasterOutComponent.h"


class MasterLookAndFeel : public juce::LookAndFeel_V4 
{
public:

    MasterLookAndFeel();
    ~MasterLookAndFeel();
    juce::Label* createSliderTextBox(juce::Slider& slider) override;
    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider& slider) override;

private:

};

//==============================================================================
/**
*/
class CuttingBoardSynthPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:

CuttingBoardSynthPluginAudioProcessorEditor (CuttingBoardSynthPluginAudioProcessor&);

~CuttingBoardSynthPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    //likely will get rid of the Sliderlisten class
   

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    MasterLookAndFeel masterLookAndFeel;

    CuttingBoardSynthPluginAudioProcessor& audioProcessor;

    OscOne oscOneGuiContainer;

    OscTwo oscTwoGuiContainer;

    MasterOutComponent masterOutGuiComponent;   

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CuttingBoardSynthPluginAudioProcessorEditor)
};
