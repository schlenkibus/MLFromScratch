#include "Neuron.h"
#include <algorithm>
#include <numeric>


Neuron::Neuron()
= default;


Neuron::~Neuron()
= default;

void Neuron::feedForward(std::vector<std::pair<std::shared_ptr<Neuron>, float>> input)
{
	std::vector<float> weightedInputs;
	std::for_each(input.begin(), input.end(), [&](auto neuronWeigthPair) {
		auto neuron = neuronWeigthPair.first;
		auto weigth = neuronWeigthPair.second;
		weightedInputs.emplace_back(neuron->activation * weigth);
	});

	auto weightedSum = std::accumulate(weightedInputs.begin(), weightedInputs.end(), 0.0);
	auto biasedSum = weightedSum - bias;
	activation = static_cast<float>(std::max<double>(1, std::max<double>(0, biasedSum)));
}

void Neuron::feedBackwards(float input)
{

}
