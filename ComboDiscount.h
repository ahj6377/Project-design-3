#pragma once
#include "Decorator.h"
class ComboDiscount :
	public Decorator
{
public:
	ComboDiscount() { burito = NULL; };
	ComboDiscount(Burito* b) {
		burito = b;
		Cost = b->getCost() - 300;
		Description = "�޺�";
	
	};
	~ComboDiscount() {};

	int getCost();
	string getDescription();

private:
	Burito* burito;
};

