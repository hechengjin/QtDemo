#include "dialog.h"
#include "ui_dialog.h"
#include <QByteArray>
#include <QtDebug>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //base64测试
    QString sub = QByteArray::fromBase64("5ZKM6YCa6KGM6K+BLeWvhueggeWPmOabtA==");
    QMessageBox msgBox;
      msgBox.setText(sub);
      msgBox.exec();
}
