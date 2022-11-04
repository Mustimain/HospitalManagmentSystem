#pragma once
#include <stdio.h>
#include "string"
#include "Doctor.h"

using namespace std;

class Nurse : public User {
private:
    string name;
    string surname;
    string phoneNumber;
    string adress;

public:

    Nurse(int id, string username, string password, string name, string surname, string phoneNumber, string adress) : User(id, username, password) {
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        this->adress = adress;
    }
    Nurse() :User() {

    }



    string getName() {
        return this->name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getSurname() {
        return this->surname;
    }

    void setSurname(string surname) {
        this->surname = surname;
    }

    string getPhoneNumber() {
        return this->phoneNumber;
    }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    string getAdress() {
        return this->adress;
    }

    void setAdress(string adress) {
        this->adress = adress;
    }

};
