/*
  ==============================================================================

    FilterEnvelope.cpp
    Created: 22 Dec 2018 8:57:40pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterEnvelope.h"

//==============================================================================
FilterEnvelope::FilterEnvelope(SynthmkIiAudioProcessor& p): processor(p)
{
	setSize(600, 200);

	// Slider initialisation values
	attackSlider1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	attackSlider1.setRange(0.1f, 5000.0f);
	attackSlider1.setValue(0.1f);
	attackSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	attackSlider1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&attackSlider1);

	decaySlider1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	decaySlider1.setRange(0.1f, 5000.0f);
	decaySlider1.setValue(0.1f);
	decaySlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	decaySlider1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&decaySlider1);

	sustainSlider1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	sustainSlider1.setRange(0.1f, 5000.0f);
	sustainSlider1.setValue(0.1f);
	sustainSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	sustainSlider1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&sustainSlider1);

	releaseSlider1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	releaseSlider1.setRange(0.1f, 5000.0f);
	releaseSlider1.setValue(0.1f);
	releaseSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	releaseSlider1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&releaseSlider1);

	attackSlider2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	attackSlider2.setRange(0.1f, 5000.0f);
	attackSlider2.setValue(0.1f);
	attackSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	attackSlider2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&attackSlider2);

	decaySlider2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	decaySlider2.setRange(0.1f, 5000.0f);
	decaySlider2.setValue(0.1f);
	decaySlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	decaySlider2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&decaySlider2);

	sustainSlider2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	sustainSlider2.setRange(0.1f, 5000.0f);
	sustainSlider2.setValue(0.1f);
	sustainSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	sustainSlider2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&sustainSlider2);

	releaseSlider2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	releaseSlider2.setRange(0.1f, 5000.0f);
	releaseSlider2.setValue(0.1f);
	releaseSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	releaseSlider2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&releaseSlider2);

	attackSlider3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	attackSlider3.setRange(0.1f, 5000.0f);
	attackSlider3.setValue(0.1f);
	attackSlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	attackSlider3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&attackSlider3);

	decaySlider3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	decaySlider3.setRange(0.1f, 5000.0f);
	decaySlider3.setValue(0.1f);
	decaySlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	decaySlider3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&decaySlider3);

	sustainSlider3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	sustainSlider3.setRange(0.1f, 5000.0f);
	sustainSlider3.setValue(0.1f);
	sustainSlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 15);
	sustainSlider3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&sustainSlider3);

	releaseSlider3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	releaseSlider3.setRange(0.1f, 5000.0f);
	releaseSlider3.setValue(0.1f);
	releaseSlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 15);
	releaseSlider3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&releaseSlider3);

	// Sends value of the sliders to the tree states in the processor
	attackTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterAttack1", attackSlider1);
	decayTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterDecay1", decaySlider1);
	sustainTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterSustain1", sustainSlider1);
	releaseTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRelease1", releaseSlider1);

	attackTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterAttack2", attackSlider2);
	decayTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterDecay2", decaySlider2);
	sustainTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterSustain2", sustainSlider2);
	releaseTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRelease2", releaseSlider2);

	attackTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterAttack3", attackSlider3);
	decayTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterDecay3", decaySlider3);
	sustainTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterSustain3", sustainSlider3);
	releaseTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "filterRelease3", releaseSlider3);

}

FilterEnvelope::~FilterEnvelope()
{
}

void FilterEnvelope::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("FilterEnvelope", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void FilterEnvelope::resized()
{
	float x = getWidth() / 7;
	float y = getHeight() / 3;
	float knobDiameter = 70;
	float knobRadius = knobDiameter / 2;

	attackSlider1.setBounds((x * 1) - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	decaySlider1.setBounds((x * 2) - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	sustainSlider1.setBounds((x * 1) - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);
	releaseSlider1.setBounds((x * 2) - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);

	attackSlider2.setBounds((x * 3) - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	decaySlider2.setBounds((x * 4) - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	sustainSlider2.setBounds((x * 3) - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);
	releaseSlider2.setBounds((x * 4) - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);

	attackSlider3.setBounds((x * 5) - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	decaySlider3.setBounds((x * 6) - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	sustainSlider3.setBounds((x * 5) - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);
	releaseSlider3.setBounds((x * 6) - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);

}
