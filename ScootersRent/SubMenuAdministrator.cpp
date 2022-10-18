#include "SubMenuAdministrator.h"
#include <iostream>
#include "Customer.h"
#include "Store.h"
#include "Scooter.h"

using namespace std;

SubMenuAdministrator::SubMenuAdministrator(Store* store) {
	this->store = store;
}
SubMenuAdministrator::SubMenuAdministrator() {

}
void SubMenuAdministrator::show() {
	int userChoice;

	do {
			cout << "Select operation(administrator)\n\n";
			cout << "1.Create User\n";
			cout << "2.Delete User\n";
			//cout << "3.Update User\n";
			cout << "3.Show Users\n\n";
			
			cout << "4.Create Scooter\n";
			cout << "5.Delete Scooter\n";
			cout << "6.Show Scooters\n\n";
			
			cout << "7.Show Requests\n";
			cout << "8.Edit Request\n\n";

			cout << "0.Previous menu\n";

			cin >> userChoice;

			switch (userChoice){
			case 1:
				this->createUser();
				break;
			case 2:
				this->deleteUser();
				break;
			case 3:
				this->showUsers();
				break;
			case 4:
				this->createScooter();
				break;
			case 5:
				this->deleteScooter();
				break;
			case 6:
				this->showScooters();
				break;
			case 7:
				this->showRequests();
				break;
			case 8:
				this->editRequest();
				break;


				
			default:
				break;
			}

			//User* user = this->getUserById(userChoice);
			//if (user == NULL) {
			//	cout << "User not found\n";
			//}
			//else {
			//	user->toString();

			//}


	} while (userChoice != 0);
}

//Users
void SubMenuAdministrator::createUser() {
	string name;
	string email;
	cout << "Input name:"<< endl;
	cin >> name;
	cout << "Input email:" << endl;
	cin >> email;
	Customer customer = Customer(name,email);
	this->store->addUser(customer);
}
void SubMenuAdministrator::deleteUser() {
	int id;
	cout << "Input user's id for delete: ";
	cin >> id;
	this->store->deleteUserById(id);
}
void SubMenuAdministrator::showUsers() {
	this->store->showUsers();
}

//Scooters
void SubMenuAdministrator::createScooter() {
	string model;
	string year;
	int batteryCap;
	int speed;
	int price;

		cout << "Enter a model of scooter:" << endl;
		cin >> model;
		cout << "Enter a year of model:" << endl;
		cin >> year;
		cout << "Enter a battery capacity:" << endl;
		cin >> batteryCap;
		cout << "Enter a speed of model:" << endl;
		cin >> speed;
		cout << "Enter a price per hour of usage:" << endl;
		cin >> price;

	Scooter scooter = Scooter(model, year, batteryCap, speed, price);
	this->store->addScooter(scooter);
}

void SubMenuAdministrator::deleteScooter() {
	int id;
	cout << "Input scooter's id for delete: ";
	cin >> id;
	this->store->deleteScooterById(id);
}

void SubMenuAdministrator::showScooters() {
	this->store->showScooters();
}


void SubMenuAdministrator::showRequests() {
	this->store->showRequests();
}
void SubMenuAdministrator::editRequest() {
	int id;
	int status;
	cout << "Input id request:" << endl;
	cin >> id;
	Request* request = this->store->getRequestById(id);
	if (request == NULL) {
		cout << "\n\tRequest not found\n\n";
		return;
	}

	cout << "Input status:\n2-Approve, 3-Reject" << endl;
	cin >> status;
	if (status != STATUS_APPROWED && status != STATUS_REJECTED) {
		cout << "\n\tForbidden status\n\n";
		return;
	}

	this->store->changeStatusRequest(id,status);
}



