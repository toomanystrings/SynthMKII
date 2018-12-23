/*
  ==============================================================================

    Mixer.cpp
    Created: 12 Dec 2018 4:27:18pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Mixer.h"

//==============================================================================
Mixer::Mixer(SynthmkIiAudioProcessor& p): processor(p), oscGui(p), oscTunerGui(p)
{
	setSize(250, 600);

	// TODO: Master slider?

	gain1.setSliderStyle(Slider::SliderStyle::LinearVertical);
	gain1.setRange(0, 1.5);
	gain1.setValue(1);
	gain1.setTextBoxStyle(Slider::TextBoxAbove, true, 50, 15);
	gain1.setColour(0x1001700, Colours::black);
	addAndMakeVisible(&gain1);

	gain2.setSliderStyle(Slider::SliderStyle::LinearVertical);
	gain2.setRange(0, 1.5);
	gain2.setValue(1);
	gain2.setTextBoxStyle(Slider::TextBoxAbove, true, 50, 15);
	gain2.setColour(0x1001700, Colours::black);
	addAndMakeVisible(&gain2);

	gain3.setSliderStyle(Slider::SliderStyle::LinearVertical);
	gain3.setRange(0, 1.5);
	gain3.setValue(1);
	gain3.setTextBoxStyle(Slider::TextBoxAbove, true, 50, 15);
	gain3.setColour(0x1001700, Colours::black);
	addAndMakeVisible(&gain3);

	pan1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	pan1.setRange(-1, 1);
	pan1.setValue(0);
	pan1.setTextBoxStyle(Slider::NoTextBox, false, 25, 10);
	pan1.setLookAndFeel(&knobLookAndFeel);
	addAndMakeVisible(&pan1);

	pan2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	pan2.setLookAndFeel(&knobLookAndFeel);
	pan2.setRange(-1, 1);
	pan2.setValue(0);
	pan2.setTextBoxStyle(Slider::NoTextBox, false, 50, 15);
	addAndMakeVisible(&pan2);

	pan3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	pan3.setRange(-1, 1);
	pan3.setValue(0);
	pan3.setTextBoxStyle(Slider::NoTextBox, false, 25, 10);
	pan3.setLookAndFeel(&knobLookAndFeel);
	addAndMakeVisible(&pan3);

	gainTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "gain1", gain1);
	gainTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "gain2", gain2);
	gainTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "gain3", gain3);

	panTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pan1", pan1);
	panTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pan2", pan2);
	panTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "pan3", pan3);


	addAndMakeVisible(&oscTunerGui);
	addAndMakeVisible(&oscGui);
}

Mixer::~Mixer()
{
}

void Mixer::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

	g.setColour(Colours::whitesmoke);
	//g.drawFittedText;
	
	g.fillAll(Colours::black);
	juce::Rectangle<float> screw;

  
}

void Mixer::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

	float x = getWidth() / 4;
	float y = getHeight() / 6;
	float faderWidth = 50;
	float faderHeight = 280;
	float knobDiameter = 55;
	float knobRadius = knobDiameter / 2;
	float oscWidth = 250;
	float oscHeight = 20;

	gain1.setBounds((x * 1) - (faderWidth / 2), y * 3, faderWidth, faderHeight);
	gain2.setBounds((x * 2) - (faderWidth / 2), y * 3, faderWidth, faderHeight);
	gain3.setBounds((x * 3) - (faderWidth / 2), y * 3, faderWidth, faderHeight);

	pan1.setBounds((x * 1) - knobRadius, (y * 3) - knobDiameter, knobDiameter, knobDiameter);
	pan2.setBounds((x * 2) - knobRadius, (y * 3) - knobDiameter, knobDiameter, knobDiameter);
	pan3.setBounds((x * 3) - knobRadius, (y * 3) - knobDiameter, knobDiameter, knobDiameter);

	oscTunerGui.setBounds(0, 0, 250, 300);
	oscGui.setBounds(0, (y * 2) + oscHeight, oscWidth, oscHeight);
}
