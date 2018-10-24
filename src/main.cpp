#include <iostream>
#include "OutputLayer.h"
#include "InputLayer.h"

class NumberRecognition {
public:
    InputLayer input{28*28};
    Layer hidden1{16};
    Layer hidden2{16};
    OutputLayer output{10};
};

int main(int argc, char** argv) {
    NumberRecognition recognition;

    for(auto& learnInput: )

}

