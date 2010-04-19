#include "net.h"
#include "node.h"
#include "relation.h"


Net::Net(QString _name): name(_name)
{
	nodes = new vector<Node*>();
	relations = new vector<Relation*>();
}



void Net::addNode(QString name)
{
	try
	{
		getNode(name);
	}
	catch(NodeNotExistingException e)
	{
		nodes.add(new Node(this,name));
	}
}



Node* Net::getNode(QString name) throw NodeNotExistingException
{
	for(int i=0;i<nodes.size();i++)
		if (nodes.elementAt(i).name.equals(name))
			return nodes.elementAt(i);


	throw new NodeNotExistingException();

}

void Net::addRelation(QString from, QString to, double d) throw NodeNotExistingException
{
	// la relazione viene aggiunta nel nodo
	getNode(from).addRelation(getNode(to),d);
}

QString Net::toString()
{	
	StringBuffer buf = new StringBuffer();
	buf.append("digraph net {\n");
	buf.append("rankdir=LR;\n");
	buf.append("node [shape=circle];\n");
	for (int i=0;i<relations.size();i++)
	{
		Relation* rel = relations.elementAt(i);
		buf.append(rel.from);
		buf.append(" -> ");
		buf.append(rel.to);
		buf.append(" [ label = ");
		buf.append(rel.weight);
		buf.append(" ];\n");
	}
	buf.append("}\n");
	return buf.toString();
}

void Net::reset()
{
	for (int i=0;i<nodes.size();i++)
		nodes.elementAt(i).flag=false;
}




void Net::saveNet()
throw Exception
{
	Utils.writeToFile(name + ".dot", toString());
	Runtime.getRuntime().exec(new QString[] { "dot", "-O", "-Tpng", name + ".dot" }).waitFor();
	Runtime.getRuntime().exec("eog " + name + ".dot.png");
}



void Net::sort(QString from, QString destination)
{
	int posFrom=0;
	for (int i=0;i<relations.size();i++)
	{
		if (relations.elementAt(i).from.name.equals(from))
		{
			Relation* tmp=relations.elementAt(i);
			relations.setElementAt(relations.elementAt(posFrom),i);
			relations.setElementAt(tmp,posFrom);
			posFrom++;
		}
	}

	int posTo=relations.size()-1;
	for (int i=posFrom;i<relations.size();i++)
	{
		if (relations.elementAt(i).to.name.equals(destination))
		{
			Relation* tmp=relations.elementAt(i);
			relations.setElementAt(relations.elementAt(posTo),i);
			relations.setElementAt(tmp,posTo);
			posTo--;
		}
	}

}

