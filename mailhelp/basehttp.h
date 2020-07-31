#ifndef QBASEHTTP_H
#define QBASEHTTP_H

#include <QObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QSettings>


class QBaseHttp : public QObject
{
    Q_OBJECT
public:
    explicit QBaseHttp(QObject *parent = nullptr);
    ~QBaseHttp();

    void setRawHeader(const QByteArray& headerName, const QByteArray& value);
    void setHeader(QNetworkRequest::KnownHeaders header, const QVariant& value);
    void get(const QString url);
    void post(const QString url, const QByteArray &data);
protected:
    //声明了一个纯虚函数，使得子类根据自己的情况进行重写
    virtual void requestFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) = 0;

public slots:
    void serviceRequestFinished(QNetworkReply *reply);

private:
    QNetworkRequest httpRequest;
    QNetworkAccessManager networkAccessManager;
    QSettings* settings;
};

#endif // QBASEHTTP_H
