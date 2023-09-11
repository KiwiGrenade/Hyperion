//
// Created by Grim Reaper on 09.09.2023.
//

#include "Render.h"
void render3D (
        const size_t& width,
        const size_t& height,
        const std::vector<Vec3f>& imageBuffer,
        std::ofstream& file
)
{

    file << "P6\n" // header
         << width << " " << height << "\n" // dimensions
         << "255\n"; // maximum value of each color

    for (size_t i = 0; i < width * height; i++) {
//        for (size_t j = 0; j < 35; j++) {
        for (size_t k = 0; k < 3; k++) {
            file << static_cast<char>(imageBuffer[i][k]);
        }
//        }
    }
}
