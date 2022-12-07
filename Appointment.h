#pragma once
#pragma once
#include "iostream"
#include "string"
#include "Appointment.h"

using namespace std;

class Appointment {
private:

    int id;
    int doctorId;
    int patientId;
    string date;
    bool isCompleted;


public:

    Appointment(int id,int doctorId,int patientId,string date,bool isCompleted) {
        this->id = id;
        this->doctorId = doctorId;
        this->patientId = patientId;
        this->date = date;
        this->isCompleted = isCompleted;
    }

    Appointment() {

    }

    int getId() {
        return this->id;
    }

    void setId(int id) {
        this->id = id;
    }

    int getDoctorId() {
        return this->doctorId;
    }

    void setDoctorId(int doctorId) {
        this->doctorId = doctorId;
    }

    int getPatientId() {
        return this->patientId;
    }

    void setPatientId(int patientId) {
        this->patientId = patientId;
    }


    string getDate() {
        return this->date;
    }

    void setProfession(string date) {
        this->date = date;
    }

    bool getIsCompleted() {
        return this->isCompleted;
    }

    void setIsCompleted(bool isCompleted) {
        this->isCompleted = isCompleted;
    }


};
