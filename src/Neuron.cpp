#include "Neuron.h"
#include "NumTools.h"
#include <algorithm>
#include <numeric>
#include <cassert>
#include <iostream>


Neuron::Neuron() {
	bias = NumTools::getRandomBias();
}


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
	auto sumPlusBias = (weightedSum + bias);
	activation = static_cast<float>(sumPlusBias / (1 + (sumPlusBias > 0 ? sumPlusBias : sumPlusBias * -1)));

	if(activation > 1) {
		std::cerr << "[ASSERT] Activation is greater than [1]: " << activation << '\n';
		exit(134);
	}
}

void Neuron::feedBackwards(float input)
{

}
