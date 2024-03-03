/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class YoudiTemplateAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    YoudiTemplateAudioProcessorEditor (YoudiTemplateAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~YoudiTemplateAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    YoudiTemplateAudioProcessor& audioProcessor;

    juce::AudioProcessorValueTreeState& apvts;

    //GUI components
    juce::Slider sldVolume1;
    juce::Slider sldVolume2;

    //Parameter-Component attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attchVolume1;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attchVolume2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoudiTemplateAudioProcessorEditor)
};
