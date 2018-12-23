/*
  ==============================================================================

    Filter.h
    Created: 11 Dec 2018 12:36:46pm
    Author:  Olorin

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.H"
#include "CustomLookAndFeel.h"

//==============================================================================
/*
*/
class Filter    : public Component
{
public:
    Filter(SynthmkIiAudioProcessor&);
    ~Filter();

    void paint (Graphics&) override;
    void resized() override;

private:

	SynthLookAndFeel otherLookAndFeel;

	ComboBox filterMenu1;
	ComboBox filterMenu2;
	ComboBox filterMenu3;

	Slider filterCutoff1;
	Slider filterCutoff2;
	Slider filterCutoff3;

	Slider filterRes1;
	Slider filterRes2;
	Slider filterRes3;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal1;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal2;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeVal3;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterVal3;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> resVal3;



	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SynthmkIiAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filter)
};
