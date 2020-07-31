#pragma once
#include <QCoreApplication>
#include <QNetworkInterface>
#include <iostream>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>


class  httpSvr : public QObject
{
	Q_OBJECT
public:
	explicit httpSvr(quint16 port, QObject* parent = 0);
	~httpSvr();
	QTcpSocket* socket;
	int port();
public slots:
	void myConnection();
	void readMessage();
private:
	QTcpServer* server;
	quint16 _port;
signals:
	void codeGen(QString code);
};