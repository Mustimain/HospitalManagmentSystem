#pragma once
#include <stdio.h>
#include "Employee.h"
#include <vector>

using namespace std;

class EmployeeService {

public:
    void AddEmployee(Employee employee);
    void DeleteEmployee(int employeeId);
    Employee GetEmployeeById(int employeeId);
    vector<Employee> GetAllEmployee();
};
