#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPushButton>
#include <QPlainTextEdit>

class Dialog : public QDialog
{
    Q_OBJECT

private:
    QCheckBox *checkBoxUnderline;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBold;

    QRadioButton *rBtnBlack;
    QRadioButton *rBtnBlue;
    QRadioButton *rBtnRed;

    QPlainTextEdit *plainTextEdit;

    QPushButton *btnOk;
    QPushButton *btnCancel;
    QPushButton *btnClose;
    void initUi();
    void initSingalSlots();

private slots:
    void on_checkUnderline(bool checked);
    void on_checkItalic(bool checked);
    void on_checkBold(bool checked);
    void setTextFontColor();
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
