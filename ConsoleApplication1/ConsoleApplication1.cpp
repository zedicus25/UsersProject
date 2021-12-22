#include <iostream>
#include "c_Users_DB.h"
int main()
{
    c_Users_DB bd;
    c_User use(1,"name","last",15);
    c_User use1(2,"name1","last",16);
    c_User use2(3,"name2","last",17);
    c_User use3(4,"name3","last",18);
    c_User use4(5,"name4","last",19);
    c_User use5(6,"name5","last",20);
    bd.add(use);
    bd.add(use1);
    bd.add(use2);
    bd.add(use3);
    bd.add(use4);
    bd.add(use5);

    for (int i = 0; i < bd.getSize(); i++)
    {
        std::cout << bd[i];
    }

    bd.save();
}