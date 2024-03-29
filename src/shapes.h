// 3D shapes for Space Tanks.
//
// Copyright (C) 2023 Oli Wright
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// A copy of the GNU General Public License can be found in the file
// LICENSE.txt in the root of this project.
// If not, see <https://www.gnu.org/licenses/>.
//
// oli.wright.github@gmail.com

#pragma once
#include "extras/shapes3d.h"

enum class FixedShape
{
    Pyr,
    Box,
    Tank1,
    Tank2,
    Projectile,
    Missile,
    Saucer,
    RTread0,
    FTread0,
    Radar,
    Chunk0,
    Chunk1,
    Chunk2,
    Chunk3,
    Chunk4,
    Ba,
    ttle,
    Zone,
    Count
};

extern const Shape3D kFixedShapes[(int)FixedShape::Count];

inline const Shape3D& GetFixedShape(FixedShape shape) { return kFixedShapes[(int) shape]; }
