# Helion Drift

Helion Drift is a long-term systems-focused 2D top-down colony simulation project written in modern C++.

This project is intentionally architecture-first and simulation-driven. Visuals, polish, and content come later.

## Core Vision

* 2D top-down colony simulation
* Systems-first, graphics-second
* Playable prototype, not a full production game
* Deterministic simulation suitable for save/load and replay

## Technical Stack

* Language: C++23
* Build system: CMake
* Rendering and input: Raylib (wrapped, not embedded)
* Target platforms:

    * Windows
    * macOS
    * Linux

## Architectural Principles

* No global state
* Clear module boundaries
* Simulation code is independent of rendering and input
* Deterministic fixed timestep simulation
* Data-oriented design where appropriate
* Minimal dynamic allocation in hot paths

## Project Structure (planned)

* helion_core
  Utilities, logging, profiling, math, and low-level helpers

* helion_simulation
  ECS, world model, AI, jobs, pathfinding, serialization

* helion_app
  Application entry point, renderer wrapper, input wrapper

## Non-Goals (Explicitly Out of Scope)

* Multiplayer
* Complex UI frameworks
* Story systems
* Weather or biome simulation
* Procedural planets
* Visual polish before system stability

## Development Philosophy

This repository is a systems lab.
Correctness, clarity, and performance discipline take priority over speed of feature delivery.

Large systems are built incrementally, audited frequently, and rewritten when necessary.

## Build Status

Early infrastructure phase.
No gameplay implemented yet.

---

More documentation will be added as core systems stabilize.
