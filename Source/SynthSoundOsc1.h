/*
  ==============================================================================

    SynthSoundOsc1.h
    Created: 5 Dec 2018 11:37:37am
    Author:  Olorin

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSoundOsc1 : public SynthesiserSound
{
public:
	bool appliesToNote(int /*midiNoteNumber*/)
	{
		return true;
	}

	bool appliesToChannel(int /*midiChannel*/)
	{
		return true;
	}
};