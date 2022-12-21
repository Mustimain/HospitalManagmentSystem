#include "AppointmentService.h"


#include <iostream>
#include <mysql.h>
#include <sstream>
using namespace std;


extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Appointment> appointmentList;

void AppointmentService::AddAppointment(Appointment appointment) {


	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO appointments(id, doctorId, patientId, date, isCompleted) VALUES(" <<
		appointment.getId() << ",'" <<
		appointment.getDoctorId() << "','" <<
		appointment.getPatientId() << "','" <<
		appointment.getDate() << "','" <<
		appointment.getIsCompleted() << "')";
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

void AppointmentService::DeleteAppointment(int appointmentId) {

	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from appointments where id = " << appointmentId;
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

Appointment AppointmentService::GetAppointmentById(int appointmentId) {

	conn = mysql_init(0);
	stringstream a;
	a << "select * from appointments where id = " << appointmentId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Appointment(stoi(row[0]), stoi(row[1]), stoi(row[2]), (string)row[3], (bool)row[4]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}

	return *new Appointment();
};

vector<Appointment> AppointmentService::GetAllAppointment() {

	appointmentList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from appointments";

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < count; i += 5)
			{
				
				Appointment appointment(stoi(row[i]), stoi(row[i + 1]), stoi(row[i + 2]), (string)row[i + 3], (bool)row[i + 4]);
				appointmentList.push_back(appointment);

			}
		}
		return appointmentList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
	return *new vector<Appointment>();
};

void AppointmentService::AppointmentComplete(int appointmentId) {

	conn = mysql_init(0);
	stringstream a;
	a << "UPDATE appointments SET isCompleted = true WHERE id = " << appointmentId;
	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{

		if (!(mysql_query(conn, query)))
		{
			cout << "Güncelleme islemi tamam";
		}
		else
		{
			cout << "Güncelleme islemi basarisiz";
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
};