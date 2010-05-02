#ifndef WEBOFTRUST_H
#define WEBOFTRUST_H

#include <QtGui/QMainWindow>
#include "ui_weboftrust.h"
#include <QString>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QLineEdit;
QT_END_NAMESPACE

class Relnet;

class WebOfTrust : public QMainWindow
{
	Q_OBJECT

public:
	WebOfTrust(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WebOfTrust();

private:
	Ui::WebOfTrustClass ui;
	QMenu *utenteM;
	QAction *loginA;
	QString user;
	bool logged;
	Relnet *rn;
	void refresh();

private slots:
	void login();
	void emetti();
};

#endif // WEBOFTRUST_H
