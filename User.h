#pragma once
#include <stdio.h>
#include "string"

using namespace std;

class User {
private:
    int id;
    string username;
    string password;
    string name;
    string surname;
    string phoneNumber;
    string adress;
public:

    User(int id, string username, string password, string name, string surname, string phoneNumber, string adress) {
        this->id = id;
        this->username = username;
        this->password = password;
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        this->adress = adress;

    }
    User() {

    }

    int getId() {
        return this->id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getUsername() {
        return this->username;
    }

    void setUsername(string username) {
        this->username = username;
    }

    string getPassword() {
        return this->password;
    }

    void setPassword(string password) {
        this->password = password;
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