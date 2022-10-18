#include "File.h"
#include <fstream>
#include "Administrator.h"
#include <string>


File::File() {
	this->pathUsers = "E:\\CppProjects\\ScootersRent\\Store\\Users.txt";
	this->pathScooters = "E:\\CppProjects\\ScootersRent\\Store\\Scooters.txt";
	this->pathRequests = "E:\\CppProjects\\ScootersRent\\Store\\Requests.txt";

};

vector<string> explode(const string& delimiter, const string& str)
{
	vector<string> arr;
	int strleng = str.length();
	int delleng = delimiter.length();
	if (delleng == 0)
		return arr;//no change

	int i = 0;
	int k = 0;
	while (i < strleng)
	{
		int j = 0;
		while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
			j++;
		if (j == delleng)//found delimiter
		{
		
			arr.push_back(str.substr(k, i - k));
			i += delleng;
			k = i;
		}
		else
		{
			i++;
		}
	}
	string str1 = str.substr(k, i - k);
	arr.push_back(str.substr(k, i - k));
	return arr;
}


vector<User>  File::getUsers() {
	vector<User> users;
	ifstream file;
	file.open(this->pathUsers);
	if (file) {
		string line;

		while (getline(file, line)) {
			string underLine = line;
			vector<string> v = explode(" ", underLine);
			int id;
			string name;
			string email;
			int levelAccess;

			id = stoi(v[0]);
			name = v[1];
			email = v[2];
			levelAccess = stoi(v[3]);

			User user = User(name, email, levelAccess);
			user.setId(id);
			users.push_back(user);
		}
	}
	return users;

};

void File::saveUsers(vector<User> users) { 
	ofstream file(this->pathUsers);
	for (int i = 0; i < users.size(); i++) {
		file << users[i].getStringToDB();
	}
	file.close();

}

void File::saveScooters(vector<Scooter> scooters) {
	ofstream file(this->pathScooters);
	for (int i = 0; i < scooters.size(); i++) {
		file << scooters[i].getStringToDB();
	}
	file.close();

}
vector<Scooter> File::getScooters() {
	vector<Scooter> scooters;

	ifstream file;
	file.open(this->pathScooters);
	if (file) {
		string line;
		while (getline(file, line)) {
			string underLine = line;
			vector<string> v = explode(" ", underLine);
			int id;
			string model;
			string year;
			int batteryCap;
			int speed;
			int price;

			id = stoi(v[0]);
			model = v[1];
			year = v[2];
			batteryCap = stoi(v[3]);
			speed = stoi(v[4]);
			price = stoi(v[5]);
			Scooter scooter = Scooter(model, year, batteryCap, speed, price);
			scooter.setId(id);

			scooters.push_back(scooter);

	
		}
	}
	return scooters;

};

vector<Request> File::getRequests() {
	vector<Request> requests;

	ifstream file;
	file.open(this->pathRequests);
	if (file) {
		string line;
		while (getline(file, line)) {
			string underLine = line;
			vector<string> v = explode(" ", underLine);
			int id;
			int idUser;
			int idScooter;
			int status;

			id = stoi(v[0]);
			idUser = stoi(v[1]);
			idScooter = stoi(v[2]);
			status = stoi(v[3]);
	
			Request request = Request(idUser, idScooter, status);
			request.setId(id);

			requests.push_back(request);


		}
	}
	return requests;

};

void File::saveRequests(vector<Request> requests) {
	ofstream file(this->pathRequests);
	for (int i = 0; i < requests.size(); i++) {
		file << requests[i].getStringToDB();
	}
	file.close();

}


