#include "dialog.h"
#include "datadefine.h"
#include <QApplication>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(446, 404);

    QVector<MailFolderInfo> vecFolderData;
    MailFolderInfo mfiHotmail;
    mfiHotmail.id = 1;
    mfiHotmail.showName = "bigdata_fire@hotmail.com";
    mfiHotmail.parentId = 0;
    mfiHotmail.realName = "bigdata_fire@hotmail.com";
    mfiHotmail.pathName = "/";
    mfiHotmail.serverID = 1;
    vecFolderData.push_back(mfiHotmail);
    MailFolderInfo mfiInbox;
    mfiInbox.id = 2;
    mfiInbox.showName = "收件箱";
    mfiInbox.parentId = 1;
    mfiInbox.realName = "INBOX";
    mfiInbox.pathName = "INBOX";
    mfiInbox.serverID = 1;
    vecFolderData.push_back(mfiInbox);
    MailFolderInfo mfiSent;
    mfiSent.id = 3;
    mfiSent.showName = "已发送";
    mfiSent.parentId = 1;
    mfiSent.realName = "Sent";
    mfiSent.pathName = "Sent";
    mfiSent.serverID = 1;
    vecFolderData.push_back(mfiSent);


    _vLayout = new QVBoxLayout(this);
    _vLayout->setSpacing(6);
    _vLayout->setContentsMargins(11, 11, 11, 11);
    _vLayout->setObjectName(QStringLiteral("_vLayout"));
    _mailFolderTree = new QTreeView(this);
    _mailFolderTree->setObjectName(QStringLiteral("_mailFolderTree"));
    _mailFolderModel = new TreeModel();

    _mailFolderModel->setupModelData(vecFolderData);
    _mailFolderTree->setModel(_mailFolderModel);

    _vLayout->addWidget(_mailFolderTree);

    _hLayoutStyle = new QHBoxLayout(this);
    _hLayoutStyle->setSpacing(6);
    _hLayoutStyle->setObjectName(QStringLiteral("_hLayoutStyle"));
    _btnStyle1 = new QPushButton(this);
    _btnStyle1->setObjectName(QStringLiteral("_btnStyle1"));
    _btnStyle1->setText("样式1");
    _hLayoutStyle->addWidget(_btnStyle1);
    _btnStyle2 = new QPushButton(this);
    _btnStyle2->setObjectName(QStringLiteral("_btnStyle2"));
    _btnStyle2->setText("样式2");
    _hLayoutStyle->addWidget(_btnStyle2);
    _horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    _hLayoutStyle->addItem(_horizontalSpacer);


    _vLayout->addLayout(_hLayoutStyle);


    connect(_btnStyle1,SIGNAL(clicked()),this,SLOT(on__btnStyle1_clicked()));
    connect(_btnStyle2,SIGNAL(clicked()),this,SLOT(on__btnStyle2_clicked()));

    setStyleSheet(getAllFileContent(":/style/style1.qss"));

}

Dialog::~Dialog()
{

}

void Dialog::on__btnStyle1_clicked()
{
     setStyleSheet(getAllFileContent(":/style/style1.qss"));
}

void Dialog::on__btnStyle2_clicked()
{
     setStyleSheet(getAllFileContent(":/style/style2.qss")); //qApp->
}
