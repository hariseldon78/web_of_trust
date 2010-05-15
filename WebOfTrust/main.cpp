#include "weboftrust.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("TrustSoftware");
	QCoreApplication::setOrganizationDomain("wot.org");
	QCoreApplication::setApplicationName("WebOfTrust");
	QApplication a(argc, argv);
	WebOfTrust w;
	w.show();
	return a.exec();
}
