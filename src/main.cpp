#include <iostream>
#include <functional>
#include "mnist/mnist_reader.hpp"
#include <SFML/Graphics.hpp>
#include <thread>
#include "Visualizer.h"
#include "NumberRecognition.h"

int main(int argc, char** argv) {
    NumberRecognition recognition;
    Visualizer visualizer;

    mnist::MNIST_dataset<std::vector, std::vector<uint8_t>, uint8_t> dataset =
            mnist::read_dataset<std::vector, std::vector, uint8_t, uint8_t>("mnist/");

    auto trainingImages = dataset.training_images;
    auto trainingLabels = dataset.training_labels;

    std::vector<std::pair<std::vector<float>, uint8_t>> trainingData;
    trainingData.reserve(trainingImages.size());

    for(auto i = 0; i < trainingImages.size(); i++) {
        trainingData.emplace_back(std::make_pair(
                [&](){
                    std::vector<float> ret;
                    for(auto in: trainingImages[i]) {
                        ret.emplace_back(static_cast<float>(in) /
                                                 static_cast<float>(std::numeric_limits<uint8_t>::max()));
                    }
                    return ret;
                }(),
                trainingLabels[i]));
    }

    for(auto& learnInput: trainingData) {
        auto input = learnInput.first;
        auto expected = learnInput.second;

        recognition.input.setInput(input);
        visualizer.update(recognition);
        auto toh1 = recognition.input.startFeedForwards();
        auto toh2 = recognition.hidden1.feedForwards(toh1);
        auto too = recognition.hidden2.feedForwards(toh2);
        auto outPut = recognition.output.feedForwards(too);
        visualizer.update(recognition);

        auto guess = recognition.output.getGuess();

        std::vector<short> gotVector = {0,0,0,0,0,0,0,0,0,0};
        std::vector<short> expectedVector = {0,0,0,0,0,0,0,0,0,0};
        gotVector[guess.first] = 1;
        expectedVector[expected] = 1;

        std::cout << "Guess:\n";
        for(auto element: gotVector)
            std::cout << element;
        std::cout << "\nExpected:\n";
        for(auto element: expectedVector)
            std::cout << element;
        std::cout << '\n';

        //auto error =

    }
}

