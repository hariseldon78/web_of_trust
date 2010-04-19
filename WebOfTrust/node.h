#ifndef NODE_H
#define NODE_H
#include <QString>
#include <vector>
#include "exception.h"

using namespace std;

class Relation;
class Net;

class Node
{
	public: 
		Node();
		~Node();
		QString name;
		bool flag;
		vector<Relation*> outRelations;
		vector<Relation*> inRelations;
		Node(Net* net,QString name);
		void addRelation(Node* to, double d);
		Relation* getRelation(Node* destination); // throw RelationNotExistingException;
		const QString toString();
		Net* cloneNet(QString newName); //  throw NodeNotExistingException; 
		Net* cloneNet(QString n2, vector<Node*> nodes, vector<Relation*> relations); // throw NodeNotExistingException, NodeNotFoundInSubnetException;
		Node* cloneNet(Net* newNet, vector<Node*> nodes, vector<Relation*> relations); // throw NodeNotExistingException;

	private: 
		Net* net;
};

#endif // NODE_H
