#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);

    initUI();
    initSingalSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    fLabelCurFile = new QLabel;
    fLabelCurFile->setMidLineWidth(150);
    fLabelCurFile->setText("当前文件:");
    ui->statusbar->addWidget(fLabelCurFile);
    progressBar = new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(8);
    progressBar->setValue(ui->textEdit->fontPointSize());

    ui->statusbar->addWidget(progressBar);
    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);
    comboFont = new QFontComboBox;
    comboFont->setMaximumWidth(50);
    ui->toolBar->addWidget(new QLabel("字体"));
    ui->toolBar->addWidget(comboFont);
}

void MainWindow::initSingalSlots()
{
    QObject::connect(spinFontSize, SIGNAL(valueChanged(int)), this, SLOT(spinBoxFontSize_valueChanged(int)));
    QObject::connect(comboFont, SIGNAL(currentFontChanged(QFont)), this, SLOT(comboFont_currentIndexChanged(QFont)));
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actionCut->setEnabled(b);
    ui->actionCopy->setEnabled(b);
    ui->actionPaste->setEnabled(ui->textEdit->canPaste());
}


void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    ui->actionItalics->setChecked(fmt.FontItalic);
    ui->actionBold->setChecked(fmt.font().bold());
    ui->actionUnderline->setChecked(fmt.fontUnderline());
}


void MainWindow::on_actionBold_triggered(bool checked)
{
    QTextCharFormat fmt = ui->textEdit->currentCharFormat();
    if(checked) {
        fmt.setFontWeight(QFont::Bold);
    }else {
        fmt.setFontWeight(QFont::Normal);
    }
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionItalics_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontPointSize(aFontSize);

    ui->textEdit->mergeCurrentCharFormat(fmt);
    progressBar->setValue(aFontSize);
}

void MainWindow::comboFont_currentIndexChanged(const QFont &arg1)
{
    QTextCharFormat fmt;
    fmt.setFont(arg1);

    ui->textEdit->mergeCurrentCharFormat(fmt);
}

