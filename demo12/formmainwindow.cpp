#include "formmainwindow.h"
#include "ui_formmainwindow.h"

FormMainWindow::FormMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormMainWindow)
{
    ui->setupUi(this);
}

FormMainWindow::~FormMainWindow()
{
    delete ui;
}
