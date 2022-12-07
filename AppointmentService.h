#pragma once
#include "Appointment.h"
#include <vector>


class AppointmentService
{
public:
	void AddAppointment(Appointment appointment);
	void DeleteAppointment(int appointmentId);
	Appointment GetAppointmentById(int appointmentId);
	vector<Appointment> GetAllAppointment();
};

