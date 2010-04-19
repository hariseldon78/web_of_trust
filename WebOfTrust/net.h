#ifndef NET_H
#define NET_H

#include <QString>
#include "NodeNotExistingException.h"
#include <vector>
#include "exception.h"

using namespace std;

class Node;
class Relation;

class Net
{
public:
	Net(QString name)
	vector<Node*> nodes;
	vector<Relation*> relations;
	void addNode(QString name);
	QString toString();
	Node* getNode(QString name) throw NodeNotExistingException;
	void addRelation(QString from, QString to, double d) throw NodeNotExistingException;
	void reset();
	void saveNet();
	void sort(QString from, QString destination);
private:
	QString name;
	
}

#endif // NET_H