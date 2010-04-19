#ifndef WEBOFTRUST_H
#define WEBOFTRUST_H

#include <QtGui/QMainWindow>
#include "ui_weboftrust.h"

class WebOfTrust : public QMainWindow
{
	Q_OBJECT

public:
	WebOfTrust(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WebOfTrust();

private:
	Ui::WebOfTrustClass ui;
};

#endif // WEBOFTRUST_H
