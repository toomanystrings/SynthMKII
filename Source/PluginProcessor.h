/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSoundOsc1.h"
#include "SynthSoundOsc2.h"
#include "SynthSoundOsc3.h"
#include "SynthVoiceOsc1.h"
#include "SynthVoiceOsc2.h"
#include "SynthVoiceOsc3.h"

//==============================================================================
/**
*/
class SynthmkIiAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    SynthmkIiAudioProcessor();
    ~SynthmkIiAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	AudioProcessorValueTreeState tree;

	

private:
	Synthesiser synth1;
	Synthesiser synth2;
	Synthesiser synth3;
	SynthVoiceOsc1* oscVoice1;
	SynthVoiceOsc2* oscVoice2;
	SynthVoiceOsc3* oscVoice3;

	AudioBuffer<float> bufferOsc1;
	AudioBuffer<float> bufferOsc2;
	AudioBuffer<float> bufferOsc3;

	double lastSampleRate;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthmkIiAudioProcessor)
};
