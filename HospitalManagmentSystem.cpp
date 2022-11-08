#include <iostream>
#include "Doctor.h"
#include "DoctorService.h"
#include "EmployeeService.h"
#include "NurseService.h"
#include "PatientService.h"
#include "SecretaryService.h"
#include <mysql.h>
#include <vector>
using namespace std;


MYSQL* conn;
MYSQL_RES* result;
MYSQL_ROW row;

int main()
{
	conn = mysql_init(0);


	DoctorService doctorService;
	EmployeeService employeeService;
	NurseService nurseService;
	PatientService patientService;
	SecretaryService secretaryService;
	string choose;

again:
	cout << " MUSTAFA HASTANESINE HOSGELDINIZ :)" << endl;
	cout << endl;


	cout << " 1-) Yonetim Girisi" << endl;
	cout << " 2-) Sekreter Girisi" << endl;
	cout << " 3-) Doktor Girisi" << endl;
	cout << " 4-) Hemsire Girisi" << endl;
	cout << " 5-) Hasta Girisi" << endl;
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
				cin >> profession;
				cout << "Telefon Numarasi: ";
				cin >> phoneNumber;
				cout << "Adress: ";
				cin >> adress;
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
				cin >> adress;
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
				cin >> adress;
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
				cin >> adress;
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
				cin >> adress;
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
				employeeService.AddEmployee(*new Employee(bigNumber + 1, username, password, name, surname, department,phoneNumber, adress));


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



	else if (choose == "2")
	{


	}
	else if (choose == "3")
	{

	}
	else if (choose == "4")
	{

	}
	else if (choose == "5")
	{

	}
	else
	{
		cout << "Lutfen bilgileri dogru giriniz..." << endl;
		system("CLS");
		goto again;
	}

}

