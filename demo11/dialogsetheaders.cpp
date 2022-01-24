#include "dialogsetheaders.h"
#include "ui_dialogsetheaders.h"

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
