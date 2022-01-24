#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>

#define FixedColumnCount 6
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    LabelCurFile = new QLabel("当前文件", this);
    LabelCellPos = new QLabel("当前单元格", this);
    LabelCellText = new QLabel("单元格内容", this);

    theModel = new QStandardItemModel(10,FixedColumnCount, this);
    theSelection = new QItemSelectionModel(theModel, this);

    LabelCurFile->setMidLineWidth(200);
    LabelCellPos->setMidLineWidth(150);
    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->statusbar->addWidget(LabelCurFile);
    ui->statusbar->addWidget(LabelCellPos);
    ui->statusbar->addWidget(LabelCellText);

    QObject::connect(ui->tableView->selectionModel(),&QItemSelectionModel::currentChanged, this, &MainWindow::currentChangedS);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initModalFromStringList(QStringList &fileContent)
{
    theModel->setRowCount(fileContent.count() - 1);

    QString header = fileContent.at(0);
    QStringList headerList = header.split(QRegularExpression("\\s+"), Qt::KeepEmptyParts);
    // 设置表头
    theModel->setHorizontalHeaderLabels(headerList);
    // 设置表格数据
    int j = 1;
    QStandardItem *item;
    for(int i=1; i<fileContent.count(); i++) {
         QString lineText = fileContent.at(i);
         QStringList tempList = lineText.split(QRegularExpression("\\s+"), Qt::KeepEmptyParts);
         for (j=1; j< FixedColumnCount - 1 ; j++) {
             item = new QStandardItem(tempList.at(j));
              theModel->setItem(i-1, j, item);
         }
         item = new QStandardItem(tempList.at(j));
         if(tempList.at(j) == "1") {
             item->setCheckState(Qt::Checked);
         }else {
             item->setCheckState(Qt::Unchecked);
         }
         theModel->setItem(i-1, j, item);
    }
}

void MainWindow::currentChangedS(const QModelIndex &current, const QModelIndex &previous)
{
    if(!current.isValid()) return;
    LabelCellPos->setText(QString::asprintf("当前单元格: %d行 %d列",current.row(), previous.column()));
    QStandardItem *item = theModel->itemFromIndex(current);
    LabelCellText->setText("单元内容:" + item->text());
    QFont font = item->font();
    ui->actFontBold->setChecked(font.bold());
}

void MainWindow::on_actOpen_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString fileName = QFileDialog::getOpenFileName(this, "打开一个文件", curPath, "井数据文件(*.txt);;所有文件");
    if(fileName.isEmpty()) return;

    QStringList fileContent;
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ui->plainTextEdit->clear();
        while(!stream.atEnd()) {
             QString str = stream.readLine();
             ui->plainTextEdit->appendPlainText(str);
             fileContent.append(str);
        }
        file.close();
        this->LabelCellText->setText("当前文件:" + fileName);
        initModalFromStringList(fileContent);
    }
}

