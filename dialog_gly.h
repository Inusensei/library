#ifndef DIALOG_GLY_H
#define DIALOG_GLY_H

#include <QDialog>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QMessageBox>
//#include "temp.h"

namespace Ui {
class Dialog_gly;
}

class Dialog_gly : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_gly(QWidget *parent = 0);
    ~Dialog_gly();

private:
    Ui::Dialog_gly *ui;
    QSqlQueryModel *model;
private slots:
    void reshow();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
};

#endif // DIALOG_GLY_H
