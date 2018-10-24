#pragma once
#include <vector>
#include <memory>
#include "Neuron.h"

class Layer
{
public:
	Layer(int numNodes);
	~Layer();
	virtual std::vector<std::pair<std::shared_ptr<Neuron>, float>> feedForwards(
            std::vector<std::pair<std::shared_ptr<Neuron>, float>> inputs);
	virtual void feedBackwards(std::vector<float> inputs);
	std::vector<std::pair<std::shared_ptr<Neuron>, float>> neurons;
	std::shared_ptr<Layer> predecessor;
	std::shared_ptr<Layer> successor;
};

