#include "Menu.h"
#include <iostream>
#include <vector>
#include "SubMenuAdministrator.h"
#include "SubMenuCustomer.h"
using namespace std;

Menu::Menu(Store* store) {

	this->store = store;

}

void Menu::selectUser() {
	int userChoice;
	//comment this(debug list)
	this->store->showUsers();
	//this->store->showScooters();
	//this->store->showRequests();

	do {
			cout << "Select user by id\n";
			cout << "For exit enter 0\n";
			cin >> userChoice;
		User* user = this->store->getUserById(userChoice);
		if (user==NULL){
			cout << "User not found\n";
		}
		else {
			user->toString();
			if (user->isAdmin()) {
				SubMenuAdministrator menu = SubMenuAdministrator(this->store);
				menu.show();
			}
			else if (user->isCustomer()) {
				SubMenuCustomer menu = SubMenuCustomer(this->store,user);
				menu.show();
			}
		    
	
		}
	} while (userChoice != 0);
}


