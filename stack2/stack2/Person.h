#ifndef _Person
#define _Person
#include <string>

class Person
{
private:
	std::string last_name;
	std::string first_name;
	std::string patronymic;
public:
	Person() = default; 
	Person(const Person& other);
	Person(const std::string& full_name);
	const std::string& getLastName() const { return last_name; }
	const std::string& getFirstName() const { return first_name; }
	const std::string& getPatronymic() const { return patronymic; }
	void setLastName(const std::string& last_name);
	void setFirstName(const std::string& first_name);
	void setPatronymic(const std::string& patronymic);
};

Person::Person(const std::string& full_name)
{
	int i = 0;
	for (;i < full_name.size(); ++i)
	{
		if (full_name[i] == ' ')
			break;
		last_name[i] = full_name[i];
	}

	for (++i ;i < full_name.size(); ++i)
	{
		if (full_name[i] == ' ')
			break;
		first_name[i] = full_name[i];
	}

	for (++i;i < full_name.size(); ++i)
	{
		patronymic[i] = full_name[i];
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