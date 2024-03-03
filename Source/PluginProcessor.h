/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "config.h"

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
        juce::AudioProcessorValueTreeState::ParameterLayout params;

        //Lambda function to add juce::AudioParameterFloat
        const auto addFloatParameter = [&](parameters::audioParameterFloat paramFloat)
        {
            params.add(std::make_unique<juce::AudioParameterFloat>(paramFloat.id, paramFloat.name, paramFloat.minValue, paramFloat.maxValue, paramFloat.defaultValue));
        };

        //Adding parameters using above lambda functions.
        addFloatParameter(parameters::volume1);
        addFloatParameter(parameters::volume2);

        return params;
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
