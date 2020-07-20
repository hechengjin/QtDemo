#include "dialog.h"
#include "datadefine.h"
#include <QApplication>
#include "filterwidget.h"
#include <QMessageBox>
#include "mySortFilterProxyModel.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    resize(446, 404);



    reshData();


    _vLayout = new QVBoxLayout(this);
    _vLayout->setSpacing(6);
    _vLayout->setContentsMargins(11, 11, 11, 11);
    _vLayout->setObjectName(QStringLiteral("_vLayout"));

    _filterWidget = new FilterWidget(this);
    _filterWidget->setObjectName(QStringLiteral("_filterWidget"));
    _vLayout->addWidget(_filterWidget);


    _mailFolderTree = new QTreeView(this);
    _mailFolderTree->setObjectName(QStringLiteral("_mailFolderTree"));
    _mailFolderModel = new TreeModel();

    _mailFolderModel->setupModelData(vecFolderData);

    _sortFilterProxyModel = new MySortFilterProxyModel;
    _sortFilterProxyModel->setSourceModel(_mailFolderModel);
    _mailFolderTree->setModel(_sortFilterProxyModel);

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
    connect(_filterWidget, &FilterWidget::filterChanged, this, &Dialog::textFilterChanged);

    setStyleSheet(getAllFileContent(":/style/style1.qss"));

}

Dialog::~Dialog()
{

}

void Dialog::reshData()
{
    MailFolderInfo* mfiHotmail = new MailFolderInfo();
    mfiHotmail->id = 1;
    mfiHotmail->showName = "bigdata_fire@hotmail.com";
    mfiHotmail->parentId = 0;
    mfiHotmail->realName = "bigdata_fire@hotmail.com";
    mfiHotmail->pathName = "/";
    mfiHotmail->serverID = 1;
    vecFolderData.push_back(mfiHotmail);
    MailFolderInfo* mfiInbox = new MailFolderInfo();
    mfiInbox->id = 2;
    mfiInbox->showName = "收件箱";
    mfiInbox->parentId = 1;
    mfiInbox->realName = "INBOX";
    mfiInbox->pathName = "INBOX";
    mfiInbox->serverID = 1;
    vecFolderData.push_back(mfiInbox);
    MailFolderInfo* mfiSent = new MailFolderInfo();
    mfiSent->id = 3;
    mfiSent->showName = "已发送";
    mfiSent->parentId = 1;
    mfiSent->realName = "Sent";
    mfiSent->pathName = "Sent";
    mfiSent->serverID = 1;
    vecFolderData.push_back(mfiSent);
    MailFolderInfo* mfiHotmail2 = new MailFolderInfo();
    mfiHotmail2->id = 4;
    mfiHotmail2->showName = "fire@hotmail->com";
    mfiHotmail2->parentId = 0;
    mfiHotmail2->realName = "fire@hotmail->com";
    mfiHotmail2->pathName = "/";
    mfiHotmail2->serverID = 1;
    vecFolderData.push_back(mfiHotmail2);
    MailFolderInfo* mfiSent2 = new MailFolderInfo();
    mfiSent2->id = 5;
    mfiSent2->showName = "已发送";
    mfiSent2->parentId = 4;
    mfiSent2->realName = "Sent";
    mfiSent2->pathName = "Sent";
    mfiSent2->serverID = 1;
    vecFolderData.push_back(mfiSent2);
}
void Dialog::textFilterChanged()
{
//    QMessageBox msgBox;
//    msgBox.setText("changed.");
//    msgBox.exec();
    _sortFilterProxyModel->setSearchKey(_filterWidget->text());
}

void Dialog::on__btnStyle1_clicked()
{
    qDeleteAll(vecFolderData);
    vecFolderData.clear();
    reshData();
    _mailFolderModel->setupModelData(vecFolderData);
     //setStyleSheet(getAllFileContent(":/style/style1.qss"));

}

void Dialog::on__btnStyle2_clicked()
{
     setStyleSheet(getAllFileContent(":/style/style2.qss")); //qApp->
}
