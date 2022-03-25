#ifndef _Person
#define _Person
#include <string>

class Person
{
private:
	std::string last_name;//Фамилия
	std::string first_name;//Имя
	std::string patronymic;//Отчество
public:
	Person() = default; //конструктор по-умолчанию
	Person(const Person& other);//конструктор копирования
	Person(const std::string& full_name);//конструктор копирования строки

	const std::string& getLastName() const //возвращает Фамилию
	{
		return last_name; 
	}
	const std::string& getFirstName() const //возвращает Имя
	{ 
		return first_name;
	}
	const std::string& getPatronymic() const//Возвращает Отчество
	{
		return patronymic; 
	}

	void setLastName(const std::string& last_name);//устанавливаем Фамилию
	void setFirstName(const std::string& first_name);//устанавливаем Имя
	void setPatronymic(const std::string& patronymic);//устанавливаем Отчество

	~Person() = default;
};

Person::Person(const std::string& full_name)
{
	unsigned i = 0;
	for (;i < full_name.size(); ++i)//идем построке
	{
		if (full_name[i] == ' ')//если встречаем пробел
			break;//выходим из фора
		last_name.push_back(full_name[i]);//записываем в Фамилию
	}

	for (++i ;i < full_name.size(); ++i)//идём дальше по строке
	{
		if (full_name[i] == ' ')//так-же до пробела
			break;//если пробел->выходим из фора
		first_name.push_back(full_name[i]);//записываем в Имя
	}

	for (++i;i < full_name.size(); ++i)//все остальное записываем в Отчесвто
	{
		patronymic.push_back(full_name[i]);
	}
}

Person::Person(const Person& other) 
{
	last_name = other.last_name;
	first_name = other.first_name;
	patronymic = other.patronymic;
}

void Person::setLastName(const std::string& last_name)
{
	this->last_name = last_name;
}

void Person::setFirstName(const std::string& first_name)
{
	this->first_name = first_name;
}

void Person::setPatronymic(const std::string& patronymic)
{
	this->patronymic = patronymic;
}


#endif