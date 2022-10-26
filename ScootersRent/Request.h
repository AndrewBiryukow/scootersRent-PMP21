#pragma once
#include <iostream>
using namespace std;
const int STATUS_NEW = 1;
const int STATUS_APPROWED = 2;
const int STATUS_REJECTED = 3;
class Request
{
private:
	int id;
	int idUser;
	int idScooter;
	int status;
public:
	Request(int idUser,int idScooter,int status);

	void toString();
	string getStringToDB();
	int getId();
	int getUserId();
	void setId(int id);
	void setStatus(int status);
	int getIdScooter();

	bool operator==(Request request);



};


