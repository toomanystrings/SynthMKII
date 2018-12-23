/*
  ==============================================================================

    OscTuner.cpp
    Created: 6 Dec 2018 10:47:37pm
    Author:  Olorin

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "OscTuner.h"

//==============================================================================
OscTuner::OscTuner(SynthmkIiAudioProcessor& p): processor(p)
{
	setSize(250, 200);

	octaveMenu1.addItem("15vb", 1);
	octaveMenu1.addItem("8vb", 2);
	octaveMenu1.addItem(" ", 3);
	octaveMenu1.addItem("8va", 4);
	octaveMenu1.addItem("15va", 5);
	octaveMenu1.setJustificationType(Justification::centred);
	octaveMenu1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&octaveMenu1);

	octaveMenu2.addItem("15vb", 1);
	octaveMenu2.addItem("8vb", 2);
	octaveMenu2.addItem(" ", 3);
	octaveMenu2.addItem("8va", 4);
	octaveMenu2.addItem("15va", 5);
	octaveMenu2.setJustificationType(Justification::centred);
	octaveMenu2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&octaveMenu2);

	octaveMenu3.addItem("15vb", 1);
	octaveMenu3.addItem("8vb", 2);
	octaveMenu3.addItem(" ", 3);
	octaveMenu3.addItem("8va", 4);
	octaveMenu3.addItem("15va", 5);
	octaveMenu3.setJustificationType(Justification::centred);
	octaveMenu3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&octaveMenu3);

	semitoneSlider1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	semitoneSlider1.setRange(-11, 11, 1);
	semitoneSlider1.setValue(0);
	semitoneSlider1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	semitoneSlider1.setColour(0x1001700, Colours::black);
	/*semitoneSlider1.setNumDecimalPlacesToDisplay(0);
	semitoneSlider1.getNumDecimalPlacesToDisplay();*/
	semitoneSlider1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&semitoneSlider1);

	semitoneSlider2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	semitoneSlider2.setRange(-11, 11, 1);
	semitoneSlider2.setValue(0);
	semitoneSlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	semitoneSlider2.setColour(0x1001700, Colours::black);
	/*semitoneSlider2.setNumDecimalPlacesToDisplay(0);
	semitoneSlider2.getNumDecimalPlacesToDisplay();*/
	semitoneSlider2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&semitoneSlider2);

	semitoneSlider3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	semitoneSlider3.setRange(-11, 11);
	semitoneSlider3.setValue(0);
	semitoneSlider3.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	semitoneSlider3.setColour(0x1001700, Colours::black);
	/*semitoneSlider3.setNumDecimalPlacesToDisplay(0);
	semitoneSlider3.getNumDecimalPlacesToDisplay();*/
	semitoneSlider3.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&semitoneSlider3);

	centSlider1.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	centSlider1.setRange(-100, 100);
	centSlider1.setValue(0);
	centSlider1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	centSlider1.setColour(0x1001700, Colours::black);
	//centSlider1.setNumDecimalPlacesToDisplay(0);
	centSlider1.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&centSlider1);

	centSlider2.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	centSlider2.setRange(-100, 100, 1);
	centSlider2.setValue(0);
	centSlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	centSlider2.setColour(0x1001700, Colours::black);
	//centSlider2.setNumDecimalPlacesToDisplay(0);
	centSlider2.setLookAndFeel(&otherLookAndFeel);
	addAndMakeVisible(&centSlider2);

	centSlider3.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	centSlider3.setRange(-99, 99, 1);
	centSlider3.setValue(0);
	centSlider3.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
	centSlider3.setColour(0x1001700, Colours::black);
	//centSlider3.setNumDecimalPlacesToDisplay(0);
	centSlider3.setLookAndFeel(&otherLookAndFeel);
	centSlider3.setDoubleClickReturnValue(true, 0);
	addAndMakeVisible(&centSlider3);

	octaveTree1 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "octave1", octaveMenu1);
	octaveTree2 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "octave2", octaveMenu2);
	octaveTree3 = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "octave3", octaveMenu3);

	semitoneTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "semitone1", semitoneSlider1);
	semitoneTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "semitone2", semitoneSlider2);
	semitoneTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "semitone3", semitoneSlider3);

	centTree1 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "cent1", centSlider1);
	centTree2 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "cent2", centSlider2);
	centTree3 = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "cent3", centSlider3);








}

OscTuner::~OscTuner()
{
}

void OscTuner::paint (Graphics& g)
{
	juce::Rectangle<int> area = getLocalBounds();

	double x = area.getWidth() / 4;
	double y = area.getHeight() / 4;

}

void OscTuner::resized()
{
	juce::Rectangle<int> area = getLocalBounds();

	int knobDiameter = 70;
	int knobRadius = knobDiameter / 2;
	double x = area.getWidth() / 4;
	double y = area.getHeight() / 4;
	int comboBoxWidth = 70;
	int comboBoxHeight = 20;

	centSlider1.setBounds((x * 1) - knobRadius, (y * 0), knobDiameter, knobDiameter);
	centSlider2.setBounds((x * 2) - knobRadius, (y * 0), knobDiameter, knobDiameter);
	centSlider3.setBounds((x * 3) - knobRadius, (y * 0), knobDiameter, knobDiameter);

	semitoneSlider1.setBounds((x * 1) - knobRadius, (y * 1), knobDiameter, knobDiameter);
	semitoneSlider2.setBounds((x * 2) - knobRadius, (y * 1), knobDiameter, knobDiameter);
	semitoneSlider3.setBounds((x * 3) - knobRadius, (y * 1), knobDiameter, knobDiameter);
	
	octaveMenu1.setBounds((x * 1) - (comboBoxWidth / 2), (y * 2), comboBoxWidth, comboBoxHeight);
	octaveMenu2.setBounds((x * 2) - (comboBoxWidth / 2), (y * 2), comboBoxWidth, comboBoxHeight);
	octaveMenu3.setBounds((x * 3) - (comboBoxWidth / 2), (y * 2), comboBoxWidth, comboBoxHeight);
	
	


}
