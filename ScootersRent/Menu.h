#pragma once
#include "User.h"
#include "Store.h"

class Menu
{
private:
	Store* store;


public:
	void selectUser();
	Menu(Store* store);

};

