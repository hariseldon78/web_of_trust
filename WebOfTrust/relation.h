#ifndef RELATION_H
#define RELATION_H

#include <QString>

class Node;

class Relation
{
	public:
		Node* from;
		Node* to;
		double weight;
		Relation(Node* from, Node* to, double d);
        QString toString();
};

#endif // RELATION_H
