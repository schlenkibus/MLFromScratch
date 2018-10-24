#pragma once
#include "Layer.h"
class OutputLayer :
	public Layer
{
public:
	explicit OutputLayer(int numNodes);
	~OutputLayer();
};

