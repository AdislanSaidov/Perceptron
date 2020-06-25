#include "perceptron.h"
#include "utils.h"
#include "constants.h"

Perceptron::Perceptron(): inputs(new int[CELL_COUNT])
{

}

//loading weights into the network or
//if they absents generating new ones at random in the interval [-1/2n; 1/2n]
void Perceptron::initWeights(float * weights)
{
    if(weights == nullptr){
        this->weights = new float[CELL_COUNT];
        float f = 1.0f/(float)(2*CELL_COUNT); // [-1/2n; 1/2n]
        int x = f*100000;
        for(int i = 0; i < CELL_COUNT; ++i){
            int y = randomBetween(-x,x);
            this->weights[i] = (float)y/100000;
            qDebug() << "generated: " << (float)y/100000 << " y" << y;
        }
    }else{
        this->weights = weights;
    }
}
//answer of the network
bool Perceptron::predict(int* inputs)
{
    this->inputs = inputs;
    int sum = computeScalar() + TRESHOLD;
    int activation = activate(sum);
    qDebug() << sum << " SUM";
    qDebug() << activation << " activation " << (activation == 1);
    return activation == 1;
}

//training the network
void Perceptron::train()
{
    float sum = computeScalar() + TRESHOLD;

    int activation = activate(sum);
    for(int i = 0; i < CELL_COUNT; ++i){
        if(activation == -1){
            if(inputs[i] == 1){
                weights[i] += 1.0f;
                qDebug() << weights[i] << " ++";
            }
        }else{
            if(inputs[i] == 1){
                weights[i] -= 1.0f;
                qDebug() << weights[i] << " --";
            }
        }
    }
}

//computing dot product between weights and inputs
float Perceptron::computeScalar()
{
    float sum = 0.0f;
    for(int i = 0; i < CELL_COUNT; ++i){
        sum += weights[i] * inputs[i];
    }
    qDebug() << "SUM: " << sum;
    return sum;
}

//activation function
int Perceptron::activate(float sum)
{
    return (sum >= 0) ? 1 : -1;
}


Perceptron::~Perceptron()
{
    delete[] weights;
    delete[] inputs;
}
