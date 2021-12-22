#pragma once
#include "c_User.h"
class c_UsersBD
{
private:
	int size;
	c_User* users;
public:
	c_UsersBD();

	inline int getSize() const {
		return this->size;
	}
	c_User& operator[](const int index);

	void load();
	void remove(int index);
	void remove(c_User& user);
	void save();

	c_User getById(int id);

	~c_UsersBD()
	{
		delete[] this->users;
	}
};

