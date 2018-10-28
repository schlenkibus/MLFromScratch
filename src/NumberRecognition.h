#pragma once
#include "InputLayer.h"
#include "OutputLayer.h"

class NumberRecognition {
public:
    InputLayer input{28*28};
    Layer hidden1{16};
    Layer hidden2{16};
    OutputLayer output{10};
};