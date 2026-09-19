# MiraForge 1.0

Original JUCE-based VST3/AU synth prototype for dark melodic trap production. The concept is inspired by the broad sonic palette of modern melodic trap—not by copying any specific commercial synth's factory content.

### 250,000 presets
MiraForge exposes 250,000 deterministic procedural programs. Each program number maps to its own generated oscillator, envelope, filter-shaping and texture parameters, so a huge preset pool exists without bundling copyrighted factory presets or samples.

### Build
You need JUCE 8.x locally because this environment did not have the SDK available. On Windows:

`cmake -B build -DJUCE_DIR=C:/SDK/JUCE -DCMAKE_BUILD_TYPE=Release`

`cmake --build build --config Release`

The project builds VST3, AU (on macOS), and Standalone.

### FL Studio
After building, place the generated `MiraForge.vst3` in a VST3 folder scanned by FL Studio. In FL Studio go to **Options > Manage plugins > Find installed plugins**, then search for MiraForge and load it from the Synth/plugin list.

### Sound direction
The procedural pool emphasizes arp-like melodic patches, dark plucks/bells, keys, pads, low guitar-like oscillator textures and bass. It uses generated oscillators rather than samples from Pigments, Keyscape, Nexus, Serum, FLEX, Vital, Zenology, Surge XT, Analog Lab or Xpand!2.

### Prototype note
This package is source/build material, not a signed commercial installer. The environment could not obtain JUCE, so no claim is made that a compiled VST3/AU binary was produced here.

## Easiest Windows setup

You do not need to install Visual Studio, CMake, or JUCE locally if you use the included GitHub Actions workflow.

See **BUILD_WITH_GITHUB.md** for the exact click-by-click instructions.
