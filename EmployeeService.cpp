#include "EmployeeService.h"
#include <mysql.h>
#include <sstream>


extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Employee> employeeList;

void EmployeeService::AddEmployee(Employee employee) {

	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO employeess (id,username,password,name,surname,phonenumber,adress,department) VALUES (" <<
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
		const char* query =b.c_str();
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
	a << "DELETE from employeess where id = " << employeeId;
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
	a << "select * from employeess where id = " << employeeId;

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

	employeeList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from employeess";

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);

		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < count; i += 8)
			{
				int a = (int)row[i][i] - 48;
				Employee employee(a, (string)row[i + 1], (string)row[i + 2], (string)row[i + 3], (string)row[i + 4], (string)row[i + 5], (string)
					row[i + 6], (string)row[i + 7]);
				employeeList.push_back(employee);

			}
		}
		return employeeList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
    return *new vector<Employee>();
};
