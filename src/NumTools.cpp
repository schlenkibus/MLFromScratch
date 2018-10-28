#include "NumTools.h"

std::random_device NumTools::rd;
std::mt19937 NumTools::gen(NumTools::rd());
std::uniform_real_distribution<float> NumTools::dis(0, 1);
std::uniform_real_distribution<float> NumTools::biasDis(0, 100);

float NumTools::getRandomNumber()  {
    return dis(gen);
}

float NumTools::getRandomBias() {
    return biasDis(gen);
}

