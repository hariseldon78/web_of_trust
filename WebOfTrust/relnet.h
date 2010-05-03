#ifndef RELNET_H
#define RELNET_H

#include <QString>
#include <QVector>
#include "exception.h"
#include "utils.h"

using namespace std;

#define hopsValue 6.0

class Node;
class Relation;
class Net;

class Relnet
{

public:
	Relnet();
	Relnet(QString name);
	~Relnet();
	QVector<Node*> traversedNodes;
	QVector<Relation*> traversedRelations;
	Net* net;
	Net* getNet();
	NodeStatus getStatus(Node* from, Node* destination);
	NodeStatus getStatus(QString path); // throw NodeNotExistingException;
	double trustRic(Node* from, Node* destination); // throw RelationNotExistingException,
	// SelfRelationCalledException;
	double trust(QString from, QString destination);
	//throw Exception;
	double trust(QString path);
	//throw Exception;
	void indent(QString dest, QString s);
	void saveNet();
	//throw Exception;
	void addRelation(QString r, double d);
	void addRelation(QString from, QString to, double d);

private:
	int indentationLevel;
	QString name;
};

void printLog();

#endif // RELNET_H
