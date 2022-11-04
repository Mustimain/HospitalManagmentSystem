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

int main()
{
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

	if (choose == "1")
	{
		system("CLS");
	adminStart:
		cout << " 1-) Doktor islemleri" << endl;
		cout << " 2-) Sekreter islemleri" << endl;
		cout << " 3-) Hemsire Girisi" << endl;
		cout << " 4-) Hasta islemleri" << endl;
		cout << " 5-) back" << endl;
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
				int roleId = 2;

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
				}
			}
			else if (choose == "3")
			{
			againDoctorInput:
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

