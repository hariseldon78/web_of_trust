/********************************************************************************
** Form generated from reading ui file 'weboftrust.ui'
**
** Created: Tue 20. Apr 01:23:13 2010
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WEBOFTRUST_H
#define UI_WEBOFTRUST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebOfTrustClass
{
public:
    QAction *action_Imposta_Fiducia;
    QAction *action_Calcola_Fiducia;
    QAction *action_Emetti;
    QAction *actionImpo_rta;
    QAction *actionE_sporta;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_Certificati;
    QMenu *menu_Fiducia;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WebOfTrustClass)
    {
        if (WebOfTrustClass->objectName().isEmpty())
            WebOfTrustClass->setObjectName(QString::fromUtf8("WebOfTrustClass"));
        WebOfTrustClass->resize(600, 400);
        action_Imposta_Fiducia = new QAction(WebOfTrustClass);
        action_Imposta_Fiducia->setObjectName(QString::fromUtf8("action_Imposta_Fiducia"));
        action_Calcola_Fiducia = new QAction(WebOfTrustClass);
        action_Calcola_Fiducia->setObjectName(QString::fromUtf8("action_Calcola_Fiducia"));
        action_Emetti = new QAction(WebOfTrustClass);
        action_Emetti->setObjectName(QString::fromUtf8("action_Emetti"));
        actionImpo_rta = new QAction(WebOfTrustClass);
        actionImpo_rta->setObjectName(QString::fromUtf8("actionImpo_rta"));
        actionE_sporta = new QAction(WebOfTrustClass);
        actionE_sporta->setObjectName(QString::fromUtf8("actionE_sporta"));
        centralWidget = new QWidget(WebOfTrustClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        WebOfTrustClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WebOfTrustClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menu_Certificati = new QMenu(menuBar);
        menu_Certificati->setObjectName(QString::fromUtf8("menu_Certificati"));
        menu_Fiducia = new QMenu(menuBar);
        menu_Fiducia->setObjectName(QString::fromUtf8("menu_Fiducia"));
        WebOfTrustClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(WebOfTrustClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        WebOfTrustClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(WebOfTrustClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        WebOfTrustClass->setStatusBar(statusBar);

        menuBar->addAction(menu_Certificati->menuAction());
        menuBar->addAction(menu_Fiducia->menuAction());
        menu_Certificati->addAction(action_Emetti);
        menu_Certificati->addAction(actionImpo_rta);
        menu_Certificati->addAction(actionE_sporta);
        menu_Fiducia->addAction(action_Calcola_Fiducia);

        retranslateUi(WebOfTrustClass);

        QMetaObject::connectSlotsByName(WebOfTrustClass);
    } // setupUi

    void retranslateUi(QMainWindow *WebOfTrustClass)
    {
        WebOfTrustClass->setWindowTitle(QApplication::translate("WebOfTrustClass", "WebOfTrust", 0, QApplication::UnicodeUTF8));
        action_Imposta_Fiducia->setText(QApplication::translate("WebOfTrustClass", "&Imposta Fiducia", 0, QApplication::UnicodeUTF8));
        action_Calcola_Fiducia->setText(QApplication::translate("WebOfTrustClass", "&Calcola Fiducia", 0, QApplication::UnicodeUTF8));
        action_Emetti->setText(QApplication::translate("WebOfTrustClass", "&Emetti", 0, QApplication::UnicodeUTF8));
        actionImpo_rta->setText(QApplication::translate("WebOfTrustClass", "&Importa", 0, QApplication::UnicodeUTF8));
        actionE_sporta->setText(QApplication::translate("WebOfTrustClass", "E&sporta", 0, QApplication::UnicodeUTF8));
        menu_Certificati->setTitle(QApplication::translate("WebOfTrustClass", "&Certificati", 0, QApplication::UnicodeUTF8));
        menu_Fiducia->setTitle(QApplication::translate("WebOfTrustClass", "&Fiducia", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WebOfTrustClass: public Ui_WebOfTrustClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBOFTRUST_H
