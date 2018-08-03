/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Juceproject2AudioProcessorEditor::Juceproject2AudioProcessorEditor (Juceproject2AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true,100, 25);
    gainSlider.setTextBoxStyle(Slider::TextBoxAbove, true, 100, 15);
    gainSlider.setRange(-48.0, 0.0);
    gainSlider.setValue(-1.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

Juceproject2AudioProcessorEditor::~Juceproject2AudioProcessorEditor()
{
}

//==============================================================================
void Juceproject2AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("ARSNL first plugin!", getLocalBounds(), Justification::centred, 1);
}

void Juceproject2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    gainSlider.setBounds(getLocalBounds());
}

void Juceproject2AudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if(slider == &gainSlider){
        processor.gainValue = pow(10.0, gainSlider.getValue()/20.0);
        
    }
}


