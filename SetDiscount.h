#pragma once
#include "Decorator.h"
class SetDiscount :
	public Decorator
{
public:
	SetDiscount() { burito = NULL; };
	SetDiscount(Burito* b);
	~SetDiscount() {};

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

