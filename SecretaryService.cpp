#include "SecretaryService.h"
#include <mysql.h>
#include <sstream>
#include <iostream>

extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Secretary> secretaryList;

void SecretaryService::AddSecretary(Secretary secretary) {

	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO secretaries (id,username,password,name,surname,phonenumber,adress) VALUES (" <<
		secretary.getId() << ",'" <<
		secretary.getUsername() << "','" <<
		secretary.getPassword() << "','" <<
		secretary.getName() << "','" <<
		secretary.getSurname() << "','" <<
		secretary.getPhoneNumber() << "','" <<
		secretary.getAdress() << "')";

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

void SecretaryService::DeleteSecretary(int secretaryId) {


	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from secretaries where id = " << secretaryId;
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

Secretary SecretaryService::GetSecretaryById(int secretaryId) {

	conn = mysql_init(0);
	stringstream a;
	a << "select * from secretaries where id = " << secretaryId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Secretary(stoi(row[0]), (string)row[1], (string)row[2], (string)row[3], (string)row[4], (string)row[5], (string)
				row[6]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
    return *new Secretary();
};

vector<Secretary> SecretaryService::GetAllSecretary() {

	secretaryList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from secretaries";

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
				Secretary secretary(stoi(row[i]), (string)row[i + 1], (string)row[i + 2], (string)row[i + 3], (string)row[i + 4], (string)row[i + 5], (string)
					row[i + 6]);
				secretaryList.push_back(secretary);

			}
		}
		return secretaryList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
    return *new vector<Secretary>();

};
