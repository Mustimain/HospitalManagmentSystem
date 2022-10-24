#include "DbContext.h"
#include <iostream>
#include <sstream>

using namespace std;


int DbContext::callback(void* data, int argc, char** argv, char** azColName)
{
    int i;
    fprintf(stderr, "%s: ", (const char*)data);

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}

string DbContext::IntToString(int a) {

    stringstream ss;
    string result;

    ss << a;
    ss >> result;

    return result;

}