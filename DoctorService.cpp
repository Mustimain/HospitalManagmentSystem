#include "DoctorService.h"
#include "Doctor.h"
#include <iostream>
#include <mysql.h>
#include <sstream>
using namespace std;


extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Doctor> doctorList;

void DoctorService::AddDoctor(Doctor doctor) {


	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO doctors (id,username,password,name,surname,profession,phonenumber,adress) VALUES (" <<
		doctor.getId() << ",'" <<
		doctor.getUsername() << "','" <<
		doctor.getPassword() << "','" <<
		doctor.getName() << "','" <<
		doctor.getSurname() << "','" <<
		doctor.getProfession() << "','" <<
		doctor.getPhoneNumber() << "','" <<
		doctor.getAdress() << "')";
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

void DoctorService::DeleteDoctor(int doctorId) {

	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from doctors where id = " << doctorId;
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

Doctor DoctorService::GetDoctorById(int doctorId) {

	conn = mysql_init(0);
	stringstream a;
	a << "select * from doctors where id = " << doctorId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Doctor((int)row[0], (string)row[1], (string)row[2], (string)row[3], (string)row[4], (string)row[5], (string)
				row[6], (string)row[7]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}

	return *new Doctor();
};

vector<Doctor> DoctorService::GetAllDoctor() {

	doctorList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from doctors";

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < count; i+=8)
			{
				int a = (int)row[i][i]-48;
				Doctor doctor(a, (string)row[i+1], (string)row[i + 2], (string)row[i + 3], (string)row[i + 4], (string)row[i + 5], (string)
					row[i + 6], (string)row[i + 7]);
				doctorList.push_back(doctor);
				
			}
		}
		return doctorList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
	return *new vector<Doctor>();
};

