#include "weboftrust.h"
#include "relnet.h"
#include "net.h"
#include "exception.h"
#include <QInputDialog>

WebOfTrust::WebOfTrust(QWidget *parent, Qt::WFlags flags): QMainWindow(parent, flags), logged(false)
{
	ui.setupUi(this);
	utenteM = ui.menu_Utente;
	loginA = ui.action_Login;
	connect(loginA, SIGNAL(triggered()), this, SLOT(login()));
	connect(ui.action_Emetti, SIGNAL(triggered()), this, SLOT(emetti()));
	ui.menu_Certificati->setDisabled(true);
	ui.menu_Fiducia->setDisabled(true);
}

WebOfTrust::~WebOfTrust()
{

}

void WebOfTrust::login()
{
	bool ok;
	QString name = QInputDialog::getText(this, tr("Login"), tr("Inserisci il tuo nome:"), QLineEdit::Normal, "", &ok);
	if (ok && !name.isEmpty())
	{
		user = name;
		logged = true;
		ui.menu_Certificati->setDisabled(false);
		ui.menu_Fiducia->setDisabled(false);
		loginA->setDisabled(true);
		rn = new Relnet(user);
		try{
			rn->getNet()->loadNet();
		} catch(FileErrorException& e)
		{};
		rn->getNet()->refreshImage();
		refresh();
	}
}

void WebOfTrust::emetti()
{
	bool ok;
	QString target = QInputDialog::getText(this, tr("Emetti"), tr("Inserisci il nome utente:"), QLineEdit::Normal, "", &ok);
	if (!ok || target.isEmpty())
	{
		return;
	}
	double dTrust;
	do
	{
		QString trust = QInputDialog::getText(this, tr("Emetti"), tr("Inserisci il valore di fiducia:"), QLineEdit::Normal, "", &ok);
		if (!ok || trust.isEmpty())
		{
			return;
		}
		dTrust = trust.toDouble(&ok);
	}
	while (!ok || dTrust < 0.0 || dTrust > 1.0);
	rn->addRelation(user, target, dTrust);
	rn->getNet()->saveNet();
	refresh();
}

void WebOfTrust::refresh()
{
	QGraphicsScene *scene = new QGraphicsScene(ui.netImg);
	scene->setSceneRect(ui.netImg->rect());
	ui.netImg->setScene(scene);
	QPixmap pix(user + ".dot.png");
	scene->addPixmap(pix);
	ui.netImg->show();
}
