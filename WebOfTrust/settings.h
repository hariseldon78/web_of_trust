#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtGui/QDialog>
#include "ui_settings.h"

class Settings: public QDialog
{
Q_OBJECT

public:
	Settings(QWidget *parent = 0);
	~Settings();

private:
	Ui::SettingsClass ui;

public slots:
	virtual void accept();
};

#endif // SETTINGS_H
