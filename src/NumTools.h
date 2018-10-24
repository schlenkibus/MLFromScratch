#pragma once
#include <random>

class NumTools {
public:
    static float getRandomNumber(float from, float to) {
        std::uniform_real_distribution<float> dis(from, to);
        return dis(gen);
    }

    static std::random_device rd;
    static std::mt19937 gen;
};