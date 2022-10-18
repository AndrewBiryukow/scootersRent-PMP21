#pragma once
#include "User.h";
#include <vector>
#include "Scooter.h"
#include "Request.h"

class Store
{
private:
	vector<User> users;
	vector<Scooter> scooters;
	vector<Request> requests;

public:
	Store(vector<User> users, vector<Scooter> scooters, vector<Request> requests);
	Store();
	User* getUserById(int id);
	void addUser(User user);
	void deleteUserById(int id);
	void saveToFile();
	void showUsers();

	void addScooter(Scooter scooter);
	void deleteScooterById(int id);
	Scooter* getScooterById(int id);
	void showScooters();

	void addRequest(Request user);
	void deleteRequestById(int id);
	void deleteRequestById(int id, User* user);
	Request* getRequestById(int id);
	void showRequests();
	void showRequests(User* user);
	void changeStatusRequest(int id,int status);
	
	
	//User* getUserByEmail(string email);

	
};

