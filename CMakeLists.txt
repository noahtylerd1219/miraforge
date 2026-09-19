cmake_minimum_required(VERSION 3.22)
project(MiraForge VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT JUCE_DIR)
  message(FATAL_ERROR "JUCE_DIR is required. Example: -DJUCE_DIR=C:/SDK/JUCE")
endif()
add_subdirectory(${JUCE_DIR} JUCE)
juce_add_plugin(MiraForge
  COMPANY_NAME "MiraForge Audio"
  BUNDLE_ID com.miraforge.audio.miraforge
  IS_SYNTH TRUE NEEDS_MIDI_INPUT TRUE NEEDS_MIDI_OUTPUT FALSE IS_MIDI_EFFECT FALSE
  EDITOR_WANTS_KEYBOARD_FOCUS TRUE
  COPY_PLUGIN_AFTER_BUILD TRUE
  PLUGIN_MANUFACTURER_CODE MfAu PLUGIN_CODE MrFg
  FORMATS VST3 AU Standalone PRODUCT_NAME "MiraForge")
target_sources(MiraForge PRIVATE Source/PluginProcessor.cpp Source/PluginProcessor.h Source/PluginEditor.cpp Source/PluginEditor.h)
target_compile_definitions(MiraForge PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 JUCE_VST3_CAN_REPLACE_VST2=0)
target_link_libraries(MiraForge PRIVATE juce::juce_audio_utils juce::juce_dsp juce::juce_recommended_config_flags juce::juce_recommended_lto_flags juce::juce_recommended_warning_flags)
