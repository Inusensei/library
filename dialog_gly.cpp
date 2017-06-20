#include "dialog_gly.h"
#include "ui_dialog_gly.h"
#include <QtSql/QSqlTableModel>
#include <QtSql>

Dialog_gly::Dialog_gly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_gly)
{
    ui->setupUi(this);
    model = nullptr;


}

Dialog_gly::~Dialog_gly()
{
    delete ui;
}

void Dialog_gly::reshow()
{
    this->show();
}

void Dialog_gly::on_pushButton_3_clicked()
{
    QString tsbh,name,cbs,zz,nums,fenlei,knum;
    int num;
    tsbh = this->ui->lineEdit->text();
    name = this->ui->lineEdit_2->text();
    cbs = this->ui->lineEdit_3->text();
    zz = this->ui->lineEdit_4->text();
    nums = this->ui->lineEdit_5->text();
    knum = this->ui->lineEdit_16->text();
    fenlei=this->ui->comboBox->currentIndex();
    bool ok;
    num=nums.toInt(&ok,10);

    QSqlQuery querys;
    bool value;
    value = querys.exec("insert into tsxx(t#,name,cbs,zz,num,fenlei,stock) values('"+tsbh+"','"+name+"','"+cbs+"','"+zz+"','"+nums+"','"+fenlei+"','"+knum+"')");
    if(value){
        QMessageBox::information(this,"提示","添加成功");

    }else{
        QMessageBox::information(this,"提示","添加失败");
    }

}

void Dialog_gly::on_pushButton_clicked()
{
    QString user;
    user = this->ui->lineEdit_6->text();

    QSqlTableModel *modelT = new QSqlTableModel();
    modelT->setTable("yhjyxx");
    //modelT->setHeaderData(0,Qt::Horizontal,tr("ID"));
    modelT->setHeaderData(0,Qt::Horizontal,tr("姓名"));
    modelT->setHeaderData(1,Qt::Horizontal,tr("密码"));
    modelT->setHeaderData(2,Qt::Horizontal,tr("性别"));
    modelT->setHeaderData(3,Qt::Horizontal,tr("`最大借阅数`"));
    modelT->setHeaderData(4,Qt::Horizontal,tr("`已借阅数`"));
    modelT->setHeaderData(5,Qt::Horizontal,tr("`超期借阅数`"));
    this->ui->tableView->setModel(modelT);

    if(user.isEmpty()){
        //modelT->setQuery("select * from yhjyxx");
        modelT->select();
    }else{
        //modelT->setTable("yhjyxx");
        modelT->setFilter(tr("name = '%1'").arg(user));
        modelT->select();



    }

//    modelT->setFilter(tr("name = '%1'").arg(user));
//    modelT->select();

//    if(modelT.rowCount()==1)
//        {
//        //QMessageBox::information(this, tr("tishi"), tr("suc"));
//        //ui->tableView->setModel(Tmodel);
//        ui->tableView->show();
//    }else{
//        QMessageBox::information(this, tr("tishi"), tr("fail"));
//    }
}

void Dialog_gly::on_pushButton_2_clicked()
{
    QString id,user,pwd,max,sex;

    id = this->ui->lineEdit_10->text();
    user = this->ui->lineEdit_9->text();
    pwd = this->ui->lineEdit_11->text();
    max = this->ui->lineEdit_12->text();
    sex = this->ui->lineEdit_14->text();

    if(user.isEmpty()){
        QMessageBox::information(this,"提示","用户名为空!");
    }else{


        QSqlQuery query,query2;
        bool value,value2;
        value = query.exec("insert into yhxx(id,name,pwd,sex) values('"+id+"','"+user+"','"+pwd+"','"+sex+"')");
        value2 = query2.exec("insert into jyxx(name,maxNum) values('"+user+"','"+max+"')");
        if(value&&value2){
            QMessageBox::information(this,"提示","添加成功");

        }else{
            QMessageBox::information(this,"提示","添加失败");

    }
}

}

void Dialog_gly::on_pushButton_4_clicked()
{
    QString userD;
    userD = this->ui->lineEdit_9->text();

    QSqlQuery query;
    bool value,value2;
    value = query.exec("delete from yhxx where name = '"+userD+"'");
    value2 = query.exec("delete from jyxx where name = '"+userD+"'");
    if(value&&value2){
        QMessageBox::information(this,"提示","~删除成功~");

    }else{
        QMessageBox::information(this,"提示","~删除失败~");

    }
}

