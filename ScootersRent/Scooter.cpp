#include "Scooter.h"

Scooter::Scooter(string model, string year, int batteryCap, int speed, int price) {
	this->model = model;
	this->year = year;
	this->batteryCap = batteryCap;
	this->speed = speed;
	this->price = price;
}


void Scooter::toString() {
	printf("id: %d, Model: %s, Year: %s, Battery: %d, Speed: %d, Price: $%d\n", this->id, this->model.c_str(), this->year.c_str()
		, this->batteryCap,this->speed,this->price);
}

string Scooter::getStringToDB() {
	string data = "" + std::to_string(this->id) + " " + this->model + " " + this->year + " " + std::to_string(this->batteryCap) 
		+ " " + std::to_string(this->speed) + " " + std::to_string(this->price) + "\n";
	return data;

}

int Scooter::getId() {
	return this->id;
}

void Scooter::setId(int id) {
	this->id = id;
}