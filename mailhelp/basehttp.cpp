#include "basehttp.h"
#include <QThread>
QBaseHttp::QBaseHttp(QObject *parent) : QObject(parent)
{
	settings = nullptr;
	/*httpRequest.setRawHeader("Accept", API_ACCEPT);
	httpRequest.setRawHeader("User-Agent", API_USER_AGENT);
	httpRequest.setRawHeader("X-XXX-API-Key", API_KEY);
	httpRequest.setRawHeader("X-XXX-API-Secret", API_SECRET);
	httpRequest.setRawHeader("Accept-Encoding", "gzip, deflate");
	httpRequest.setRawHeader("Content-Type", "application/json");

	settings = new QSettings("XXX");
	QString id = settings->value(SETTING_ACCOUNT_ID, "").toString();
	QString token = settings->value(SETTING_ACCOUNT_TOKEN, "").toString();

	if (!id.isEmpty()) {
		httpRequest.setRawHeader("X-XXX-User-ID", id.toStdString().c_str());
	}

	if (!token.isEmpty()) {
		httpRequest.setRawHeader("X-XXX-User-Token", token.toStdString().c_str());
	}

	qDebug() << "BaseAPI...id:" << id << " token:" + token;*/

	QObject::connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
}

QBaseHttp::~QBaseHttp()
{
    networkAccessManager.disconnect();
	if (settings) {
		delete settings;
		settings = nullptr;
	}
}

void QBaseHttp::setRawHeader(const QByteArray& headerName, const QByteArray& value)
{
    //httpRequest.setRawHeader("Content-Type", "application/json");
    httpRequest.setRawHeader(headerName, value);
}

void QBaseHttp::setHeader(QNetworkRequest::KnownHeaders header, const QVariant& value)
{
    httpRequest.setHeader(header, value);
}

void QBaseHttp::get(const QString url)
{
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.get(httpRequest);
}

void QBaseHttp::post(const QString url, const QByteArray &data)
{
//    qDebug() << "BaseHttp::post thread Id:" << QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0'));
//    QLoggingLib::instance().info("BaseHttp::post thread Id:" + QString::number((uint64_t)QThread::currentThreadId()), LMV_NET);
//    QLoggingLib::instance().info("BaseHttp::post thread: + " + QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0')));
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.post(httpRequest, data);
}

void QBaseHttp::serviceRequestFinished(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
 //   qDebug() << "BaseHttp::serviceRequestFinished thread Id:" << QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0'));
//    QLoggingLib::instance().info("BaseHttp::serviceRequestFinished thread Id:" + QString::number((uint64_t)QThread::currentThreadId()), LMV_NET);
//    QLoggingLib::instance().info("BaseHttp::serviceRequestFinished thread: + " + QStringLiteral("@0x%1").arg(quintptr(QThread::currentThreadId()), 16, 16, QLatin1Char('0')));
//    qDebug() << "BaseAPI...serviceRequestFinished...statusCode:" << statusCode;

    if(reply->error() == QNetworkReply::NoError) {
        requestFinished(reply, reply->readAll(), statusCode);
    } else {
        requestFinished(reply, "", statusCode);
    }

    // At the end of that slot, we won't need it anymore
    reply->deleteLater();
}
