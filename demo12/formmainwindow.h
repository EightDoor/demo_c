#ifndef FORMMAINWINDOW_H
#define FORMMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class FormMainWindow;
}

class FormMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormMainWindow(QWidget *parent = nullptr);
    ~FormMainWindow();

private:
    Ui::FormMainWindow *ui;
};

#endif // FORMMAINWINDOW_H
