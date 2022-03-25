#ifndef _Person_keeper
#define _Person_keeper
#include "stack.h"
#include "Person.h"
#include <string>
#include <fstream>

class Person_keeper
{
private:
	Person_keeper() = default;//конструктор по-умолчанию
	Person_keeper(const Person_keeper& other);//конструктор копирования
	~Person_keeper() = default;//деструктор

public:
	static Person_keeper& instance();//получение ссылки на объект
	Stack<Person> read_persons(std::fstream& File);//метод для считывания из файла ФИО
	void write_persons(const Stack<Person>& Persons, std::fstream& File);//метод для записи в файл ФИО

};

Person_keeper& Person_keeper::instance()
{
	static Person_keeper obj;
	return obj;
}

Stack<Person> Person_keeper::read_persons(std::fstream& File) 
{
	if (!File.is_open())//если не открылся, то кидаем исключение
		throw "Can't open the file";
	Stack<Person> Persons;
	std::string string;
	while (std::getline(File, string))//пока мы можем брать строку из файла
		Persons.push(Person(string));//и кладём в стэк персону
	return Persons;
}

void Person_keeper::write_persons(const Stack<Person>& Persons, std::fstream& File)
{
	if (!File.is_open())//если не открылся, то кидаем исключение
		throw "Can't open the file";
	for (unsigned i = 0; i < Persons.size(); ++i)//идём по элементам стэка
	{
		File << Persons[i].getLastName();//выводим в файл Фамилию
		File << ' ';
		File << Persons[i].getFirstName(); //выводим в файл Имя
		File << ' ';
		File << Persons[i].getPatronymic();//выводим в файл Отчество
		File << '\n';
	}
}


#endif