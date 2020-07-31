#include "gmailtokenapi.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include "util.h"
QGmailTokenApi::QGmailTokenApi()
{

}

QGmailTokenApi::~QGmailTokenApi()
{

}

void QGmailTokenApi::buildGmailAccountFromAuthResponse(QString code)
{
    QString postUrl = "https://www.googleapis.com/oauth2/v4/token";

    QString localUrl = Util::encodeURIComponent(LOCAL_REDIRECT_URI + QString::number(LOCAL_SERVER_PORT));
	QString bodyInfo = "code=" + Util::encodeURIComponent(code) + 
        "&client_id=" + Util::encodeURIComponent(GMAIL_CLIENT_ID) +
        "&redirect_uri=" + localUrl +
        "&grant_type=" + Util::encodeURIComponent("authorization_code");

    QByteArray content =  bodyInfo.toUtf8();
	//int contentLength = content.length();

	setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded;charset=UTF-8");
	//setHeader(QNetworkRequest::ContentLengthHeader, contentLength);

   
    post(postUrl, content);
}


void QGmailTokenApi::requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode)
{
    Q_UNUSED(reply);
    int code = EC_UNKNOWN;
    bool ok = false;
    QString msg = "Unknown error";
    if (statusCode == 200) {
        QJsonParseError jsonError;
        QJsonDocument resJsonDoc = QJsonDocument::fromJson(data, &jsonError);
        if (jsonError.error == QJsonParseError::NoError) {
            if(resJsonDoc.isObject()){
                QVariantMap result = resJsonDoc.toVariant().toMap();
               
                //ok = result["ok"].toBool();
                //if (ok)
                //{
					QString accessToken = result["access_token"].toString();
                    QString refreshToken = result["refresh_token"].toString();
                    int expiresIn = result["expires_in"].toInt();
                    emit accessTokenGen(accessToken);
     //           }
     //           else {
					//code = result["status"].toInt();
					//msg = result["statusText"].toString();
					////Gmail OAuth Code exchange returned ${resp.status} ${resp.statusText}: ${JSON.stringify(json)
     //           }
                
                //QString info = QString("start up finish! code: %1  msg: %2").arg(QString::number(code)).arg(msg);
            }
        }
    }
}
