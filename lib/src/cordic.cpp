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

    for(int i = 0; i < n; ++i){
        float angle = atanf(pow(2, -i));
        cordic::LUT.push_back(angle);
    }

}


std::vector<float> cordic::cordic_rotation(float z, int n){   

    if(z < -cordic::PI / 2 || z > cordic::PI / 2){
        std::vector<float> rotated;
        if(z < 0){
            rotated = cordic::cordic_rotation(z + cordic::PI, n);
        }
        else{
            rotated = cordic::cordic_rotation(z - cordic::PI, n);
        }

        rotated[0] = -rotated[0];
        rotated[1] = -rotated[1];
        return rotated;
    }

    float x = 1;
    float y = 0;

    float xt;
    float yt;

    for(int i = 0; i < n; ++i){
        if(z < 0){
            xt = x + (y * pow(2, -i));
            yt = y - (x * pow(2, -i));
            z = z + cordic::LUT[i];
        }
        else{
            xt = x - (y * pow(2, -i));
            yt = y + (x * pow(2, -i));
            z = z - cordic::LUT[i]; 
        }

        x = xt; y = yt;
    }
    
    std::vector<float> rotated{x, y};

    return rotated;

}

std::vector<std::vector<float>> cordic::sin_cos_generator(std::vector<float> z, int n){
    float gain = cordic::set_gain(n);
    cordic::set_LUT(n);

    std::vector<float> xt;
    std::vector<float> yt;

    for(int i = 0; i < z.size(); ++i){
        std::vector<float> rot = cordic::cordic_rotation(z[i], n);
        rot[0] = rot[0] * gain;
        rot[1] = rot[1] * gain;
        xt.push_back(rot[0]);
        yt.push_back(rot[1]);
    }

    std::vector<std::vector<float>> sin_cos{xt, yt};

    return sin_cos;
}