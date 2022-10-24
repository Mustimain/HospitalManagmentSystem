#pragma once
#include <stdio.h>
#include "string"
#include "User.h"
using namespace std;


class Patient {

private:
    int id;
    string tcNo;
    string name;
    string surname;
    string adress;
    string phoneNumber;
    string bloodGroup;
    string gender;
    string birthDate;


public:
    Patient(int id, string tcNo, string name, string surname, string adress, string phoneNumber, string bloodGroup, string gender, string birthDate) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->tcNo = tcNo;
        this->adress = adress;
        this->phoneNumber = phoneNumber;
        this->bloodGroup = bloodGroup;
        this->gender = gender;
        this->birthDate = birthDate;
    }

    Patient() {
    }

    int getId() {
        return this->id;
    }

    void setId(int id) {
        this->id = id;
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

    string getTcNo() {
        return this->tcNo;
    }

    void setTcNo(string tcNo) {
        this->tcNo = tcNo;
    }

    string getAdress() {
        return this->adress;
    }

    void setAdress(string adress) {
        this->adress = adress;
    }

    string getPhoneNumber() {
        return this->phoneNumber;
    }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    string getBloodGroup() {
        return this->bloodGroup;
    }

    void setBloodGroup(string bloodGroup) {
        this->bloodGroup = bloodGroup;
    }


    string getGender() {
        return this->gender;
    }

    void setGender(string gender) {
        this->gender = gender;
    }

    string getBirthDate() {
        return this->birthDate;
    }

    void setBirthDate(string birthDate) {
        this->birthDate = birthDate;
    }
};
