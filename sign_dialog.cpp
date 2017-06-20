#include "sign_dialog.h"
#include "ui_sign_dialog.h"
#include <QMessageBox>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlTableModel>

sign_Dialog::sign_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_Dialog)
 /*
  ,
    mDbconnection("127.0.0.1",
                  "SQL SERVER",
                  "sa",
                  "123456",
                  "lib",
                  true)
*/
{
    ui->setupUi(this);
    mModel = nullptr;
    this->ui->lineEdit_pwd->setEchoMode(QLineEdit::Password);
}

sign_Dialog::~sign_Dialog()
{
    delete ui;
}
void sign_Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void sign_Dialog::on_pushButton_clicked()
{
   // this->hide();//隐藏登录对话框
   // emit showmainwindow();//显示主窗口

    QString nam,pwd;
    nam = this->ui->lineEdit_nam->text();
    pwd = this->ui->lineEdit_pwd->text();

    QString error;
    /*
    if(!mDbc.openDatabse(&error)){
        QMessageBox::critical(this,"Error",error);
        return;
    }
    */
    if(mModel == nullptr){
        mModel = new QSqlQueryModel(this);
        //mModel->setQuery("SELECT * FROM YHXX");
        //ui->tableView->setModel(mModel);

        model.setTable("yhxx");
        model.setFilter(tr("name = '%1' and pwd = '%2'").arg(nam).arg(pwd));
        model.select();
        if(model.rowCount()==1)//查询到有一个结果
            {
                //accept();//隐含窗口，并返回结果QDialg::Accepted
                this->hide();
                emit showmainwindow();
            }else
            {
                QMessageBox::warning(this, tr("warn"), tr("用户名或者密码不正确"));
                this->ui->lineEdit_nam->clear();
                this->ui->lineEdit_pwd->clear();
                this->ui->lineEdit_nam->setFocus();
            }
    } else {
        //mModel->setQuery("SELECT * FROM YHXX");

        //mModel->setQuery("SELECT * FROM YHXX");
        //ui->tableView->setModel(mModel);
        model.setTable("yhxx");
        model.setFilter(tr("name = '%1' and pwd = '%2'").arg(nam).arg(pwd));
        model.select();
        if(model.rowCount()==1)//查询到有一个结果
            {
                //accept();//隐含窗口，并返回结果QDialg::Accepted
                this->hide();
                emit showmainwindow();
            }else
            {
                QMessageBox::warning(this, tr("warn"), tr("用户名或者密码不正确"));
                this->ui->lineEdit_nam->clear();
                this->ui->lineEdit_pwd->clear();
                this->ui->lineEdit_nam->setFocus();
            }

    }



/*
    if(nam==tr("qwe")&&pwd==tr("123")){
        this->hide();
        emit showmainwindow();
    }
    else{
        QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误!"),QMessageBox::Yes);
    }
*/

/*
    if(this->ui->lineEdit_nam->text().trimmed()== tr("admin") &&
         this->ui->lineEdit_pwd->text().trimmed()==tr("admin"))
      {
          accept();
      }
      else
      {
          QTextCodec::setCodecForTr( QTextCodec::codecForName("GBK") );
          QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误!"),QMessageBox::Yes);
          this->ui->lineEdit_nam->clear();
          this->ui->lineEdit_pwd->clear();
          this->ui->lineEdit_nam->setFocus();
      }
  */
    }





void sign_Dialog::receiveshow()
{
    this->show();//显示登录对话框

}

void sign_Dialog::on_pushButton_cancel_clicked()
{
    emit quit();//发射退出信号
}
