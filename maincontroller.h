#pragma once
#include "datamanager.h"
#include "perceptron.h"
#include "view.h"

class MainController
{
public:
    MainController(View* view, DataManager* dataManager, Perceptron* perceptron);

    void predict(QSet<Point> *points);

    void train();



private:
    DataManager* dataManager;
    Perceptron* perceptron;
    View* view;

};
