#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTreeView>
#include <QVBoxLayout>
#include "treeitem.h"
#include "treemodel.h"
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QTreeView* _mailFolderTree;
    QVBoxLayout* _vLayout;

    TreeModel* _mailFolderModel;
};

#endif // DIALOG_H
