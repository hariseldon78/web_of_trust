#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QtCore>

using QtConcurrent::Exception;

class RelationNotExistingException: public Exception {};
class SelfRelationCalledException: public Exception {};
class NodeNotExistingException: public Exception {};
class NodeNotFoundInSubnetException: public Exception {};
class FileErrorException: public Exception {};

#endif // EXCEPTION_H