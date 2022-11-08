#pragma once
#include <stdio.h>
#include "string"
#include "Doctor.h"

using namespace std;

class Employee : public User {
private:

    string department;

public:

    Employee(int id, string username, string password, string name, string surname,string department, string phoneNumber, string adress) : User(id, username, password,name,surname,phoneNumber,adress) {
        
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


