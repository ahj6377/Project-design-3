#pragma once
#include <string>
using namespace std;
class Burito
{
public:
	Burito() { Cost = 0; Description = ""; };
	~Burito() {};

	virtual int getCost() = 0;
	virtual string getDescription() = 0;
protected:
	int Cost;
	string Description;
};

