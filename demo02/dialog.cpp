#include "dialog.h"
#include <QHBoxLayout>
#include <QVBoxLayout>




Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
  initUi();
  initSingalSlots();
}

Dialog::~Dialog()
{
}

void Dialog::initUi() {
    checkBoxUnderline = new QCheckBox(tr("Underline"));
    checkBoxItalic = new QCheckBox(tr("Italic"));
    checkBold = new QCheckBox(tr("Bold"));

    QHBoxLayout *Hlayout1 = new QHBoxLayout;
    Hlayout1->addWidget(checkBoxUnderline);
    Hlayout1->addWidget(checkBoxItalic);
    Hlayout1->addWidget(checkBold);

    rBtnBlack = new QRadioButton("Black");
    rBtnBlue = new QRadioButton("BLue");
    rBtnRed = new QRadioButton("Red");
    QHBoxLayout *Hlayout2 = new QHBoxLayout;
    Hlayout2->addWidget(rBtnBlack);
    Hlayout2->addWidget(rBtnBlue);
    Hlayout2->addWidget(rBtnRed);

    plainTextEdit = new QPlainTextEdit();
    QFont font = plainTextEdit->font();
    font.setPointSize(20);
    plainTextEdit->setFont(font);
    plainTextEdit->setPlainText("Hello World");
    QHBoxLayout *Hlayout3 = new QHBoxLayout;
    Hlayout3->addWidget(plainTextEdit);

    btnOk = new QPushButton("Ok");
    btnCancel = new QPushButton("Cancel");
    btnClose = new QPushButton("Close");
    QHBoxLayout *Hlayout4 = new QHBoxLayout;
    Hlayout4->addWidget(btnOk);
    Hlayout4->addWidget(btnCancel);
    Hlayout4->addWidget(btnClose);

    QVBoxLayout *qvBoxLayout = new QVBoxLayout;
    qvBoxLayout->addLayout(Hlayout1);
    qvBoxLayout->addLayout(Hlayout2);
    qvBoxLayout->addLayout(Hlayout3);
    qvBoxLayout->addLayout(Hlayout4);
    setLayout(qvBoxLayout);
}

void Dialog::initSingalSlots()
{
    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    QObject::connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(checkBoxUnderline, SIGNAL(clicked(bool)), this, SLOT(on_checkUnderline(bool)));
    QObject::connect(checkBoxItalic, SIGNAL(clicked(bool)), this, SLOT(on_checkItalic(bool)));
    QObject::connect(checkBold, SIGNAL(clicked(bool)), this, SLOT(on_checkBold(bool)));

    QObject::connect(rBtnRed, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(rBtnBlue, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
    QObject::connect(rBtnBlack, SIGNAL(clicked()), this, SLOT(setTextFontColor()));
}

void Dialog::on_checkUnderline(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setUnderline(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkItalic(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setItalic(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkBold(bool checked) {
    QFont font = plainTextEdit->font();
    font.setBold(checked);
    plainTextEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette qpalette = plainTextEdit->palette();

    if(rBtnRed->isChecked()) {
         qpalette.setColor(QPalette::Text, Qt::red);
    }else if(rBtnBlue->isChecked()){
         qpalette.setColor(QPalette::Text, Qt::blue);
    }else {
        qpalette.setColor(QPalette::Text, Qt::black);
    }
    plainTextEdit->setPalette(qpalette);
}
