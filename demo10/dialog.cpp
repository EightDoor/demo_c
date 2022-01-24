#include "dialog.h"
#include "ui_dialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_strClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Dialog::on_pushButton_clicked()
{
    QString curPath = QDir::currentPath();
    QString dialogTitle = "选择对话框";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QString fileName = QFileDialog::getOpenFileName(this, dialogTitle, curPath, filter);

    if(!fileName.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileName);
    }
}


void Dialog::on_pushButton_2_clicked()
{
    QString curPath = QDir::currentPath();
    QString dialogTitle = "选择对话框";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QStringList fileNames = QFileDialog::getOpenFileNames(this, dialogTitle, curPath, filter);

    if(fileNames.count() != 0) {
        foreach(auto str, fileNames) {
            ui->plainTextEdit->appendPlainText(str);
        }
    }
}


void Dialog::on_pushButton_3_clicked()
{
    QString curPath = QDir::currentPath();
    QString dialogTitle = "选择对话框";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QString selectedDir = QFileDialog::getExistingDirectory(this, dialogTitle, curPath, QFileDialog::ShowDirsOnly);

    if(!selectedDir.isEmpty()) {
        ui->plainTextEdit->appendPlainText(selectedDir);
    }
}


void Dialog::on_pushButton_4_clicked()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString dialogTitle = "选择对话框";
    QString filter = "文本文件(*.txt);;图片文件(*.jpg *.gif);;所有文件(*.*)";
    QString fileName = QFileDialog::getSaveFileName(this, dialogTitle, curPath, filter);

    if(!fileName.isEmpty()) {
        ui->plainTextEdit->appendPlainText(fileName);
    }
}


void Dialog::on_pushButton_5_clicked()
{
 QColor initColor = ui->plainTextEdit->palette().color(QPalette::Text);
 QColor color = QColorDialog::getColor(initColor, this, "选择颜色");

 QPalette pan = ui->plainTextEdit->palette();
 if(!color.isValid()) return;
 pan.setColor(QPalette::Text, color);
 ui->plainTextEdit->setPalette(pan);
}


void Dialog::on_pushButton_6_clicked()
{
  bool ok = false;
  QFont initFont = ui->plainTextEdit->font();
  QFont font = QFontDialog::getFont(&ok, initFont, this, "选择字体");
  if(!ok) return;
  ui->plainTextEdit->setFont(font);
}


void Dialog::on_pushButton_16_clicked()
{
    QString dialogTitle = "输入文字对话框";
    QString textLabel = "请输入文件名";
    QString defaultInput = "xxx.txt";
    QLineEdit::EchoMode echoMode = QLineEdit::Normal;
    bool ok = false;
    QString str = QInputDialog::getText(this, dialogTitle, textLabel, echoMode, defaultInput, &ok);
    if(!ok) return;
    ui->plainTextEdit->appendPlainText(str);
}


void Dialog::on_pushButton_17_clicked()
{
    QString dialogTitle = "输入整数对话框";
    QString textLabel = "请输入整数";
    int defaultValue = ui->plainTextEdit->font().pointSize();
    int minValue = 0, maxValue = 100;
    bool ok = false;
    int str = QInputDialog::getInt(this, dialogTitle, textLabel, defaultValue,minValue, maxValue, 1, &ok);
    if(!ok) return;
    QFont font = ui->plainTextEdit->font();
    ui->plainTextEdit->setFont(font);
    ui->plainTextEdit->appendPlainText(QString::asprintf("%d", str));
}


void Dialog::on_pushButton_18_clicked()
{
    QString dialogTitle = "输入浮点数对话框";
    QString textLabel = "请输入浮点数";
    float defaultValue = 15.0;
    float minValue = 0, maxValue = 100;
    bool ok = false;
    float str = QInputDialog::getDouble(this, dialogTitle, textLabel, defaultValue,minValue, maxValue, 2, &ok);
    if(!ok) return;
    ui->plainTextEdit->appendPlainText(QString::asprintf("%.2f", str));
}


void Dialog::on_pushButton_19_clicked()
{
    QStringList items;
    items << "优秀" << "良好" << "及格" << "不及格";
    QString dialogTitle = "输入条目";
    QString textLabel = "请选择条目";
    bool ok = false;
    QString text = QInputDialog::getItem(this, dialogTitle, textLabel, items, 0, true, &ok);
    if(!ok || text.isEmpty()) return;
    ui->plainTextEdit->appendPlainText(text);
}


void Dialog::on_pushButton_7_clicked()
{
    QString dialogTitle = "Question消息框";
    QString textLabel = "文件已被修改，是否保存?";
    QMessageBox::StandardButtons result;
    result = QMessageBox::question(this, dialogTitle, textLabel, QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::NoButton);
    QString str;
    if(result == QMessageBox::Yes)
     {
        str = "Question消息框: yes被选中";
    }else if(result == QMessageBox::No) {
        str = "Question消息框: no被选中";
    }else if(result == QMessageBox::Cancel) {
          str = "Question消息框: cancel被选中";
    }

    ui->plainTextEdit->appendPlainText(str);
}


void Dialog::on_pushButton_8_clicked()
{
    QMessageBox::information(this, "Title", "TXT", QMessageBox::Ok);
}


void Dialog::on_pushButton_9_clicked()
{
     QMessageBox::warning(this, "Title", "TXT", QMessageBox::Ok);
}


void Dialog::on_pushButton_13_clicked()
{
     QMessageBox::critical(this, "Title", "TXT", QMessageBox::Ok);
}


void Dialog::on_pushButton_14_clicked()
{
    QMessageBox::about(this, "Title", "TXT");
}


void Dialog::on_pushButton_15_clicked()
{
    QMessageBox::aboutQt(this);
}

