#include "dialoglocato.h"
#include "ui_dialoglocato.h"
#include <QMessageBox>
#include <mainwindow.h>

DialogLocato::DialogLocato(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLocato)
{
    ui->setupUi(this);
}

DialogLocato::~DialogLocato()
{
    QMessageBox::information(this, "提示", "单元格定位对话框被删除");
    delete ui;
}

void DialogLocato::setRange(int row, int col)
{
 ui->spinBoxRow->setRange(0, row - 1);
 ui->spinBoxColumn->setRange(0, col - 1);
}

void DialogLocato::setValue(int row, int col)
{
    ui->spinBoxRow->setValue(row);
    ui->spinBoxColumn->setValue(col);
}

void DialogLocato::closeEvent(QCloseEvent *event)
{
     MainWindow *parW = (MainWindow *) parentWidget();
     parW->setActLocateEnable(true);
     parW->setDlgLocateNULL();
}

void DialogLocato::on_btnSubmit_clicked()
{
     int row = ui->spinBoxRow->value();
     int col = ui->spinBoxColumn->value();

     emit changeCellText(row, col, ui->lineEdit->text());
     if(ui->checkBoxRow->isChecked()) {
        ui->spinBoxRow->setValue(ui->spinBoxRow->value() + 1);
     }
     if(ui->checkBoxColum->isChecked()) {
         ui->spinBoxColumn->setValue(ui->spinBoxColumn->value() + 1);
     }
}

