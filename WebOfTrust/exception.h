#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class Exception: public std::exception 
{
public:
	void printStackTrace();
};

class RelationNotExistingException: public Exception {};
class SelfRelationCalledException: public Exception {};
class NodeNotExistingException: public Exception {};
class NodeNotFoundInSubnetException: public Exception {};

#endif // EXCEPTION_H
