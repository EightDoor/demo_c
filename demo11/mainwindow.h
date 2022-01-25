#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "dialogsetheaders.h"
#include "dialoglocato.h";


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setActLocateEnable(bool enable);
    void setDlgLocateNULL();
private:
    QStandardItemModel *theModel;
    QItemSelectionModel *theSelection;
    DialogSetHeaders *dialogHeaders = NULL;
    DialogLocato *dialogLocato = NULL;
private slots:
    void on_actTab_SetSize_triggered();

    void on_actTab_SetHeader_triggered();

    void on_actTab_Locale_triggered();
    void on_tableView_clicked(const QModelIndex &index);
    void setACellText(int row, int col, QString text);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
