/*
  ==============================================================================

    Oscillator.cpp
    Created: 5 Dec 2018 3:29:45pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthmkIiAudioProcessor& p): processor(p)
{
	setSize(250, 20);

	// Initialise the drop down menu
	oscMenu1.addItem("Void", 1);
	oscMenu1.addItem("Sine", 2);
	oscMenu1.addItem("Saw", 3);
	oscMenu1.addItem("Triangle", 4);
	oscMenu1.addItem("Square", 5);
	oscMenu1.setLookAndFeel(&otherLookAndFeel);
	oscMenu1.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscMenu1);


	oscMenu2.addItem("Void", 1);
	oscMenu2.addItem("Sine", 2);
	oscMenu2.addItem("Saw", 3);
	oscMenu2.addItem("Triangle", 4);
	oscMenu2.addItem("Square", 5);
	oscMenu2.setLookAndFeel(&otherLookAndFeel);
	oscMenu2.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscMenu2);

	oscMenu3.addItem("Void", 1);
	oscMenu3.addItem("Sine", 2);
	oscMenu3.addItem("Saw", 3);
	oscMenu3.addItem("Triangle", 4);
	oscMenu3.addItem("Square", 5);
	oscMenu3.setLookAndFeel(&otherLookAndFeel);
	oscMenu3.setJustificationType(Justification::centred);
	addAndMakeVisible(&oscMenu3);

	waveSelection1 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype1", oscMenu1);
	waveSelection2 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype2", oscMenu2);
	waveSelection3 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype3", oscMenu3);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
	
}

void Oscillator::resized()
{
	juce::Rectangle<int> area = getLocalBounds();

	float x = getWidth() / 4;
	float y = getHeight() / 2;
	float width = 70;
	float height = 20;

	oscMenu1.setBounds((x * 1) - (width / 2), 0, width, height);
	oscMenu2.setBounds((x * 2) - (width / 2), 0, width, height);
	oscMenu3.setBounds((x * 3) - (width / 2), 0, width, height);
}