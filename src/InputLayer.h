#pragma once
#include <SFML/Graphics/Color.hpp>
#include "Layer.h"

class InputLayer : public Layer
{
public:
	InputLayer(int numNodes);
	~InputLayer();
	void setInput(std::vector<float> values);
	std::vector<std::pair<std::shared_ptr<Neuron>, float>> startFeedForwards();
	std::vector<sf::Color> pixels;
};

