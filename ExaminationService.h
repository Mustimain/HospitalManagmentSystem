#pragma once
#include "Examination.h"
#include <vector>
using namespace std;
class ExaminationService
{
public:
	void AddExamination(Examination examination);
	void DeleteExamination(int examinationId);
	Examination GetExaminationById(int examinationId);
	vector<Examination> GetAllExamination();
};

