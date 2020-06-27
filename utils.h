#pragma once

#include <QDebug>
#include "models/cell.h"
#include "constants.h"
#include "models/point.h"

namespace utils {
    //removing redundant cells
    QList<Cell> reduce(QList<Cell> &cells);

    // relating to cells
    QList<Cell> convertPointsToCells(const QSet<Point>* points);

    // converting cells to 1-dimensional array
    int* flatMatrix(QList<Cell> &cells);

    int randomBetween(int low, int high);

}
