/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CuttingBoardSynthPluginAudioProcessorEditor::CuttingBoardSynthPluginAudioProcessorEditor (CuttingBoardSynthPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), oscOneGuiContainer(p), oscTwoGuiContainer(p), masterOutGuiComponent(p)
{
    addAndMakeVisible(&oscOneGuiContainer);
    addAndMakeVisible(&oscTwoGuiContainer);
    addAndMakeVisible(&masterOutGuiComponent);

    setSize (675, 600);
    setResizable(false, false);
    
}

CuttingBoardSynthPluginAudioProcessorEditor::~CuttingBoardSynthPluginAudioProcessorEditor()
{
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

