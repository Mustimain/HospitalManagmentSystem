#include <iostream>
#include "Doctor.h"
#include "DoctorService.h"
#include "EmployeeService.h"
#include "NurseService.h"
#include "PatientService.h"
#include "SecretaryService.h"
#include <mysql.h>
#include <ctime>
#include <vector>
#include "Appointment.h"
#include "AppointmentService.h"
#include "ExaminationService.h"
using namespace std;


MYSQL* conn;
MYSQL_RES* result;
MYSQL_ROW row;

int main()
{
	setlocale(LC_ALL, "Turkish");
	conn = mysql_init(0);

	ExaminationService examinationService;
	DoctorService doctorService;
	EmployeeService employeeService;
	NurseService nurseService;
	PatientService patientService;
	SecretaryService secretaryService;
	AppointmentService appointmentService;
	Doctor currentDoctor;
	Secretary currentSecretary;
	Patient currentPatient;

	string choose;


again:
	cout << " MUSTAFA HASTANESINE HOSGELDINIZ :)" << endl;
	cout << endl;


	cout << " 1-) Yonetim Girisi" << endl;
	cout << " 2-) Sekreter Girisi" << endl;
	cout << " 3-) Doktor Girisi" << endl;
	cout << " 4-) Hasta Girisi" << endl;
	cout << "Lutfen yapmak istediginiz islemi seciniz: ";
	cin >> choose;


	// Doktor İşlemleri

	if (choose == "1")
	{
		system("CLS");
	adminStart:
		cout << " 1-) Doktor islemleri" << endl;
		cout << " 2-) Sekreter islemleri" << endl;
		cout << " 3-) Hemsire Girisi" << endl;
		cout << " 4-) Hasta islemleri" << endl;
		cout << " 5-) Calisan islemleri" << endl;
		cout << " 6-) Cikis" << endl;
		cout << "Lutfen yapmak istediginiz islemi seciniz: ";
		cin >> choose;


		if (choose == "1")
		{
			system("CLS");
		doctorStart:
			cout << " 1-) Doktor Ekle" << endl;
			cout << " 2-) Doktor Sil" << endl;
			cout << " 3-) Doktor Arama" << endl;
			cout << " 4-) Tum doktorlar" << endl;
			cout << " 5-) back" << endl;
			cout << "Lutfen yapmak istediginiz islemi seciniz: ";

			cin >> choose;


			// doktor ekleme
			if (choose == "1")
			{
				int id;
				string username;
				string password;
				string name;
				string surname;
				string profession;
				string phoneNumber;
				string adress;

				cout << "Isim: ";
				cin >> name;
				cout << "Soyisim: ";
				cin >> surname;
				cout << "Uzmanlik Alani: ";
				cin.ignore();
				getline(cin, profession);
				cout << "Telefon Numarasi: ";
				cin >> phoneNumber;
				cout << "Adress: ";
				cin.ignore();
				getline(cin, adress);
				cout << "Kullanici adi: ";
				cin >> username;
				cout << "Sifre: ";
				cin >> password;

				int bigNumber = 0;

				auto doctorSize = doctorService.GetAllDoctor().size();
				auto datas = doctorService.GetAllDoctor();
				for (int i = 0; i < doctorSize; i++)
				{
					if (datas[i].getId() > bigNumber)
					{
						bigNumber = datas[i].getId();
					}
				}
				doctorService.AddDoctor(*new Doctor(bigNumber + 1, username, password, name, surname, profession, phoneNumber, adress));


				system("CLS");
				goto doctorStart;
			}

			// doktor silme
			else if (choose == "2")
			{
				int id;
				auto doctorList = doctorService.GetAllDoctor();
				for (int i = 0; i < doctorList.size(); i++)
				{
					cout << "Id: " << doctorList[i].getId() << endl;
					cout << "Isim: " << doctorList[i].getName() << endl;
					cout << "Soyisim: " << doctorList[i].getSurname() << endl;
					cout << endl;
				}
				cout << "Cikmak icin 0 a basiniz:" << endl;
				cout << "Silmek istediginiz doktor id'sini giriniz: ";
				cin >> id;
				if (id == 0)
				{
					system("CLS");
					goto doctorStart;
				}
				else
				{
					doctorService.DeleteDoctor(id);
					goto doctorStart;
				}
			}

			// doktor filtreleme
			else if (choose == "3")
			{
				system("CLS");
				string name;
				cout << "Aramak Istediginiz kisinin isim veya soyisim bilgisini giriniz: ";
				cin >> name;
				vector<Doctor> doctorList;
				doctorList.clear();
				doctorList = doctorService.GetAllDoctor();
				for (int i = 0; i < doctorList.size(); i++)
				{
					if (doctorList[i].getName().find(name) != string::npos || doctorList[i].getSurname().find(name) != string::npos)
					{

						cout << "Id: " << doctorList[i].getId() << endl;
						cout << "Isim: " << doctorList[i].getName() << endl;
						cout << "Soyisim: " << doctorList[i].getSurname() << endl;
						cout << "Uzmanlik Alani: " << doctorList[i].getProfession() << endl;
						cout << "Telefon Numarasi: " << doctorList[i].getPhoneNumber() << endl;
						cout << "Adress: " << doctorList[i].getAdress() << endl;
					}

				}

				cout << "Cikmak icin 0 a tuslayiniz:";
				cin >> choose;
				if (choose == "0")
				{
					system("CLS");
					goto doctorStart;
				}


			}

			//tüm doktorlar
			else if (choose == "4")
			{
				system("CLS");
				auto doctorList = doctorService.GetAllDoctor();
				for (int i = 0; i < doctorList.size(); i++)
				{

					cout << "Id: " << doctorList[i].getId() << endl;
					cout << "Isim: " << doctorList[i].getName() << endl;
					cout << "Soyisim: " << doctorList[i].getSurname() << endl;
					cout << "Uzmanlik Alani: " << doctorList[i].getProfession() << endl;
					cout << "Telefon Numarasi: " << doctorList[i].getPhoneNumber() << endl;
					cout << "Adress: " << doctorList[i].getAdress() << endl;
					cout << endl;

				}

				cout << "Cikmak icin 0'i tuslayiniz: ";
				cin >> choose;


				if (choose == "0")
				{
					system("CLS");
					goto doctorStart;
				}


			}
			else if (choose == "5")
			{
				system("CLS");
				goto adminStart;
			}
			else
			{
				cout << "Lutfen bilgileri dogru giriniz..." << endl;
				system("CLS");
				goto adminStart;
			}
		}


		// SEKRETERRR
		else if (choose == "2")
		{

			system("CLS");
		secretaryStart:
			cout << " 1-) Sekreter Ekle" << endl;
			cout << " 2-) Sekreter Sil" << endl;
			cout << " 3-) Sekreter Arama" << endl;
			cout << " 4-) Tum Sekreterler" << endl;
			cout << " 5-) back" << endl;
			cout << "Lutfen yapmak istediginiz islemi seciniz: ";

			cin >> choose;

			// sekreter ekleme
			if (choose == "1")
			{
				int id;
				string username;
				string password;
				string name;
				string surname;
				string phoneNumber;
				string adress;

				cout << "Isim: ";
				cin >> name;
				cout << "Soyisim: ";
				cin >> surname;
				cout << "Telefon Numarasi: ";
				cin >> phoneNumber;
				cout << "Adress: ";
				cin.ignore();
				getline(cin, adress);
				cout << "Kullanici adi: ";
				cin >> username;
				cout << "Sifre: ";
				cin >> password;

				int bigNumber = 0;

				auto secretarySize = secretaryService.GetAllSecretary().size();
				auto datas = secretaryService.GetAllSecretary();
				for (int i = 0; i < secretarySize; i++)
				{
					if (datas[i].getId() > bigNumber)
					{
						bigNumber = datas[i].getId();
					}
				}
				secretaryService.AddSecretary(*new Secretary(bigNumber + 1, username, password, name, surname, phoneNumber, adress));


				system("CLS");
				goto secretaryStart;
			}

			// sekreter silme
			else if (choose == "2")
			{
				int id;
				auto secretaryList = secretaryService.GetAllSecretary();
				for (int i = 0; i < secretaryList.size(); i++)
				{
					cout << "Id: " << secretaryList[i].getId() << endl;
					cout << "Isim: " << secretaryList[i].getName() << endl;
					cout << "Soyisim: " << secretaryList[i].getSurname() << endl;
					cout << endl;
				}
				cout << "Cikmak icin 0 a basiniz:" << endl;
				cout << "Silmek istediginiz sekreter id'sini giriniz: ";
				cin >> id;
				if (id == 0)
				{
					system("CLS");
					goto secretaryStart;
				}
				else
				{
					secretaryService.DeleteSecretary(id);
					goto secretaryStart;
				}
			}

			// sekreter filtreleme
			else if (choose == "3")
			{
				system("CLS");
				string name;
				cout << "Aramak Istediginiz kisinin isim veya soyisim bilgisini giriniz: ";
				cin >> name;
				vector<Secretary> secretaryList;
				secretaryList = secretaryService.GetAllSecretary();
				for (int i = 0; i < secretaryList.size(); i++)
				{
					if (secretaryList[i].getName().find(name) != string::npos || secretaryList[i].getSurname().find(name) != string::npos)
					{

						cout << "Id: " << secretaryList[i].getId() << endl;
						cout << "Isim: " << secretaryList[i].getName() << endl;
						cout << "Soyisim: " << secretaryList[i].getSurname() << endl;
						cout << "Telefon Numarasi: " << secretaryList[i].getPhoneNumber() << endl;
						cout << "Adress: " << secretaryList[i].getAdress() << endl;
					}

				}

				cout << "Cikmak icin 0 a tuslayiniz:";
				cin >> choose;
				if (choose == "0")
				{
					system("CLS");
					goto secretaryStart;
				}


			}

			// sekreter listeleme
			else if (choose == "4")
			{
				system("CLS");
				auto secretaryList = secretaryService.GetAllSecretary();
				for (int i = 0; i < secretaryList.size(); i++)
				{

					cout << "Id: " << secretaryList[i].getId() << endl;
					cout << "Isim: " << secretaryList[i].getName() << endl;
					cout << "Soyisim: " << secretaryList[i].getSurname() << endl;
					cout << "Telefon Numarasi: " << secretaryList[i].getPhoneNumber() << endl;
					cout << "Adress: " << secretaryList[i].getAdress() << endl;
					cout << endl;

				}

				cout << "Cikmak icin 0'i tuslayiniz: ";
				cin >> choose;


				if (choose == "0")
				{
					system("CLS");
					goto secretaryStart;
				}


			}
			else if (choose == "5")
			{
				system("CLS");
				goto adminStart;
			}
			else
			{
				cout << "Lutfen bilgileri dogru giriniz..." << endl;
				system("CLS");
				goto adminStart;
			}

		}
		// HEMŞİREEEE
		else if (choose == "3")
		{
		nurseStart:

			system("CLS");
			cout << " 1-) Hemsire Ekle" << endl;
			cout << " 2-) Hemsire Sil" << endl;
			cout << " 3-) Hemsire Arama" << endl;
			cout << " 4-) Tum Hemsire" << endl;
			cout << " 5-) back" << endl;
			cout << "Lutfen yapmak istediginiz islemi seciniz: ";

			cin >> choose;

			// hemsire ekleme
			if (choose == "1")
			{
				int id;
				string username;
				string password;
				string name;
				string surname;
				string phoneNumber;
				string adress;

				cout << "Isim: ";
				cin >> name;
				cout << "Soyisim: ";
				cin >> surname;
				cout << "Telefon Numarasi: ";
				cin >> phoneNumber;
				cout << "Adress: ";
				cin.ignore();
				getline(cin, adress);
				cout << "Kullanici adi: ";
				cin >> username;
				cout << "Sifre: ";
				cin >> password;

				int bigNumber = 0;

				auto nurseSize = nurseService.GetAllNurse().size();
				auto datas = nurseService.GetAllNurse();
				for (int i = 0; i < nurseSize; i++)
				{
					if (datas[i].getId() > bigNumber)
					{
						bigNumber = datas[i].getId();
					}
				}
				nurseService.AddNurse(*new Nurse(bigNumber + 1, username, password, name, surname, phoneNumber, adress));


				system("CLS");
				goto nurseStart;
			}

			// hemşire silme
			else if (choose == "2")
			{
				int id;
				auto nurseList = nurseService.GetAllNurse();
				for (int i = 0; i < nurseList.size(); i++)
				{
					cout << "Id: " << nurseList[i].getId() << endl;
					cout << "Isim: " << nurseList[i].getName() << endl;
					cout << "Soyisim: " << nurseList[i].getSurname() << endl;
					cout << endl;
				}
				cout << "Cikmak icin 0 a basiniz:" << endl;
				cout << "Silmek istediginiz sekreter id'sini giriniz: ";
				cin >> id;
				if (id == 0)
				{
					system("CLS");
					goto nurseStart;
				}
				else
				{
					nurseService.DeleteNurse(id);
					goto nurseStart;
				}
			}

			// hemşire filtreleme
			else if (choose == "3")
			{

				system("CLS");
				string name;
				cout << "Aramak Istediginiz kisinin isim veya soyisim bilgisini giriniz: ";
				cin >> name;
				vector<Nurse> nurseList;
				nurseList = nurseService.GetAllNurse();
				for (int i = 0; i < nurseList.size(); i++)
				{
					if (nurseList[i].getName().find(name) != string::npos || nurseList[i].getSurname().find(name) != string::npos)
					{

						cout << "Id: " << nurseList[i].getId() << endl;
						cout << "Isim: " << nurseList[i].getName() << endl;
						cout << "Soyisim: " << nurseList[i].getSurname() << endl;
						cout << "Telefon Numarasi: " << nurseList[i].getPhoneNumber() << endl;
						cout << "Adress: " << nurseList[i].getAdress() << endl;
					}

				}

				cout << "Cikmak icin 0 a tuslayiniz:";
				cin >> choose;
				if (choose == "0")
				{
					system("CLS");
					goto nurseStart;
				}


			}

			// hemşire listeleme
			else if (choose == "4")
			{
				system("CLS");
				auto nurseList = nurseService.GetAllNurse();
				for (int i = 0; i < nurseList.size(); i++)
				{

					cout << "Id: " << nurseList[i].getId() << endl;
					cout << "Isim: " << nurseList[i].getName() << endl;
					cout << "Soyisim: " << nurseList[i].getSurname() << endl;
					cout << "Telefon Numarasi: " << nurseList[i].getPhoneNumber() << endl;
					cout << "Adress: " << nurseList[i].getAdress() << endl;
					cout << endl;

				}

				cout << "Cikmak icin 0'i tuslayiniz: ";
				cin >> choose;


				if (choose == "0")
				{
					system("CLS");
					goto nurseStart;
				}


			}
			else if (choose == "5")
			{
				system("CLS");
				goto adminStart;
			}
			else
			{
				cout << "Lutfen bilgileri dogru giriniz..." << endl;
				system("CLS");
				goto adminStart;
			}

		}

		// HASTAAA
		else if (choose == "4")
		{

		patientStart:

			system("CLS");
			cout << " 1-) Hasta Ekle" << endl;
			cout << " 2-) Hasta Sil" << endl;
			cout << " 3-) Hasta Arama" << endl;
			cout << " 4-) Tum Hastalar" << endl;
			cout << " 5-) back" << endl;
			cout << "Lutfen yapmak istediginiz islemi seciniz: ";

			cin >> choose;

			// hasta ekleme
			if (choose == "1")
			{
				int id;
				string tcNo;
				string bloodGroup;
				string name;
				string surname;
				string phoneNumber;
				string adress;
				string gender;
				string birthDate;

				cout << "Isim: ";
				cin >> name;
				cout << "Soyisim: ";
				cin >> surname;
				cout << "Telefon Numarasi: ";
				cin >> phoneNumber;
				cout << "Adress: ";
				cin.ignore();
				getline(cin, adress);
				cout << "Tc No: ";
				cin >> tcNo;
				cout << "Kan Grubu: ";
				cin >> bloodGroup;
				cout << "Cinsiyet: ";
				cin >> gender;
				cout << "Dogum Tarihi: ";
				cin >> birthDate;

				int bigNumber = 0;

				auto patientSize = patientService.GetAllPatient().size();
				auto datas = patientService.GetAllPatient();
				for (int i = 0; i < patientSize; i++)
				{
					if (datas[i].getId() > bigNumber)
					{
						bigNumber = datas[i].getId();
					}
				}
				patientService.AddPatient(*new Patient(bigNumber + 1, tcNo, name, surname, adress, phoneNumber, bloodGroup, gender, birthDate));


				system("CLS");
				goto patientStart;
			}

			// hasta silme
			else if (choose == "2")
			{
				int id;
				auto patientList = patientService.GetAllPatient();
				for (int i = 0; i < patientList.size(); i++)
				{
					cout << "Id: " << patientList[i].getId() << endl;
					cout << "Isim: " << patientList[i].getName() << endl;
					cout << "Soyisim: " << patientList[i].getSurname() << endl;
					cout << endl;
				}
				cout << "Cikmak icin 0 a basiniz:" << endl;
				cout << "Silmek istediginiz sekreter id'sini giriniz: ";
				cin >> id;
				if (id == 0)
				{
					system("CLS");
					goto patientStart;
				}
				else
				{
					secretaryService.DeleteSecretary(id);
					goto patientStart;
				}
			}

			// hasta filtreleme
			else if (choose == "3")
			{
				system("CLS");
				string name;
				cout << "Aramak Istediginiz kisinin isim veya soyisim bilgisini giriniz: ";
				cin >> name;
				vector<Patient> patientList;
				patientList = patientService.GetAllPatient();
				for (int i = 0; i < patientList.size(); i++)
				{
					if (patientList[i].getName().find(name) != string::npos || patientList[i].getSurname().find(name) != string::npos)
					{

						cout << "Id: " << patientList[i].getId() << endl;
						cout << "Tc No: " << patientList[i].getTcNo() << endl;
						cout << "Isim: " << patientList[i].getName() << endl;
						cout << "Soyisim: " << patientList[i].getSurname() << endl;
						cout << "Telefon Numarasi: " << patientList[i].getPhoneNumber() << endl;
						cout << "Adress: " << patientList[i].getAdress() << endl;
						cout << "Kan grubu: " << patientList[i].getBloodGroup() << endl;
						cout << "Cinsiyet: " << patientList[i].getGender() << endl;
						cout << "Dogum Tarihi: " << patientList[i].getBirthDate() << endl;
						cout << endl;
					}

				}

				cout << "Cikmak icin 0 a tuslayiniz:";
				cin >> choose;
				if (choose == "0")
				{
					system("CLS");
					goto patientStart;
				}


			}

			// hasta listeleme
			else if (choose == "4")
			{
				system("CLS");
				auto patientList = patientService.GetAllPatient();
				for (int i = 0; i < patientList.size(); i++)
				{

					cout << "Id: " << patientList[i].getId() << endl;
					cout << "Tc No: " << patientList[i].getTcNo() << endl;
					cout << "Isim: " << patientList[i].getName() << endl;
					cout << "Soyisim: " << patientList[i].getSurname() << endl;
					cout << "Telefon Numarasi: " << patientList[i].getPhoneNumber() << endl;
					cout << "Adress: " << patientList[i].getAdress() << endl;
					cout << "Kan grubu: " << patientList[i].getBloodGroup() << endl;
					cout << "Cinsiyet: " << patientList[i].getGender() << endl;
					cout << "Dogum Tarihi: " << patientList[i].getBirthDate() << endl;
					cout << endl;

				}

				cout << "Cikmak icin 0'i tuslayiniz: ";
				cin >> choose;


				if (choose == "0")
				{
					system("CLS");
					goto patientStart;
				}


			}
			else if (choose == "5")
			{
				system("CLS");
				goto adminStart;
			}
			else
			{
				cout << "Lutfen bilgileri dogru giriniz..." << endl;
				system("CLS");
				goto adminStart;
			}

		}
		// ÇALIŞANNN
		else if (choose == "5")
		{
		employeeStart:

			system("CLS");
			cout << " 1-) Calisan Ekle" << endl;
			cout << " 2-) Calisan Sil" << endl;
			cout << " 3-) Calisan Arama" << endl;
			cout << " 4-) Tum Calisanlar" << endl;
			cout << " 5-) back" << endl;
			cout << "Lutfen yapmak istediginiz islemi seciniz: ";

			cin >> choose;

			// calısan ekleme
			if (choose == "1")
			{
				int id;
				string username;
				string password;
				string name;
				string surname;
				string phoneNumber;
				string adress;
				string department;

				cout << "Isim: ";
				cin >> name;
				cout << "Soyisim: ";
				cin >> surname;
				cout << "Telefon Numarasi: ";
				cin >> phoneNumber;
				cout << "Adress: ";
				cin.ignore();
				getline(cin, adress);
				cout << "Kullanici adi: ";
				cin >> username;
				cout << "Sifre: ";
				cin >> password;
				cout << "Calisma alani: ";
				cin >> department;

				int bigNumber = 0;

				auto employeeSize = employeeService.GetAllEmployee().size();
				auto datas = employeeService.GetAllEmployee();
				for (int i = 0; i < employeeSize; i++)
				{
					if (datas[i].getId() > bigNumber)
					{
						bigNumber = datas[i].getId();
					}
				}
				employeeService.AddEmployee(*new Employee(bigNumber + 1, username, password, name, surname, department, phoneNumber, adress));


				system("CLS");
				goto employeeStart;
			}

			// calısan silme
			else if (choose == "2")
			{
				int id;
				auto employeeList = employeeService.GetAllEmployee();
				for (int i = 0; i < employeeList.size(); i++)
				{
					cout << "Id: " << employeeList[i].getId() << endl;
					cout << "Isim: " << employeeList[i].getName() << endl;
					cout << "Soyisim: " << employeeList[i].getSurname() << endl;
					cout << endl;
				}
				cout << "Cikmak icin 0 a basiniz:" << endl;
				cout << "Silmek istediginiz sekreter id'sini giriniz: ";
				cin >> id;
				if (id == 0)
				{
					system("CLS");
					goto employeeStart;
				}
				else
				{
					employeeService.DeleteEmployee(id);
					goto nurseStart;
				}
			}

			// calısan filtreleme
			else if (choose == "3")
			{

				system("CLS");
				string name;
				cout << "Aramak Istediginiz kisinin isim veya soyisim bilgisini giriniz: ";
				cin >> name;
				vector<Employee> employeeList;
				employeeList = employeeService.GetAllEmployee();
				for (int i = 0; i < employeeList.size(); i++)
				{
					if (employeeList[i].getName().find(name) != string::npos || employeeList[i].getSurname().find(name) != string::npos)
					{

						cout << "Id: " << employeeList[i].getId() << endl;
						cout << "Isim: " << employeeList[i].getName() << endl;
						cout << "Soyisim: " << employeeList[i].getSurname() << endl;
						cout << "Telefon Numarasi: " << employeeList[i].getPhoneNumber() << endl;
						cout << "Adress: " << employeeList[i].getAdress() << endl;
						cout << "Calisma alani: " << employeeList[i].getDepartment() << endl;

					}

				}

				cout << "Cikmak icin 0 a tuslayiniz:";
				cin >> choose;
				if (choose == "0")
				{
					system("CLS");
					goto employeeStart;
				}


			}

			// calısan listeleme
			else if (choose == "4")
			{
				system("CLS");
				auto employeeList = employeeService.GetAllEmployee();
				for (int i = 0; i < employeeList.size(); i++)
				{

					cout << "Id: " << employeeList[i].getId() << endl;
					cout << "Isim: " << employeeList[i].getName() << endl;
					cout << "Soyisim: " << employeeList[i].getSurname() << endl;
					cout << "Telefon Numarasi: " << employeeList[i].getPhoneNumber() << endl;
					cout << "Adress: " << employeeList[i].getAdress() << endl;
					cout << "Calisma alani: " << employeeList[i].getDepartment() << endl;

					cout << endl;

				}

				cout << "Cikmak icin 0'i tuslayiniz: ";
				cin >> choose;


				if (choose == "0")
				{
					system("CLS");
					goto employeeStart;
				}


			}
			else if (choose == "5")
			{
				system("CLS");
				goto adminStart;
			}
			else
			{
				cout << "Lutfen bilgileri dogru giriniz..." << endl;
				system("CLS");
				goto adminStart;
			}


		}
		else if (choose == "6")
		{
			system("CLS");
			goto again;
		}
		else
		{
			cout << "Lutfen bilgileri dogru giriniz..." << endl;
			system("CLS");
			goto adminStart;
		}
	}


	// SEKRETER RANDEVU İSLEMLERİ
	else if (choose == "2")
	{


	secretaryMenu:
		system("CLS");

		cout << "1-) Hasta Kayit" << endl;
		cout << "2-) Randevu Olustur" << endl;
		cout << "3-) Tum Randevular" << endl;
		cout << "4-) Cikis" << endl;


		cin >> choose;

		if (choose == "1")
		{

			int id;
			string tcNo;
			string bloodGroup;
			string name;
			string surname;
			string phoneNumber;
			string adress;
			string gender;
			string birthDate;

			cout << "Isim: ";
			cin >> name;
			cout << "Soyisim: ";
			cin >> surname;
			cout << "Telefon Numarasi: ";
			cin >> phoneNumber;
			cout << "Adress: ";
			cin.ignore();
			getline(cin, adress);
			cout << "Tc No: ";
			cin >> tcNo;
			cout << "Kan Grubu: ";
			cin >> bloodGroup;
			cout << "Cinsiyet: ";
			cin >> gender;
			cout << "Dogum Tarihi: ";
			cin >> birthDate;

			int bigNumber = 0;

			auto patientSize = patientService.GetAllPatient().size();
			auto datas = patientService.GetAllPatient();
			for (int i = 0; i < patientSize; i++)
			{
				if (datas[i].getId() > bigNumber)
				{
					bigNumber = datas[i].getId();
				}
			}
			patientService.AddPatient(*new Patient(bigNumber + 1, tcNo, name, surname, adress, phoneNumber, bloodGroup, gender, birthDate));


			system("CLS");
			goto secretaryMenu;
		}
		else if (choose == "2")
		{

			int doctorId;
			int patientId;
			string day;
			string month;
			string year;
			string hour;
			system("CLS");
			auto doctorList = doctorService.GetAllDoctor();
			for (int i = 0; i < doctorList.size(); i++)
			{

				cout << "Id: " << doctorList[i].getId() << endl;
				cout << "Ad Soyad: " << doctorList[i].getName() << "  " << doctorList[i].getSurname() << endl;
				cout << "Uzmanlik Alani: " << doctorList[i].getProfession() << endl;
				cout << endl;

			}

			cout << "Doktor Seciniz: ";
			cin >> doctorId;
			system("CLS");

			auto patientList = patientService.GetAllPatient();
			for (int i = 0; i < patientList.size(); i++)
			{

				cout << "Id: " << patientList[i].getId() << endl;
				cout << "Ad Soyad: " << patientList[i].getName() << "  " << patientList[i].getSurname() << endl;
				cout << endl;

			}

			cout << "Hasta Seciniz: ";
			cin >> patientId;
			cout << "Gun giriniz: ";
			cin >> day;
			cout << "Ay giriniz: ";
			cin >> month;
			cout << "Yil giriniz: ";
			cin >> year;
			cout << "Saat giriniz: ";
			cin >> hour;


			string date = day + "/" + month + "/" + year + " " + hour;
			int bigNumber = 0;

			auto appointmentSize = appointmentService.GetAllAppointment().size();
			auto datas = appointmentService.GetAllAppointment();
			for (int i = 0; i < appointmentSize; i++)
			{
				if (datas[i].getId() > bigNumber)
				{
					bigNumber = datas[i].getId();
				}
			}

			Appointment appointment(bigNumber + 1, doctorId, patientId, date, false);

			appointmentService.AddAppointment(appointment);

			goto secretaryMenu;


		}
		else if (choose == "3")
		{
			system("CLS");
			cout << "Tum Randevular" << endl << endl;
			auto allData = appointmentService.GetAllAppointment();

			for (int i = 0; i < allData.size(); i++)
			{
				auto doctorDetail = doctorService.GetDoctorById(allData[i].getDoctorId());
				auto patientDetail = patientService.GetPatientById(allData[i].getPatientId());
				cout << "Randevu id: " << allData[i].getId() << endl;
				cout << "Doktor Ad Soyad: " << doctorDetail.getName() << "  " << doctorDetail.getSurname() << endl;
				cout << "Uzmanlik Alani: " << doctorDetail.getProfession() << endl;
				cout << "Hasta Ad Soyad: " << patientDetail.getName() << "  " << patientDetail.getSurname() << endl;
				cout << "Randevu Tarihi: " << allData[i].getDate() << endl << endl;

			}
			cout << "Cikmak icin 0 Tuslayiniz:" << endl;
			cin >> choose;
			if (choose == "0")
			{
				goto secretaryMenu;
			}
			else
			{
				goto secretaryMenu;

			}

		}
		else if (choose == "4")
		{
			system("CLS");
			goto again;
		}
		else
		{
			cout << "Lutfen bilgileri dogru giriniz..." << endl;
			system("CLS");
			goto again;

		}



	}
	else if (choose == "3")
	{
		system("CLS");
	doktorStart:
		string username;
		string password;
		cout << "Kullanici Adi: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;

		auto doctorList = doctorService.GetAllDoctor();
		for (int i = 0; i < doctorList.size(); i++)
		{
			if (doctorList[i].getPassword() == password && doctorList[i].getUsername() == username && doctorList.size() > 0)
			{
			doktorList:

				vector<Appointment> personelAppoinemnts;
				personelAppoinemnts.clear();
				system("CLS");
				currentDoctor = doctorList[i];
				cout << "1-) Randevular" << endl;
				cout << "2-) Reçete Oluştur" << endl;
				cout << "3-) Cikis" << endl << endl;

				cout << "Lutfem Yapmak istediginiz islemi seciniz:";
				cin >> choose;
				if (choose == "1")
				{
					auto allData = appointmentService.GetAllAppointment();
					for (int i = 0; i < allData.size(); i++)
					{
						auto doctorDetail = doctorService.GetDoctorById(allData[i].getDoctorId());
						auto patientDetail = patientService.GetPatientById(allData[i].getPatientId());
						if (currentDoctor.getId() == doctorDetail.getId())
						{
							cout << "Randevu id: " << allData[i].getId() << endl;
							cout << "Hasta id: " << patientDetail.getId() << endl;
							cout << "Hasta Ad Soyad: " << patientDetail.getName() << "  " << patientDetail.getSurname() << endl;
							cout << "Randevu Tarihi: " << allData[i].getDate() << endl << endl;
						}


					}

					cout << "Cikmak icin 0 Tuslayiniz:" << endl;
					cout << "Muayene yapmak istediginiz randevu idsini giriniz:" << endl;
					cin >> choose;



					if (choose == "0")
					{
						goto doktorList;
					}
					else if (patientService.GetPatientById(stoi(choose)).getId() != NULL)
					{

						time_t now = time(0);
						char* dt = ctime(&now);

						int bigNumber = 0;

						auto examinationSize = examinationService.GetAllExamination().size();
						auto datas = examinationService.GetAllExamination();
						for (int i = 0; i < examinationSize; i++)
						{
							if (datas[i].getId() > bigNumber)
							{
								bigNumber = datas[i].getId();
							}
						}
						int patientId = appointmentService.GetAppointmentById(stoi(choose)).getPatientId();
						int doctorId = currentDoctor.getId();
						string heartDisease; // kalp
						string diabetes; //diabet
						string bloodPressure; // kan basıncı
						string allergy; // alerji
						string respiratoryDisease;// solunum hastalıgı
						string patientFever; // hasta atesi
						string patientPulse; // hasta nabzı
						string patientComplaint; //hasta şikayeti
						string diagnosis; // teşhis
						string treatment; // tedavi
						string createDate = dt; // dosya olusturma tarihi


						cout << endl;
						cout << "Kalp Hastaligi: ";
						cin.ignore();
						getline(cin, heartDisease);
						cout << "Seker Hastaligi: ";
						cin.ignore();
						getline(cin, diabetes);
						cout << "Tansiyon: ";
						cin.ignore();
						getline(cin, bloodPressure);
						cout << "Alerji: ";
						cin.ignore();
						getline(cin, allergy);
						cout << "Solunum Hastaligi: ";
						cin.ignore();
						getline(cin, respiratoryDisease);
						cout << "Hasta Atesi: ";
						cin.ignore();
						getline(cin, patientFever);
						cout << "Nabiz: ";
						cin.ignore();
						getline(cin, patientPulse);
						cout << "Hasta Sikayeti: ";
						cin.ignore();
						getline(cin, patientComplaint);
						cout << "Teshis: ";
						cin.ignore();
						getline(cin, diagnosis);
						cout << "Uygulanacak Tedavi: ";
						cin.ignore();
						getline(cin, treatment);

						examinationService.AddExamination
						(*new Examination(bigNumber, doctorId, patientId, heartDisease, diabetes,
							bloodPressure, allergy, respiratoryDisease, patientFever, patientPulse, patientComplaint, diagnosis, treatment, createDate));

						appointmentService.AppointmentComplete(stoi(choose));

						goto doktorList;
					}
					else
					{
						cout << "Lutfen Bilgileri dogru giriniz..." << endl;
						goto doktorList;

					}
				}
				else if (choose == "2")
				{

				}
				else if (choose == "3")
				{
					currentDoctor = *new Doctor();
					system("CLS");
					goto again;
				}
				else
				{
					goto doktorList;

				}


			}
			else
			{
				cout << "Bilgiler Hatali Tekrar deneyiniz" << endl;
				goto doktorStart;
			}
		}

	}
	else if (choose == "4")
	{
	hastaStart:
		system("CLS");
		cout << "1-) Randevu Sorgulama" << endl;
		cout << "2-) Muayene Sonuclari Sorgulama" << endl;
		cout << "3-) Cikis" << endl << endl;


		cout << "Lutfen islem seciniz:";
		cin >> choose;

		if (choose == "1")
		{

			system("CLS");
			string tcNo;
			cout << "Tcno Giriniz: ";
			cin >> tcNo;
			cout << "Randevulariniz" << endl << endl;
			auto allData = appointmentService.GetAllAppointment();


			for (int i = 0; i < allData.size(); i++)
			{
				auto doctorDetail = doctorService.GetDoctorById(allData[i].getDoctorId());
				auto patientDetail = patientService.GetPatientById(allData[i].getPatientId());
				if (tcNo == patientDetail.getTcNo())
				{
					cout << "Randevu id: " << allData[i].getId() << endl;
					cout << "Doktor Ad Soyad: " << doctorDetail.getName() << "  " << doctorDetail.getSurname() << endl;
					cout << "Uzmanlik Alani: " << doctorDetail.getProfession() << endl;
					cout << "Hasta Ad Soyad: " << patientDetail.getName() << "  " << patientDetail.getSurname() << endl;
					cout << "Randevu Tarihi: " << allData[i].getDate() << endl << endl;

				}


			}




			if (choose == "0")
			{
				goto hastaStart;
			}
			else
			{
				goto hastaStart;
			}

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{
			system("CLS");
			goto again;
		}
		else
		{
			cout << "Lutfen bilgileri dogru giriniz..." << endl;
			system("CLS");
			goto hastaStart;
		}

	}
	else
	{
		cout << "Lutfen bilgileri dogru giriniz..." << endl;
		system("CLS");
		goto again;
	}

}

