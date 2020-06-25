#pragma once
#include <QMainWindow>
#include "constants.h"
#include "maincontroller.h"
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public View
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showPrediction(QString prediction);

private:
    Ui::MainWindow *ui;
    MainController* controller;

    void inject();

};
