#include "PatientService.h"
#include "Patient.h"
#include <mysql.h>
#include <sstream>
#include <iostream>


extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Patient> patientList;

void PatientService::AddPatient(Patient patient) {

	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO patients (id,tcNo,name,surname,adress,phoneNumber,bloodGroup,gender,birthDate) VALUES (" <<
		patient.getId() << ",'" <<
		patient.getTcNo() << "','" <<
		patient.getName() << "','" <<
		patient.getSurname() << "','" <<
		patient.getAdress() << "','" <<
		patient.getPhoneNumber() << "','" <<
		patient.getBloodGroup() << "','" <<
		patient.getGender() << "','" <<
		patient.getBirthDate() << "')";

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

void PatientService::DeletePatient(int patientId) {

	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from patients where id = " << patientId;
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

Patient PatientService::GetPatientById(int patientId) {

	conn = mysql_init(0);
	stringstream a;
	a << "select * from patients where id = " << patientId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Patient(stoi(row[0]), (string)row[1], (string)row[2], (string)row[3], (string)row[4], (string)row[5], (string)
				row[6], (string)row[7], (string)row[8]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}

	return *new Patient();
};

vector<Patient> PatientService::GetAllPatient() {

	patientList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from patients";

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < count; i += 9)
			{
				Patient patient(stoi(row[i]), (string)row[i + 1], (string)row[i + 2], (string)row[i + 3], (string)row[i + 4], (string)row[i + 5], (string)
					row[i + 6], (string)row[i + 7], (string)row[i + 8]);
				patientList.push_back(patient);

			}
		}
		return patientList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
	return *new vector<Patient>();
};
