/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthmkIiAudioProcessorEditor::SynthmkIiAudioProcessorEditor (SynthmkIiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), envGui (p), oscGui (p), oscTunerGui (p), filterGui (p), mixerGui (p), filterEnvGui (p), distortionGui (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1000, 600);

	

	

	addAndMakeVisible(&envGui);
	
	

	//addAndMakeVisible(&oscTunerGui);

	addAndMakeVisible(&filterGui);
	
	addAndMakeVisible(&mixerGui);

	addAndMakeVisible(&filterEnvGui);

	addAndMakeVisible(&distortionGui);

	

	

	
}

SynthmkIiAudioProcessorEditor::~SynthmkIiAudioProcessorEditor()
{
}

//==============================================================================
void SynthmkIiAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

   
}

void SynthmkIiAudioProcessorEditor::resized()
{
	juce::Rectangle<int> area = getLocalBounds();

	const int componentWidth = 200;
	const int componentHeight = 200;
	const int envComponentWidth = 600;
	
	envGui.setBounds(0, 0, 600, 200);
	oscTunerGui.setBounds(0, 200, 200, 300);
	filterGui.setBounds(0, 200, 600, 200);
	mixerGui.setBounds(area.removeFromRight(250));
	filterEnvGui.setBounds(0, 400, 600, 200);
	distortionGui.setBounds(600, 0, 150, 300);
	
	
}
