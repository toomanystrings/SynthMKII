/*
  ==============================================================================

    Distortion.cpp
    Created: 28 Dec 2018 4:10:28pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Distortion.h"

//==============================================================================
Distortion::Distortion(SynthmkIiAudioProcessor& p): processor(p)
{
	setSize(150, 300);

	driveKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	driveKnob.setRange(0.f, 1.f);
	driveKnob.setValue(0.5f);
	driveKnob.setLookAndFeel(&knobLookAndFeel);
	driveKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	addAndMakeVisible(&driveKnob);

	rangeKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	rangeKnob.setRange(0.f, 3000.f);
	rangeKnob.setValue(0.5f);
	rangeKnob.setLookAndFeel(&knobLookAndFeel);
	rangeKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	addAndMakeVisible(&rangeKnob);

	blendKnob.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	blendKnob.setRange(0.f, 1.f);
	blendKnob.setValue(0.5f);
	blendKnob.setLookAndFeel(&knobLookAndFeel);
	blendKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	addAndMakeVisible(&blendKnob);

	driveTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "drive", driveKnob);
	rangeTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "range", rangeKnob);
	blendTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "blend", blendKnob);
}

Distortion::~Distortion()
{
}

void Distortion::paint (Graphics& g)
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
    //g.drawText ("Distortion", getLocalBounds(),
               // Justification::centred, true);   // draw some placeholder text
}

void Distortion::resized()
{
	juce::Rectangle<int> area = getLocalBounds();
	
	float x = getWidth() / 2;
	float y = getHeight() / 4;
	float knobDiameter = 70;
	float knobRadius = knobDiameter / 2;

	driveKnob.setBounds(x - knobRadius, (y * 1) - knobRadius, knobDiameter, knobDiameter);
	rangeKnob.setBounds(x - knobRadius, (y * 2) - knobRadius, knobDiameter, knobDiameter);
	blendKnob.setBounds(x - knobRadius, (y * 3) - knobRadius, knobDiameter, knobDiameter);
}
