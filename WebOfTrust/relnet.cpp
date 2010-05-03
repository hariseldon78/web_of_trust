#include "relnet.h"
#include "node.h"
#include "relation.h"
#include "net.h"
#include <QDebug>

QString logStatus, logSim;

Relnet::Relnet() :
	indentationLevel(0)
{

}

Relnet::Relnet(QString _name) :
	name(_name)
{
	net = new Net(_name);
}

Relnet::~Relnet()
{
}

Net* Relnet::getNet()
{
	return net;
}

NodeStatus Relnet::getStatus(Node* from, Node* destination)
{
	indent(logStatus, QString("status(") + from->toString() + " -> " + destination->toString() + ")=");
	if (from == destination)
	{
		indent(logStatus, "SELF");
		return SELF;
	}

	bool hasTerminale = false;
	bool hasPaths = false;
	QVectorIterator<Relation*> i(from->outRelations);
	qDebug() << ".";
	while (i.hasNext())
	{
		Relation* relation = i.next();

		if (relation->to == destination)
			hasTerminale = true;
		else if (!relation->to->flag)
			hasPaths = true;
	}
	if (hasTerminale)
	{
		if (hasPaths)
		{
			indent(logStatus, "TERMINAL_PATHS");
			return TERMINAL_PATHS;
		}
		else
		{
			indent(logStatus, "TERMINAL");
			return TERMINAL;
		}
	}
	else if (hasPaths)
	{
		indent(logStatus, "PATHS");
		return PATHS;
	}
	else
	{
		indent(logStatus, "NO_PATH");
		return NO_PATH;
	}
}

NodeStatus Relnet::getStatus(QString path)
{
	Node* from = net->getNode(path.at(0));
	Node* destination = net->getNode(path.at(1));

	return getStatus(from, destination);

}

double Relnet::trustRic(Node* from, Node* destination)
{
	QString result = "";
	double retVal;
	from->flag = true;
	indent(logSim, "{");
	indentationLevel++;
	switch (getStatus(from, destination))
	{
	case NO_PATH:
		indent(logSim, from->toString() + " -> " + destination->toString() + "(0) + ");
		result = "(0)";
		retVal = 0;
		break;
	case SELF:
		throw new SelfRelationCalledException();
		// result="(1)";
		// return 1;
	case TERMINAL:
	{
		traversedNodes.append(from);
		Relation* r = from->getRelation(destination);
		double w = r->weight;
		traversedRelations.append(r);
		indent(logSim, from->toString() + " -> " + destination->toString() + "(" + QString::number(w) + ") + ");
		result = QString("(") + QString::number(w) + ")";
		retVal = w;
		break;
	}
	case PATHS:
	case TERMINAL_PATHS:
		if (from == destination)
		{
			retVal = 1.0;
			break;
		}
		double ret = 0.0;
		double weightSum = 0.0;
		QVectorIterator<Relation*> i(from->outRelations);
		double maxTrust = 0;
		while (i.hasNext())
		{
			Relation* r = i.next();
			if (r->to->flag)
				continue;
			indent(logSim, QString() + "" + r->toString() + "(" + QString::number(r->weight) + ")*rel("
					+ r->to->toString() + " -> " + destination->toString() + ") ");
			maxTrust = max(maxTrust, r->weight);
			if (r->to != destination)
			{
				double ricorsiva = min(trustRic(r->to, destination), maxTrust);

				weightSum += ricorsiva > 0.0 ? pow(hopsValue, -1) * r->weight : 0.0;
				ret += (pow(hopsValue, -1) * r->weight * ricorsiva);
				if (ricorsiva > 0.0)
					traversedRelations.append(r);

			}
			else
			{
				traversedRelations.append(r);
				weightSum += 1.0;
				ret += r->weight;
			}
		}
		if (ret > 0.0)
			traversedNodes.append(from);

		if (weightSum > 0.0)
		{
			result = QString() + "(" + ret + ")/" + weightSum + "[=" + ret / weightSum + "] ";
			retVal = ret / weightSum;
		}
		else
		{
			result = QString() + "[=" + ret + "] ";
			retVal = ret;
		}
		break;
	}
	retVal = 0.0;
	from->flag = false;
	indentationLevel--;
	indent(logSim, QString() + "}" + result + "+");
	return retVal;
}

double Relnet::trust(QString from, QString destination)
{
	net->reset();
	for (QVector<Node*>::iterator it = traversedNodes.begin(); it != traversedNodes.end(); ++it)
	{
		delete *it;
	}
	traversedNodes.clear();
	for (QVector<Relation*>::iterator it = traversedRelations.begin(); it != traversedRelations.end(); ++it)
	{
		delete *it;
	}
	traversedRelations.clear();
	double ret = trustRic(net->getNode(from), net->getNode(destination));
	traversedNodes.append(net->getNode(destination));
	Net* n2 = net->getNode(from)->cloneNet(name + "_" + from + "_trust", traversedNodes, traversedRelations);
	n2->sort(from, destination);
	n2->saveNet();

	return ret;
}

double Relnet::trust(QString path)
{
	return trust(path.at(0), path.at(1));
}

void Relnet::indent(QString dest, QString s)
{
	for (int i = 0; i < indentationLevel; i++)
		dest.append("\t");
	dest.append(s);
	dest.append('\n');
}

void printLog()
{
	qDebug() << logSim;
	qDebug() << logStatus;
}

void Relnet::saveNet()
{
	net->saveNet();
}

void Relnet::addRelation(QString r, double d)
{
	net->addNode(r.at(0));
	net->addNode(r.at(1));
	try
	{
		net->addRelation(r.at(0), r.at(1), d);
	} catch (NodeNotExistingException &e)
	{
		qDebug() << "NodeNotExistingException";
	}
}

void Relnet::addRelation(QString from, QString to, double d)
{
	net->addNode(from);
	net->addNode(to);
	try
	{
		net->addRelation(from, to, d);
	} catch (NodeNotExistingException e)
	{
		qDebug() << "NodeNotExistingException";
	}
}

