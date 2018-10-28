#pragma once
#include <random>

class NumTools {
public:
    static float getRandomNumber();

    static std::uniform_real_distribution<float> dis;
    static std::uniform_real_distribution<float> biasDis;
    static std::random_device rd;
    static std::mt19937 gen;

    static float getRandomBias();
};