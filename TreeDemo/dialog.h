#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTreeView>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

#include "treeitem.h"
#include "treemodel.h"
class FilterWidget;
class MySortFilterProxyModel;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();


    void reshData();
private slots:
    void on__btnStyle1_clicked();
    void on__btnStyle2_clicked();
    void textFilterChanged();

private:
    FilterWidget *_filterWidget;
    QTreeView* _mailFolderTree;
    QVBoxLayout* _vLayout;
    QHBoxLayout* _hLayoutStyle;

    TreeModel* _mailFolderModel;
    MySortFilterProxyModel * _sortFilterProxyModel;
    QPushButton *_btnStyle1;
    QSpacerItem *_horizontalSpacer;
    QPushButton *_btnStyle2;

    QVector<MailFolderInfo*> vecFolderData;
};



#endif // DIALOG_H
