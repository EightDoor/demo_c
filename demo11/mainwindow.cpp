#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialogsetsize.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    theModel = new QStandardItemModel(this);
    theSelection = new QItemSelectionModel(theModel);

    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actTab_SetSize_triggered()
{
    QDialogSetSize *dia = new QDialogSetSize(this);
    dia->setRowsColumns(theModel->rowCount(), theModel->columnCount());
    int ret = dia->exec();
    if(ret == QDialog::Accepted) {
        int col = dia->columnCount();
        int row = dia->rowCount();
        theModel->setColumnCount(col);
        theModel->setRowCount(row);
    }

    delete dia;
}


void MainWindow::on_actTab_SetHeader_triggered()
{
    if(dialogHeaders == NULL) {
        dialogHeaders = new DialogSetHeaders(this);
    }

    if(dialogHeaders->stringList().count() != theModel->columnCount()) {
       QStringList strList;
       for(int i=0; i< theModel->columnCount(); i++) {
           strList << theModel->headerData(i, Qt::Horizontal);;
       }
       dialogHeaders->setStringList(strList);
    }

    int ret = dialogHeaders->exec();
    if(ret == QDialog::Accepted) {
        QStringList strList = dialogHeaders->stringList();
        theModel->setHorizontalHeaderLabels(strList);
    }
}

