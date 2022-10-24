#include "EmployeeService.h"

void EmployeeService::AddEmployee(Employee employee) {

};

void EmployeeService::DeleteEmployee(int employeeId) {

};

Employee EmployeeService::GetEmployeeById(int employeeId) {
    return *new Employee();
};

list<Employee> EmployeeService::GetAllEmployee() {
    return *new list<Employee>();
};
