/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 20 Dec 2018 12:45:11pm
    Author:  Olorin

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SynthLookAndFeel : public LookAndFeel_V4
{
public:
	void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPosProportional,
		float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
	{
		float radius = jmin(width / 2, height / 2) - 10.0f;
		float centreX = x + (width / 2);
		float centreY = y + (height / 2);
		float rx = centreX - radius;
		float ry = centreY - radius;
		float rw = radius * 2.0f;
		float angle = rotaryStartAngle + (sliderPosProportional * (rotaryEndAngle - rotaryStartAngle));




		juce::Rectangle<float> dialArea(rx, ry, rw, rw);

		g.setColour(Colours::whitesmoke);
		//g.drawRect(dialArea);
		g.fillEllipse(dialArea);

		Path dialTick;
		dialTick.addRectangle(0, -radius, 2.0, radius * 0.33);

		g.setColour(Colours::black);
		g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));

		g.setColour(Colours::darkcyan);
		g.drawEllipse(rx, ry, rw, rw, 3.f);
		

		//createSliderTextBox(slider);
		//slider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 15);
		

		
		

	}

	

	void drawComboBox(Graphics &g, int width, int height, bool isButtonDown, int buttonX, int buttonY, int buttonW, int buttonH, ComboBox &box) override
	{
		buttonX = 0;
		buttonY = 0;
		buttonW = 0;
		buttonH = 0;
		isButtonDown = false;

		juce::Rectangle<float> area(width, height);
		Label textBox;
		textBox.setJustificationType(Justification::centred);

		g.setColour(Colours::grey);
		g.fillRect(area);
		g.setColour(Colours::darkcyan);
		g.drawRect(area, 2.0f);

	}
};

class CustomLookAndFeel    : public Component
{
public:
    CustomLookAndFeel()
    {
        // In your constructor, you should add any child components, and
        // initialise any special settings that your component needs.

    }

    ~CustomLookAndFeel()
    {
    }

    void paint (Graphics& g) override
    {
        
    }

    void resized() override
    {
        // This method is where you should set the bounds of any child
        // components that your component contains..

    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomLookAndFeel)
};
