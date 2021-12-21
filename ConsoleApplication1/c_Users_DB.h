#pragma once
#include "c_User.h"
class c_Users_DB
{
private:
	int size;
	c_User* users;
public:
	c_Users_DB();
	
	void add(c_User& user);
	void save();

	inline int getSize() const {
		return this->size;
	}

	

};

