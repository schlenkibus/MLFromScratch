#pragma once
#include <vector>
#include <memory>

class Neuron
{
public:
	Neuron();
	~Neuron();
	void feedForward(std::vector<std::pair<std::shared_ptr<Neuron>, float>> input);
	void feedBackwards(float input);
	float activation;
	float bias;
};

