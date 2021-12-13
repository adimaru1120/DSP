#ifndef CORDIC_H
#define CORDIC_H

#include <vector>

class cordic{

    private:

        std::vector<float> LUT;

        /*
            setting gain of signal 
        */
        float set_gain(int n);

        /*
            generating lookup table with values of tan(-2^i)^-1 
            and setting it private vector LUT
        */
        void set_LUT(int n);

    public:
        std::vector<float> cordic_rotation(float x, float y, float z, int n);
        std::vector<std::vector<float>> sin_cos_generator(float x, float y, std::vector<float> z, int n);
        
};


#endif