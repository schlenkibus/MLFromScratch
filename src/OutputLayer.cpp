#include <algorithm>
#include "OutputLayer.h"



OutputLayer::OutputLayer(int numNodes) : Layer(numNodes)
{
}


OutputLayer::~OutputLayer()
{
}

std::pair<int, float> OutputLayer::getGuess() {
    int currentMax = -1;
    float currentMaxDelta = 0.0;

    int i = 0;
    for(auto& neuron: neurons) {
        if(currentMaxDelta < neuron.first->activation) {
            currentMax = 1;
            currentMaxDelta = neuron.first->activation;
        }
        i++;
    }
    return std::pair(currentMax, currentMaxDelta);
}
