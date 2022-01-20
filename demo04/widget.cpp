#include "widget.h"
#include "ui_widget.h"
#include <QMetaProperty>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBoxBody->setProperty("isBody", true);
    ui->spinBoxGirl->setProperty("isBody", false);

    body = new QPerson("王小明");
    body->setProperty("score", 95);
    body->setProperty("age", 10);
    body->setProperty("sex", "Boy");

   connect(body, &QPerson::ageChanged, this, &Widget::onAgeChange);

   girl = new QPerson("丽丽");
   girl->setProperty("score", 80);
   girl->setProperty("age",20);
   girl->setProperty("sex", "girl");
   connect(girl, &QPerson::ageChanged, this, &Widget::onAgeChange);

   QObject::connect(ui->btnBody, SIGNAL(clicked()), this, SLOT(onBtnBodyIncClicked()));
   QObject::connect(ui->btnGirl, SIGNAL(clicked()), this, SLOT(onBtnGirlIncClicked()));

   QObject::connect(ui->spinBoxBody, SIGNAL(valueChanged(int)), this, SLOT(onValueChangeBoy(int)));
   QObject::connect(ui->spinBoxGirl, SIGNAL(valueChanged(int)), this, SLOT(onValueChangeGirl(int)));
   QObject::connect(ui->BtnClassInfo, SIGNAL(clicked()), this, SLOT(onBtnClassInfoClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onSpinValueChanged(int arg1)
{
    Q_UNUSED(arg1);
    QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if(spinBox->property("isBody").toBool()) {
        body->setAge(spinBox->value());
    }else {
        girl->setAge(spinBox->value());
    }
}

void Widget::onAgeChange(unsigned value)
{
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson*>(sender());
    QString aName = aPerson->property("name").toString();
    unsigned aAge= aPerson->age();
    QString aSex = aPerson->property("sex").toString();

    ui->textEdit->appendPlainText(aName + "," + aSex + "," + QString::asprintf("年龄=%d", aAge));
}

void Widget::onBtnBodyIncClicked()
{
    body->incAge();
}

void Widget::onBtnGirlIncClicked()
{
    girl->incAge();
}

void Widget::onBtnClassInfoClicked()
{
  const QMetaObject *meta = girl->metaObject();
  ui->textEdit->clear();
  ui->textEdit->appendPlainText("===元对象信息===\n");
  ui->textEdit->appendPlainText(
              QString("类名称:%1\n").arg(meta->className()));
  ui->textEdit->appendPlainText(
              QString("property:"));
  for (int i= meta->propertyOffset();i < meta->propertyCount() ; i++) {
    QMetaProperty prop = meta->property(i);
    const char* propName = prop.name();
    QString propValue = body->property(propName).toString();
    ui->textEdit->appendPlainText(QString("属性名称: %1, 属性名称: %2").arg(propName).arg(propValue));
  }

  ui->textEdit->appendPlainText("");

  ui->textEdit->appendPlainText("classInfo");
  for (int i=meta->classInfoOffset();i<meta->classInfoCount();i++ ) {
    QMetaClassInfo classInfo = meta->classInfo(i);
    ui->textEdit->appendPlainText(QString("Name=%1,Value=%2").arg(classInfo.name()).arg(classInfo.value()));
  }
}

void Widget::onValueChangeBoy(int value)
{
    body->setAge(value);
}

void Widget::onValueChangeGirl(int value)
{
    girl->setAge(value);
}

