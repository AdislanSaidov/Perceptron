#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnClear, &QPushButton::clicked, this, [=]{
        ui->openGLView->clear();
        ui->lblTruth->setText("");
    });
    connect(ui->btnTrain, &QPushButton::clicked, this, [=]{
        controller->train();
    });
    connect(ui->btnDetect, &QPushButton::clicked, this, [=]{
        controller->predict(ui->openGLView->collectPoints());
    });
    inject();
}


void MainWindow::inject()
{
    auto dataManager = new DataManager();
    auto perceptron = new Perceptron();
    controller = new MainController(this, dataManager, perceptron);
}

void MainWindow::showPrediction(QString prediction)
{
    ui->lblTruth->setText(prediction);
}


MainWindow::~MainWindow()
{
    delete controller;
    delete ui;
}

