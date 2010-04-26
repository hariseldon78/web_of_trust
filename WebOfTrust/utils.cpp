#include "utils.h"
#include <QFile>
#include <QTextStream>

bool writeToFile(QString fileName, QString what)
{
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return false;
	}
	QTextStream out(&file);
	out << what;
	file.close();
	return true;
}
