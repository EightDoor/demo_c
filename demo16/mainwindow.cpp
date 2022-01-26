#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(&threadA, &QThread::started, this, &MainWindow::on_threadAStarted);
    QObject::connect(&threadA, &QThread::finished, this, &MainWindow::on_threadAFinished);
    QObject::connect(&mTimer, SIGNAL(timeout()), SLOT(onTimerOut()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    if(threadA.isRunning()) {
        threadA.stopThread();
        threadA.wait();
    }

    event->accept();
}

void MainWindow::on_threadAnew(int seq, int diceValue)
{
   ui->plainTextEdit->appendPlainText(QString::asprintf("第%d次投掷筛子,点数为: %d", seq, diceValue));
}

void MainWindow::on_threadAStarted()
{
    mTimer.start(100);
    ui->label->setText("threadA状态: started");
    ui->startThread->setEnabled(false);
    ui->start->setEnabled(true);
    ui->pause->setEnabled(true);
    ui->stopThread->setEnabled(true);
}

void MainWindow::on_threadAFinished()
{
    mTimer.stop();
    ui->label->setText("threadA状态: finished");
    ui->startThread->setEnabled(true);
    ui->start->setEnabled(false);
    ui->pause->setEnabled(false);
    ui->stopThread->setEnabled(false);
}


void MainWindow::on_startThread_clicked()
{
    threadA.start();
}


void MainWindow::on_stopThread_clicked()
{
    threadA.stopThread();
}


void MainWindow::on_start_clicked()
{
    threadA.diceBegin();
     ui->pause->setEnabled(true);
     ui->start->setEnabled(false);
}


void MainWindow::on_pause_clicked()
{
    threadA.dicePause();
    ui->start->setEnabled(true);
    ui->pause->setEnabled(false);
}


void MainWindow::on_clearText_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::onTimerOut()
{
   int seq, diceValue;
   static int lastSeq = 0;
   bool status = threadA.readValue(&seq, &diceValue);
   if(!status || seq == 0 || seq == lastSeq) return;
   lastSeq = seq;
  ui->plainTextEdit->appendPlainText(QString::asprintf("第%d次投掷筛子,点数为: %d", seq, diceValue));
}

