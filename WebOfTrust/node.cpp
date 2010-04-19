#include "node.h"

Node::~Node()
{
}

Node::Node(Net* net,QString name)
{
	this.net=net;
	this.name = name;
}

void Node::addRelation(Node* to, double d)
{
	Relation* r = new Relation(this,to, d);
	outRelations.add(r);
	to.inRelations.add(r);
	net.relations.add(r);
}

Relation* Node::getRelation(Node* destination) throw RelationNotExistingException
{
	for (int i=0;i<outRelations.size();i++)
		if (outRelations.elementAt(i).to==destination)
			return outRelations.elementAt(i);
	throw new RelationNotExistingException();
}

const QString Node::toString()

    return name;
}

Net* Node::cloneNet(QString newName) throw NodeNotExistingException 
{
	net.reset();
	Net* n=new Net(newName);
	cloneNet(n,net.nodes,net.relations);

	net.reset();
	return n;
}

Net* Node::cloneNet(QString n2, vector<Node*> nodes, vector<Relation*> relations) throw NodeNotExistingException, NodeNotFoundInSubnetException
{
	net.reset();
	Net* n=new Net(n2);
	if(!nodes.contains(this)) 
		throw new NodeNotFoundInSubnetException();
	cloneNet(n,nodes,relations);

	net.reset();
	return n;
}

Node* Node::cloneNet(Net* newNet, vector<Node*> nodes, vector<Relation*> relations) throw NodeNotExistingException
{
    Node* ret=new Node(newNet,name);
    newNet.nodes.add(ret);
    flag=true;
    for(int i=0;i<outRelations.size();i++)
    {
    	Relation* r = outRelations.elementAt(i);
    	Node* to;
        if(!relations.contains(r) || !nodes.contains(r.to)) 
        	continue;
    	if (!r.to.flag) 
    		to=r.to.cloneNet(newNet,nodes,relations);
    	else
    	{
    		to=newNet.getNode(r.to.name);
    	}
    	Relation* rNew=new Relation(ret,to,r.weight);
    	ret.outRelations.add(rNew);
    	newNet.relations.add(rNew);
    	
    }
    return ret;
}

