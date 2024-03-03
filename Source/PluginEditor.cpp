/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
YoudiTemplateAudioProcessorEditor::YoudiTemplateAudioProcessorEditor (YoudiTemplateAudioProcessor& p, juce::AudioProcessorValueTreeState& valueTree)
    : AudioProcessorEditor (&p), audioProcessor (p), apvts(valueTree)
    ,sldVolume1(juce::Slider::SliderStyle::LinearHorizontal,juce::Slider::TextEntryBoxPosition::TextBoxBelow)
    ,sldVolume2(juce::Slider::SliderStyle::LinearHorizontal, juce::Slider::TextEntryBoxPosition::TextBoxBelow)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);

    addAndMakeVisible(sldVolume1);
    addAndMakeVisible(sldVolume2);

    attchVolume1.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(apvts, parameters::volume1.id, sldVolume1));
    attchVolume2.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(apvts, parameters::volume2.id, sldVolume2));
}

YoudiTemplateAudioProcessorEditor::~YoudiTemplateAudioProcessorEditor()
{
}

//==============================================================================
void YoudiTemplateAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void YoudiTemplateAudioProcessorEditor::resized()
{
    sldVolume1.setBounds(20, 20, 300, 30);
    sldVolume2.setBounds(20, 70, 300, 30);
}
