#include "node.h"
#include "relation.h"
#include "net.h"
#include "exception.h"

Node::~Node()
{
}

Node::Node(Net* _net, QString _name) :
	 name(_name), net(_net)
{

}

void Node::addRelation(Node* to, double d)
{
	Relation* r = new Relation(this, to, d);
	outRelations.append(r);
	to->inRelations.append(r);
	net->relations.append(r);
}

Relation* Node::getRelation(Node* destination)
{
	for (int i = 0; i < outRelations.size(); i++)
		if (outRelations.at(i)->to == destination)
			return outRelations.at(i);
	throw new RelationNotExistingException();
}

const QString Node::toString()
{
	return name;
}

Net* Node::cloneNet(QString newName)
{
	net->reset();
	Net* n = new Net(newName);
	cloneNet(n, net->nodes, net->relations);

	net->reset();
	return n;
}

Net* Node::cloneNet(QString n2, QVector<Node*> nodes, QVector<Relation*> relations)
{
	net->reset();
	Net* n = new Net(n2);
	if (!nodes.contains(this))
		throw new NodeNotFoundInSubnetException();
	cloneNet(n, nodes, relations);

	net->reset();
	return n;
}

Node* Node::cloneNet(Net* newNet, QVector<Node*> nodes, QVector<Relation*> relations)
{
	Node* ret = new Node(newNet, name);
	newNet->nodes.append(ret);
	flag = true;
	for (int i = 0; i < outRelations.size(); i++)
	{
		Relation* r = outRelations.at(i);
		Node* to;
		if (!relations.contains(r) || !nodes.contains(r->to))
			continue;
		if (!r->to->flag)
			to = r->to->cloneNet(newNet, nodes, relations);
		else
		{
			to = newNet->getNode(r->to->name);
		}
		Relation* rNew = new Relation(ret, to, r->weight);
		ret->outRelations.append(rNew);
		newNet->relations.append(rNew);

	}
	return ret;
}

