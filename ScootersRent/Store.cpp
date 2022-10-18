#include "Store.h"
#include <iostream>
#include "File.h"


using namespace std;
Store::Store(vector<User> users,vector<Scooter> scooters, vector<Request> requests) {
	this->users = users;
	this->scooters = scooters;
	this->requests = requests;
}

Store::Store(){
}

User* Store::getUserById(int id) {
	for (int i = 0; i < this->users.size(); i++) {
	if (this->users[i].getId() == id) {
	  return	&this->users[i];
	}
	}
	return NULL;
}

void Store::addUser(User user) {
	this->users.back().toString();
	int lastId =  this->users.back().getId();
	user.setId(lastId +1 );
	this->users.push_back(user);
	for (int i = 0; i < this->users.size(); i++) {
		this->users[i].toString();
	}
	cout << "The user has been successfully added\n";
	user.toString();
}

void Store::saveToFile() {
	File fileReader = File();
	cout << "before save users\n";
	for (int i = 0; i < this->users.size(); i++) {
		this->users[i].toString();
	}
	fileReader.saveUsers(this->users);

	cout << "before save scooters\n";
	for (int i = 0; i < this->scooters.size(); i++) {
		this->scooters[i].toString();
	}
	fileReader.saveScooters(this->scooters);

	cout << "before save requests\n";
	for (int i = 0; i < this->requests.size(); i++) {
		this->requests[i].toString();
	}
	fileReader.saveRequests(this->requests);
}

void Store::deleteUserById(int id) {
	User* user = this->getUserById(id);
	if (user!=NULL && user->isCustomer()) {
		cout << "\n\tUser has found and deleted \n";
		user->toString();
		int index = -1;
		for (int i = 0; i < this->users.size(); i++) {
			if (this->users[i].getId()==id) {
				index = i;
			}
		}
		if (index > -1) {
			this->users.erase(this->users.begin()+index);
		}
	}
	else {
		cout << "\n\tUser not found \n\n";
	}
}

void Store::showUsers() {
	cout << "\n\tUsers List \n";
	for (int i = 0; i < this->users.size(); i++) {
		this->users[i].toString();
	}
	cout << "\n\n";
}




// scooters block
void Store::addScooter(Scooter scooter) {

	int id = 1;
	if (this->scooters.size()) {
		int lastId = this->scooters.back().getId();
		id = lastId + 1;
	}

	scooter.setId(id);
	this->scooters.push_back(scooter);

	cout << "The scooter has been successfully added\n";

	scooter.toString();
}
Scooter* Store::getScooterById(int id) {
	for (int i = 0; i < this->scooters.size(); i++) {
		if (this->scooters[i].getId() == id) {
			return	&this->scooters[i];
		}
	}
	return NULL;
}


void Store::deleteScooterById(int id) {
	
	Scooter* scooter = this->getScooterById(id);
	if (scooter != NULL) {
		cout << "\n\Scooter has found and deleted \n";
		scooter->toString();
		int index = -1;
		for (int i = 0; i < this->scooters.size(); i++) {
			if (this->scooters[i].getId() == id) {
				index = i;
			}
		}
		if (index > -1) {
			this->scooters.erase(this->scooters.begin() + index);
		}
	}
	else {
		cout << "\n\tScooter not found \n\n";
	}
}

void Store::showScooters() {
	cout << "\n\tScooters List \n";
	for (int i = 0; i < this->scooters.size(); i++) {
		this->scooters[i].toString();
	}
	cout << "\n\n";
}


// request block
void Store::addRequest(Request request) {

	int id = 1;
	if (this->requests.size()) {
		int lastId = this->requests.back().getId();
		id = lastId + 1;
	}
	request.setId(id);
	this->requests.push_back(request);
	cout << "The request has been successfully added\n";
	request.toString();
}



Request* Store::getRequestById(int id) {
	for (int i = 0; i < this->requests.size(); i++) {
		if (this->requests[i].getId() == id) {
			return	&this->requests[i];
		}
	}
	return NULL;
}

void Store::deleteRequestById(int id) {

	Request* request = this->getRequestById(id);

	if (request != NULL) {
		cout << "\n\Request has found and deleted \n";
		request->toString();
		int index = -1;
		for (int i = 0; i < this->requests.size(); i++) {
			if (this->requests[i].getId() == id) {
				index = i;
			}
		}
		if (index > -1) {
			this->requests.erase(this->requests.begin() + index);
		}
	}
	else {
		cout << "\n\tRequest not found \n\n";
	}
}
void Store::deleteRequestById(int id,User* user) {

	Request* request = this->getRequestById(id);

	if (request != NULL && request->getUserId()==user->getId()) {
		this->deleteRequestById(id);
	}
	else {
		cout << "\n\tAccess denied\n\n";
	}
}

void Store::showRequests() {
	cout << "\n\tRequests List \n";
	for (int i = 0; i < this->requests.size(); i++) {
		this->requests[i].toString();
	}
	cout << "\n\n";
}
void Store::showRequests(User* user) {
	cout << "\n\tMy Requests List \n";
	for (int i = 0; i < this->requests.size(); i++) {
		if (this->requests[i].getUserId() == user->getId()) {
			this->requests[i].toString();
		}
	}
	cout << "\n\n";
}

void Store::changeStatusRequest(int id, int status) {

	Request* request = this->getRequestById(id);

	if (request != NULL) {
		cout << "\n\Request has found and edited \n";
		request->setStatus(status);
		request->toString();
	}
	else {
		cout << "\n\tRequest not found \n\n";
	}
}
