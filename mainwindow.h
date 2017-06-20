#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaseconnet.h"
#include "mylabel.h"
#include <QtSql/QSqlTableModel>
#include <QStandardItemModel>
//#include "temp.h"

namespace Ui {
class MainWindow;
}

class QSqlQueryModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void receivelogin();//与login中发射的信号关联的槽函数
    void on_pushButton_clicked();//与relogin的click()关联的槽函数
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_5_clicked();

signals:
    void dlgshow();//显示登录对话框信号
    void quit();//退出信号
    void glyshow();//管理界面信号
    void sendData(QString);   //用来传递数据的信号

private:
    Ui::MainWindow *ui;
   // Databaseconnet mDbC;
    QSqlQueryModel *mModel;
   // QSqlTableModel model;

    QStandardItemModel *TStyle = new QStandardItemModel();

    int nCurScroller=0; //翻页时的当时滑动条位置
    int pageValue = 6; // 一页显示条数
};

#endif // MAINWINDOW_H
