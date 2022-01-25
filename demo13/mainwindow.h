#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void painEvent(QPaintEvent *event);

private slots:
    void on_actWidgetInsite_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_tabWidget_currentChanged(int index);

    void on_actWidget_triggered();

    void on_actMainWindowInsite_triggered();

    void on_actWindow_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
