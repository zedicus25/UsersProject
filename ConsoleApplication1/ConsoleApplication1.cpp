#include <iostream>
#include "c_Users_DB.h"
int main()
{
    c_Users_DB bd;
    c_User use(1,"name","last",15);
    bd.add(use);
    bd.add(use);
    bd.add(use);
    bd.save();
    
 
}