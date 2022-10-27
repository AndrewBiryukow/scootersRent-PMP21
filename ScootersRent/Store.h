#pragma once
#include "User.h";
#include <vector>
#include "Scooter.h"
#include "Request.h"
#include "Sorts.h"

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
	void showScooters(Sorts sort = Sorts());
	void updateScooter(Scooter scooter);

	void addRequest(Request user);
	void deleteRequestById(int id);
	void deleteRequestById(int id, User* user);
	Request* getRequestById(int id);
	void showRequests();
	vector<Request> getRequests();
	void showRequests(User* user);
	void changeStatusRequest(int id,int status);
	vector<Scooter> bubbleSortingByPrice(vector<Scooter> scooters);
	

	
};

