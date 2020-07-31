/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_Gmail;
    QWebEngineView *webEngineView_Google;
    QPushButton *pushButton_proxy;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(687, 485);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 430, 75, 23));
        pushButton_Gmail = new QPushButton(Dialog);
        pushButton_Gmail->setObjectName(QString::fromUtf8("pushButton_Gmail"));
        pushButton_Gmail->setGeometry(QRect(30, 30, 75, 23));
        webEngineView_Google = new QWebEngineView(Dialog);
        webEngineView_Google->setObjectName(QString::fromUtf8("webEngineView_Google"));
        webEngineView_Google->setGeometry(QRect(10, 80, 651, 321));
        webEngineView_Google->setUrl(QUrl(QString::fromUtf8("about:blank")));
        pushButton_proxy = new QPushButton(Dialog);
        pushButton_proxy->setObjectName(QString::fromUtf8("pushButton_proxy"));
        pushButton_proxy->setGeometry(QRect(350, 20, 75, 23));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "test", nullptr));
        pushButton_Gmail->setText(QApplication::translate("Dialog", "GMail", nullptr));
        pushButton_proxy->setText(QApplication::translate("Dialog", "proxy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
