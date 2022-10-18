#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include <vector>
#include "Scooter.h"
#include "Request.h"

using namespace std;

class File
{
private:
	string pathUsers;
	string pathScooters;
	string pathRequests;



public:
	File();
	vector<User> getUsers();
	vector<Scooter> getScooters();
	vector<Request> getRequests();

	//vector<User> getUsers3();
	void saveUsers(vector<User> users);
	void saveScooters(vector<Scooter> scooters);
	void saveRequests(vector<Request> requests);
	
};

