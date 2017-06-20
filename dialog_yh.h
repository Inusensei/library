#ifndef DIALOG_YH_H
#define DIALOG_YH_H

#include <QDialog>
#include <QMessageBox>
#include <QtCharts/chartsnamespace.h>
//#include "temp.h"


namespace Ui {
class Dialog_yh;
}

class Dialog_yh : public QDialog
{
    Q_OBJECT


private slots:
    void receiveshow();
    void receiveData(QString data);   //接收传递过来的数据的槽
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

public:
    explicit Dialog_yh(QWidget *parent = 0);
    ~Dialog_yh();


private:
    Ui::Dialog_yh *ui;
    QString honely;

};

#endif // DIALOG_YH_H
