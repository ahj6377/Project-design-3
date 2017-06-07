#include"SetDiscount.h"

int SetDiscount::getCost()
{
	return Cost;

}

string SetDiscount::getDescription()
{
	return Description;

}
SetDiscount::SetDiscount(Burito* b)
{
	burito = b;
	Cost = b->getCost() - 500;
	Description = "¼¼Æ®";
}