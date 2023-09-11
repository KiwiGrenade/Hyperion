#include <iostream>
#include <fstream>
#include "Vectors.h"

int main() {
    const int width = 1280;
    const int height = 720;
    const float fWidth = static_cast<float> (width);
    const float fHeight = static_cast<float> (height);

    std::vector<Vec3f> imageBuffer = std::vector<Vec3f> (1280*720);



    for(size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            imageBuffer[j + i * width] =    Vec3f {
                                                (static_cast<float>(i)) * fHeight,
                                                (static_cast<float>(j)) * fWidth,
                                                0
                                            };
        }
    }

    std::ofstream file;
    file.open("image.ppm", std::ios_base::out);


    file.close();
    return 0;
}
