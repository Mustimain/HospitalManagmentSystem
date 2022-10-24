#pragma once
#include <stdio.h>
#include "Employee.h"
#include <list>

using namespace std;

class EmployeeService {

public:
    void AddEmployee(Employee employee);
    void DeleteEmployee(int employeeId);
    Employee GetEmployeeById(int employeeId);
    list<Employee> GetAllEmployee();
};
