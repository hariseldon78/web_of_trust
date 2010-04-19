#include "exception.h"
#include <QDebug>

void Exception::printStackTrace()
{
	qDebug() << "Questo e'' male\n";
}
