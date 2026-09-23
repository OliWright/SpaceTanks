# SpaceTanks Development Guide

## Build

```bash
git submodule update --init --recursive   # --recursive is required (PicoVectorscope has its own submodule)
mkdir -p build && cd build
cmake .. -DPICO_SDK_PATH=/path/to/pico-sdk   # PICO_SDK_PATH env var also works
make -j$(nproc)
```

Or let CMake fetch the SDK: `cmake .. -DPICO_SDK_FETCH_FROM_GIT=ON`

- No test suite, no CI, no linter script — only compilation as verification (CMake `-Wall`).
- The Pico SDK locate/fetch logic lives in `PicoVectorscope/pico_sdk_import.cmake` (submodule), included before `project()`.
- `build/` contains generated UF2/BIN/HEX/DIS (pico_add_extra_outputs); output goes to UART stdio, not USB.
- This is hardware firmware for Raspberry Pi Pico — you cannot run it on a host.

## Structure

- `src/spacetanks.cpp` — Entry point; `SpaceTanks` class inherits `Demo` from PicoVectorscope
- `src/*.cpp|.h` — Game modules: Player, EnemyTanks, Projectiles, Particles, Collisions, Grid, Obstacles, Background, Radar, Shapes
- `PicoVectorscope/` — Git submodule (rendering framework); do not treat as project code

## Architecture

- `Demo::UpdateAndRender(DisplayList&, float dt)` is the per-frame callback
- All subsystems use static `Reset()` / `Init()` / `Update()` / `Draw(DisplayList&, const Camera&)` methods
  - Exception: `Player::Draw(displayList)` has no camera param; `Grid`, `Obstacles`, `Background`, `Collisions` have no `Update()`
- `Player::GetCamera()` provides the camera used by all other draw calls
- Fixed 240 fps: use `kPerSecondMultiplier` (src/spacetanks.h) to convert per-second values to per-frame
- PIO-based vector display, not a general screen — draw calls emit into a `DisplayList`

## Style (from .clang-format)

- Allman braces, 4-space indent, 100-col limit, no tabs, left-aligned pointers (`DisplayList& dl`, `const Camera& camera`)
- If clang-format is available, run it on touched files; it enforces include regrouping too
