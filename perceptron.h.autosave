#pragma once

class Perceptron
{
public:
    Perceptron();
    ~Perceptron();

    void initWeights(float*);
    bool predict(int *inputs);
    void train();

    float* getWeights(){
        return weights;
    }

private:
    float* weights = nullptr;
    int* inputs = nullptr;

    float computeDotProduct();
    int activate(float sum);
};
