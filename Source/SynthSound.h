/*
  ==============================================================================

    SynthSound.h
    Created: 14 Aug 2020 12:10:11pm
    Author:  Trevor

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber);
    bool appliesToChannel (int midiChannel);
};


