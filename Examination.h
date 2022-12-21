#pragma once

#include <iostream>
#include <string>

using namespace std;

class Examination
{
	// kalp hastalýgý -seker hastalýgý- tansiyon- taný -tedavi- alerji- solunum hastalýgý - hasta þikayeti - ateþ -nabýz -
private:
	int id;
	int doctorId;
	int patientId;
	string heartDisease; // kalp
	string diabetes; //diabet
	string bloodPressure; // kan basýncý
	string allergy; // alerji
	string respiratoryDisease;// solunum hastalýgý
	string patientFever; // hasta atesi
	string patientPulse; // hasta nabzý
	string patientComplaint; //hasta þikayeti
	string diagnosis; // teþhis
	string treatment; // tedavi
	string createDate; // dosya olusturma tarihi
public:

	Examination(int id, int doctorId, int patientId, string heartDisease, string diabetes, string bloodPressure, string allergy, string respiratoryDisease
		, string patientFever, string patientPulse, string patientComplaint, string diagnosis, string treatment, string createDate) {

		this->id = id;
		this->doctorId = doctorId;
		this->patientId = patientId;
		this->heartDisease = heartDisease;
		this->diabetes = diabetes;
		this->bloodPressure = bloodPressure;
		this->allergy = allergy;
		this->respiratoryDisease = respiratoryDisease;
		this->patientFever = patientFever;
		this->patientPulse = patientPulse;
		this->patientComplaint = patientComplaint;
		this->diagnosis = diagnosis;
		this->treatment = treatment;
		this->createDate = createDate;
	}
	Examination() {

	}

	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return this->id;
	}

	void setPatientId(int patientId) {
		this->patientId = patientId;
	}
	int getPatientId() {
		return this->patientId;
	}

	void setDoctorId(int doctorId) {
		this->doctorId = doctorId;
	}
	int getDoctorId() {
		return this->doctorId;
	}

	void setHeartDisease(string heartDisease) {
		this->heartDisease = heartDisease;
	}

	string getHeartDisease() {
		return this->heartDisease;
	}

	void setDiabetes(string diabetes) {
		this->diabetes = diabetes;
	}

	string getDiabetes() {
		return this->diabetes;
	}

	void setBloodPressure(string bloodPressure) {
		this->bloodPressure = bloodPressure;
	}

	string getBloodPressure() {
		return this->bloodPressure;
	}

	void setAllergy(string allergy) {
		this->allergy = allergy;
	}

	string getAllergy() {
		return this->allergy;
	}

	void setRespiratoryDisease(string respiratoryDisease) {
		this->respiratoryDisease = respiratoryDisease;
	}

	string getRespiratoryDisease() {
		return this->respiratoryDisease;
	}

	void setPatientFever(string patientFever) {
		this->patientFever = patientFever;
	}

	string getPatientFever() {
		return this->patientFever;
	}
	void setPatientPulse(string patientPulse) {
		this->patientPulse = patientPulse;
	}

	string getPatientPulse() {
		return this->patientPulse;
	}
	void setPatientComplaint(string patientComplaint) {
		this->patientComplaint = patientComplaint;
	}

	string getPatientComplaint() {
		return this->patientComplaint;
	}

	void setDiagnosis(string diagnosis) {
		this->diagnosis = diagnosis;
	}

	string getDiagnosis() {
		return this->diagnosis;
	}
	void setTreatment(string treatment) {
		this->treatment = treatment;
	}

	string getTreatment() {
		return this->treatment;
	}

	void setCreateDate(string createDate) {
		this->createDate = createDate;
	}

	string getCreateDate() {
		return this->createDate;
	}


};

