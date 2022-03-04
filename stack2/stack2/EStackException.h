#ifndef _EStackException_h
#define _EStackException_h


#include<cstring>


class EStackException
{
public:
	EStackException()
	{
		str = nullptr;
	}

	EStackException(const char* message)
	{
		unsigned char size = strlen(message);
		str = new char[size + 1];
		for (unsigned i = 0; i < size; ++i) {
			str[i] = message[i];
		}
		str[size] = '\0';
	}

	EStackException(const EStackException& other)
	{
		if (!other.str)
			return;

		unsigned size = strlen(other.str);
		str = new char[size];
		for (unsigned i = 0; i < size; ++i) {
			str[i] = other.str[i];
		}
	}

	~EStackException()
	{
		delete[] str;
	}

protected:
	char* str;
};

#endif