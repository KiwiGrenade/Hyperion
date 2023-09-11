//
// Created by Grim Reaper on 09.09.2023.
//

#ifndef INC_3DVECTOR_RENDER_H
#define INC_3DVECTOR_RENDER_H

#include <iostream>
#include "Vectors.h"
#include <fstream>
void render3D (
    const size_t& width,
    const size_t& height,
    const std::vector<Vec3f>& imageBuffer,
    std::ofstream& file
    );

#endif //INC_3DVECTOR_RENDER_H
