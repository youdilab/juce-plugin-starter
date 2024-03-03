/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/**
*/
class YoudiTemplateAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    YoudiTemplateAudioProcessor();
    ~YoudiTemplateAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //Value Tree State.
    juce::AudioProcessorValueTreeState parameters;
    
    //Adding parameters to parameter layout.
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
    {
        return
        {
            std::make_unique<juce::AudioParameterFloat>("volume1","Volume 1",0.0f,100.0f,0.5f),
            std::make_unique<juce::AudioParameterFloat>("volume2","Volume 2",0.0f,100.0f,0.5f)
        };
    };

    //Accessing parameters.
    
    //Reading parameter values.
    std::atomic<float>* paramReadVolume1 = nullptr;
    std::atomic<float>* paramReadVolume2 = nullptr;

    //Modifying parameter values.
    juce::RangedAudioParameter* paramVolume1 = nullptr;
    juce::RangedAudioParameter* paramVolume2 = nullptr;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (YoudiTemplateAudioProcessor)
};
