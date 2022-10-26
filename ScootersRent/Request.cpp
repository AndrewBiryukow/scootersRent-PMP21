#include "Request.h"
#include <string>
//#include <iostream>
//using namespace std;

Request::Request(int idUser, int idScooter, int status) {
	this->idUser = idUser;
	this->idScooter = idScooter;
	this->status = status;

};

void Request::toString() {
	string status = "***";
	if (this->status == STATUS_NEW) {
		status = "New";
	}
	else if (this->status == STATUS_APPROWED) {
		status = "Approved";
	}
	else if (this->status == STATUS_REJECTED) {
		status = "Rejected";
	}
	else {
		cout << "STATUS(bug): " << this->status << endl;
	}
	printf("id: %d, User id: %d, Scooter id: %d, Status: %s\n", this->id, this->idUser, this->idScooter,status.c_str());
}

string Request::getStringToDB() {
	string data = "" + std::to_string(this->id) + " " + std::to_string(this->idUser) + " " + std::to_string(this->idScooter) + " " + std::to_string(this->status) + "\n";
	return data;

}


int Request::getUserId() {
	return this->idUser;
}
int Request::getId() {
	return this->id;
}

int Request::getIdScooter() {
	return this->idScooter;
}

void Request::setId(int id) {
	this->id = id;
}
void Request::setStatus(int status) {
	this->status = status;
}

bool Request::operator==(Request request) {
	if (this->idScooter == request.getIdScooter())
	{
		return true;
	}
	else {
		return false;
	}
}


bool Request::operator!=(Request request) {
	if (this->idScooter != request.getIdScooter())
	{
		return true;
	}
	else {
		return false;
	}
}