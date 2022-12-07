#pragma once
#include <stdio.h>
#include "string"
#include "Doctor.h"

using namespace std;

class Nurse : public User {
private:


public:

    Nurse(int id, string username, string password, string name, string surname, string phoneNumber, string adress) : User(id, username, password,name,surname,phoneNumber,adress) {

    }
    Nurse() :User() {

    }

};
