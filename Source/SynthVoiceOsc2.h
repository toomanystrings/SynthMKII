/*
  ==============================================================================

    SynthVoiceOsc2.h
    Created: 5 Dec 2018 11:38:08am
    Author:  Olorin

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSoundOsc2.h"
#include "maximilian.h"

class SynthVoiceOsc2 : public SynthesiserVoice
{
public:
	// Must return true if this voice object is capable of playing the given sound.
	bool canPlaySound(SynthesiserSound* sound)
	{
		return dynamic_cast<SynthSoundOsc2*>(sound) != nullptr;
	}

	//==============================================================================

	void getPitchShift(float* octave, float* semitone, float* cent)
	{
		oscOctave = *octave;
		oscSemitone = *semitone;
		oscCent = *cent;
	}

	//==============================================================================

	double setPitchShift(int inputMidi)
	{
		double semitoneRatio = pow(2, oscSemitone / 12);
		double centUp = (semitoneRatio - pow(2, (oscSemitone + 1) / 12)) * -1;
		double centDown = (semitoneRatio - pow(2, (oscSemitone - 1) / 12)) * -1;

		if (oscOctave == 0)
		{
			if (oscCent > 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) / 4 * (semitoneRatio + (oscCent * (centUp / 100)));
			}
			else if (oscCent < 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) / 4 * (semitoneRatio + (oscCent * (centDown / 100)));
			}
			else if (oscCent == 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) / 4 * semitoneRatio;
			}
		}

		if (oscOctave == 1)
		{
			if (oscCent > 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) / 2 * (semitoneRatio + (oscCent * (centUp / 100)));
			}
			else if (oscCent < 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) / 2 * (semitoneRatio + (oscCent * (centDown / 100)));
			}
			else if (oscCent == 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) / 2 * semitoneRatio;
			}
		}

		if (oscOctave == 2)
		{
			if (oscCent > 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * (semitoneRatio + (oscCent * (centUp / 100)));
			}
			else if (oscCent < 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * (semitoneRatio + (oscCent * (centDown / 100)));
			}
			else if (oscCent == 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * semitoneRatio;
			}
		}


		if (oscOctave == 3)
		{
			if (oscCent > 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * 2 * (semitoneRatio + (oscCent * (centUp / 100)));
			}
			else if (oscCent < 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * 2 * (semitoneRatio + (oscCent * (centDown / 100)));
			}
			else if (oscCent == 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * 2 * semitoneRatio;
			}
		}


		if (oscOctave == 4)
		{
			if (oscCent > 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * 4 * (semitoneRatio + (oscCent * (centUp / 100)));
			}
			else if (oscCent < 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * 4 * (semitoneRatio + (oscCent * (centDown / 100)));
			}
			else if (oscCent == 0)
			{
				return MidiMessage::getMidiNoteInHertz(inputMidi) * 4 * semitoneRatio;
			}
		}
		else
		{
			return MidiMessage::getMidiNoteInHertz(inputMidi);
		}

	}

	//==========================================================================

	// Reads the selection from the drop down menu.
	void getOscType(float* selection)
	{
		theWave = *selection;
	}

	//==========================================================================

	// Sets the oscillator to the selection from the drop down menu.
	double setOscType()
	{
		if (theWave == 0)
		{
			return osc1.sinewave(0);
		}

		if (theWave == 1)
		{
			return osc1.sinewave(frequency);
		}

		if (theWave == 2)
		{
			return osc1.saw(frequency);
		}

		if (theWave == 3)
		{
			return osc1.triangle(frequency);
		}

		if (theWave == 4)
		{
			return osc1.square(frequency);
		}
		else
		{
			return osc1.sinewave(0);
		}
	}

	//==============================================================================

	void getPan(float* panKnob)
	{
		pan = *panKnob;
	}

	float setPanLeft()
	{
		float p = (float_Pi * (pan + 1) / 4);
		return cos(p);
	}

	float setPanRight()
	{
		float p = (float_Pi * (pan + 1) / 4);
		return sin(p);
	}

	//==============================================================================

	void getOscGain(float* g)
	{
		gain = *g;
	}

	//==============================================================================

	// Function to return the parameters of an envelope.
	void getOscEnvelopeParam(float* attack, float* decay, float* sustain, float* release)
	{
		oscEnv.setAttack(*attack);
		oscEnv.setDecay(*decay);
		oscEnv.setSustain(*sustain);
		oscEnv.setRelease(*release);
	}

	//==============================================================================

	double setOscEnvelope()
	{
		return oscEnv.adsr(setDistortion(), oscEnv.trigger) * level * gain;
	}

	//==============================================================================

	void getFilterParam(float* filterType, float* filterCutoff, float* filterRes)
	{
		filterChoice = *filterType;
		cutoff = *filterCutoff;
		res = *filterRes;
	}

	//==============================================================================

	double setFilter()
	{
		if (filterChoice == 0)
		{
			return filter1.lores(setOscEnvelope(), cutoff, res);
		}

		if (filterChoice == 1)
		{
			return filter1.hires(setOscEnvelope(), cutoff, res);
		}

		if (filterChoice == 2)
		{
			return setOscEnvelope();
		}
	}

	//==============================================================================

	void getDistortionParam(float* drive, float* range, float* blend)
	{
		driveVal = *drive;
		rangeVal = *range;
		blendVal = *blend;
	}

	//==============================================================================

	double setDistortion()
	{
		double cleanSignal = setOscType();
		double dirtySignal = setOscType();

		dirtySignal *= driveVal * rangeVal;

		dirtySignal = ((((2.f / float_Pi) * atan(dirtySignal) * blendVal) + (cleanSignal * (1.f - blendVal))) / 2);

		return dirtySignal;


	}


	//==============================================================================

	// Called to start a new note.
	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
	{
		oscEnv.trigger = 1;
		level = velocity;
		frequency = setPitchShift(midiNoteNumber);
	}

	//==============================================================================

	// Called to stop a note.
	void stopNote(float velocity, bool allowTailOff)
	{
		oscEnv.trigger = 0;

		allowTailOff = true;
		if (velocity == 0)
			clearCurrentNote();
	}

	//==============================================================================

	void pitchWheelMoved(int newPitchWheelValue)
	{

	}

	//==============================================================================

	void controllerMoved(int controllerNumber, int newControllervalue)
	{

	}

	//==============================================================================

	void renderNextBlock(AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
	{
		outputBuffer.applyGain(0, startSample, numSamples, setPanLeft());
		outputBuffer.applyGain(1, startSample, numSamples, setPanRight());

		for (int sample = 0; sample < numSamples; ++sample)
		{
			//double theWave = osc1.saw(frequency / 2);

			//double theSound = oscEnv.adsr(setOscType(), oscEnv.trigger) * level;

			for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
			{
				outputBuffer.addSample(channel, startSample, setFilter());
			}

			++startSample;
		}

	}

private:
	double level;
	double frequency;
	double theWave;
	double theNote;
	double gain;

	int oscOctave;
	float oscSemitone;
	float oscCent;

	int filterChoice;
	float cutoff;
	float res;

	float driveVal;
	float rangeVal;
	float blendVal;

	double pan;
	float pi = 3.141592653589793238462;

	maxiOsc osc1;
	maxiEnv oscEnv;
	maxiFilter filter1;
};