#include <cassert>
#include "InputLayer.h"


InputLayer::InputLayer(int numNodes) : Layer(numNodes)
{

}


InputLayer::~InputLayer()
{
}

std::vector<std::pair<std::shared_ptr<Neuron>, float>> InputLayer::startFeedForwards() {
    return neurons;
}

void InputLayer::setInput(std::vector<float> input) {
    assert(input.size() == neurons.size());
    for(auto i = 0; i < input.size(); i++) {
        neurons[i].first->setActivationExplicitly(input[i]);
    }
}
