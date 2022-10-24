#include <iostream>
#include "Doctor.h"
#include "DoctorService.h"
#include <mysql.h>
using namespace std;

int main()
{
	

	DoctorService service;
	service.AddDoctor(*new Doctor(3, "musti", "musti123", "Mustafa", "Ceylan", "Software Developer", "123123123", "Konya", 1));

}

