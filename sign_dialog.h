#ifndef SIGN_DIALOG_H
#define SIGN_DIALOG_H

#include <QDialog>
#include "databaseconnet.h"
#include <QtSql/QSqlTableModel>

namespace Ui {
class sign_Dialog;
}

class QSqlQueryModel;

class sign_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit sign_Dialog(QWidget *parent = 0);
    ~sign_Dialog();

protected:
    void changeEvent(QEvent *e);

private slots:

    void on_pushButton_clicked();//与login关联的槽函数
    void receiveshow();//与relogin中发射的信号关联的槽函数
    void on_pushButton_cancel_clicked();//与exit关联的槽函数
signals:
    void showmainwindow();//显示主窗口信号
    void quit();//退出信号


private:
    Ui::sign_Dialog *ui;
   // Databaseconnet mDbconnection;
    QSqlQueryModel *mModel;
    QSqlTableModel model;
};

#endif // SIGN_DIALOG_H
