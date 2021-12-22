#include <iostream>
#include "c_UsersBD.h"
int main()
{
    c_UsersBD bd;
    bd.load();
	for (int i = 0; i < bd.getSize(); i++)
	{
		std::cout << bd[i];
	}
	system("pause");
	system("cls");

	c_User use(3, "name", "name", 15);
	bd.remove(use);
	for (int i = 0; i < bd.getSize(); i++)
	{
		std::cout << bd[i];
	}
	system("pause");
	system("cls");
	bd.remove(2);
	for (int i = 0; i < bd.getSize(); i++)
	{
		std::cout << bd[i];
	}
	bd.save();
}