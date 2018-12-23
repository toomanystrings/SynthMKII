/*
  ==============================================================================

    Oscillator.h
    Created: 5 Dec 2018 3:29:45pm
    Author:  Olorin

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"



//==============================================================================
/*
*/
class Oscillator    : public Component
{
public:
    Oscillator(SynthmkIiAudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

private:

	ComboBox oscMenu1;
	ComboBox oscMenu2;
	ComboBox oscMenu3;

	SynthLookAndFeel otherLookAndFeel;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection1;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection2;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection3;

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SynthmkIiAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
