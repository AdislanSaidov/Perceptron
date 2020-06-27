#pragma once
#include "datamanager.h"
#include "perceptron.h"
#include "view.h"

class MainController
{
public:
    MainController(View* view, DataManager* dataManager, Perceptron* perceptron);
    ~MainController();

    void predict(QSet<Point> *points);

    void train();



private:
    View* view;
    DataManager* dataManager;
    Perceptron* perceptron;


};
