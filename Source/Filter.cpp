/*
  ==============================================================================

    Filter.cpp
    Created: 11 Dec 2018 12:36:46pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"

//==============================================================================
Filter::Filter(SynthmkIiAudioProcessor& p): processor(p)
{
	setSize(600, 200);

	filterMenu1.addItem("Lowpass", 1);
	filterMenu1.addItem("Highpass", 2);
	filterMenu1.addItem("No Filter", 3);
	filterMenu1.setJustificationType(Justification::centred);
	filterMenu1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterMenu1);

	filterMenu2.addItem("Lowpass", 1);
	filterMenu2.addItem("Highpass", 2);
	filterMenu2.addItem("No Filter", 3);
	filterMenu2.setJustificationType(Justification::centred);
	filterMenu2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterMenu2);

	filterMenu3.addItem("Lowpass", 1);
	filterMenu3.addItem("Highpass", 2);
	filterMenu3.addItem("No Filter", 3);
	filterMenu3.setJustificationType(Justification::centred);
	filterMenu3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterMenu3);

	filterCutoff1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterCutoff1.setRange(20, 10000);
	filterCutoff1.setValue(400);
	filterCutoff1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	filterCutoff1.setColour(0x1001700, Colours::black);
	filterCutoff1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterCutoff1);
	filterVal1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff1", filterCutoff1);
	filterCutoff1.setSkewFactorFromMidPoint(1000);

	filterCutoff2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterCutoff2.setRange(20, 10000);
	filterCutoff2.setValue(400);
	filterCutoff2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	filterCutoff2.setColour(0x1001700, Colours::black);
	filterCutoff2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterCutoff2);
	filterVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff2", filterCutoff2);
	filterCutoff2.setSkewFactorFromMidPoint(1000);

	filterCutoff3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterCutoff3.setRange(20, 10000);
	filterCutoff3.setValue(400);
	filterCutoff3.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	filterCutoff3.setColour(0x1001700, Colours::black);
	filterCutoff3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterCutoff3);
	filterVal3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterCutoff3", filterCutoff3);
	filterCutoff3.setSkewFactorFromMidPoint(1000);

	filterRes1.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterRes1.setRange(1, 5);
	filterRes1.setValue(1);
	filterRes1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	filterRes1.setColour(0x1001700, Colours::black);
	filterRes1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterRes1);

	filterRes2.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterRes2.setRange(1, 5);
	filterRes2.setValue(1);
	filterRes2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	filterRes2.setColour(0x1001700, Colours::black);
	filterRes2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterRes2);

	filterRes3.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	filterRes3.setRange(1, 5);
	filterRes3.setValue(1);
	filterRes3.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	filterRes3.setColour(0x1001700, Colours::black);
	filterRes3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&filterRes3);

	filterTypeVal1 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType1", filterMenu1);
	filterTypeVal2 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType2", filterMenu2);
	filterTypeVal3 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "filterType3", filterMenu3);

	resVal1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRes1", filterRes1);
	resVal2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRes2", filterRes2);
	resVal3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRes3", filterRes3);


}

Filter::~Filter()
{
}

void Filter::paint (Graphics& g)
{
	


}

void Filter::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(40);

	filterMenu1.setBounds(50, 40, 100, 30);
	filterCutoff1.setBounds(30, 100, 70, 70);
	filterRes1.setBounds(100, 100, 70, 70);

	filterMenu2.setBounds(250, 40, 100, 30);
	filterCutoff2.setBounds(230, 100, 70, 70);
	filterRes2.setBounds(300, 100, 70, 70);

	filterMenu3.setBounds(450, 40, 100, 30);
	filterCutoff3.setBounds(430, 100, 70, 70);
	filterRes3.setBounds(500, 100, 70, 70);
}
