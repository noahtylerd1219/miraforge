@echo off
set JUCE_DIR=C:\SDK\JUCE
cmake -B build -DJUCE_DIR=%JUCE_DIR% -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
pause
