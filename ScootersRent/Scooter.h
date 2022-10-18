#pragma once
#include <string>
using namespace std;

class Scooter
{
private:
	int id;
	string model;
	string year;
	int batteryCap;
	int speed;
	int price;
public:
	Scooter(string model, string year, int batteryCap, int speed, int price);
	void toString();
	string getStringToDB();
	int getId();
	void setId(int id);
};

