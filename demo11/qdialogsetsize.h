#ifndef QDIALOGSETSIZE_H
#define QDIALOGSETSIZE_H

#include <QDialog>

namespace Ui {
class QDialogSetSize;
}

class QDialogSetSize : public QDialog
{
    Q_OBJECT

public:
    explicit QDialogSetSize(QWidget *parent = nullptr);
    ~QDialogSetSize();

    int columnCount();
    int rowCount();
    void setRowsColumns(int rowCount, int colCount);
private:
    Ui::QDialogSetSize *ui;
};

#endif // QDIALOGSETSIZE_H
