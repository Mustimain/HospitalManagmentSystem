#pragma once
#include <stdio.h>
#include "string"

using namespace std;

class User {
private:
    int id;
    string username;
    string password;
    int roleId;
public:

    User(int id, string username, string password, int roleId) {
        this->id = id;
        this->username = username;
        this->password = password;
        this->roleId = roleId;

    }
    User() {

    }

    int getId() {
        return this->id;
    }

    void setId(int id) {
        this->id = id;
    }

    string getUsername() {
        return this->username;
    }

    void setUsername(string username) {
        this->username = username;
    }

    string getPassword() {
        return this->password;
    }

    void setPassword(string password) {
        this->password = password;
    }

    int getRoleId() {
        return this->roleId;
    }

    void setRoleId(int roleId) {
        this->roleId = roleId;
    }


};