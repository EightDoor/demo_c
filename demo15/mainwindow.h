#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dicethread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    DiceThread threadA;
private slots:
    void on_threadAnew(int seq, int diceValue);
    void on_threadAStarted();
    void on_threadAFinished();
};
#endif // MAINWINDOW_H
