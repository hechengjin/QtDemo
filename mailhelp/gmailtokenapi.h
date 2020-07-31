#ifndef QGMAILTOKENAPI_H
#define QGMAILTOKENAPI_H

#include <QObject>
#include "basehttp.h"
#include "common.h"

class QGmailTokenApi : public QBaseHttp
{
    Q_OBJECT
public:
    QGmailTokenApi();
    ~QGmailTokenApi();
public:
    void buildGmailAccountFromAuthResponse(QString code);
protected:
    void requestFinished(QNetworkReply* reply, const QByteArray data, const int statusCode);
signals:
	void accessTokenGen(QString accessToken);
};

#endif // QGMAILTOKENAPI_H
