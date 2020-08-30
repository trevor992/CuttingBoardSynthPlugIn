/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CuttingBoardSynthPluginAudioProcessor::CuttingBoardSynthPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), minEnvTime(0.5f), maxEnvTime(10000.0), defEnvtime(0.5f),minVolEnvTime(0.0f), maxVolEnvTime(1.0f),
defVolEnvTime(0.0f),
//second parameter 
processorTree(*this, nullptr, "PARAMETERS",createParameters())
#endif
{
    synth.clearVoices();
    
    for(int i = 0; i < 5; i++)
    {
        synth.addVoice(new SynthVoice());
    }
    synth.clearSounds();
    synth.addSound(new SynthSound());
    
}

CuttingBoardSynthPluginAudioProcessor::~CuttingBoardSynthPluginAudioProcessor()
{
}

//==============================================================================
const juce::String CuttingBoardSynthPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool CuttingBoardSynthPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CuttingBoardSynthPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CuttingBoardSynthPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double CuttingBoardSynthPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CuttingBoardSynthPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CuttingBoardSynthPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CuttingBoardSynthPluginAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String CuttingBoardSynthPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void CuttingBoardSynthPluginAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void CuttingBoardSynthPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(samplesPerBlock); //ignore unused samples from the last key that we pressed---why?
    
    lastSampleRate = sampleRate;
    synth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void CuttingBoardSynthPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool CuttingBoardSynthPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void CuttingBoardSynthPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    for (int i =0; i < synth.getNumVoices(); i++)
    {
        if ((voice = dynamic_cast<SynthVoice*>(synth.getVoice(i))))
        {
            
            voice->applyAdsrParams(processorTree.getRawParameterValue(adsrAPVTIdentifiers[0]),processorTree.getRawParameterValue(adsrAPVTIdentifiers[1]), processorTree.getRawParameterValue(adsrAPVTIdentifiers[2]), processorTree.getRawParameterValue(adsrAPVTIdentifiers[3]));
            
            
            voice->applyMasterGain(processorTree.getRawParameterValue("MasterGain"));


        }
    }
    
    buffer.clear();
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

}

//==============================================================================
bool CuttingBoardSynthPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* CuttingBoardSynthPluginAudioProcessor::createEditor()
{
    return new CuttingBoardSynthPluginAudioProcessorEditor (*this);
}

//==============================================================================
void CuttingBoardSynthPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void CuttingBoardSynthPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}
juce::AudioProcessorValueTreeState::ParameterLayout CuttingBoardSynthPluginAudioProcessor::createParameters()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    params.push_back(std::make_unique<juce::AudioParameterFloat>(adsrAPVTIdentifiers[0], "AmpAttack", minEnvTime,maxEnvTime,defEnvtime));
    params.push_back(std::make_unique<juce::AudioParameterFloat>(adsrAPVTIdentifiers[1], "AmpDecay", minEnvTime, maxEnvTime, defEnvtime));
    params.push_back(std::make_unique<juce::AudioParameterFloat>(adsrAPVTIdentifiers[2], "AmpSustain", minVolEnvTime, maxVolEnvTime,defVolEnvTime));
    params.push_back(std::make_unique<juce::AudioParameterFloat>(adsrAPVTIdentifiers[3], "AmpRelease", minEnvTime,maxEnvTime,defEnvtime));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("MasterGain", "MasterGain", 0.0f, 1.0f, 0.0f));
    
    return {params.begin(), params.end()};
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CuttingBoardSynthPluginAudioProcessor();
}
