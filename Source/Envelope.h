/*
  ==============================================================================

    Envelope.h
    Created: 5 Dec 2018 2:24:08pm
    Author:  Olorin

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class Envelope    : public Component
{
public:
    Envelope(SynthmkIiAudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;



	Slider attackSlider1;
	Slider decaySlider1;
	Slider sustainSlider1;
	Slider releaseSlider1;

	Slider attackSlider2;
	Slider decaySlider2;
	Slider sustainSlider2;
	Slider releaseSlider2;

	Slider attackSlider3;
	Slider decaySlider3;
	Slider sustainSlider3;
	Slider releaseSlider3;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> attackTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> decayTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sustainTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> releaseTree1;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> attackTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> decayTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sustainTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> releaseTree2;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> attackTree3;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> decayTree3;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> sustainTree3;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> releaseTree3;

private:

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SynthmkIiAudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
