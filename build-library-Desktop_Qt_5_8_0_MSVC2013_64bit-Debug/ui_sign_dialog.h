/********************************************************************************
** Form generated from reading UI file 'sign_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_DIALOG_H
#define UI_SIGN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sign_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_nam;
    QLineEdit *lineEdit_pwd;
    QPushButton *pushButton;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *sign_Dialog)
    {
        if (sign_Dialog->objectName().isEmpty())
            sign_Dialog->setObjectName(QStringLiteral("sign_Dialog"));
        sign_Dialog->resize(313, 309);
        label = new QLabel(sign_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 71, 41));
        label_2 = new QLabel(sign_Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 130, 51, 41));
        lineEdit_nam = new QLineEdit(sign_Dialog);
        lineEdit_nam->setObjectName(QStringLiteral("lineEdit_nam"));
        lineEdit_nam->setGeometry(QRect(140, 80, 121, 21));
        lineEdit_pwd = new QLineEdit(sign_Dialog);
        lineEdit_pwd->setObjectName(QStringLiteral("lineEdit_pwd"));
        lineEdit_pwd->setGeometry(QRect(140, 140, 121, 21));
        pushButton = new QPushButton(sign_Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 240, 91, 31));
        pushButton_cancel = new QPushButton(sign_Dialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        pushButton_cancel->setGeometry(QRect(210, 240, 81, 31));

        retranslateUi(sign_Dialog);

        QMetaObject::connectSlotsByName(sign_Dialog);
    } // setupUi

    void retranslateUi(QDialog *sign_Dialog)
    {
        sign_Dialog->setWindowTitle(QApplication::translate("sign_Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("sign_Dialog", "<html><head/><body><p><span style=\" font-size:14pt;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("sign_Dialog", "<html><head/><body><p><span style=\" font-size:14pt;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("sign_Dialog", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("sign_Dialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sign_Dialog: public Ui_sign_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_DIALOG_H
