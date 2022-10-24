#pragma once
#include <stdio.h>
#include <list>
#include "Secretary.h"

using namespace std;

class SecretaryService {
public:
    void AddSecretary(Secretary secretary);
    void DeleteSecretary(int secretaryId);
    Secretary GetSecretaryById(int secretaryId);
    list<Secretary> GetAllSecretary();
};
