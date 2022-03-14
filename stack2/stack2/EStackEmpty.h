#ifndef _EStackEmpty_h
#define _EStackEmpty_h


#include "EStackException.h"


class EStackEmpty : public EStackException
{
public:

	EStackEmpty() : EStackException("Error: Stack is Empty\n")//конструктор поумолчанию
	{

	}

	EStackEmpty(const EStackEmpty& other) : EStackException(other)//конструктор копирования
	{

	}

	const char* what()const//метод, который возвращает сообщение об ошибке
	{
		return str;
	}
};


#endif