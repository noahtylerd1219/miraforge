#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
class MiraForgeAudioProcessorEditor:public juce::AudioProcessorEditor,private juce::Timer{public:MiraForgeAudioProcessorEditor(MiraForgeAudioProcessor&);void paint(juce::Graphics&)override;void resized()override;private:MiraForgeAudioProcessor&p;juce::Label title,preset,count;juce::TextButton prev{"◀"},next{"▶"},random{"RANDOMIZE"};void timerCallback()override;JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MiraForgeAudioProcessorEditor)};
