#pragma once
#include <stdio.h>
#include "string"
#include "User.h"
using namespace std;


class Secretary : public User {

private:
    string name;
    string surname;

public:
    Secretary(int id, string username, string password, string name, string surname, int roleId) : User(id, username, password, roleId) {
        this->name = name;
        this->surname = surname;
    }

    Secretary() :User() {
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

};