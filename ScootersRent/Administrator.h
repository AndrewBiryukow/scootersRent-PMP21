#pragma once
#include "User.h"

class Administrator :
    public User
{
public:
    Administrator(string name, string email);
    Administrator(string name, string email,int id);
};

