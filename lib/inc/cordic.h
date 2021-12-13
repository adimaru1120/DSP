#ifndef CORDIC_H
#define CORDIC_H

#include <vector>

class cordic{

    private:
        int set_gain(int x);
        void lookup_table(int n);

    public:
        std::vector<int> cordic_rotation(int x, int y, int z, int n);
        std::vector<std::vector<int>> sin_cos_generator(int x, int y, int z, int n);
};


#endif