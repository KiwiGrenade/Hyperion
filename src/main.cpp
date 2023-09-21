#include <iostream>
#include <fstream>
#include <cmath>
#include "Vectors.h"
#include "Render.h"

void buildImageBuffer(std::vector<Vec3f>& imageBuffer,
                      const size_t& width,
                      const size_t& height,
                      const float& colourLimit) {
    float* y = new float;
    float* x = new float;
    float* z = new float;
    for(size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            *x = static_cast<float>(i) / static_cast<float>(height) * colourLimit;
            *y = static_cast<float>(j) / static_cast<float>(width) * colourLimit;
            *z = std::remainder(static_cast<float>(i + j), colourLimit); // (i + j) % colourLimit
            imageBuffer[i * width + j] = Vec3f {*x,*y,*z};
        }
    }
}

int main() {
    const size_t width = 1920;
    const size_t height = 1080;
    const float colourLimit = 380;
    const std::string imgName = "image1.pnm";
    std::vector<Vec3f> imageBuffer = std::vector<Vec3f> (width * height);

    buildImageBuffer(imageBuffer, width, height, colourLimit);

    std::ofstream file;
    file.open(imgName, std::ios_base::out);

    render3D(width, height, imageBuffer, file, colourLimit);

    file.close();
    return 0;
}
