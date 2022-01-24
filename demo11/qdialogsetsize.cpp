#include "qdialogsetsize.h"
#include "ui_qdialogsetsize.h"
#include <QMessageBox>

QDialogSetSize::QDialogSetSize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDialogSetSize)
{
    ui->setupUi(this);
}

QDialogSetSize::~QDialogSetSize()
{
    QMessageBox::information(this, "", "设置大小对话框已退出");
    delete ui;
}

int QDialogSetSize::columnCount()
{
    return ui->spinBoxColumn->value();
}

int QDialogSetSize::rowCount()
{
    return ui->spinBoxRow->value();
}

void QDialogSetSize::setRowsColumns(int rowCount, int colCount)
{
    ui->spinBoxColumn->setValue(colCount);
    ui->spinBoxRow->setValue(rowCount);
}
