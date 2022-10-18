#include "User.h"
#include <iostream>
#include <random>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

User::User(string name, string email, int levelAccess) {
	this->id = abs(rand());
	this->name = name;
	this->email = email;
	this->levelAccess = levelAccess;


}

User::User(string name, string email, int levelAccess,int id) {
	this->id = id;
	this->name = name;
	this->email = email;
	this->levelAccess = levelAccess;
}

void User::toString() {
	string level = "***";
	if (this->levelAccess == LEVEL_ADMINISTRATOR) {
		level = "Administrator";
	}
	else if (this->levelAccess == LEVEL_CUSTOMER) {
		level = "Customer";
	}
	else {
		cout << "LEVEL(bug): " << this->levelAccess<< endl;
	}
	printf("%s - id: %d, Name: %s, Email: %s\n", level.c_str(),this->id,this->name.c_str(),this->email.c_str());
}

string User::getStringToDB() {
	string data =""+ std::to_string(this->id) + " " + this->name + " " + this->email + " " + std::to_string(this->levelAccess) +"\n";
	return data;
	
}
int User::getId() {
	return this->id;
}

void User::setId(int id) {
	this->id = id;
}

bool User::isCustomer() {
	return this->levelAccess == LEVEL_CUSTOMER;
}
bool User::isAdmin() {
	return this->levelAccess == LEVEL_ADMINISTRATOR;
}