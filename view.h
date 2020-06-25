#pragma once
#include <QString>

class View
{
public:
    virtual void showPrediction(QString prediction) = 0;
};

