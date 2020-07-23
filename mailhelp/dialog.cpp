#include "dialog.h"
#include "ui_dialog.h"
#include <QByteArray>
#include <QtDebug>
#include <QMessageBox>

static mailcore::String* password = NULL;
static mailcore::String* displayName = NULL;
static mailcore::String* email = NULL;

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

static void testIMAP()
{
	mailcore::IMAPSession* session;
	mailcore::ErrorCode error;

	session = new mailcore::IMAPSession();
	session->setHostname(MCSTR("imap.139.com"));
	session->setPort(143);
	session->setUsername(email);
	session->setPassword(password);
	session->setConnectionType(mailcore::ConnectionTypeClear);

	mailcore::IMAPMessagesRequestKind requestKind = (mailcore::IMAPMessagesRequestKind)
		(mailcore::IMAPMessagesRequestKindHeaders | mailcore::IMAPMessagesRequestKindStructure |
			mailcore::IMAPMessagesRequestKindInternalDate | mailcore::IMAPMessagesRequestKindHeaderSubject |
			mailcore::IMAPMessagesRequestKindFlags);
	//mailcore::Array * messages = session->fetchMessagesByUID(MCSTR("INBOX"),
	//                                                         requestKind, mailcore::IndexSet::indexSetWithRange(mailcore::RangeMake(1, UINT64_MAX)), NULL, &error);
	mailcore::Array* messages = session->fetchMessagesByNumber(MCSTR("INBOX"),
		requestKind, mailcore::IndexSet::indexSetWithRange(mailcore::RangeMake(0, 3)), NULL, &error);

	MCLog("%s", MCUTF8DESC(messages));

	session->release();
}

void Dialog::on_pushButton_clicked()
{
    //base64测试
    //QString sub = QByteArray::fromBase64("5ZKM6YCa6KGM6K+BLeWvhueggeWPmOabtA==");
    //QMessageBox msgBox;
    //  msgBox.setText(sub);
    //  msgBox.exec();
	mailcore::setICUDataDirectory(MCSTR("/usr/local/share/icu"));

	email = MCSTR("15313159857@139.com");
	password = MCSTR("9857139i94");
	displayName = MCSTR("139_9857");

	mailcore::AutoreleasePool* pool = new mailcore::AutoreleasePool();
	MCLogEnabled = 1;

	testIMAP();

    pool->release();
}
