#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>
#include <QtSql>
#include "variate.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
/*
  , mDbC("127.0.0.1",
         "SQL Server",
         "sa",
         "123456",
         "lib",
         true)

*/


{
    ui->setupUi(this);
    mModel = nullptr;

    this->ui->lineEdit_5->setEchoMode(QLineEdit::Password);
    QStandardItemModel * head = new QStandardItemModel();
    head->setHorizontalHeaderItem(0,new QStandardItem(tr("图书编号")));
    head->setHorizontalHeaderItem(1,new QStandardItem(tr("书名")));
    head->setHorizontalHeaderItem(2,new QStandardItem(tr("`出版社`")));
    head->setHorizontalHeaderItem(3,new QStandardItem(tr("`作者`")));
    head->setHorizontalHeaderItem(4,new QStandardItem(tr("总数")));
    head->setHorizontalHeaderItem(5,new QStandardItem(tr("可借数")));
    head->setHorizontalHeaderItem(6,new QStandardItem(tr("`预约数`")));
    head->setHorizontalHeaderItem(7,new QStandardItem(tr("`分类`")));
    ui->tableView->setModel(head);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::receivelogin()
{
    this->show();//显示主窗口
}

void MainWindow::on_pushButton_clicked()
{
    //this->hide();//隐藏主窗口
    //emit dlgshow();//发射显示登录对话框信号

    QString name,pwd;
    name = this->ui->lineEdit_6->text();
    pwd = this->ui->lineEdit_5->text();
    //xstr = this->ui->lineEdit_6->text();
    //honely = name;
    emit sendData(ui->lineEdit_6->text());
    if(name.isEmpty()||pwd.isEmpty()){
        QMessageBox::warning(this,"提示","~请检查输入~");
    }else{
//        QSqlQuery queryY;
//        bool value=false;
//        value=queryY.exec("select name from yhxx where name='"+name+"'and pwd='"+pwd+"'");
       QSqlTableModel modelY;

        modelY.setTable("yhxx");
        modelY.setFilter(tr("name = '%1' and pwd = '%2'").arg(name).arg(pwd));

        modelY.select();
        if(modelY.rowCount()==1)//查询到有一个结果
            {
                //accept();//隐含窗口，并返回结果QDialg::Accepted
                //this->hide();
                //xstr = name;
                emit dlgshow();
                this->ui->lineEdit_6->clear();
                this->ui->lineEdit_5->clear();
                this->ui->lineEdit_6->setFocus();
            }else
            {
                QMessageBox::warning(this, tr("!警告!"), tr("用户名或者密码不正确"));
                this->ui->lineEdit_6->clear();
                this->ui->lineEdit_5->clear();
                this->ui->lineEdit_6->setFocus();
            }
    }



    //ui->label_7->setText(name);


}

void MainWindow::on_pushButton_2_clicked()
{

   // emit quit();//发射退出信号
    QString error;
    QString Sname,Szz,Scbs,Sid;
    Sname = this->ui->lineEdit->text();
    Szz = this->ui->lineEdit_2->text();
    Sid = this->ui->lineEdit_3->text();
    Scbs = this->ui->lineEdit_4->text();

    int flag;
    bool n,z,t,c;
    n=Sname.isEmpty();
    z=Szz.isEmpty();
    t=Sid.isEmpty();
    c=Scbs.isEmpty();
    if(!n && z && t && c){
        flag = 1;
    }else if(n && !z && t && c){
        flag = 2;
    }else if(n && z && !t && c){
        flag = 3;
    }else if(n && z && t && !c){
        flag = 4;
    }else if(!n && !z && t && c){
        flag = 5;
    }else if(n && !z && t && !c){
        flag = 6;
    }else if(!n && z && t && !c){
        flag = 7;
    }
    else{
            QMessageBox::information(this,tr("提示"),tr("内容为空"));
        }

//    QSqlTableModel *model = new QSqlTableModel();
//    model->setTable("tsxx");
    QSqlQueryModel *model = new QSqlQueryModel();
//    model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
//    model->setHeaderData(1,Qt::Horizontal,tr("书名"));
//    model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
//    model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
//    model->setHeaderData(4,Qt::Horizontal,tr("总数"));
//    model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
//    model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
//    model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));
    //ui->tableView->setModel(model);
    //设置列宽为文本自动调节
    //ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //隐藏默认序号
    //ui->tableView->verticalHeader()->hide();
    QString str;
    switch (flag) {
    case 1:

//        model->setFilter(tr("name = '%1'").arg(Sname));
//        model->select();

//        //ui->tableView->setModel(model);
//        ui->tableView->show();


        //str="select top 6 * from tsxx where name like '%"+Sname+"%'";
        str="select * from tsxx where name like '%"+Sname+"%'";
        model->setQuery(str);

        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();


        break;
    case 2:

//        model->setFilter(tr("zz = '%1'").arg(Szz));
//        model->select();

       // ui->tableView->setModel(model);
        str="select * from tsxx where zz like '%"+Szz+"%'";
        model->setQuery(str);
        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    case 3:

//        model->setFilter(tr("t# = '%1'").arg(Sid));
//        model->select();

       // ui->tableView->setModel(model);
        str="select * from tsxx where t# like '%"+Sid+"%'";
        model->setQuery(str);
        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    case 4:

//        model->setFilter(tr("cbs = '%1'").arg(Scbs));
//        model->select();

        //ui->tableView->setModel(model);
        str="select * from tsxx where cbs like '%"+Scbs+"%'";
        model->setQuery(str);
        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();

        break;
    case 5:
        str="select * from tsxx where zz like '%"+Szz+"%' and name like '%"+Sname+"%'";
        model->setQuery(str);
        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();
        break;
    case 6:
        str="select * from tsxx where zz like '%"+Szz+"%' and cbs like '%"+Scbs+"%'";
        model->setQuery(str);
        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();
        break;
    case 7:
        str="select * from tsxx where name like '%"+Sname+"%' and cbs like '%"+Scbs+"%'";
        model->setQuery(str);
        model->setHeaderData(0,Qt::Horizontal,tr("图书编号"));
        model->setHeaderData(1,Qt::Horizontal,tr("书名"));
        model->setHeaderData(2,Qt::Horizontal,tr("`出版社`"));
        model->setHeaderData(3,Qt::Horizontal,tr("`作者`"));
        model->setHeaderData(4,Qt::Horizontal,tr("总数"));
        model->setHeaderData(5,Qt::Horizontal,tr("可借数"));
        model->setHeaderData(6,Qt::Horizontal,tr("`预约数`"));
        model->setHeaderData(7,Qt::Horizontal,tr("`分类`"));

        ui->tableView->setModel(model);
        ui->tableView->show();
        break;
    default:
        break;
    }


}

void MainWindow::on_pushButton_3_clicked()
{
    QString name,pwd;
    name = this->ui->lineEdit_6->text();
    pwd = this->ui->lineEdit_5->text();
/*
    QSqlQuery query;

    bool success = query.exec("select g# from gly where pwd='"+pwd+"'");
    query.seek(-1);
    query.next();
    if(query.value(0).toString()==pwd&&success!=false&&pwd!=""){
      emit glyshow();

    }
    */
    QSqlTableModel model;
    model.setTable("gly");
    model.setFilter(tr("name = '%1' and pwd = '%2'").arg(name).arg(pwd));

    model.select();

    if(model.rowCount()==1)//查询到有一个结果
        {
            //accept();//隐含窗口，并返回结果QDialg::Accepted
            //this->hide();
            emit glyshow();
            this->ui->lineEdit_6->clear();
            this->ui->lineEdit_5->clear();
            this->ui->lineEdit_6->setFocus();
        }else
        {
            QMessageBox::warning(this, tr("!警告!"), tr("用户名或者密码不正确"));
            this->ui->lineEdit_6->clear();
            this->ui->lineEdit_5->clear();
            this->ui->lineEdit_6->setFocus();
        }


}

void MainWindow::on_pushButton_4_clicked()
{

}


void MainWindow::on_pushButton_5_clicked()
{

}
