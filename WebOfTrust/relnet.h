#ifndef RELNET_H
#define RELNET_H

#include <QString>
#include <vector>
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
	vector<Node*> traversedNodes;
	vector<Relation*> traversedRelations;
	Net* net;
	Net* getNet();
	Relnet();
	Relnet(QString name);
	NodeStatus getStatus(Node* from, Node* destination);
	NodeStatus getStatus(QString path); // throw NodeNotExistingException;
	double trustRic(Node* from, Node* destination); // throw RelationNotExistingException,
		// SelfRelationCalledException;
	double trust(QString from, QString destination);
		//throw Exception;
	double trust(QString path);
		//throw Exception;
	void indent(QString dest, QString s);
	void printLog();
	void saveNet();
		//throw Exception;
	void addRelation(QString r, double d);
	void addRelation(QString from, QString to, double d);

private:
	int indentationLevel;
	QString name;
}

#endif // RELNET_H