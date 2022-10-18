#include "Administrator.h"

Administrator::Administrator(string name, string email):User( name,email, LEVEL_ADMINISTRATOR) {

}

Administrator::Administrator(string name, string email,int id) :User(name, email, LEVEL_ADMINISTRATOR,id) {

}