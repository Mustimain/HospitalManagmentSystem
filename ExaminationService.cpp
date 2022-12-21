#include "ExaminationService.h"
#include <mysql.h>
#include <sstream>

extern MYSQL* conn;
extern MYSQL_RES* result;
extern MYSQL_ROW row;
vector<Examination> examinationList;

void ExaminationService::AddExamination(Examination examination) {


	conn = mysql_init(0);
	stringstream a;
	a << "INSERT INTO examinations (id,doctorId,patientId,heartDisease,diabetes,bloodPressure,allergy,respiratoryDisease,patientFever,patientPulse,patientComplaint,diagnosis,treatment,createDate) VALUES (" <<
		examination.getId() << "," <<
		examination.getDoctorId() << "," <<
		examination.getPatientId() << ",'" <<
		examination.getHeartDisease() << "','" <<
		examination.getDiabetes() << "','" <<
		examination.getBloodPressure() << "','" <<
		examination.getAllergy() << "','" <<
		examination.getRespiratoryDisease() << "','" <<
		examination.getPatientFever() << "','" <<
		examination.getPatientPulse() << "','" <<
		examination.getPatientComplaint() << "','" <<
		examination.getDiagnosis() << "','" <<
		examination.getTreatment() << "','" <<
		examination.getCreateDate() << "')";
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

void ExaminationService::DeleteExamination(int examinationId) {

	conn = mysql_init(0);
	stringstream a;
	a << "DELETE from examinations where id = " << examinationId;
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

Examination ExaminationService::GetExaminationById(int examinationId) {

	conn = mysql_init(0);
	stringstream a;
	a << "select * from examinations where id = " << examinationId;

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			return Examination(stoi(row[0]), stoi(row[1]), stoi(row[2]), (string)row[3], (string)row[4], (string)row[5], (string)row[6], (string)row[7], (string)row[8], (string)row[9], (string)row[10], (string)row[11], (string)row[12], (string)row[13]);
		}
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}

	return *new Examination();
};

vector<Examination> ExaminationService::GetAllExamination() {

	examinationList.clear();
	conn = mysql_init(0);
	stringstream a;
	a << "select * from examinations";

	string b = a.str();
	const char* query = b.c_str();


	if (conn = mysql_real_connect(conn, "localhost", "root", "musti123", "hospitalmanagmentdb", 3306, NULL, 0))
	{
		mysql_query(conn, query);
		result = mysql_store_result(conn);
		int count = mysql_num_fields(result);
		while (row = mysql_fetch_row(result))
		{
			for (int i = 0; i < count; i += 14)
			{
				Examination examination(stoi(row[i + 0]), stoi(row[i + 1]), stoi(row[i + 2]), (string)row[i + 3], (string)row[i + 4], (string)row[i + 5], (string)row[i + 6], (string)row[i + 7], (string)row[8], (string)row[i + 9], (string)row[i + 10], (string)row[i + 11], (string)row[i + 12], (string)row[i + 13]);
				examinationList.push_back(examination);

			}
		}
		return examinationList;
	}
	else
	{
		cout << "sql baglanmadi" << endl;

	}
	return *new vector<Examination>();
};