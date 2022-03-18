#ifndef _Person_keeper
#define _Person_keeper
#include "stack.h"
#include "Person.h"

class Person_keeper
{
private:
	Person_keeper() = default;
	Person_keeper(const ::Person_keeper& other);
	~Person_keeper() = default;

	stack<Person> keeper;
public:



};

#endif