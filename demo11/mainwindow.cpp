#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdialogsetsize.h"
#include <QDebug>
#include <QDialog>

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

void MainWindow::setActLocateEnable(bool enable)
{
    ui->actTab_Locale->setEnabled(enable);
}

void MainWindow::setDlgLocateNULL()
{
    dialogLocato = NULL;
}

void MainWindow::setACellText(int row, int col, QString text)
{
    QModelIndex index = theModel->index(row, col);
    theModel->setData(index, text, Qt::DisplayRole);
    theSelection->clearSelection();

    theSelection->setCurrentIndex(index, QItemSelectionModel::Select);
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
           strList << theModel->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString();
       }
       dialogHeaders->setStringList(strList);
    }

    int ret = dialogHeaders->exec();
    if(ret == QDialog::Accepted) {
        QStringList strList = dialogHeaders->stringList();
        theModel->setHorizontalHeaderLabels(strList);
    }
}


void MainWindow::on_actTab_Locale_triggered()
{
     ui->actTab_Locale->setEnabled(false);
     dialogLocato = new DialogLocato(this);
     dialogLocato->setAttribute(Qt::WA_DeleteOnClose);
     Qt::WindowFlags flags = dialogLocato->windowFlags();
     dialogLocato->setWindowFlags(flags | Qt::WindowStaysOnTopHint);

     dialogLocato->setRange(theModel->rowCount(), theModel->columnCount());
     QModelIndex curIndex = theSelection->currentIndex();
     if(curIndex.isValid()) {
        dialogLocato->setValue(curIndex.row(), curIndex.column());
     }

     QObject::connect(dialogLocato, SIGNAL(changeCellText(int, int, QString)), this, SLOT(setACellText(int, int, QString)));
     dialogLocato->show();
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(dialogLocato!=NULL) {
        dialogLocato->setValue(index.row(), index.column());
    }
}

