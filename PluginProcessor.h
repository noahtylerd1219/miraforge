#pragma once
#include <JuceHeader.h>
class MiraForgeAudioProcessor : public juce::AudioProcessor {
public:
 MiraForgeAudioProcessor(); ~MiraForgeAudioProcessor() override=default;
 void prepareToPlay(double,int) override; void releaseResources() override; bool isBusesLayoutSupported(const BusesLayout&) const override; void processBlock(juce::AudioBuffer<float>&,juce::MidiBuffer&) override;
 juce::AudioProcessorEditor* createEditor() override; bool hasEditor() const override{return true;} const juce::String getName() const override{return "MiraForge";} bool acceptsMidi() const override{return true;} bool producesMidi() const override{return false;} bool isMidiEffect() const override{return false;} double getTailLengthSeconds() const override{return 2.0;}
 int getNumPrograms() override{return 250000;} int getCurrentProgram() override{return presetIndex;} void setCurrentProgram(int i) override; const juce::String getProgramName(int i) override; void changeProgramName(int,const juce::String&) override{} void getStateInformation(juce::MemoryBlock&) override; void setStateInformation(const void*,int) override;
 struct Params{float mix=.55f,detune=.08f,cutoff=.5f,res=.15f,attack=.01f,decay=.5f,sustain=.7f,release=.7f,drive=.08f,space=.25f,width=.65f; int wave=0;};
 void setPresetIndex(int); int getPresetIndex()const{return presetIndex;} juce::String getPresetName()const;
 class Sound:public juce::SynthesiserSound{public:bool appliesToNote(int)override{return true;}bool appliesToChannel(int)override{return true;}};
 class Voice:public juce::SynthesiserVoice{public:Voice(const Params* p=nullptr):params(p){} bool canPlaySound(juce::SynthesiserSound*s)override{return dynamic_cast<Sound*>(s)!=nullptr;} void startNote(int,float,juce::SynthesiserSound*,int)override;void stopNote(float,bool)override;void pitchWheelMoved(int)override{}void controllerMoved(int,int)override{}void renderNextBlock(juce::AudioBuffer<float>&,int,int)override;void setSR(double s){sr=s;} private:const Params*params;double sr=44100,ph1=0,ph2=0;float hz=440,vel=0;bool rel=false;int age=0;};
private: static Params makeParams(int); static juce::String makeName(int); void applyPreset(int); juce::Synthesiser synth; Params params; int presetIndex=0; JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MiraForgeAudioProcessor)
};
