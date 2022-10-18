#include <iostream>
#include "User.h"
#include "Administrator.h"
#include "Customer.h"
#include "File.h"
#include "Menu.h"
#include "Store.h"
#include "Request.h"

using namespace std;

int main()
{   
    srand(time(NULL)); //initial rand
    std::cout << "\tWelcome to our scooter shop!\n";


    File fileReader = File();
    vector<User> users=  fileReader.getUsers();
    vector<Scooter> scooters = fileReader.getScooters();
    vector<Request> requests = fileReader.getRequests();

    if (!users.size()) {
        Administrator admin = Administrator("admin", "admin@gmail.com",1);
        users.push_back(admin);
    }


    Store store = Store(users,scooters, requests);
    Menu menu=Menu(&store);



    menu.selectUser();

 








    store.saveToFile();


}

