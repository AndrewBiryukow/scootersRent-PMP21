#include "SubMenuCustomer.h"
#include <iostream>

using namespace std;

SubMenuCustomer::SubMenuCustomer(Store* store, User* user) {
	this->store = store;
	this->user = user;
}
//SubMenuCustomer::SubMenuCustomer() {
//
//}
void SubMenuCustomer::show() {
	int userChoice;
	int userSubChoice;

	do {
		cout << "Select operation(customer) \n\n";
		cout << "1.Show Scooters\n";
		cout << "2.Create Request\n";
		cout << "3.Delete Request\n";
		cout << "4.Show my Requests\n";
//		cout << "5.Show my Scooters\n\n";

		cout << "0.Previous menu\n";

		cin >> userChoice;

		switch (userChoice) {
		case 1:
			do {
				cout << "\n1.Show Scooters\n";
				cout << "2.Show Best Scooters\n";
				cout << "0.Previous menu\n";
				cin >> userSubChoice;
				switch (userSubChoice) {
				case 1:
					this->showScooters();
					break;
				case 2:
					this->showBestScooters();
					break;

					break;
				default:
					break;
				}
			} while (userSubChoice != 0);
		break;
		case 2:
			this->createReqest();
			break;
		case 3:
			this->deleteReqest();
			break;
		case 4:
			this->showReqests();
			break;
		case 5:
			this->showScooters(this->user);
			break;


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

void SubMenuCustomer::showScooters() {
	this->store->showScooters();
}

void SubMenuCustomer::showScooters(User* user) {
	this->store->showScooters();
}

void SubMenuCustomer::showBestScooters() {
	Sorts sort = Sorts::SORT_PRICE;
	this->store->showScooters(sort);
}

//Requests
void SubMenuCustomer::createReqest() {

	//----------------
	int idUser;
	int idScooter;
	idUser = this->user->getId();;

		cout << "Enter  id  of scooter:" << endl;
		cin >> idScooter;
		Scooter* scooter  = this->store->getScooterById(idScooter);
		// todo equal_with_request

		if (scooter == NULL) {
			cout << "\tScooter not found\n" << endl;
			return;
		}
	Request request = Request(idUser, idScooter,STATUS_NEW);
	for (int i = 0; i < this->store->getRequests().size(); i++)
	{
		// it's working block operator!= overload 
		/*if (request == this->store->getRequests()[i]) {
			cout << "This scooter is already busy" << endl;
			return;
		}*/
		// it's working block operator== overload 
		if ( !(request != this->store->getRequests()[i]) ) {
			cout << "This scooter is already busy" << endl;
			return;
		}
	}
	this->store->addRequest(request);
}
void SubMenuCustomer::deleteReqest() {
	int id;
	cout << "Input request's id for delete: ";
	cin >> id;

	this->store->deleteRequestById(id, this->user);
}

void SubMenuCustomer::showReqests() {
	this->store->showRequests(this->user);
}
