#pragma once

#include "models/point.h"
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QMouseEvent>

class OpenGLView : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    OpenGLView(QWidget *parent);



    void clear();
    QSet<Point>* points()
    {
        return currentPoints;
    }


protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    int width;
    int height;
    QSet<Point>* currentPoints;
    QList<QSet<Point>*>* sets;
    int x = 300, y = 300;

    void drawGrid();
    void drawInput();


};
