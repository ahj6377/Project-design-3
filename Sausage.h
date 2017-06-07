#pragma once
#include "Decorator.h"
class Sausage :
	public Decorator
{
public:
	Sausage() { burito = NULL; };
	Sausage(Burito* b);
	~Sausage() {};

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