void Dialog_gly::on_pushButton_6_clicked()
{
    QString userU,maxU;
    userU = this->ui->lineEdit_9->text();
    maxU = this->ui->lineEdit_12->text();

    QSqlQuery query;
    bool value;
    value = query.exec("update jyxx set maxNum= '"+maxU+"' where name = '"+userU+"'");
    if(value){
        QMessageBox::information(this,"提示","更新成功");

    }else{
        QMessageBox::information(this,"提示","更新失败");

    }

}

void Dialog_gly::on_pushButton_8_clicked()
{
    QString idD;

    idD = this->ui->lineEdit_7->text();
   // numD = this->ui->lineEdit_8->text();

    QSqlQuery queryD;
    bool value;
    value = queryD.exec("delete from tsxx where t# = '"+idD+"'");
    if(value){
        QMessageBox::information(this,"!提示!","!删除成功!");

    }else{
        QMessageBox::information(this,"!提示!","!删除失败!");

    }

}

void Dialog_gly::on_pushButton_5_clicked()
{
    //借书
    QString sno,bno,flag,stime,etime;
    sno = this->ui->lineEdit_8->text();
    bno = this->ui->lineEdit_13->text();
    flag='1';
    QDate time,time2;
    time = QDate::currentDate();
    stime = time.toString("yyyy-MM-dd");
    time2 = QDate::currentDate().addDays(15);
    etime = time2.toString("yyyy-MM-dd");

    QString stock,max,ynum;
    int m,y;
    QSqlQuery query1,query2,query3;
    query2.exec("select stock from tsxx where t#='"+bno+"'");
    while(query2.next()){
        stock = query2.value(0).toString();
        qDebug()<<stock;

    }
    if(stock == '0'){
        QMessageBox::information(this,"提示","可借数目为0");
        return;
    }
    query1.exec("select maxNum from jyxx where name='"+sno+"'");
    while(query1.next()){
        max = query1.value(0).toString();
        qDebug()<<max;
        m=max.toInt();

    }
    query3.exec("select yijieNum from jyxx where name='"+sno+"'");
    while(query3.next()){
        ynum = query3.value(0).toString();
        qDebug()<<ynum;
        y=ynum.toInt();

    }

    if(m<=y){
        QMessageBox::information(this,"提示","~您已达到最大借阅额~");
        return;
    }

    QSqlQuery queryJ;
    bool value;
    value = queryJ.exec("insert into bookread(sno,bno,flag,sTime,eTime) values('"+sno+"','"+bno+"','"+flag+"','"+stime+"','"+etime+"')");
    if(value){
        QMessageBox::information(this,"提示","借书成功");
    }else{
        QMessageBox::information(this,"提示","借书失败");
    }

}

void Dialog_gly::on_pushButton_9_clicked()
{
    QString sno,bno,flag;
    sno = this->ui->lineEdit_8->text();
    bno = this->ui->lineEdit_13->text();
    flag='1';

    QSqlQuery queryH;
    bool value,value2;
    value2 = queryH.exec("select * from bookread where sno='"+sno+"'and bno='"+bno+"'and flag='"+flag+"'");
    if(value2){
        value = queryH.exec("update bookread set flag='0' where sno='"+sno+"'and bno='"+bno+"'");
        if(value){
            QMessageBox::information(this,"提示","还书成功");
        }else{
            QMessageBox::information(this,"提示","还书失败");
        }
    }else{
        //value=false;
        QMessageBox::information(this,"提示","~请核实信息~");
    }

}

void Dialog_gly::on_pushButton_7_clicked()
{
    QString num,id;
    id=ui->lineEdit->text();
    num=ui->lineEdit_5->text();
    if(num.isEmpty() || id.isEmpty()){
        QMessageBox::information(this,"提示","~请检查输入~");

    }else{
        QSqlQuery queryG;
        bool value;
        value = queryG.exec("update tsxx set num = '"+num+"' where t# = '"+id+"'");
        if(value){
            QMessageBox::information(this,"提示","更新成功");
        }else{
            QMessageBox::information(this,"提示","更新失败");
        }
    }
}

