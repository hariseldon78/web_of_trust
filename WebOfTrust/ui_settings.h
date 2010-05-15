/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Sun May 16 01:31:16 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsClass
{
public:
    QDialogButtonBox *buttonBox;
    QTabWidget *tabWidget;
    QWidget *personali;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *nomeUtenteLabel;
    QLineEdit *nomeUtenteLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *chiaveGpgLabel;
    QLineEdit *chiaveGpgLineEdit;
    QWidget *sistema;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *dotPathLabel;
    QLineEdit *dotPathLineEdit;

    void setupUi(QDialog *SettingsClass)
    {
        if (SettingsClass->objectName().isEmpty())
            SettingsClass->setObjectName(QString::fromUtf8("SettingsClass"));
        SettingsClass->resize(689, 497);
        buttonBox = new QDialogButtonBox(SettingsClass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 430, 611, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(SettingsClass);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(30, 10, 611, 401));
        personali = new QWidget();
        personali->setObjectName(QString::fromUtf8("personali"));
        formLayoutWidget_2 = new QWidget(personali);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 10, 571, 331));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        nomeUtenteLabel = new QLabel(formLayoutWidget_2);
        nomeUtenteLabel->setObjectName(QString::fromUtf8("nomeUtenteLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, nomeUtenteLabel);

        nomeUtenteLineEdit = new QLineEdit(formLayoutWidget_2);
        nomeUtenteLineEdit->setObjectName(QString::fromUtf8("nomeUtenteLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, nomeUtenteLineEdit);

        emailLabel = new QLabel(formLayoutWidget_2);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, emailLabel);

        emailLineEdit = new QLineEdit(formLayoutWidget_2);
        emailLineEdit->setObjectName(QString::fromUtf8("emailLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, emailLineEdit);

        chiaveGpgLabel = new QLabel(formLayoutWidget_2);
        chiaveGpgLabel->setObjectName(QString::fromUtf8("chiaveGpgLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, chiaveGpgLabel);

        chiaveGpgLineEdit = new QLineEdit(formLayoutWidget_2);
        chiaveGpgLineEdit->setObjectName(QString::fromUtf8("chiaveGpgLineEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, chiaveGpgLineEdit);

        tabWidget->addTab(personali, QString());
        sistema = new QWidget();
        sistema->setObjectName(QString::fromUtf8("sistema"));
        formLayoutWidget = new QWidget(sistema);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 571, 331));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        dotPathLabel = new QLabel(formLayoutWidget);
        dotPathLabel->setObjectName(QString::fromUtf8("dotPathLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, dotPathLabel);

        dotPathLineEdit = new QLineEdit(formLayoutWidget);
        dotPathLineEdit->setObjectName(QString::fromUtf8("dotPathLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, dotPathLineEdit);

        tabWidget->addTab(sistema, QString());

        retranslateUi(SettingsClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SettingsClass);
    } // setupUi

    void retranslateUi(QDialog *SettingsClass)
    {
        SettingsClass->setWindowTitle(QApplication::translate("SettingsClass", "Settings", 0, QApplication::UnicodeUTF8));
        nomeUtenteLabel->setText(QApplication::translate("SettingsClass", "Nome utente", 0, QApplication::UnicodeUTF8));
        emailLabel->setText(QApplication::translate("SettingsClass", "Email", 0, QApplication::UnicodeUTF8));
        chiaveGpgLabel->setText(QApplication::translate("SettingsClass", "Chiave gpg", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(personali), QApplication::translate("SettingsClass", "&Personali", 0, QApplication::UnicodeUTF8));
        dotPathLabel->setText(QApplication::translate("SettingsClass", "dot path", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(sistema), QApplication::translate("SettingsClass", "&Sistema", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsClass: public Ui_SettingsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
