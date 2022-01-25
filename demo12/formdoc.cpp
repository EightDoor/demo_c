#include "formdoc.h"
#include "ui_formdoc.h"
#include <QVBoxLayout>
#include <QToolBar>

FormDoc::FormDoc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormDoc)
{
    ui->setupUi(this);

    QToolBar *localToolBar = new QToolBar("文档", this);
    localToolBar->addAction(ui->actOpen);
    localToolBar->addAction(ui->actFont);
    localToolBar->addSeparator();
    localToolBar->addAction(ui->actCut);
    localToolBar->addAction(ui->actCopy);
    localToolBar->addAction(ui->actPaste);
    localToolBar->addAction(ui->actUndo);
    localToolBar->addAction(ui->actRedo);
    localToolBar->addSeparator();
    localToolBar->addAction(ui->actClose);

    localToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(localToolBar);
    layout->addWidget(ui->plainTextEdit);
    layout->setSpacing(2);
    layout->setContentsMargins(2, 2, 2, 2);
    setLayout(layout);
}

FormDoc::~FormDoc()
{
    delete ui;
}
