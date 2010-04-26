#include "net.h"
#include "node.h"
#include "relation.h"
#include "exception.h"
#include "utils.h"
#include <QDebug>
#include <QtCore>
#include <QDir>
#include <QStringList>

Net::Net(QString _name): name(_name)
{

}



void Net::addNode(QString nodeName)
{
	try
	{
		getNode(nodeName);
	}
	catch(NodeNotExistingException &e)
	{
		qDebug() << QString("aggiungo il nodo %1 alla rete %2").arg(nodeName).arg(name);
		nodes.append(new Node(this, nodeName));
	}
}



Node* Net::getNode(QString _name)
{
	for(int i = 0; i < nodes.size(); i++)
		if (nodes.at(i)->name.compare(_name) == 0)
			return nodes.at(i);

	throw NodeNotExistingException();

}

void Net::addRelation(QString from, QString to, double d)
{
	// la relazione viene aggiunta nel nodo
	getNode(from)->addRelation(getNode(to), d);
}

QString Net::toString()
{	
	QString buf;
	buf.append("digraph net {\n");
	buf.append("rankdir=LR;\n");
	buf.append("node [shape=circle];\n");
	for (int i = 0; i < relations.size(); i++)
	{
		Relation* rel = relations.at(i);
		buf.append(rel->from->toString());
		buf.append(" -> ");
		buf.append(rel->to->toString());
		buf.append(" [ label = ");
		buf.append(QString::number(rel->weight));
		buf.append(" ];\n");
	}
	buf.append("}\n");
	return buf;
}

void Net::reset()
{
	for (int i=0;i<nodes.size();i++)
		nodes.at(i)->flag = false;
}




void Net::saveNet() // TODO installare dot
{
	writeToFile(name + ".dot", toString());
	QStringList args;
	args.append("-O");
	args.append("-Tpng");
	args.append(name + ".dot");
	QString path = "C:\\Program Files\\Graphviz2.26.3\\bin\\dot.exe";
	QProcess::execute(path, args);
//	QProcess::waitForFinished(4000);
	//Runtime.getRuntime().exec("eog " + name + ".dot.png");
}



void Net::sort(QString from, QString destination)
{
	int posFrom=0;
	for (int i=0;i<relations.size();i++)
	{
		if (relations.at(i)->from->name.compare(from) == 0)
		{
			Relation* tmp = relations.at(i);
			relations[i] = relations.at(posFrom);
			relations[posFrom] = tmp;
			posFrom++;
		}
	}

	int posTo = relations.size() - 1;
	for (int i=posFrom;i<relations.size();i++)
	{
		if (relations.at(i)->to->name.compare(destination) == 0)
		{
			Relation* tmp = relations.at(i);
			relations[i] = relations.at(posTo);
			relations[posTo] = tmp;
			posTo--;
		}
	}

}

