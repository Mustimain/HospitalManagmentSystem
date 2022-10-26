#pragma once
#include <stdio.h>
#include "Patient.h"
#include <vector>

using namespace std;

class PatientService {
public:
    void AddPatient(Patient patient);
    void DeletePatient(int patientId);
    Patient GetPatientById(int patientId);
    vector<Patient> GetAllPatient();

};