void Dialog_gly::on_pushButton_10_clicked()
{
    QString user,flag;
    user = this->ui->lineEdit_8->text();
    flag='1';

    QSqlQueryModel *modelT = new QSqlQueryModel();

//    modelT->setHeaderData(0,Qt::Horizontal,tr("`读者`"));
//    modelT->setHeaderData(1,Qt::Horizontal,tr("`图书编号`"));
//    modelT->setHeaderData(2,Qt::Horizontal,tr("借出时间"));
//    modelT->setHeaderData(3,Qt::Horizontal,tr("应还时间"));

//    this->ui->tableView_2->setModel(modelT);

    if(user.isEmpty()){
        QMessageBox::information(this,"提示","请输入用户名");
    }else{
        //modelT->setTable("yhjyxx");
        //modelT->setFilter(tr("name = '%1'").arg(user)&&tr("flag = '%1'").arg(flag));
        modelT->setQuery("select sno,bno,stime,etime from bookread where sno = '"+user+"' and flag = '"+flag+"'");
        if(modelT->rowCount()==0){
            QMessageBox::warning(this,"错误","~用户不存在~");
        }else{
           // modelT->select();
            modelT->setHeaderData(0,Qt::Horizontal,tr("`读者`"));
            modelT->setHeaderData(1,Qt::Horizontal,tr("`图书编号`"));
            modelT->setHeaderData(2,Qt::Horizontal,tr("借出时间"));
            modelT->setHeaderData(3,Qt::Horizontal,tr("应还时间"));

            this->ui->tableView_2->setModel(modelT);
            ui->tableView_2->show();
        }
}
}

void Dialog_gly::on_pushButton_11_clicked()
{
    QString user,flag;
    user = this->ui->lineEdit_13->text();
    flag='1';

    QSqlQueryModel *modelT = new QSqlQueryModel();

//    modelT->setHeaderData(0,Qt::Horizontal,tr("`读者`"));
//    modelT->setHeaderData(1,Qt::Horizontal,tr("`图书编号`"));
//    modelT->setHeaderData(2,Qt::Horizontal,tr("借出时间"));
//    modelT->setHeaderData(3,Qt::Horizontal,tr("应还时间"));

//    this->ui->tableView_2->setModel(modelT);

    if(user.isEmpty()){
        QMessageBox::information(this,"提示","!请输入图书编号!");
    }else{
        //modelT->setTable("yhjyxx");
        //modelT->setFilter(tr("name = '%1'").arg(user)&&tr("flag = '%1'").arg(flag));
        modelT->setQuery("select bno,sno,stime,etime from bookread where bno = '"+user+"' and flag = '"+flag+"'");
        if(modelT->rowCount()==0){
            QMessageBox::warning(this,"提示","~图书未借出~");
        }else{
           // modelT->select();
            modelT->setHeaderData(0,Qt::Horizontal,tr("`读者`"));
            modelT->setHeaderData(1,Qt::Horizontal,tr("`图书编号`"));
            modelT->setHeaderData(2,Qt::Horizontal,tr("借出时间"));
            modelT->setHeaderData(3,Qt::Horizontal,tr("应还时间"));

            this->ui->tableView_2->setModel(modelT);
            ui->tableView_2->show();
        }
 }
}

void Dialog_gly::on_pushButton_12_clicked()
{
    QString lujing;
    lujing = ui->lineEdit_15->text();
    QSqlQuery query1;
    bool value;
    value=query1.exec("backup database lib to disk='"+lujing+"'");
    if(value){
        QMessageBox::information(this,"提示","备份成功");
    }else{
        QMessageBox::information(this,"提示","备份失败");
    }
}

void Dialog_gly::on_pushButton_13_clicked()
{
    QString lujing;
    lujing = ui->lineEdit_15->text();
    QSqlQuery query1;
    bool value;
    value=query1.exec("restore database kaifang from disk = '"+lujing+"' with move 'lib' to 'E:\\code\\library\\data\\lib.mdf', move 'lib_log' to 'E:\\code\\library\\data\\lib_log.ldf'");
    if(value){
        QMessageBox::information(this,"提示","恢复失败");
    }else{
        QMessageBox::information(this,"提示","恢复成功");
    }
}
