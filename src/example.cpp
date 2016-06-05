#include <iostream>
#include "Palette.h"
#include <FreeImage.h>
#include <math.h>

using namespace std;

int main() {
    const unsigned int width = 640;
    const unsigned int height = 480;
    const unsigned int bpp = 24;

    FreeImage_Initialise();

    FIBITMAP *image = FreeImage_Allocate(width, height, bpp);
    if (!image)
    {
        cerr << "Image allocation failed" << endl;
        exit(EXIT_FAILURE);
    }


    Palette palettes[] = {
            {{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,1.0,1.0},{0.0,0.33,0.67}},
            {{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,1.0,1.0},{0.0,0.10,0.20}},
            {{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,1.0,1.0},{0.3,0.20,0.20}},
            {{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,1.0,0.5},{0.8,0.90,0.30}},
            {{0.5,0.5,0.5},{0.5,0.5,0.5},{1.0,0.7,0.4},{0.0,0.15,0.20}},
            {{0.5,0.5,0.5},{0.5,0.5,0.5},{2.0,1.0,0.0},{0.5,0.20,0.25}},
            {{0.8,0.5,0.4},{0.2,0.4,0.2},{2.0,1.0,1.0},{0.0,0.25,0.25}},
    };

    unsigned int deltaY = height / 7;
    unsigned int y = (height - (deltaY * 7)) / 2;
    for (int p = 0; p < 7; ++p)
    {
        for (; y < ((p+1) * deltaY); ++y)
        {
            for (unsigned int x = 0; x < width; ++x)
            {
                auto col = palettes[p]((float)x / (float)width);
                RGBQUAD colour;
                colour.rgbRed   = col.x() * 255;
                colour.rgbGreen = col.y() * 255;
                colour.rgbBlue  = col.z() * 255;
                FreeImage_SetPixelColor(image, x, y, &colour);
            }
        }
    }

    if (FreeImage_Save(FIF_PNG, image, "output.png", 0))
        cout << "Image saved!" << endl;

    FreeImage_Unload(image);
    FreeImage_DeInitialise();
    exit(EXIT_SUCCESS);
}
