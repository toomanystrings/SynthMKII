/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Envelope.h"
#include "Oscillator.h"
#include "OscTuner.h"
#include "Filter.h"
#include "Mixer.h"
#include "FilterEnvelope.h"


//==============================================================================
/**
*/
class SynthmkIiAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SynthmkIiAudioProcessorEditor (SynthmkIiAudioProcessor&);
    ~SynthmkIiAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	//MidiKeyboardComponent keyboard;
	//MidiKeyboardState keyboardState;

private:

	Envelope envGui;

	Oscillator oscGui;

	OscTuner oscTunerGui;

	Filter filterGui;

	Mixer mixerGui;

	FilterEnvelope filterEnvGui;

	

	

	

	

	// This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SynthmkIiAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthmkIiAudioProcessorEditor)
};
