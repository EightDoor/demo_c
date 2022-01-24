#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>

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
    // 用于状态栏的信息显示
    QLabel *LabelCurFile; // 当前文件
    QLabel *LabelCellPos; // 当前单元格行列号
    QLabel *LabelCellText; // 当前单元格内容

    QStandardItemModel *theModel; // 数据模型
    QItemSelectionModel *theSelection; // Item选择模型

    void initModalFromStringList(QStringList &fileContent);
private slots:
    void currentChangedS(const QModelIndex &current, const QModelIndex &previous);
    void on_actOpen_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
