#include "Scooter.h"
#include "Helper.h"
#include <iostream>
Scooter::Scooter(string model, string year, int batteryCap, int speed, int price) {
	this->model = model;
	this->year = year;
	this->batteryCap = batteryCap;
	this->speed = speed;
	this->price = price;
}


void Scooter::toString() {
	double ratioCurrent =  ((double)this->speed / (double)this->price) + ((double)this->batteryCap / (double)this->price);
	printf("id: %d, Model: %s, Year: %s, Battery: %d, Speed: %d, Price: $%d, Rating: %f\n", this->id, this->model.c_str(), this->year.c_str()
		, this->batteryCap,this->speed,this->price,ratioCurrent);
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
void Scooter::setPrice(int price) {
	this->price = price;
}




// overloaded
bool Scooter::operator>(Scooter next) {
	double ratioCurrent = ((double)this->speed / (double)this->price) + ((double)this->batteryCap / (double)this->price);
	double ratioNext = ((double)next.speed / (double)next.price) + ((double)next.batteryCap / (double)next.price);
	if (ratioCurrent > ratioNext) {
		return true;
	}
	else {
		return false;
	}
}
bool Scooter::operator<(Scooter next) {
	double ratioCurrent = ((double)this->speed / (double)this->price) + ((double)this->batteryCap / (double)this->price);
	double ratioNext = ((double)next.speed / (double)next.price) + ((double)next.batteryCap / (double)next.price);
	if (ratioCurrent < ratioNext) {
		return true;
	}
	else {
		return false;
	}
}

void Scooter::operator+=(int percent) {
	(*this).price=Helper::addCalculatedValuePercent((*this).price, percent);
	(*this).speed =Helper::addCalculatedValuePercent((*this).speed, percent);
	(*this).batteryCap =Helper::addCalculatedValuePercent((*this).batteryCap, percent);
}

void Scooter::operator-=(int percent) {
	(*this).price = Helper::minusCalculatedValuePercent((*this).price, percent);
	(*this).speed = Helper::minusCalculatedValuePercent((*this).speed, percent);
	(*this).batteryCap = Helper::minusCalculatedValuePercent((*this).batteryCap, percent);
}

