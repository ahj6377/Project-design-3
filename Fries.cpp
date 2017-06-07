#include "Fries.h"


int Fries::getCost()
{

	return Cost;

}
string Fries::getDescription()
{

	return Description;
}

Fries::Fries(Burito* b)
{
	burito = b;
	Cost = b->getCost() + 2000;
	Description = b->getDescription() + " + °¨ÀÚÆ¢±è";

}