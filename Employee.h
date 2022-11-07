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
    string department;

public:

    Employee(int id, string password, string username, string name, string surname,string department, string phoneNumber, string adress) : User(id, username, password,name,surname,phoneNumber,adress) {
        
        this->department = department;
    }
    Employee() :User() {

    }


    string getDepartment() {
        return this->department;
    }

    void setDepartment(string department) {
        this->department = department;
    }
};


