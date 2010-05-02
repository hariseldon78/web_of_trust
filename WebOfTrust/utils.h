#ifndef UTILS_H
#define UTILS_H

#include <QString>

typedef enum NodeStatus
{
	NO_PATH = 0, TERMINAL, TERMINAL_PATHS, PATHS, SELF
};

bool writeToFile(QString fileName, QString what);
QString readFromFile(QString fileName);

#endif // UTILS_H