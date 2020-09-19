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

//==============================================================================
/**
*/
class CuttingBoardSynthPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    void extracted();
    
CuttingBoardSynthPluginAudioProcessorEditor (CuttingBoardSynthPluginAudioProcessor&);
    ~CuttingBoardSynthPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    //likely will get rid of the Sliderlisten class
   

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    

    CuttingBoardSynthPluginAudioProcessor& audioProcessor;

    OscOne oscOneGuiContainer;

    OscTwo oscTwoGuiContainer;

    MasterOutComponent masterOutGuiComponent;


    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CuttingBoardSynthPluginAudioProcessorEditor)
};
