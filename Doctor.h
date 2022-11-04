#pragma once
#include "iostream"
#include "string"
#include "User.h"

using namespace std;

class Doctor : public User {
private:
    string name;
    string surname;
    string profession;
    string phoneNumber;
    string adress;

public:

    Doctor(int id, string username, string password, string name, string surname, string profession, string phoneNumber, string adress) : User(id, username, password) {

        this->name = name;
        this->surname = surname;
        this->profession = profession;
        this->phoneNumber = phoneNumber;
        this->adress = adress;
    }

    Doctor() :User() {

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

    string getProfession() {
        return this->profession;
    }

    void setProfession(string profession) {
        this->profession = profession;
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
