#include "Visualizer.h"
#include "NumberRecognition.h"

void Visualizer::update(NumberRecognition &r) {
    {
        window.clear();

        auto colors = r.input.pixels;
        for(auto y = 0; y < 28; y++) {
            for(auto x = 0; x < 28; x++) {
                image.setPixel(x, y, colors[y*28+x]);
            }
        }

        texture.update(image);
        shape.setTexture(&texture);
        window.draw(shape);

        int i = 0;
        for(auto& neuron: r.hidden1.neurons) {
            h1[i].setFillColor(activationToColor(neuron.first->activation));
            window.draw(h1[i]);
            i++;
        }
        i = 0;
        for(auto& neuron: r.hidden2.neurons) {
            h2[i].setFillColor(activationToColor(neuron.first->activation));
            window.draw(h2[i]);
            i++;
        }
        i = 0;
        for(auto& neuron: r.output.neurons) {
            out[i].setFillColor(activationToColor(neuron.first->activation));
            window.draw(out[i]);
            i++;
        }
        window.display();
    }
}
