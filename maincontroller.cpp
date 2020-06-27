#include "maincontroller.h"
#include "utils.h"

MainController::MainController(View *view, DataManager *dataManager, Perceptron *classifier):
    view(view),
    dataManager(dataManager),
    perceptron(classifier)
{
    auto weights = dataManager->read();
    classifier->initWeights(weights);
}

void MainController::predict(QSet<Point>* points)
{
    QList<Cell> cells = utils::convertPointsToCells(points);
    auto inputs = utils::flatMatrix(cells);
    auto prediction = perceptron->predict(inputs);
    view->showPrediction((prediction == 1) ? "Yes" : "No");
}

void MainController::train()
{
    perceptron->train();
    dataManager->save(perceptron->getWeights());
}

MainController::~MainController()
{
    delete dataManager;
    delete perceptron;
}
