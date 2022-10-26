#pragma once
#include <stdio.h>
#include <vector>
#include "Doctor.h"

using namespace std;

class DoctorService {
public:
    void AddDoctor(Doctor doctor);
    void DeleteDoctor(int doctorId);
    Doctor GetDoctorById(int doctorId);
    vector<Doctor> GetAllDoctor();
};
