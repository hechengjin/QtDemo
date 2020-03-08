#include "dialog.h"

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

}

Dialog::~Dialog()
{

}
