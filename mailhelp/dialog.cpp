#include "dialog.h"
#include "ui_dialog.h"
#include <QByteArray>
#include <QtDebug>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include "util.h"
#include "common.h"

#define QSTRING2STRING(x) mailcore::String::uniquedStringWithUTF8Characters(x.toStdString().c_str())
static mailcore::String* password = NULL;
static mailcore::String* displayName = NULL;
static mailcore::String* email = NULL;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
	serverPort = LOCAL_SERVER_PORT;
	server = new httpSvr(serverPort);
	QObject::connect(server, &httpSvr::codeGen, this, &Dialog::on_codeGen);
	pGmailTokenApi = new QGmailTokenApi();
	QObject::connect(pGmailTokenApi, &QGmailTokenApi::accessTokenGen, this, &Dialog::on_AccessTokenGen);
}

Dialog::~Dialog()
{
    delete ui;
}
QUrl Dialog::genGmailOAuth2()
{
	//return QUrl("http://www.baidu.com");

		
	QString localUrl = Util::encodeURIComponent(LOCAL_REDIRECT_URI + QString::number(LOCAL_SERVER_PORT));
	QString scope = Util::encodeURIComponent("https://www.googleapis.com/auth/userinfo.email https://www.googleapis.com/auth/userinfo.profile https://mail.google.com/ https://www.googleapis.com/auth/contacts https://www.googleapis.com/auth/calendar");
	QString strUrl = "https://accounts.google.com/o/oauth2/auth?client_id=" + QString(GMAIL_CLIENT_ID) + 
		"&redirect_uri=" + localUrl + "&response_type=code&scope=" + scope +
		"&access_type=offline&select_account"+ Util::encodeURIComponent(" ") +"consent";
	QUrl url = QUrl(strUrl);
	return url;
}



static void testIMAP_GMAIL(QString accessToken)
{
	email = MCSTR("hechengjin.com@gmail.com");
	password = MCSTR("HCJGMi94");
	displayName = MCSTR("hcj");

	mailcore::IMAPSession* session;
	mailcore::ErrorCode error;

	session = new mailcore::IMAPSession();
	session->setHostname(MCSTR("imap.gmail.com")); //imap.googlemail.com imap.gmail.com
	session->setPort(993);
	session->setUsername(email);
	session->setPassword(password);
	session->setConnectionType(mailcore::ConnectionTypeTLS);
	session->setOAuth2Token(QSTRING2STRING(accessToken));
	session->setAuthType(mailcore::AuthTypeXOAuth2);

	session->connect(&error);
	session->login(&error);
	session->select(MCSTR("INBOX"), &error);
	mailcore::IMAPFolderStatus* fs = session->folderStatus(MCSTR("INBOX"), &error);
	MCLog("%d", fs->unseenCount());
	session->release();
}

void Dialog::on_pushButton_Gmail_clicked()
{
	//server = new EchoServer(serverPort, true);
	QDesktopServices::openUrl(genGmailOAuth2());
	//testIMAP_GMAIL("ya29.a0AfH6SMABtywvqk0NrzlgxMWW - Mt2DE5zSAInEvES_UjCBEkDEBRUaTavAOIsnkAoVsbWFjEQqpc35vB33qEshPIcVzilnFuu4MA0NRVwSFM83aMZ5HgtIi_uwEmioHwFtmwWD8PqnolkWWP3DMeW05QnBuZxs7HbcKo");
	//QObject::connect(server, &EchoServer::closed, this, &QCoreApplication::quit);
	//
}




void Dialog::on_codeGen(QString code)
{
	pGmailTokenApi->buildGmailAccountFromAuthResponse(code);
}

void Dialog::on_AccessTokenGen(QString accessToken)
{
	testIMAP_GMAIL(accessToken);
}

static void testIMAP_139()
{
	email = MCSTR("15313159857@139.com");
	password = MCSTR("9857139i94");
	displayName = MCSTR("139_9857");

	mailcore::IMAPSession* session;
	mailcore::ErrorCode error;

	session = new mailcore::IMAPSession();
	session->setHostname(MCSTR("imap.139.com"));
	session->setPort(143);
	session->setUsername(email);
	session->setPassword(password);
	session->setConnectionType(mailcore::ConnectionTypeClear);

	//选择邮件夹 获取未读邮件数量
	session->connect(&error);
	session->login(&error);
	session->select(MCSTR("INBOX"), &error);
	mailcore::IMAPFolderStatus* fs = session->folderStatus(MCSTR("INBOX"), &error);
	MCLog("%d", fs->unseenCount());
	//列出所有邮件夹
	mailcore::Array* folders = session->fetchAllFolders(&error);
	MCLog("%s", MCUTF8DESC(folders));

	//获取邮件头
	//mailcore::IMAPMessagesRequestKind requestKind = (mailcore::IMAPMessagesRequestKind)
	//	(mailcore::IMAPMessagesRequestKindHeaders | mailcore::IMAPMessagesRequestKindStructure |
	//		mailcore::IMAPMessagesRequestKindInternalDate | mailcore::IMAPMessagesRequestKindHeaderSubject |
	//		mailcore::IMAPMessagesRequestKindFlags);
	//mailcore::Array * messages = session->fetchMessagesByUID(MCSTR("INBOX"),
	//                                                         requestKind, mailcore::IndexSet::indexSetWithRange(mailcore::RangeMake(1, UINT64_MAX)), NULL, &error);
	//mailcore::Array* messages = session->fetchMessagesByNumber(MCSTR("INBOX"),
	//	requestKind, mailcore::IndexSet::indexSetWithRange(mailcore::RangeMake(0, 3)), NULL, &error);

	//MCLog("%s", MCUTF8DESC(messages));



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

	//testIMAP_139();
	//testIMAP_GMAIL("");

    pool->release();
}

