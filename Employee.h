#pragma once
#include <stdio.h>
#include "string"
#include "Doctor.h"

using namespace std;

class Employee : public User {
private:
    string name;
    string surname;
    string phoneNumber;
    string adress;

public:

    Employee(int id, string password, string username, string name, string surname, string phoneNumber, string adress, int roleId) : User(id, username, password, roleId) {
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        this->adress = adress;
    }
    Employee() :User() {

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


