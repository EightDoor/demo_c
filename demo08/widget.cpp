#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    theModel = new QStringListModel(this);
    QStringList strList;
    strList << "item1" << "item2" << "item3" << "item4";
    theModel->setStringList(strList);

    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_7_clicked()
{
    theModel->removeRows(0, theModel->rowCount());
}


void Widget::on_pushButton_8_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_pushButton_9_clicked()
{
 QStringList strList = theModel->stringList();
 ui->plainTextEdit->clear();
 foreach(auto str, strList) {
     ui->plainTextEdit->appendPlainText(str);
 }
}


void Widget::on_pushButton_3_clicked()
{
    QStringList strList;
    strList << "item1" << "item2" << "item3" << "item4";
    theModel->setStringList(strList);
}


void Widget::on_pushButton_6_clicked()
{
    theModel->removeRow(ui->listView->currentIndex().row());
}


void Widget::on_pushButton_4_clicked()
{
    theModel->insertRow(theModel->rowCount());
    QModelIndex index = theModel->index(theModel->rowCount() - 1, 0);
    theModel->setData(index, "new Item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}


void Widget::on_pushButton_5_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    theModel->insertRow(index.row());
    theModel->setData(index, "new Item", Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}


void Widget::on_listView_clicked(const QModelIndex &index)
{
    ui->label->setText(QString::asprintf("行: %d, 列: %d", index.row(), index.column()));
}

