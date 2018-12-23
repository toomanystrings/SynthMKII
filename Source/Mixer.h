/*
  ==============================================================================

    Mixer.h
    Created: 12 Dec 2018 4:27:18pm
    Author:  Olorin

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "CustomLookAndFeel.h"
#include "OscTuner.h"



//==============================================================================
/*
*/
class Mixer    : public Component
{
public:
    Mixer(SynthmkIiAudioProcessor&);
    ~Mixer();

    void paint (Graphics&) override;
    void resized() override;

private:
	Slider gain1;
	Slider gain2;
	Slider gain3;
	Slider master;

	Slider pan1;
	Slider pan2;
	Slider pan3;

	Oscillator oscGui;
	OscTuner oscTunerGui;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> gainTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> gainTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> gainTree3;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> masterTree;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> panTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> panTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> panTree3;

	SynthLookAndFeel knobLookAndFeel;

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SynthmkIiAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Mixer)
};
