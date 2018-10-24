#include "Neuron.h"
#include <algorithm>


Neuron::Neuron()
{
}


Neuron::~Neuron()
{
}

void Neuron::feedForward(std::vector<std::pair<std::shared_ptr<Neuron>, float>> input)
{
	std::vector<float> weightedInputs;
	std::for_each(input.begin(), input.end(), [&](auto neuronWeigthPair) {
		auto neuron = neuronWeigthPair.first;
		auto weigth = neuronWeigthPair.second;
		weightedInputs.emplace_back(neuron->activation * weigth);
		auto sum = 0.0;
			for((weightedInputs.begin(), weightedInputs.end());
		auto biasedSum = sum - bias;
		activation = std::max(1, std::max(0, biasedSum));
	});
}

void Neuron::feedBackwards(float input)
{

}
