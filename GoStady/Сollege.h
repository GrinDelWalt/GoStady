#pragma once
#include <iostream>
#include "EducationalInstitution.h"


using namespace std;

class College : public EducationalInstitution
{
private:

public:
	College() {}
	College(string title, string category)
		:EducationalInstitution(title, category)
	{

	}
};

