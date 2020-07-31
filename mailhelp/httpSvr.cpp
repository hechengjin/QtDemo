#include "httpSvr.h"
#include <QFile>
#include <QChar>
using namespace std;
#include <QtCore/QDebug>
httpSvr::httpSvr(quint16 port, QObject* parent) : QObject(parent)
{
	_port = port;
	socket = 0; // 客户端socket
	server = new QTcpServer(this);
	connect(server, SIGNAL(newConnection()), this, SLOT(myConnection()));
	//qDebug() << "Echoserver listening on port" << port;
	if (server->listen(QHostAddress::Any, port)) {
		//qDebug() << "success";
	}
	else {
		//qDebug() << "failed";
	}
}

int httpSvr::port() {
	return _port;
}

void httpSvr::readMessage() {
	QByteArray ary = socket->readAll();
	//qDebug() << ary << endl;
	QString readmsg = QString(ary);
	//GET ?code=4/2gGyZEhTz4o_CCKDNPZYpi2xraXs-9gioZJlu2HF6D5azcOOp7kWb7Kck2pmxbg2uoWEAsk1horqyIxq2-UF2O8&scope=email%20profile%20https://www.googleapis.com/auth/userinfo.email%20https://www.googleapis.com/auth/userinfo.profile%20https://mail.google.com/%20https://www.googleapis.com/auth/contacts%20https://www.googleapis.com/auth/calendar%20openid&authuser=0&prompt=consent
	// 通过URL取文件路径，具体看下面说明
	QStringList msgList = readmsg.split('\n');
	QString getURL = msgList.first();
	getURL.replace("GET /", "");
	getURL.replace(" HTTP/1.1", "");
	getURL.replace("\r", "").replace("\n", "");
	getURL.trimmed();
	//URL解码
	QByteArray ba;
	QString getPath = ba.fromPercentEncoding(getURL.toUtf8());
	QStringList msgList2 = getPath.split('&');
	QString getURL2 = msgList2.first();
	QStringList msgList3 = getURL2.split('=');
	if (msgList3.size()>1)
	{
		QString code = msgList3.at(1);
		emit codeGen(code);
	}
	

	// 模拟http协议
	socket->write("HTTP/1.1 302 Moved Permanently\r\n");
	socket->write("Content-Type: text/html;charset=uft-8\r\n");
	socket->write("Location: https://id.getmailspring.com/oauth/finished\r\n");
	socket->flush();
	connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
	socket->disconnectFromHost();
}

void httpSvr::myConnection()
{
	socket = server->nextPendingConnection();
	if (socket) {
		connect(socket, SIGNAL(disconnected()), socket, SLOT(deleteLater()));
		connect(socket, SIGNAL(readyRead()), this, SLOT(readMessage())); //有可读的信息，触发读函数槽
	}
}

httpSvr::~httpSvr()
{
	if (socket)
		socket->close();
}