//
// Created by Grim Reaper on 09.09.2023.
//

#include "Render.h"

void makeHeader(const size_t &width,
                const size_t &height,
                const float &colourLimit,
                std::string &header) {
    header.append("P6\n");
    header.append(std::to_string(width));
    header.push_back(' ');
    header.append(std::to_string(height));
    header.push_back('\n');
    header.append(std::to_string(colourLimit));
    header.push_back('\n');
}

void render3D(const size_t &width,
              const size_t &height,
              const std::vector<Vec3f> &imageBuffer,
              std::ofstream &file,
              const float &colourLimit)
{
    std::string header;

    makeHeader(width, height, colourLimit, header);

    file << header;

    float max = 0;

    try {
        for (size_t i = 0; i < width * height; i++) {
            for (size_t k = 0; k < 3; k++) {
                max = std::max(max, imageBuffer[i][k]);
                file << static_cast<char>(imageBuffer[i][k]) << " ";
            }
        }
        if(max > colourLimit) {
            throw std::invalid_argument(std::to_string(max));
        }
    } catch (std::exception &e) {
        std::cerr << "Found val: " << e.what() <<" > limit: " << colourLimit << '\n';
    }

}
