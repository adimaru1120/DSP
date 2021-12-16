#include <iostream>
#include "math.h"
#include <fstream>

#include "lib/inc/cordic.h"

template<typename T>
std::vector<T> arange(T start, T stop, T step = 1) {
    std::vector<T> values;
    for (T value = start; value < stop; value += step)
        values.push_back(value);
    return values;
}

void save_to_file(std::vector<std::vector<float>> re){
    std::ofstream f_save;
    f_save.open("cos.txt", std::ios_base::out);
    for(int a = 0; a < re[0].size(); ++a)

            f_save << re[0][a] << "\n";

    f_save.close();

    f_save.open("sin.txt", std::ios_base::out);
    for(int a = 0; a < re[0].size(); ++a)

            f_save << re[1][a] << "\n";

    f_save.close();
}

int main(){

    
    std::vector<float> theta = arange<float>(-5, 5, pow(2, -8));

    cordic dsp;

    int n = 12;

    std::vector<std::vector<float>> res = dsp.sin_cos_generator(theta, n);

    save_to_file(res);
    

    return 0;
}