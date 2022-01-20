#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // 信号发射和槽关联
    QObject::connect(ui->btn1,SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(ui->btn2,SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(ui->btn3,SIGNAL(clicked()), this, SLOT(setTextFontColor()));
}

Dialog::~Dialog()
{
    delete ui;
}

// 设置下划线
void Dialog::on_checkBoxUndereLine_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

// 设置斜体
void Dialog::on_checkBoxLtalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}

// 设置是否加粗
void Dialog::on_checkBoxBoold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->btn1->isChecked()) {
         plet.setColor(QPalette::Text, Qt::red);
    }else if(ui->btn2->isChecked()) {
        plet.setColor(QPalette::Text, Qt::blue);
    }else if(ui->btn3->isChecked()) {
        plet.setColor(QPalette::Text, Qt::black);
    }else {
        plet.setColor(QPalette::Text, Qt::black);
    }

    ui->plainTextEdit->setPalette(plet);
}

