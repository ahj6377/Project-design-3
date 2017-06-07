#pragma once
#include "BaseBurito.h"
#include "Drink.h"
#include "Fries.h"
#include"Jumbo.h"
#include"Sausage.h"
#include "ComboDiscount.h"
#include "SetDiscount.h"
#include<vector>
#include<iostream>
using namespace std;
class BuritoFactory
{
public:
	BuritoFactory() {};
	~BuritoFactory() {};

	Burito* makeOrderedMenu(int type, vector<int>& Ingred);
		
		;
};

