#include "c_User.h"

c_User::c_User()
{
	this->id = 0;
	this->name = "none";
	this->last_name = "none";
	this->age = 0;
}

c_User::c_User(long id, std::string name, std::string last_name, int age)
{
	this->id = id;
	this->name = name;
	this->last_name = name;
	this->age = age;
}

c_User::c_User(c_User& copy)
{
	this->id = copy.getId();
	this->name = copy.getName();
	this->last_name = copy.getLastName();
	this->age = copy.getAge();
}

std::ostream& operator<<(std::ostream& out, const c_User us)
{
	out << "Last name: " << us.getLastName() << "\n";
	out << "Name: " << us.getName() << "\n";
	out << "Age: " << us.getAge() << "\n";
	return out;
}

