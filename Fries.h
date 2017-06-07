#pragma once
#include "Decorator.h"
class Fries :
	public Decorator
{
public:
	Fries() { burito = NULL; };
	Fries(Burito* b);
	~Fries() {};

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

