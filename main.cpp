#include "mainwindow.h"
#include "sign_dialog.h"
#include "dialog_gly.h"
#include "dialog_yh.h"
#include <QApplication>
#include "databaseconnet.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlerror.h>
#include <QMessageBox>
#include <QTextCodec>



int main(int argc, char *argv[])

{

    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        QTextCodec::setCodecForLocale(codec);

        /*
        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("localhost");
        db.setDatabaseName("lib");
        db.setUserName("sa");
        db.setPassword("123456");
        */

        QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
        db.setHostName("127.0.0.1"); // 如果dsn中已经含有SERVER，可以省略此句
        QString dsn = QString("DRIVER={SQL SERVER};SERVER=127.0.0.1;DATABASE=lib;UID=sa;PWD=123456");
        db.setDatabaseName(dsn);
        if (!db.open())
        {
           // qDebug() << "error opened" << endl;
            QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());

        }
    a.setStyle("fusion");
    //QString honely;
    MainWindow w;
    w.show();
    //sign_Dialog dlg;
    //dlg.show();
    Dialog_gly gly;
    Dialog_yh yh;

/*
    Databaseconnet mDbc(const QString &server,
                        const QString &driver,
                        const QString &user,
                        const QString &password,
                        const QString &databaseName,
                        bool trustedConnection);

    mDbc("127.0.0.1",
             "SQL Server",
             "sa",
             "123456",
             "lib",
             true);
*/
/*
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "lib");
    db.setHostName("127.0.0.1"); // 如果dsn中已经含有SERVER，可以省略此句
    QString dsn = QString("DRIVER={SQL SERVER};SERVER=127.0.0.1;DATABASE=lib;UID=sa;PWD=123456");
    db.setDatabaseName(dsn);
    if(!db.open()) {
            QMessageBox::critical(0,QObject::tr("Database Error"),db.lastError().text());
    }

    */
    //信号与槽之间进行关联


    //QObject::connect(&w,SIGNAL(dlgshow()),&dlg,SLOT(receiveshow()));
    QObject::connect(&w,SIGNAL(sendData(QString)),&yh,SLOT(receiveData(QString)));
    QObject::connect(&w,SIGNAL(dlgshow()),&yh,SLOT(receiveshow()));

    QObject::connect(&w,SIGNAL(glyshow()),&gly,SLOT(reshow()));
    QObject::connect(&w,SIGNAL(quit()),&a,SLOT(quit()));
    //QObject::connect(&dlg,SIGNAL(quit()),&a,SLOT(quit()));



    return a.exec();
}
