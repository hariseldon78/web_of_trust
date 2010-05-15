#include "settings.h"
#include <QSettings>

Settings::Settings(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui.buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	QSettings s;
	ui.nomeUtenteLineEdit->setText(s.value("nome_utente").toString());
	ui.emailLineEdit->setText(s.value("email").toString());
	ui.chiaveGpgLineEdit->setText(s.value("chiave_gpg").toString());
	ui.dotPathLineEdit->setText(s.value("dot_path").toString());

}

Settings::~Settings()
{

}

void Settings::accept()
{
	QSettings s;
	s.setValue("nome_utente",ui.nomeUtenteLineEdit->text());
	s.setValue("email",ui.emailLineEdit->text());
	s.setValue("chiave_gpg",ui.chiaveGpgLineEdit->text());
	s.setValue("dot_path",ui.dotPathLineEdit->text());
	QDialog::accept();
}
