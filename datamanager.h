#pragma once

#include "models/point.h"
#include "models/cell.h"

class DataManager
{
public:
    DataManager();
    void save(float* weights);
    bool read(float* weights);
    float* read();
private:


};
