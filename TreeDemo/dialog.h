#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTreeView>
#include <QVBoxLayout>
#include <QPushButton>

#include "treeitem.h"
#include "treemodel.h"
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void on__btnStyle1_clicked();
    void on__btnStyle2_clicked();

private:
    QTreeView* _mailFolderTree;
    QVBoxLayout* _vLayout;
    QHBoxLayout* _hLayoutStyle;

    TreeModel* _mailFolderModel;
    QPushButton *_btnStyle1;
    QSpacerItem *_horizontalSpacer;
    QPushButton *_btnStyle2;
};

#endif // DIALOG_H
