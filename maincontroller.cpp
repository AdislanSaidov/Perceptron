#include "maincontroller.h"
#include "utils.h"

MainController::MainController(View *view, DataManager *dataManager, Perceptron *perceptron):
    view(view),
    dataManager(dataManager),
    perceptron(perceptron)
{
    auto weights = dataManager->read();
    perceptron->initWeights(weights);
}

void MainController::predict(QSet<Point>* points)
{
    QList<Cell> cells = convertPointsToCells(points);
    auto inputs = flatMatrix(cells);
    auto prediction = perceptron->predict(inputs);
    view->showPrediction((prediction == 1) ? "Yes" : "No");
}

void MainController::train()
{
    perceptron->train();
    dataManager->save(perceptron->getWeights());
}

