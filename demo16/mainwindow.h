#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dicethread.h"
#include <QTimer>

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
protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
    DiceThread threadA;
    QTimer mTimer; // 定时器
private slots:
    void on_threadAnew(int seq, int diceValue);
    void on_threadAStarted();
    void on_threadAFinished();
    void on_startThread_clicked();
    void on_stopThread_clicked();
    void on_start_clicked();
    void on_pause_clicked();
    void on_clearText_clicked();
    void onTimerOut();
};
#endif // MAINWINDOW_H
