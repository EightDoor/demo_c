#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(threadA, SIGNAL());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_threadAnew(int seq, int diceValue)
{

}

void MainWindow::on_threadAStarted()
{
    threadA.start();
    ui->startThread->setEnabled(false);
    ui->start->setEnabled(true);
    ui->pause->setEnabled(true);

    ui->stopThread->setEnabled(true);
}

void MainWindow::on_threadAFinished()
{

}


void MainWindow::on_startThread_clicked()
{
    threadA.start();
}

