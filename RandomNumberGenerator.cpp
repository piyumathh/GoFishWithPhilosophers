//
// Created by piyum on 12/21/2022.
//

#include "RandomNumberGenerator.h"
mt19937 RandomNumberGenerator::random(time(0));

int RandomNumberGenerator::RandInt(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random);
}