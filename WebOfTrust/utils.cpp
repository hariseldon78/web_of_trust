#include "utils.h"
#include "exception.h"
#include <QFile>
#include <QTextStream>

bool writeToFile(QString fileName, QString what)
{
	QFile file(fileName);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		throw FileErrorException();
	}
	QTextStream out(&file);
	out << what;
	file.close();
	return true;
}

QString readFromFile(QString fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		throw FileErrorException();
	}
	QTextStream in(&file);
	QString ret = in.readAll();
	file.close();
	return ret;	
}
