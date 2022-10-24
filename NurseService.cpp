#include "NurseService.h"
#include "Nurse.h"


void NurseService::AddNurse(Nurse nurse) {

};

void NurseService::DeleteNurse(int nurseId) {

};

Nurse NurseService::GetNurseById(int nurseId) {
    return *new Nurse();
};

list<Nurse> NurseService::GetAllNurse() {
    return *new list<Nurse>();

};
