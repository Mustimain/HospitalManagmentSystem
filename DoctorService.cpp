#include "DoctorService.h"
#include "Doctor.h"
#include <iostream>
#include "DbContext.h"
#include <mysql.h>
#include <sstream>
using namespace std;

void DoctorService::AddDoctor(Doctor doctor) {

    DbContext dbContext;
 
	MYSQL* conn;

	stringstream a;
	a << "INSERT INTO doctors (id,username,password,name,surname,profession,phonenumber,adress,roleid) VALUES ("<<
		doctor.getId() << ",'" <<
		doctor.getUsername() << "','" <<
		doctor.getPassword() << "','" <<
		doctor.getName() << "','" <<
		doctor.getSurname() << "','" <<
		doctor.getProfession() << "','" <<
		doctor.getPhoneNumber() << "','" <<
		doctor.getAdress() << "'," <<
		doctor.getRoleId() << ")";

	string b = a.str();
		 

	if (!(conn = mysql_init(0)))
	{
		cout << "Hata: MYSQL nesnesi olusturulamadi" << endl;
	}
	else
	{
		cout << "sql nesnesi olustu" << endl;
	}

	if (conn = mysql_real_connect(conn, "localhost", "root", "mustimain123", "hospitalmanagmentdb", 3306, NULL, 0))
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

};

Doctor DoctorService::GetDoctorById(int doctorId) {
    return *new Doctor();
};

list<Doctor> DoctorService::GetAllDoctor() {
    return *new list<Doctor>();
};

