//#include "weboftrust.h"
#include <QtGui/QApplication>
#include "relnet.h"
#include "net.h"
#include "utils.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//WebOfTrust w;
	//w.show();
	Relnet rn("butei");
	rn.addRelation("roby", "ciro", 0.6);
	rn.addRelation("ciro", "tosi", 0.75);
	rn.addRelation("roby", "tosi", 0.2);
	rn.getNet()->saveNet();
	qDebug() << "fatta saveNet()";
	double d = rn.trust("roby","ciro");
	qDebug() << "d = " << d;
	printLog();
	qDebug() << "fatto printLog()";
	//Q_ASSERT(0.6 == d);
	return a.exec();
}
