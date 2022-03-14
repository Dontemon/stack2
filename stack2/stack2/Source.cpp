#include <iostream>
#include "Stack.h"


int main()
{
	try {
		Stack<int> a;
		a.pop();
	}
	catch (const EStackEmpty& empty)
	{
		std::cout << empty.what();
	}
	return 0;
}