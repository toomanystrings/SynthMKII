/*
  ==============================================================================

    Distortion.h
    Created: 28 Dec 2018 4:10:28pm
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
class Distortion    : public Component
{
public:
    Distortion(SynthmkIiAudioProcessor&);
    ~Distortion();

    void paint (Graphics&) override;
    void resized() override;

private:
	SynthLookAndFeel knobLookAndFeel;

	Slider driveKnob;
	Slider rangeKnob;
	Slider blendKnob;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveTree;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeTree;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendTree;

	SynthmkIiAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Distortion)
};
