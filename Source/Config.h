/*
  ==============================================================================

    Config.h
    Created: 3 Mar 2024 11:57:30am
    Author:  Uditha

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

namespace parameters
{
    struct audioParameterFloat
    {
        const juce::String id;
        const juce::String name;
        const float minValue;
        const float maxValue;
        const float defaultValue;
    };

    static const audioParameterFloat volume1{"volume1", "Volume 1", 0, 100, 50};
    static const audioParameterFloat volume2{"volume2", "Volume 2", 0, 100, 50};
}
