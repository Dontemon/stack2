#include <iostream>
#include "Stack.h"
#include "PersonKeeper.h"



int main()
{
	try {
		std::fstream File("input.txt", std::ios::in);//открываем файл для считывания 
		Stack<Person> Persons = Person_keeper::instance().read_persons(File);//вызываем функцию считывания из файла в стэк
		std::fstream File1("output.txt", std::ios::out);// создаём и открываем файл для вывода из стэка в текстовый документ
		Person_keeper::instance().write_persons(Persons, File1);//заполняем созданный файл output данными из стэка	
		Stack<int> stack;
		int a = 2;
		stack.push(a);
		std::cout << stack[5];
		//stack.pop_front();
		
		
		//std::cout << stack.top();
	}
	catch (EStackEmpty& Error)
	{
		std::cout << Error.what();
	}
	catch(const char* badIndexError)
	{
		std::cout << badIndexError;
	}
	catch (...)
	{
		std::cout << "Can't open the file";
	}
	return 0;
}