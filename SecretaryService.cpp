#include "SecretaryService.h"



void SecretaryService::AddSecretary(Secretary secretary) {

};

void SecretaryService::DeleteSecretary(int secretaryId) {

};

Secretary SecretaryService::GetSecretaryById(int secretaryId) {
    return *new Secretary();
};

vector<Secretary> SecretaryService::GetAllSecretary() {
    return *new vector<Secretary>();

};
