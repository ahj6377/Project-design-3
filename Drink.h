#pragma once
#include "Decorator.h"
class Drink :
	public Decorator
{
public:
	Drink() { burito = NULL; };
	Drink(Burito* b);
	~Drink() {};

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

