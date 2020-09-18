/*
  ==============================================================================

    MasterOutComponent.h
    Created: 18 Sep 2020 11:43:22am
    Author:  Trevor

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MasterOutComponent  : public juce::Component
{
public:
    MasterOutComponent();
    ~MasterOutComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterOutComponent)
};
