#ifndef CORDIC_H
#define CORDIC_H

#include <vector>

class cordic{

    private:

        float PI = 3.14159265359f;
        std::vector<float> LUT;

    public:
        std::vector<float> cordic_rotation(float z, int n);
        std::vector<std::vector<float>> sin_cos_generator(std::vector<float> z, int n);

        /*
            setting gain of signal 
        */
        float set_gain(int n);

        /*
            generating lookup table with values of tan(-2^i)^-1 
            and setting it private vector LUT
        */
        void set_LUT(int n);
        
};


#endif