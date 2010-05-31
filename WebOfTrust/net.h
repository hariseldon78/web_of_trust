#ifndef NET_H
#define NET_H

#include <QString>
#include <QVector>

class Node;
class Relation;

class Net
{
public:
	Net(QString _name);
	QVector<Node*> nodes;
	QVector<Relation*> relations;
	void addNode(QString _name);
	QString toString();
	Node* getNode(QString _name); // throw NodeNotExistingException;
	void addRelation(QString from, QString to, double d); // throw NodeNotExistingException;
	void reset();
	void saveNet();
	void loadNet(QString fileName = "");
	void refreshImage();
	void sort(QString from, QString destination);
	void importCertFile(QString fileName);
private:
	QString name;

};
#endif // NET_H
