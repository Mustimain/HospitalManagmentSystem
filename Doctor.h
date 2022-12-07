#pragma once
#include "iostream"
#include "string"
#include "User.h"

using namespace std;

class Doctor : public User {
private:

    string profession;


public:

    Doctor(int id, string username, string password, string name, string surname, string profession, string phoneNumber, string adress) : User(id, username, password,name,surname,phoneNumber,adress) {

        this->profession = profession;
    }

    Doctor() :User() {

    }

    string getProfession() {
        return this->profession;
    }

    void setProfession(string profession) {
        this->profession = profession;
    }


};
