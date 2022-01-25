#ifndef DIALOGLOCATO_H
#define DIALOGLOCATO_H

#include <QDialog>

namespace Ui {
class DialogLocato;
}

class DialogLocato : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLocato(QWidget *parent = nullptr);
    ~DialogLocato();
    void setRange(int row, int col);
    void setValue(int row, int col);
    void closeEvent(QCloseEvent *event);
private slots:
    void on_btnSubmit_clicked();
signals:
    void changeCellText(int, int, QString);
private:
    Ui::DialogLocato *ui;
};

#endif // DIALOGLOCATO_H
