#pragma once
#include <stdio.h>
#include <vector>
#include "Secretary.h"

using namespace std;

class SecretaryService {
public:
    void AddSecretary(Secretary secretary);
    void DeleteSecretary(int secretaryId);
    Secretary GetSecretaryById(int secretaryId);
    vector<Secretary> GetAllSecretary();
};
