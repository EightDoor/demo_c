#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initConnect();
}

Widget::~Widget()
{
    delete ui;
}

// 计算
void Widget::onChangeCalculation()
{
    QString str = ui->editNum->text();
    int num = str.toInt();
    str = ui->editPrice->text();
    float price = str.toFloat();
    float total = num * price;
    str = str.setNum(total, 'f', 2);
    ui->editTotal->setText(str);
}

void Widget::onBtnDecClick()
{
 QString str = ui->editDec->text();
 int value = str.toInt();
 QString result = str.setNum(value, 2);
 ui->editBin->setText(result);
 str = str.setNum(value, 16);
 ui->editHex->setText(str.toUpper());
}

void Widget::onBtnBinClick()
{
    QString str = ui->editBin->text();
    bool ok;
    int value = str.toInt(&ok, 2);
    if(ok) {
        QString result = str.setNum(value, 10);
        ui->editDec->setText(result);
        str = str.setNum(value, 16);
        ui->editHex->setText(str.toUpper());
    }
}

void Widget::onBtnHexClick()
{
    QString str = ui->editHex->text();
    bool ok;
    int value = str.toInt(&ok, 16);
    if(ok) {
        QString result = str.setNum(value, 2);
        ui->editBin->setText(result);
        str = str.setNum(value, 10);
        ui->editDec->setText(str);
    }
}

void Widget::initConnect() {
   QObject::connect(ui->calculationJ, SIGNAL(clicked()), this, SLOT(onChangeCalculation()));
   QObject::connect(ui->btnDec, SIGNAL(clicked()), this, SLOT(onBtnDecClick()));
   QObject::connect(ui->btnBin, SIGNAL(clicked()), this, SLOT(onBtnBinClick()));
   QObject::connect(ui->btnHex, SIGNAL(clicked()), this, SLOT(onBtnHexClick()));
}
