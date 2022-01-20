#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qperson.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
private:
    QPerson *body;
    QPerson *girl;
    void onSpinValueChanged(int arg1);
    void onAgeChange(unsigned value);
private slots:
    void onBtnBodyIncClicked();
    void onBtnGirlIncClicked();
    void onBtnClassInfoClicked();
    void onValueChangeBoy(int value);
    void onValueChangeGirl(int value);
};
#endif // WIDGET_H
