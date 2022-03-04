#ifndef _EStackEmpty_h
#define _EStackEmpty_h


#include "EStackException.h"


class EStackEmpty : public EStackException
{
public:

	EStackEmpty() : EStackException("Error: Stack is Empty\n")
	{

	}

	EStackEmpty(const EStackEmpty& other) : EStackException(other)
	{

	}

	const char* what()const
	{
		return str;
	}
};


#endif