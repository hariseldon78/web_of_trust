#include "net.h"
#include "node.h"
#include "relation.h"
#include "exception.h"
#include "utils.h"
#include <QDebug>
#include <QtCore>
#include <QDir>
#include <QStringList>
#include <QDomDocument>
#include <QDomElement>

Net::Net(QString _name) :
name(_name)
{

}

void Net::addNode(QString nodeName)
{
	try
	{
		getNode(nodeName);
	} catch (NodeNotExistingException &e)
	{
		qDebug() << QString("aggiungo il nodo %1 alla rete %2").arg(nodeName).arg(name);
		nodes.append(new Node(this, nodeName));
	}
}

Node* Net::getNode(QString _name)
{
	for (int i = 0; i < nodes.size(); i++)
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
	for (int i = 0; i < nodes.size(); i++)
		nodes.at(i)->flag = false;
}

void Net::saveNet()
{
	writeToFile(name + ".dot", toString());
	refreshImage();
}

void Net::refreshImage()
{
	QStringList args;
	args.append("-O");
	args.append("-Tpng");
	args.append(name + ".dot");
	QSettings s;
	QString path = s.value("dot_path").toString();
	QProcess::execute(path, args);
}

void Net::loadNet(QString fileName)
{
	//if (fileName.isEmpty())
	//{
	//	fileName = name + ".dot";
	//}
	//QString fileData = readFromFile(fileName);
	//QTextStream in(&fileData);
	//QString line;
	//while (!in.atEnd())
	//{
	//	line = in.readLine();
	//	if (line.contains("->"))
	//	{
	//		QRegExp re("(.+) -> (.+) \\[ label = (0[.]\\d+|1|0) \\]");
	//		int pos = re.indexIn(line);
	//		if (pos > -1)
	//		{
	//			QString from = re.cap(1);
	//			QString to = re.cap(2);
	//			QString value = re.cap(3);
	//			addNode(from);
	//			addNode(to);
	//			addRelation(from, to, value.toDouble());
	//		}
	//	}
	//}
	QSettings s;
	QDir dir  = QDir(s.value("certificates_folder").toString());	//crea una directory lang a partire dal path dove si trova il programma
	QStringList filters;						//crea una una lista di stringhe 
	filters << "*.xml";							//il filtro è su tutti i file con estensione .xml
	dir.setNameFilters(filters);				//faccio in modo che dalla cartella si vedano i nomi contenuti in filters
	QStringList files = dir.entryList();		//in "files" ci sono tutti file xml
	foreach (QString certF, files)				//certF è una variabile temporanea che scorre in files
	{
		importCertFile(certF);
	}
}

void Net::importCertFile(QString fileName)
{
	QDomDocument doc("mydocument"); 
	QFile file(fileName);      
	file.open(QIODevice::ReadOnly); 

	if (!doc.setContent(&file)) 
	{          
		file.close(); 
		return;
	}      
	file.close();
	QDomElement root = doc.documentElement();
	qDebug() << root.tagName();
	QString from = root.elementsByTagName("from").at(0).toElement().text();
	QString to = root.elementsByTagName("to").at(0).toElement().text();
	QString value = root.elementsByTagName("trust").at(0).toElement().text();
	qDebug() << from << " -> " << to;

	addNode(from);
	addNode(to);
	addRelation(from, to, value.toDouble());
}

void Net::sort(QString from, QString destination)
{
	int posFrom = 0;
	for (int i = 0; i < relations.size(); i++)
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
	for (int i = posFrom; i < relations.size(); i++)
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

