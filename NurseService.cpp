#include "NurseService.h"
#include "Nurse.h"
#include <mysql.h>
#include <sstream>

extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Nurse> nurseList;

void NurseService::AddNurse(Nurse nurse) {
	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO nurses (id,username,password,name,surname,phonenumber,adress) VALUES (" <<
		nurse.getId() << ",'" <<
		nurse.getUsername() << "','" <<
		nurse.getPassword() << "','" <<
		nurse.getName() << "','" <<
		nurse.getSurname() << "','" <<
		nurse.getPhoneNumber() << "','" <<
		nurse.getAdress() << "')";

	string b = a.str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
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

void NurseService::DeleteNurse(int nurseId) {

	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from nurses where id = " << nurseId;
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

Nurse NurseService::GetNurseById(int nurseId) {

	conn = mysql_init(0);
	stringstream a;
	a << "select * from nurses where id = " << nurseId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Nurse((int)row[0], (string)row[1], (string)row[2], (string)row[3], (string)row[4], (string)row[5], (string)
				row[6]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}

    return *new Nurse();
};

vector<Nurse> NurseService::GetAllNurse() {

	nurseList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from nurses";

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < count; i += 7)
			{
				int a = (int)row[i][i] - 48;
				Nurse nurse(a, (string)row[i + 1], (string)row[i + 2], (string)row[i + 3], (string)row[i + 4], (string)row[i + 5], (string)
					row[i + 6]);
				nurseList.push_back(nurse);

			}
		}
		return nurseList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
    return *new vector<Nurse>();

};
