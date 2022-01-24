#ifndef DIALOGSETHEADERS_H
#define DIALOGSETHEADERS_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class DialogSetHeaders;
}

class DialogSetHeaders : public QDialog
{
    Q_OBJECT

private:
    QStringListModel *theModel;
public:
    explicit DialogSetHeaders(QWidget *parent = nullptr);
    ~DialogSetHeaders();
    void setStringList(QStringList strList);
    QStringList stringList();
private:
    Ui::DialogSetHeaders *ui;
};

#endif // DIALOGSETHEADERS_H
