#pragma once
#include "Transaction.h"
#include<sstream>
class TransactionManager
{
public:
	TransactionManager() { Onum = 0; orderTransactions = {}; }
	~TransactionManager() {}

	void addTransaction(Transaction* newTransaction);
	void processFrontTransaction();
	void printTransaction();
	void deleteTransaction(int index);
	void printMenu();
	string getInfo() {
		string alldata = "";
		
		for (int i = 0; i < orderTransactions.size(); i++)
		{	ostringstream savedata;
			int Mindex;
			vector<int> Ingred;
			orderTransactions[i].getInfoforSave(Mindex, Ingred);

			savedata << Ingred.size()+1 << "\t" << Mindex;
			for (int i = 0; i < Ingred.size(); i++)
			{
				savedata << "\t" <<Ingred[i];

			}
			alldata = alldata + savedata.str();
			alldata = alldata + "\n";
		}
		return alldata;
	}
private:
	vector<Transaction> orderTransactions;
	int Onum;
};

