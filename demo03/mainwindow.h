#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    void on_actionBold_triggered(bool checked);

    void on_actionItalics_triggered(bool checked);

    void spinBoxFontSize_valueChanged(int aFontSize);
    void comboFont_currentIndexChanged(const QFont &arg1);

private:
    QLabel *fLabelCurFile;
    QProgressBar *progressBar;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;
    void initUI();
    void initSingalSlots();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
