#include "c_UsersBD.h"

c_UsersBD::c_UsersBD()
{
	this->size = 0;
	this->users = new c_User[0];
}

c_User& c_UsersBD::operator[](const int i)
{
	if (i < this->size) {
		return users[i];
	}
	else {
		std::cout << "Out of bunds array\n";
		return users[0];
	}
}

void c_UsersBD::load()
{
	FILE* pf;
	fopen_s(&pf, "E:\\Project C++\\Step\\Homeworks\\UsersProject\\File.txt", "rb");
	if (pf) {
		fread(&this->size, sizeof(int), 1, pf);
		this->users = new c_User[this->size];
		fread(users, this->size * sizeof(c_User),1,pf);
		fclose(pf);
	}
}

void c_UsersBD::remove(int index)
{
	if (index < this->getSize()) {
		c_User* tmp = new c_User[this->getSize()];

		for (int i = 0; i < this->getSize(); i++)
		{
			tmp[i] = this->users[i];
		}

		this->users = nullptr;
		this->size--;
		this->users = new c_User[this->getSize()];
		
		for (int i = 0; i < index; i++)
		{
			this->users[i] = tmp[i];
		}
		for (int i = index; i < this->getSize(); i++)
		{
			this->users[i] = tmp[i+1];
		}
		delete[] tmp;
	}
}

void c_UsersBD::remove(c_User& user)
{
	int index = 0;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (user.getId() == users[i].getId()) {
			index = i;
			break;
		}
	}

	c_User* tmp = new c_User[this->getSize()];
	for (int i = 0; i < this->getSize(); i++)
	{
		tmp[i] = users[i];
	}

	this->users = nullptr;
	this->size--;
	this->users = new c_User[this->getSize()];

	for (int i = 0; i < index; i++)
	{
		this->users[i] = tmp[i];
	}
	for (int i = index; i < this->getSize(); i++)
	{
		this->users[i] = tmp[i + 1];
	}
	delete[] tmp;
}

void c_UsersBD::save()
{
	FILE* pf;
	fopen_s(&pf, "E:\\Project C++\\Step\\Homeworks\\UsersProject\\File.txt", "wb");
	if (pf) {
		fwrite(&this->size, sizeof(int), 1, pf);
		fwrite(users, this->size * sizeof(c_User), 1, pf);
		fclose(pf);
	}
}

c_User c_UsersBD::getById(int id)
{
	for (int i = 0; i < this->getSize(); i++)
	{
		if (id == users[i].getId()) {
			return users[i];
		}
	}
}
