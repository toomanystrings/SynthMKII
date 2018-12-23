/*
  ==============================================================================

    Envelope.cpp
    Created: 5 Dec 2018 2:24:08pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthmkIiAudioProcessor& p): processor(p)
{
	setSize(600, 200);

	// Slider initialisation values
	attackSlider1.setSliderStyle(Slider::SliderStyle::LinearVertical);
	attackSlider1.setRange(0.1f, 5000.0f);
	attackSlider1.setValue(0.1f);
	attackSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&attackSlider1);

	decaySlider1.setSliderStyle(Slider::SliderStyle::LinearVertical);
	decaySlider1.setRange(0.1f, 5000.0f);
	decaySlider1.setValue(0.1f);
	decaySlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&decaySlider1);

	sustainSlider1.setSliderStyle(Slider::SliderStyle::LinearVertical);
	sustainSlider1.setRange(0.1f, 5000.0f);
	sustainSlider1.setValue(0.1f);
	sustainSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&sustainSlider1);

	releaseSlider1.setSliderStyle(Slider::SliderStyle::LinearVertical);
	releaseSlider1.setRange(0.1f, 5000.0f);
	releaseSlider1.setValue(0.1f);
	releaseSlider1.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&releaseSlider1);

	attackSlider2.setSliderStyle(Slider::SliderStyle::LinearVertical);
	attackSlider2.setRange(0.1f, 5000.0f);
	attackSlider2.setValue(0.1f);
	attackSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&attackSlider2);

	decaySlider2.setSliderStyle(Slider::SliderStyle::LinearVertical);
	decaySlider2.setRange(0.1f, 5000.0f);
	decaySlider2.setValue(0.1f);
	decaySlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&decaySlider2);

	sustainSlider2.setSliderStyle(Slider::SliderStyle::LinearVertical);
	sustainSlider2.setRange(0.1f, 5000.0f);
	sustainSlider2.setValue(0.1f);
	sustainSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&sustainSlider2);

	releaseSlider2.setSliderStyle(Slider::SliderStyle::LinearVertical);
	releaseSlider2.setRange(0.1f, 5000.0f);
	releaseSlider2.setValue(0.1f);
	releaseSlider2.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&releaseSlider2);

	attackSlider3.setSliderStyle(Slider::SliderStyle::LinearVertical);
	attackSlider3.setRange(0.1f, 5000.0f);
	attackSlider3.setValue(0.1f);
	attackSlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&attackSlider3);

	decaySlider3.setSliderStyle(Slider::SliderStyle::LinearVertical);
	decaySlider3.setRange(0.1f, 5000.0f);
	decaySlider3.setValue(0.1f);
	decaySlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&decaySlider3);

	sustainSlider3.setSliderStyle(Slider::SliderStyle::LinearVertical);
	sustainSlider3.setRange(0.1f, 5000.0f);
	sustainSlider3.setValue(0.1f);
	sustainSlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&sustainSlider3);

	releaseSlider3.setSliderStyle(Slider::SliderStyle::LinearVertical);
	releaseSlider3.setRange(0.1f, 5000.0f);
	releaseSlider3.setValue(0.1f);
	releaseSlider3.setTextBoxStyle(Slider::TextBoxBelow, true, 60, 10);
	addAndMakeVisible(&releaseSlider3);

	// Sends value of the sliders to the tree states in the processor
	attackTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack1", attackSlider1);
	decayTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay1", decaySlider1);
	sustainTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain1", sustainSlider1);
	releaseTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release1", releaseSlider1);

	attackTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack2", attackSlider2);
	decayTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay2", decaySlider2);
	sustainTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain2", sustainSlider2);
	releaseTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release2", releaseSlider2);

	attackTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack3", attackSlider3);
	decayTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay3", decaySlider3);
	sustainTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain3", sustainSlider3);
	releaseTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release3", releaseSlider3);

	
}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
	g.fillAll(Colours::black);

	/*g.setColour(Colours::crimson);
	g.drawMultiLineText("A\nT\nT\nA\nC\nK", 5, 45, 20, Justification::centred);
	g.drawMultiLineText("D\nE\nC\nA\nY", 55, 45, 20, Justification::centred);
	g.drawMultiLineText("S\nU\nS\nT\nA\nI\nN", 105, 45, 20, Justification::centred);
	g.drawMultiLineText("R\nE\nL\nE\nA\nS\nE", 155, 45, 20, Justification::centred);*/
}

void Envelope::resized()
{
	juce::Rectangle<int> area = getLocalBounds().reduced(40);

	attackSlider1.setBounds(10, 50, 40, 150);
	decaySlider1.setBounds(60, 50, 40, 150);
	sustainSlider1.setBounds(110, 50, 40, 150);
	releaseSlider1.setBounds(160, 50, 40, 150);

	attackSlider2.setBounds(210, 50, 40, 150);
	decaySlider2.setBounds(260, 50, 40, 150);
	sustainSlider2.setBounds(310, 50, 40, 150);
	releaseSlider2.setBounds(360, 50, 40, 150);

	attackSlider3.setBounds(410, 50, 40, 150);
	decaySlider3.setBounds(460, 50, 40, 150);
	sustainSlider3.setBounds(510, 50, 40, 150);
	releaseSlider3.setBounds(560, 50, 40, 150);

}
