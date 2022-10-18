#pragma once
#include <string>

using namespace std;

const int LEVEL_ADMINISTRATOR = 1;
const int LEVEL_CUSTOMER = 2;

class User
{
private:
	int id;
	int levelAccess;
	string name;
	string email;
public:
	User(string name, string email,int levelAccess);
	User(string name, string email,int levelAccess,int id);
	//void scooters();
	void toString();
	string getStringToDB();
	int getId();
	void setId(int id);
	bool isCustomer();
	bool isAdmin();
	/*int makeRecord();*/
	


};

