#include "Layer.h"
#include <memory>


Layer::Layer()
{

}


Layer::~Layer()
{
}

void Layer::feedForwards(std::vector<std::pair<std::shared_ptr<Neuron>, float>> inputs)
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
