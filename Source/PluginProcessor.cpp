/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthmkIiAudioProcessor::SynthmkIiAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ), tree(*this, nullptr)
#endif
{
	// These normaliseable range objects are used to define the range of the tree state below.
	NormalisableRange<float> attackParam(0.1f, 5000.0f);
	NormalisableRange<float> decayParam(0.1f, 5000.0f);
	NormalisableRange<float> sustainParam(0.1f, 5000.0f);
	NormalisableRange<float> releaseParam(0.1f, 5000.0f);

	// Parameters that make it possible to set/get states and automate parameters in your DAW. 
	// Also connects values between the slider and the values here.
	// Envelope for oscillator
	tree.createAndAddParameter("attack1", "Attack", "attack", attackParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("decay1", "Decay", "decay", decayParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("sustain1", "Sustain", "sustain", sustainParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("release1", "Release", "release", releaseParam, 0.1f, nullptr, nullptr);

	tree.createAndAddParameter("attack2", "Attack", "attack", attackParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("decay2", "Decay", "decay", decayParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("sustain2", "Sustain", "sustain", sustainParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("release2", "Release", "release", releaseParam, 0.1f, nullptr, nullptr);

	tree.createAndAddParameter("attack3", "Attack", "attack", attackParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("decay3", "Decay", "decay", decayParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("sustain3", "Sustain", "sustain", sustainParam, 0.1f, nullptr, nullptr);
	tree.createAndAddParameter("release3", "Release", "release", releaseParam, 0.1f, nullptr, nullptr);

	// Envelope for filter
	NormalisableRange<float> filterEnvelope(0.1f, 5000.0f);
	tree.createAndAddParameter("filterAttack1", "Attack", "attack", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterDecay1", "Decay", "decay", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterSustain1", "Sustain", "sustain", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterRelease1", "Release", "release", filterEnvelope, 1.f, nullptr, nullptr);

	tree.createAndAddParameter("filterAttack2", "Attack", "attack", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterDecay2", "Decay", "decay", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterSustain2", "Sustain", "sustain", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterRelease2", "Release", "release", filterEnvelope, 1.f, nullptr, nullptr);

	tree.createAndAddParameter("filterAttack3", "Attack", "attack", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterDecay3", "Decay", "decay", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterSustain3", "Sustain", "sustain", filterEnvelope, 1.f, nullptr, nullptr);
	tree.createAndAddParameter("filterRelease3", "Release", "release", filterEnvelope, 1.f, nullptr, nullptr);
	
	// As above, but for the dropdown menu for selecting oscilliators
	NormalisableRange<float> wavetypeParam(0, 4);
	tree.createAndAddParameter("wavetype1", "Wavetype", "wavetype", wavetypeParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("wavetype2", "Wavetype", "wavetype", wavetypeParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("wavetype3", "Wavetype", "wavetype", wavetypeParam, 0, nullptr, nullptr);

	// Drop down mnu for selecting octave
	NormalisableRange<float> octaveParam(0, 4);
	tree.createAndAddParameter("octave1", "Octave1", "octave1", octaveParam, 2, nullptr, nullptr);
	tree.createAndAddParameter("octave2", "Octave2", "octave2", octaveParam, 2, nullptr, nullptr);
	tree.createAndAddParameter("octave3", "Octave3", "octave3", octaveParam, 2, nullptr, nullptr);

	// Semitone Slider
	NormalisableRange<float> semitoneParam(-11, 11, 1);
	tree.createAndAddParameter("semitone1", "Semitone1", "semitone1", semitoneParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("semitone2", "Semitone2", "semitone2", semitoneParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("semitone3", "Semitone3", "semitone3", semitoneParam, 0, nullptr, nullptr);

	// Cent Slider
	NormalisableRange<float> centParam(-99, 99, 1);
	tree.createAndAddParameter("cent1", "Cent1", "cent1", centParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("cent2", "Cent2", "cent2", centParam, 0, nullptr, nullptr);
	tree.createAndAddParameter("cent3", "Cent3", "cent3", centParam, 0, nullptr, nullptr);

	// Filter stuff
	NormalisableRange<float> filterTypeParam(0, 2);
	tree.createAndAddParameter("filterType1", "FilterType1", "filterType1", filterTypeParam, 2, nullptr, nullptr);
	tree.createAndAddParameter("filterType2", "FilterType2", "filterType2", filterTypeParam, 2, nullptr, nullptr);
	tree.createAndAddParameter("filterType3", "FilterType3", "filterType3", filterTypeParam, 2, nullptr, nullptr);

	NormalisableRange<float> filterVal(20.0f, 10000.0f);
	tree.createAndAddParameter("filterCutoff1", "FilterCutoff1", "filterCutoff1", filterVal, 400.0f, nullptr, nullptr);
	tree.createAndAddParameter("filterCutoff2", "FilterCutoff2", "filterCutoff2", filterVal, 400.0f, nullptr, nullptr);
	tree.createAndAddParameter("filterCutoff3", "FilterCutoff3", "filterCutoff3", filterVal, 400.0f, nullptr, nullptr);

	NormalisableRange<float> resVal(1, 5);
	tree.createAndAddParameter("filterRes1", "FilterRes1", "filterRes1", resVal, 1, nullptr, nullptr);
	tree.createAndAddParameter("filterRes2", "FilterRes2", "filterRes2", resVal, 1, nullptr, nullptr);
	tree.createAndAddParameter("filterRes3", "FilterRes3", "filterRes3", resVal, 1, nullptr, nullptr);

	NormalisableRange<float> panVal(-1, 1);
	tree.createAndAddParameter("pan1", "Pan1", "pan1", panVal, 0, nullptr, nullptr);
	tree.createAndAddParameter("pan2", "Pan2", "pan2", panVal, 0, nullptr, nullptr);
	tree.createAndAddParameter("pan3", "Pan3", "pan3", panVal, 0, nullptr, nullptr);

	NormalisableRange<float> oscGainVal(0, 1.5f);
	tree.createAndAddParameter("gain1", "Gain", "gain", oscGainVal, 1, nullptr, nullptr);
	tree.createAndAddParameter("gain2", "Gain", "gain", oscGainVal, 1, nullptr, nullptr);
	tree.createAndAddParameter("gain3", "Gain", "gain", oscGainVal, 1, nullptr, nullptr);

	NormalisableRange<float> distortionDriveVal(0, 1.f);
	NormalisableRange<float> distortionRangeVal(0, 3000.f);
	NormalisableRange<float> distortionBlendVal(0, 1.f);
	tree.createAndAddParameter("drive", "Drive", "drive", distortionDriveVal, 0.5f, nullptr, nullptr);
	tree.createAndAddParameter("range", "Range", "range", distortionRangeVal, 0.5f, nullptr, nullptr);
	tree.createAndAddParameter("blend", "Blend", "blend", distortionBlendVal, 0, nullptr, nullptr);



	synth1.clearVoices();

	for (int i = 0; i < 8; i++)
	{
		synth1.addVoice(new SynthVoiceOsc1());
	}

	synth1.clearSounds();
	synth1.addSound(new SynthSoundOsc1());
	
	
	synth2.clearVoices();

	for (int i = 0; i < 8; i++)
	{
		synth2.addVoice(new SynthVoiceOsc2());
	}

	synth2.clearSounds();
	synth2.addSound(new SynthSoundOsc2());


	synth3.clearVoices();

	for (int i = 0; i < 8; i++)
	{
		synth3.addVoice(new SynthVoiceOsc3());
	}

	synth3.clearSounds();
	synth3.addSound(new SynthSoundOsc3());
	


}

SynthmkIiAudioProcessor::~SynthmkIiAudioProcessor()
{
}

//==============================================================================
const String SynthmkIiAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthmkIiAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthmkIiAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthmkIiAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthmkIiAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthmkIiAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthmkIiAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthmkIiAudioProcessor::setCurrentProgram (int index)
{
}

const String SynthmkIiAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthmkIiAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SynthmkIiAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	ignoreUnused(samplesPerBlock);
	lastSampleRate = sampleRate;
	synth1.setCurrentPlaybackSampleRate(lastSampleRate);
	synth2.setCurrentPlaybackSampleRate(lastSampleRate);
	synth3.setCurrentPlaybackSampleRate(lastSampleRate);
}

void SynthmkIiAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthmkIiAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SynthmkIiAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	
	
	
	for (int i = 0; i < synth1.getNumVoices(); i++)
	{
		if (oscVoice1 = dynamic_cast<SynthVoiceOsc1*>(synth1.getVoice(i)))
		{
			oscVoice1->getOscEnvelopeParam(tree.getRawParameterValue("attack1"),
										   tree.getRawParameterValue("decay1"),
									   	   tree.getRawParameterValue("sustain1"),
										   tree.getRawParameterValue("release1"));

			oscVoice1->getFilterEnvelopeParam(tree.getRawParameterValue("filterAttack1"),
											  tree.getRawParameterValue("filterDecay1"),
											  tree.getRawParameterValue("filterSustain1"),
											  tree.getRawParameterValue("filterRelease1"),
											  tree.getRawParameterValue("release1"));

			oscVoice1->getOscType(tree.getRawParameterValue("wavetype1"));

			oscVoice1->getOscGain(tree.getRawParameterValue("gain1"));

			oscVoice1->getPitchShift(tree.getRawParameterValue("octave1"),
									 tree.getRawParameterValue("semitone1"),
									 tree.getRawParameterValue("cent1"));

			oscVoice1->getFilterParam(tree.getRawParameterValue("filterType1"),
									  tree.getRawParameterValue("filterCutoff1"),
									  tree.getRawParameterValue("filterRes1"));

			oscVoice1->getPan(tree.getRawParameterValue("pan1"));

			oscVoice1->getDistortionParam(tree.getRawParameterValue("drive"),
										  tree.getRawParameterValue("range"),
										  tree.getRawParameterValue("blend"));

			
		}

	}

	for (int i = 0; i < synth2.getNumVoices(); i++)
	{
		if (oscVoice2 = dynamic_cast<SynthVoiceOsc2*>(synth2.getVoice(i)))
		{
			oscVoice2->getOscEnvelopeParam(tree.getRawParameterValue("attack2"),
										   tree.getRawParameterValue("decay2"),
										   tree.getRawParameterValue("sustain2"),
										   tree.getRawParameterValue("release2"));

			oscVoice2->getOscType(tree.getRawParameterValue("wavetype2"));

			oscVoice2->getOscGain(tree.getRawParameterValue("gain2"));

			oscVoice2->getPitchShift(tree.getRawParameterValue("octave2"),
									 tree.getRawParameterValue("semitone2"),
									 tree.getRawParameterValue("cent2"));

			oscVoice2->getFilterParam(tree.getRawParameterValue("filterType2"),
									  tree.getRawParameterValue("filterCutoff2"),
									  tree.getRawParameterValue("filterRes2"));

			oscVoice2->getPan(tree.getRawParameterValue("pan2"));

			oscVoice2->getDistortionParam(tree.getRawParameterValue("drive"),
										  tree.getRawParameterValue("range"),
										  tree.getRawParameterValue("blend"));
		}

	}

	for (int i = 0; i < synth3.getNumVoices(); i++)
	{
		if (oscVoice3 = dynamic_cast<SynthVoiceOsc3*>(synth3.getVoice(i)))
		{
			oscVoice3->getOscEnvelopeParam(tree.getRawParameterValue("attack3"),
										   tree.getRawParameterValue("decay3"),
										   tree.getRawParameterValue("sustain3"),
										   tree.getRawParameterValue("release3"));

			oscVoice3->getOscType(tree.getRawParameterValue("wavetype3"));

			oscVoice3->getOscGain(tree.getRawParameterValue("gain3"));

			oscVoice3->getPitchShift(tree.getRawParameterValue("octave3"),
									 tree.getRawParameterValue("semitone3"),
								 	 tree.getRawParameterValue("cent3"));

			oscVoice3->getFilterParam(tree.getRawParameterValue("filterType3"),
									  tree.getRawParameterValue("filterCutoff3"),
									  tree.getRawParameterValue("filterRes3"));

			oscVoice3->getPan(tree.getRawParameterValue("pan3"));

			oscVoice3->getDistortionParam(tree.getRawParameterValue("drive"),
										  tree.getRawParameterValue("range"),
										  tree.getRawParameterValue("blend"));
		}

	}
	
	
	// Self explanetory, set the size of the buffer for each osc
	bufferOsc1.setSize(2, buffer.getNumSamples(), false, true, true);
	bufferOsc2.setSize(2, buffer.getNumSamples(), false, true, true);
	bufferOsc3.setSize(2, buffer.getNumSamples(), false, true, true);
	
	// Clear the buffers
	buffer.clear();
	bufferOsc1.clear();
	bufferOsc2.clear();
	bufferOsc3.clear();
	
	// Calls renderNextBlock() with the new buffers
	synth1.renderNextBlock(bufferOsc1, midiMessages, 0, buffer.getNumSamples());
	synth2.renderNextBlock(bufferOsc2, midiMessages, 0, buffer.getNumSamples());
	synth3.renderNextBlock(bufferOsc3, midiMessages, 0, buffer.getNumSamples());

	// Copy buffers
	bufferOsc1.getWritePointer(0);
	bufferOsc1.getWritePointer(1);
	bufferOsc2.getWritePointer(0);
	bufferOsc2.getWritePointer(1);
	bufferOsc3.getWritePointer(0);
	bufferOsc3.getWritePointer(1);

	// Add the buffers to the output
	buffer.addFrom(0, 0, bufferOsc1.getReadPointer(0), buffer.getNumSamples());
	buffer.addFrom(1, 0, bufferOsc1.getReadPointer(1), buffer.getNumSamples());
	buffer.addFrom(0, 0, bufferOsc2.getReadPointer(0), buffer.getNumSamples());
	buffer.addFrom(1, 0, bufferOsc2.getReadPointer(1), buffer.getNumSamples());
	buffer.addFrom(0, 0, bufferOsc3.getReadPointer(0), buffer.getNumSamples());
	buffer.addFrom(1, 0, bufferOsc3.getReadPointer(1), buffer.getNumSamples());


    
}

//==============================================================================
bool SynthmkIiAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SynthmkIiAudioProcessor::createEditor()
{
    return new SynthmkIiAudioProcessorEditor (*this);
}

//==============================================================================
void SynthmkIiAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthmkIiAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthmkIiAudioProcessor();
}
