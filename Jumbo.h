#pragma once
#include "Decorator.h"
class Jumbo :
	public Decorator
{
public:
	Jumbo() { burito = NULL; };
	Jumbo(Burito* b);
	~Jumbo() {};

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

