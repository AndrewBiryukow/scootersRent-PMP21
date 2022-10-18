#pragma once
#include "User.h"
#include "Store.h"

class SubMenuAdministrator
{
private:
	Store* store;


public:
	SubMenuAdministrator(Store* store);
	SubMenuAdministrator();
	void show();
	void createUser();
	void deleteUser();
	void showUsers();

	//void updateUser();

	void createScooter();
	void deleteScooter();
	void showScooters();

	//void updateScooter();

	void showRequests();
	void editRequest();

	void confirmRequest();
	void rejectRequest();

	
};

