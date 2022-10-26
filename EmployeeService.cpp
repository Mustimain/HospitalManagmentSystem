#include "EmployeeService.h"

void EmployeeService::AddEmployee(Employee employee) {

};

void EmployeeService::DeleteEmployee(int employeeId) {

};

Employee EmployeeService::GetEmployeeById(int employeeId) {
    return *new Employee();
};

vector<Employee> EmployeeService::GetAllEmployee() {
    return *new vector<Employee>();
};
