# SpaceTanks Development Guide

## Quick Start

```bash
git submodule update --init --recursive
mkdir -p build && cd build
cmake .. -DPICO_SDK_PATH=/path/to/pico-sdk
make -j$(nproc)
```

Or let CMake fetch the SDK automatically:
```bash
mkdir -p build && cd build
cmake .. -DPICO_SDK_FETCH_FROM_GIT=ON
```

## Structure

- `src/spacetanks.cpp` — Main entry point, inherits from `Demo` base class
- `src/*.cpp|*.h` — Game modules (Player, EnemyTanks, Projectiles, Particles, Collisions, Grid, Obstacles, Background, Radar)
- `PicoVectorscope/` — Git submodule containing the rendering framework

## Key Architecture Facts

- Game loop is driven by `Demo::UpdateAndRender()` with a `float dt` parameter
- All game subsystems have static `Reset()`, `Init()`, `Update()`, and `Draw()` methods
- Updates happen before Draws within each frame (separate update/draw phases)
- Uses PicoVectorscope framework with PIO-based vector graphics on Raspberry Pi Pico


## Dependencies

- **PICO SDK 1.3.0+** — Required, can be auto-fetched via `-DPICO_SDK_FETCH_FROM_GIT=ON`
- **PicoVectorscope submodule** — Initialize with `git submodule update --init`

## Build Artifacts

CMake generates multiple output formats via `pico_add_extra_outputs()`: UF2, BIN, HEX, DIS.
