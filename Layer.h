#pragma once
#include <vector>
#include <memory>
#include "Neuron.h"

class Layer
{
public:
	Layer();
	~Layer();
	virtual void feedForwards(std::vector<std::pair<std::shared_ptr<Neuron>, float>> inputs);
	virtual void feedBackwards(std::vector<float> inputs);
	std::vector<std::pair<std::shared_ptr<Neuron>, float>> neurons;
	std::shared_ptr<Layer> predecessor;
	std::shared_ptr<Layer> successor;
};

