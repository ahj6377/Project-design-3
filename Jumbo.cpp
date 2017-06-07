#include"Jumbo.h"

int Jumbo::getCost()
{
	return Cost;
}
string Jumbo::getDescription()
{
	return Description;
}
Jumbo::Jumbo(Burito* b) 
{
	burito = b;
	Cost = b->getCost() + 1000;
	Description = b->getDescription() + " + Á¡º¸";


}