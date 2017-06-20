#include "dialog_yh.h"
#include "ui_dialog_yh.h"
#include "variate.h"
#include <QtSql>



Dialog_yh::Dialog_yh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_yh)
{
    ui->setupUi(this);

    //ui->label->setText(honely);
    //Dialog *dlg = new Dialog;
        //关联信号和槽函数

    //dlg->show();

}

Dialog_yh::~Dialog_yh()
{
    delete ui;
}
void Dialog_yh::receiveshow()
{
    this->show();//显示对话框

}
void Dialog_yh::receiveData(QString data)
{
    this->ui->label->setText(data);//获取传递过来的数据
    honely=data;
}

void Dialog_yh::on_pushButton_clicked()
{

    QSqlQueryModel *modelT = new QSqlQueryModel();


    this->ui->tableView->setModel(modelT);
    modelT->setQuery("select bno,name,zz,cbs,sTime,eTime from test2 where sno = '"+honely+"'");
    if(modelT->rowCount()==0){
        QMessageBox::warning(this,"提示","~您没有借阅图书~");
    }else{
           // modelT->select();
        modelT->setHeaderData(0,Qt::Horizontal,tr("`图书编号`"));
        modelT->setHeaderData(1,Qt::Horizontal,tr("`书名`"));
        modelT->setHeaderData(2,Qt::Horizontal,tr("`作者`"));
        modelT->setHeaderData(3,Qt::Horizontal,tr("`出版社`"));
        modelT->setHeaderData(4,Qt::Horizontal,tr("借出时间"));
        modelT->setHeaderData(5,Qt::Horizontal,tr("应还时间"));
        ui->tableView->show();
    }

}

void Dialog_yh::on_pushButton_2_clicked()
{
    QString flag;
    flag='1';

    QSqlQueryModel *modelT = new QSqlQueryModel();

    this->ui->tableView->setModel(modelT);
    modelT->setQuery("select bno,name,zz,cbs,sTime,eTime from test2 where sno = '"+honely+"' and flag = '"+flag+"'");
    if(modelT->rowCount()==0){
        QMessageBox::warning(this,"提示","~您没有借阅图书~");
    }else{
           // modelT->select();
        modelT->setHeaderData(0,Qt::Horizontal,tr("`图书编号`"));
        modelT->setHeaderData(1,Qt::Horizontal,tr("`书名`"));
        modelT->setHeaderData(2,Qt::Horizontal,tr("`作者`"));
        modelT->setHeaderData(3,Qt::Horizontal,tr("`出版社`"));
        modelT->setHeaderData(4,Qt::Horizontal,tr("借出时间"));
        modelT->setHeaderData(5,Qt::Horizontal,tr("应还时间"));
        ui->tableView->show();
    }
}


void Dialog_yh::on_pushButton_3_clicked()
{
    QString old,pwd1,pwd2,pwd;
    old=ui->lineEdit->text();
    pwd1=ui->lineEdit_2->text();
    pwd2=ui->lineEdit_3->text();
    qDebug()<<old;
    if(old.isEmpty() || pwd1.isEmpty() || pwd2.isEmpty()){
        QMessageBox::information(this,"提示","~请检查填写信息~");
    }else{
        if(pwd1==pwd2){
            QSqlQuery query;
            query.exec("select pwd from yhxx where name = '"+honely+"'");
            while(query.next())
                       {
                        pwd = query.value(0).toString();
                       qDebug()<<pwd;
                        }
            if(pwd==old){
                QSqlQuery query2;
                query2.exec("update yhxx set pwd = '"+pwd1+"' where name = '"+honely+"'");
                QMessageBox::information(this,"提示","!修改成功!");
                this->ui->lineEdit->clear();
                this->ui->lineEdit_2->clear();
                this->ui->lineEdit_3->clear();
                this->ui->lineEdit->setFocus();
            }else{
                QMessageBox::information(this,"提示","!密码错误!");
                this->ui->lineEdit->clear();
                this->ui->lineEdit_2->clear();
                this->ui->lineEdit_3->clear();
                this->ui->lineEdit->setFocus();
            }
        }else{
            QMessageBox::information(this,"提示","!两次输入不同!");
            this->ui->lineEdit->clear();
            this->ui->lineEdit_2->clear();
            this->ui->lineEdit_3->clear();
            this->ui->lineEdit->setFocus();
        }

    }
}

void Dialog_yh::on_pushButton_4_clicked()
{
    QFont ft;
    ft.setPointSize(14);

    QString znum,cnum,dnum,max;
    QSqlQuery query,query1,query2,query3;
    query.exec("select maxNum from jyxx where name = '"+honely+"'");
    while(query.next()){
        max = query.value(0).toString();
        qDebug()<<max;
        ui->label_13->setText(max);
        ui->label_13->setFont(ft);
    }

    query1.exec("select chaoqiNum from jyxx where name = '"+honely+"'");
    while(query1.next()){
        cnum = query1.value(0).toString();
        qDebug()<<cnum;
        ui->label_9->setText(cnum);
        ui->label_9->setFont(ft);
    }

    query2.exec("select yijieNum from jyxx where name = '"+honely+"'");
    while(query2.next()){
        znum = query2.value(0).toString();
        qDebug()<<znum;
        ui->label_7->setText(znum);
        ui->label_7->setFont(ft);
    }
    QString flag;
    flag='1';
    query3.exec("select COUNT(sno) from bookread where flag='"+flag+"' and sno = '"+honely+"'");
    while(query3.next()){
        dnum = query3.value(0).toString();
        qDebug()<<dnum;
        ui->label_11->setText(dnum);
        ui->label_11->setFont(ft);
    }



}
