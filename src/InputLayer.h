#pragma once
#include "Layer.h"

class InputLayer : public Layer
{
public:
	InputLayer(int numNodes);
	~InputLayer();
    void input();
};

