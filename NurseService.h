#pragma once
#include <stdio.h>
#include <vector>
#include "Nurse.h"

using namespace std;

class NurseService {
public:
    void AddNurse(Nurse nurse);
    void DeleteNurse(int nurseId);
    Nurse GetNurseById(int nurseId);
    vector<Nurse> GetAllNurse();
};
