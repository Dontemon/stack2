#include <iostream>
#include "Stack.h"
#include "PersonKeeper.h"



int main()
{
	try {
		std::fstream File("input.txt", std::ios::in);
		Stack<Person> Persons = Person_keeper::instance().read_persons(File);
		std::fstream File1("output.txt", std::ios::out);
		Person_keeper::instance().write_persons(Persons, File1);
	}
	catch (const EStackEmpty& empty)
	{
		std::cout << empty.what();
	}
	return 0;
}