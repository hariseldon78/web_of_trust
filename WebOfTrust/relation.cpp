#include "relation.h"
#include "node.h"

Relation::Relation(Node* _from, Node* _to, double d) :
	from(_from), to(_to), weight(d)
{
}

QString Relation::toString()
{
	return QString("[") + from->name + "->" + to->name + "]";
}
