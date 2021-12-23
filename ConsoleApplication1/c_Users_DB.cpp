#include "c_Users_DB.h"

c_Users_DB::c_Users_DB()
{
	this->size = 0;
	this->users = new c_User[0];
}

void c_Users_DB::add(c_User& user)
{
	c_User* tmp = new c_User[size];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->users[i];
	}

	this->size++;
	this->users = nullptr;
	this->users = new c_User[size];

	for (int i = 0; i < this->size-1; i++)
	{
		this->users[i] = tmp[i];
	}
	c_User use(user);
	use.setId(size);
	this->users[size-1] = use;
	delete[] tmp;
}

void c_Users_DB::save()
{
	FILE* pf;
	fopen_s(&pf, "E:\\Project C++\\Step\\Homeworks\\UsersProject\\File.txt", "wb");
	if (pf) {
		fwrite(&this->size, sizeof(int), 1, pf);
		fwrite(users, this->size * sizeof(c_User), 1, pf);
		fclose(pf);
	}
}

c_User& c_Users_DB::operator[](const int index)
{
	if (index < this->size) {
		return users[index];
	}
	else {
		std::cout << "Out of bunds array\n";
		return users[0];
	}
}


