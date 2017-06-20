#ifndef DATABASECONNET_H
#define DATABASECONNET_H

#include<QtSql/QSqlDatabase>

class Databaseconnet
{
public:
    Databaseconnet(const QString &server,
                   const QString &driver,
                   const QString &user,
                   const QString &password,
                   const QString &databaseName,
                   bool trustedConnection = true);
    bool openDatabse(QString *error = nullptr);
private:
    QSqlDatabase mDatabase;

    QString mServer;
    QString mDriver;
    QString mUser;
    QString mPassword;
    QString mDatabaseName;
    bool mTrustedConnection;
};

#endif // DATABASECONNET_H
