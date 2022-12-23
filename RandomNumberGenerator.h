//
// Created by piyum on 12/21/2022.
//

#ifndef GOFISHWITHPHILOSOPHERS2_RANDOMNUMBERGENERATOR_H
#define GOFISHWITHPHILOSOPHERS2_RANDOMNUMBERGENERATOR_H
#include <random>
using namespace std;

class RandomNumberGenerator
{
    static mt19937 random;
public:
    static int RandInt(int min, int max);
};



#endif //GOFISHWITHPHILOSOPHERS2_RANDOMNUMBERGENERATOR_H
