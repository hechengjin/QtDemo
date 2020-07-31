#include "util.h"
QString Util::encodeURIComponent(QString orgUrl) {
	QByteArray ba = orgUrl.toUtf8();
	QByteArray byteArrayPercentEncoded = ba.toPercentEncoding();
	return  QString(byteArrayPercentEncoded);
}

