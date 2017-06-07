#include"Sausage.h"

int Sausage::getCost()
{
	return Cost;

}

string Sausage::getDescription()
{
	return Description;


}
Sausage::Sausage(Burito* b)
{
	burito = b;
	Cost = b->getCost() + 1000;
	Description = b->getDescription() + " + ¼Ò¼¼Áö";

}