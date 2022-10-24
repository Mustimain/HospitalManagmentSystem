#include "PatientService.h"
#include "Patient.h"

void PatientService::AddPatient(Patient patient) {

};

void PatientService::DeletePatient(int patientId) {

};

Patient PatientService::GetPatientById(int patientId) {
    return *new Patient();
};

list<Patient> PatientService::GetAllPatient() {
    return *new list<Patient>();
};
