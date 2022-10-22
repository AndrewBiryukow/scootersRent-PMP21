#pragma once
#include "Store.h"
class SubMenuCustomer
{
private:
	Store* store;
	User* user;
public:
	SubMenuCustomer(Store* store, User* user);
	//SubMenuCustomer();
	void showScooters();
	void showScooters(User* user);
	void showBestScooters();
	void createReqest();
	void deleteReqest();
	void showReqests();
	void show();
};

