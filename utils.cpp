#include "utils.h"

QList<Cell> utils::reduce(QList<Cell> &cells){
    QHash<Cell, uint> map;
    for(auto cell: cells) {
        if(map.contains(cell)){
            map[cell] = map[cell]+1;
        }else{
            map[cell] = 1;
        }
    }
    QList<Cell> resultCells;
    QHash<Cell, uint>::iterator it = map.begin();
    while (it != map.end()) {
        if(it.value() >= POINTS_PER_CELL){
            resultCells << it.key();
        }
        ++it;
    }
    return resultCells;
}

QList<Cell> utils::convertPointsToCells(const QSet<Point>* points){
    QList<Cell> cells;
    for(auto p: *points){
        //        qDebug() << "current: x = "<<p.x <<" y = "<< p.y;
        uint xp = -1;
        uint yp = -1;
        for(uint i = 0; i < COLUMN_COUNT; ++i){
            uint start = i * COLUMN_WIDTH;
            uint end = start + COLUMN_WIDTH;
            bool isXinRange = start <= p.x && p.x < end;

            if(isXinRange){
                xp = i;
            }
            bool isYinRange = start <= p.y && p.y < end;
            if(isYinRange){
                yp = i;
            }
        }
        cells << Cell(xp, yp);
    }
    return reduce(cells);
}


int* utils::flatMatrix(QList<Cell> &cells){
    int* inputs = new int[CELL_COUNT];
    std::fill(inputs, inputs+CELL_COUNT, 0);
    for(int i = 0; i < CELL_COUNT; ++i){
        qDebug() << inputs[i];
    }
    for(auto cell: cells){
        int n = cell.y*COLUMN_COUNT+cell.x;
        qDebug() << cell <<" "<< n;
        inputs[n] = 1;
    }
    for(int i = 0; i < CELL_COUNT; ++i){
        qDebug() << inputs[i];
    }
    return inputs;
}


int utils::randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}
