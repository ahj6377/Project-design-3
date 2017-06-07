#pragma once
#include "BuritoFactory.h"
#include "TransactionManger.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class App
{
public:
	App();
	~App();

	void run();

private:
	void readTransaction();
	void writeTransaction();

private:
	BuritoFactory* bf;
	TransactionManager* tm;
	int OrderID;
};

