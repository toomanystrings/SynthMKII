/*
  ==============================================================================

    OscTuner.h
    Created: 6 Dec 2018 10:47:37pm
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
class OscTuner    : public Component
{
public:
    OscTuner(SynthmkIiAudioProcessor&);
    ~OscTuner();

    void paint (Graphics&) override;
    void resized() override;

private:

	SynthLookAndFeel otherLookAndFeel;

	ComboBox octaveMenu1;
	ComboBox octaveMenu2;
	ComboBox octaveMenu3;

	Slider semitoneSlider1;
	Slider semitoneSlider2;
	Slider semitoneSlider3;

	Slider centSlider1;
	Slider centSlider2;
	Slider centSlider3;

	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> octaveTree1;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> octaveTree2;
	ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> octaveTree3;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> semitoneTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> semitoneTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> semitoneTree3;

	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> centTree1;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> centTree2;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> centTree3;
	
	
	
	
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	SynthmkIiAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTuner)
};
