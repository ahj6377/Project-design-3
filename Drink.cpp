#include"Drink.h"

int Drink::getCost()
{

	return Cost;
}
string Drink::getDescription()
{
	
	return Description;

}
Drink::Drink(Burito* b)
{
	burito = b;
	Cost = b->getCost() + 1000;
	Description = b->getDescription() + " + À½·á";
}