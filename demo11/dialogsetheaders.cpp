#include "dialogsetheaders.h"
#include "ui_dialogsetheaders.h"
#include <QMessageBox>

DialogSetHeaders::DialogSetHeaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSetHeaders)
{
    ui->setupUi(this);

    theModel = new QStringListModel(this);
    ui->listView->setModel(theModel);
}

DialogSetHeaders::~DialogSetHeaders()
{
    QMessageBox::information(this, "", "set header 对话框退出");
    delete ui;
}

void DialogSetHeaders::setStringList(QStringList strList)
{
    theModel->setStringList(strList);
}

QStringList DialogSetHeaders::stringList()
{
    return theModel->stringList();
}
