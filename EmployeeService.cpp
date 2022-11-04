#include "EmployeeService.h"
#include <mysql.h>
#include <sstream>


MYSQL* conn;
MYSQL_RES* result;
MYSQL_ROW row;
vector<Employee> nurseList;

void EmployeeService::AddEmployee(Employee employee) {

	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO employees (id,username,password,name,surname,phonenumber,adress,department) VALUES (" <<
		employee.getId() << ",'" <<
		employee.getUsername() << "','" <<
		employee.getPassword() << "','" <<
		employee.getName() << "','" <<
		employee.getSurname() << "','" <<
		employee.getPhoneNumber() << "','" <<
		employee.getAdress() << "','" <<
		employee.getDepartment() << "')";

	string b = a.str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		cout << "sql baglandi" << endl;
		const char* query = b.c_str();
		if (!(mysql_query(conn, query)))
		{
			cout << "kayit tamam";
		}
		else
		{
			cout << "kayit olmadi";
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
};

void EmployeeService::DeleteEmployee(int employeeId) {

	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from employees where id = " << employeeId;
	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{

		if (!(mysql_query(conn, query)))
		{
			cout << "Silme islemi tamam";
		}
		else
		{
			cout << "Silme islemi basarisiz";
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
};

Employee EmployeeService::GetEmployeeById(int employeeId) {


	conn = mysql_init(0);
	stringstream a;
	a << "select * from doctors where id = " << employeeId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Employee((int)row[0], (string)row[1], (string)row[2], (string)row[3], (string)row[4], (string)row[5], (string)
				row[6], (string)row[7]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}

    return *new Employee();
};

vector<Employee> EmployeeService::GetAllEmployee() {
    return *new vector<Employee>();
};
