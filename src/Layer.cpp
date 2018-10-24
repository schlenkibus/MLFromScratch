#include "Layer.h"
#include "NumTools.h"
#include <memory>


Layer::Layer(int numNodes)
{
    for(int i = 0; i < numNodes; i++) {
        neurons.emplace_back(std::make_shared<Neuron>(), NumTools::getRandomNumber(0, 1));
    }
}


Layer::~Layer()
{
}

std::vector<std::pair<std::shared_ptr<Neuron>, float>> Layer::feedForwards(
		std::vector<std::pair<std::shared_ptr<Neuron>, float>> inputs)
{
	for (auto& neuron : neurons) {
		neuron.first->feedForward(inputs);
	}

	auto feed = std::vector<std::pair<std::shared_ptr<Neuron>, float>>{};

	for (auto& pair : neurons) {
		feed.emplace_back(std::make_pair(pair.first, pair.second));
	}

	successor->feedForwards(feed);
}

void Layer::feedBackwards(std::vector<float> inputs)
{
}
