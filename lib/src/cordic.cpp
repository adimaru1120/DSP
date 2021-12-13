#include <iostream>
#include <vector>
#include "math.h"
#include "../inc/cordic.h"


float cordic::set_gain(int n){
    float gain = 1;

    for(int i = 0; i < n; ++i){
        gain *= sqrt(1 + pow(2, -2 * i));
    }

    gain = 1 / gain;

    return gain;
}

void cordic::set_LUT(int n){
    float PI = 3.14159265359f;
    for(int i = 0; i < n; ++i){
        cordic::LUT.push_back(atanf(pow(2, -i)) / (PI / 2));
    }
}

std::vector<float> cordic::cordic_rotation(float x, float y, float z, int n){
    float xt = x;
    float yt = y;

    for(int i = 0; i < n; ++i){

        if(z < 0){
            z = z + cordic::LUT[i];
            x = x + yt;
            y = y - xt;
        }
        else{
            z = z - cordic::LUT[i];
            x = x - yt;
            y = y + xt;
        }

        xt = x * pow(2, -(i + 1));
        yt = y * pow(2, -(i + 1));
    }

    std::vector<float> rotated{x, y, z};

    return rotated;

}


std::vector<std::vector<float>> cordic::sin_cos_generator(float x, float y, std::vector<float> z, int n){
    float gain = cordic::set_gain(n);
    cordic::set_LUT(n);

    std::vector<float> xt;
    std::vector<float> yt;
    std::vector<float> zt;

    for(int i = 0; i < z.size(); ++i){
        std::vector<float> rot = cordic::cordic_rotation(gain, y, z[i], n);
        xt.push_back(rot[0]);
        yt.push_back(rot[1]);
        zt.push_back(rot[2]);
    }

    std::vector<std::vector<float>> sin_cos{xt, yt, zt};

    return sin_cos;
}