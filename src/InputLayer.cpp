#include <cassert>
#include <iostream>
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
    pixels.clear();
    pixels.reserve(input.size());
    for(auto& in: input) {
        auto delta = static_cast<sf::Uint8 >(in * 255.0);
        pixels.emplace_back(sf::Color(delta,delta,delta));
    }

    assert(input.size() == neurons.size());
    for(auto i = 0; i < input.size(); i++) {
        neurons[i].first->activation = input[i];
    }
}
