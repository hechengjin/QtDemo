#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <MailCore/MailCore.h>
#include "EchoServer.h"
#include "httpSvr.h"
#include "gmailtokenapi.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
    QUrl genGmailOAuth2();
    

private:
    quint16 serverPort;
    //EchoServer* server;
    httpSvr* server;
    QGmailTokenApi* pGmailTokenApi;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_Gmail_clicked();
    void on_pushButton_proxy_clicked();
    void on_codeGen(QString code);
    void on_AccessTokenGen(QString accessToken);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
