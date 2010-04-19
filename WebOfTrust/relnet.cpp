#include "relnet.h"
#include "node.h"
#include "relation.h"

Relnet::Relnet()
{
	indentationLevel = 0;
	traversedNodes = new vector<Node*>();
	traversedRelations = new vector<Relation*>();
}

Relnet::~Relnet()
{
}

Net Relnet::getNet()
{
	return net;
}

Relnet::Relnet(QString name)
{
	this.name = name;
	net = new Net(name);
}

NodeStatus Relnet::getStatus(Node* from, Node* destination)
{
	indent(log_status, "status(" + from + " -> " + destination + ")=");
	if (from.equals(destination))
	{
		indent(log_status, "SELF");
		return NodeStatus.SELF;
	}

	boolean hasTerminale = false;
	boolean hasPaths = false;
	Enumeration<Relation> i = from.outRelations.elements();
	System.out.print(".");
	while (i.hasMoreElements())
	{
		Relation relation = i.nextElement();

		if (relation.to == destination)
			hasTerminale = true;
		else if (!relation.to.flag)
			hasPaths = true;
	}
	if (hasTerminale)
	{
		if (hasPaths)
		{
			indent(log_status, "TERMINAL_PATHS");
			return NodeStatus.TERMINAL_PATHS;
		}
		else
		{
			indent(log_status, "TERMINAL");
			return NodeStatus.TERMINAL;
		}
	}
	else if (hasPaths)
	{
		indent(log_status, "PATHS");
		return NodeStatus.PATHS;
	}
	else
	{
		indent(log_status, "NO_PATH");
		return NodeStatus.NO_PATH;
	}
}

NodeStatus Relnet::getStatus(QString path)
{
	Node* from = net.getNode("" + path.charAt(0));
	Node* destination = net.getNode("" + path.charAt(1));

	return getStatus(from, destination);

}

private double Relnet::trustRic(Node* from, Node* destination)
{
	QString result = "";
	from.flag = true;
	indent(log_sim, "{");
	indentationLevel++;
	try
	{
		switch (getStatus(from, destination))
		{
		case NO_PATH:
			indent(log_sim, from + " -> " + destination + "(0) + ");
			result = "(0)";
			return 0;
		case SELF:
			throw new SelfRelationCalledException();
			// result="(1)";
			// return 1;
		case TERMINAL:
			{
				traversedNodes.add(from);
				Relation r = from.getRelation(destination);
				Double w = r.weight;
				traversedRelations.add(r);
				indent(log_sim, from + " -> " + destination + "(" + w + ") + ");
				result = "(" + w + ")";
				return w;
			}
		case PATHS:
		case TERMINAL_PATHS:
			if (from == destination)
			{
				return 1.0;
			}
			double ret = 0.0;
			double weightSum = 0.0;
			Enumeration<Relation> i = from.outRelations.elements();
			double maxTrust=0;
			while (i.hasMoreElements())
			{
				Relation r = i.nextElement();
				if (r.to.flag)
					continue;
				indent(log_sim, "" + r + "(" + r.weight + ")*rel(" + r.to + " -> " + destination + ") ");
				maxTrust=Math.max(maxTrust,r.weight);
				if (r.to != destination)
				{
					double ricorsiva = Math.min(trustRic(r.to, destination),maxTrust);

					weightSum += ricorsiva > 0.0 ? Math.pow(hopsValue, -1) * r.weight : 0.0;
					ret += (Math.pow(hopsValue, -1) * r.weight * ricorsiva);
					if (ricorsiva > 0.0)
						traversedRelations.add(r);

				}
				else
				{
					traversedRelations.add(r);
					weightSum += 1.0;
					ret += r.weight;
				}
			}
			if (ret > 0.0)
				traversedNodes.add(from);

			if (weightSum > 0.0)
			{

				result = "(" + ret + ")/" + weightSum + "[=" + ret / weightSum + "] ";
				return ret / weightSum;
			}
			else
			{
				result = "[=" + ret + "] ";
				return ret;
			}
		}
		return 0.0;
	} finally
	{
		from.flag = false;
		indentationLevel--;
		indent(log_sim, "}" + result + "+");

	}

}

double Relnet::trust(QString from, QString destination)
throw Exception
{
	net.reset();
	traversedNodes.clear();
	traversedRelations.clear();
	double ret = trustRic(net.getNode(from), net.getNode(destination));
	traversedNodes.add(net.getNode(destination));
	Net n2 = net.getNode(from).cloneNet(name + "_" + from + "_trust", traversedNodes, traversedRelations);
	n2.sort(from, destination);
	n2.saveNet();

	return ret;
}

double Relnet::trust(QString path)
throw Exception
{
	return trust("" + path.charAt(0), "" + path.charAt(1));
}

private void Relnet::indent(StringBuffer dest, QString s)
{
	for (int i = 0; i < indentationLevel; i++)
		dest.append("\t");
	dest.append(s);
	dest.append('\n');
}

static void Relnet::printLog()
{
	System.out.println(log_sim);
	System.out.println();
	System.out.println(log_status);

}

void Relnet::saveNet()
{
	net.saveNet();
}

void Relnet::addRelation(QString r, double d)
{
	net.addNode("" + r.charAt(0));
	net.addNode("" + r.charAt(1));
	try
	{
		net.addRelation("" + r.charAt(0), "" + r.charAt(1), d);
	} 
	catch (NodeNotExistingException &e)
	{
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
}

void Relnet::addRelation(QString from, QString to, double d)
{
	net.addNode(from);
	net.addNode(to);
	try
	{
		net.addRelation(from, "" + to, d);
	} catch (NodeNotExistingException e)
	{
		// TODO Auto-generated catch block
		e.printStackTrace();
	}
}

