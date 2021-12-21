#pragma once
#include <iostream>
class c_User
{
private:
	long id;
	std::string name;
	std::string last_name;
	int age;
public:
	c_User();
	c_User(long id,std::string name, std::string last_name, int age);
	c_User(c_User& copy);

	//gets
	inline std::string getName() const {
		return this->name;
	}
	inline std::string getLastName() const {
		return this->last_name;
	}
	inline int getAge()const {
		return this->age;
	}
	inline int getId() const {
		return this->id;
	}

	//sets
	inline void setLastName(std::string last_name) {
		this->last_name = last_name;
	}
	inline void setName(std::string name) {
		this->name = name;
	}
	inline void setAge(int age) {
		this->age = age;
	}

	friend std::ostream& operator << (std::ostream& out, const c_User us);


};

