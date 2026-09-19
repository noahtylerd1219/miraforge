# MiraForge — easiest Windows build

This version is designed so you do **not** need to install Visual Studio, CMake, or JUCE on your PC.

## What you need

- A free GitHub account
- The MiraForge folder from this ZIP

## Step 1 — Create a GitHub repository

1. Go to https://github.com/new
2. Name the repository `MiraForge`.
3. Choose **Public** (recommended for the simplest GitHub Actions setup).
4. Click **Create repository**.

## Step 2 — Upload this project

On the new repository page:

1. Click **Add file → Upload files**.
2. Upload the **contents inside this MiraForge folder**, not the outer folder itself.
3. Make sure you can see these at the top level of the repository:

```text
CMakeLists.txt
Source/
.github/
BUILD_WITH_GITHUB.md
README.md
```

4. Click **Commit changes**.

## Step 3 — Start the automatic build

1. Open the repository's **Actions** tab.
2. Click **Build MiraForge VST3 (Windows)** on the left.
3. Click **Run workflow**.
4. Click the green **Run workflow** button.

GitHub will download JUCE, configure the project, and compile the Windows VST3 on a hosted Windows machine.

## Step 4 — Download MiraForge

Wait for the workflow to turn green.

1. Click the completed workflow run.
2. Scroll to **Artifacts**.
3. Download **MiraForge-Windows-VST3**.
4. Extract the downloaded ZIP.

You should get:

```text
MiraForge.vst3
```

## Step 5 — Install in FL Studio

Copy `MiraForge.vst3` to:

```text
C:\Program Files\Common Files\VST3
```

Then open FL Studio:

**Options → Manage plugins → Find installed plugins**

Search for **MiraForge** and load it as a generator/instrument.

JUCE's documentation identifies `C:\Program Files\Common Files\VST3` as the typical Windows VST3 installation folder. citeturn0search1

## If the build fails

Open the failed workflow and copy the final 30–50 lines of the build log. Send them to ChatGPT and I can diagnose the build error.

## Why this works

The repository contains a GitHub Actions workflow. GitHub runs that workflow on a Windows build machine and stores the resulting VST3 as an artifact you can download. GitHub documents artifacts as a way to persist and share files produced by a workflow, including compiled binaries. citeturn0search0

The project uses JUCE's CMake-based plugin system; JUCE supports VST3 plugin targets and requires a C++ build toolchain when building locally. citeturn0search3turn0search7
