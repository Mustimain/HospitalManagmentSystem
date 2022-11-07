#pragma once
#include <stdio.h>
#include "string"
#include "User.h"
using namespace std;


class Secretary : public User {

private:


public:

    Secretary(int id, string username, string password, string name, string surname, string phoneNumber, string adress) : User(id, username, password,name,surname,phoneNumber,adress) {

        
    }
    Secretary() :User() {

    }

};