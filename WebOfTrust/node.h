#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QVector>

class Relation;
class Net;

class Node
{
public:
	Node();
	~Node();
	QString name;
	bool flag;
	QVector<Relation*> outRelations;
	QVector<Relation*> inRelations;
	Node(Net* net, QString name);
	void addRelation(Node* to, double d);
	Relation* getRelation(Node* destination); // throw RelationNotExistingException;
	const QString toString();
	Net* cloneNet(QString newName); //  throw NodeNotExistingException; 
	Net* cloneNet(QString n2, QVector<Node*> nodes, QVector<Relation*> relations); // throw NodeNotExistingException, NodeNotFoundInSubnetException;
	Node* cloneNet(Net* newNet, QVector<Node*> nodes, QVector<Relation*> relations); // throw NodeNotExistingException;

private:
	Net* net;
};

#endif // NODE_H
