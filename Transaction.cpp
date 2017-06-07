#include"Transaction.h"
Transaction::Transaction(int OID,int MIndex, Burito* B)
{
	MenuIndex = MIndex;
	orderedMenu = B;
	orderID = OID;

}
Transaction::Transaction(int OID, int MIndex, vector<int> Ingred)	
{
	orderID = OID;
	
	
	MenuIndex = MIndex;
	orderedMenu = new BaseBurito;
	switch (MIndex)
	{
	case 1:
		break;
	case 2:
		orderedMenu = new Drink(orderedMenu);
		orderedMenu = new ComboDiscount(orderedMenu);
		break;
	case 3:
		orderedMenu = new Drink(orderedMenu);
		orderedMenu = new Fries(orderedMenu);
		orderedMenu = new SetDiscount(orderedMenu);
		break;
	default:
		break;
	}
	ingredientsInfo = Ingred;
	for (int i = 0; i < Ingred.size(); i++)
	{
		switch (Ingred[i])
		{
		case 1:
			orderedMenu = new Jumbo(orderedMenu);
			break;
		case 2:
			orderedMenu = new Sausage(orderedMenu);
			break;
		case 3:
			orderedMenu = new Fries(orderedMenu);
			break;
		case 4:
			orderedMenu = new Drink(orderedMenu);
			break;
		}

	}



};	//DB에서 추가할때

void Transaction:: PrintInfo()
{
	cout << orderID << ". " << orderedMenu->getDescription();
	/*switch (MenuIndex)
	{
	case 1:
		cout << "단품";
		break;
	case 2:
		cout << "콤보";
		break;
	case 3:
		cout << "세트";
		break;
	}
	
	for (int i = 0; i < ingredientsInfo.size(); i++)
	{	cout << " + ";
		switch (ingredientsInfo[i])
		{
		case 1:
			cout << "점보 ";
			break;
		case 2:
			cout << "소시지";
			break;
		case 3:
			cout << "감자 튀김";
			break;
		case 4:
			cout << "음료수";
			break;
		}
	}*/
	cout << ",  가격: " << orderedMenu->getCost() << "원" << endl;
};
void Transaction::getInfoforSave(int& Mindex, vector<int>& ingred)
{
	Mindex = MenuIndex;
	//ingred = ingredientsInfo;
	for (int i = 0; i < ingredientsInfo.size(); i++)
	{
		ingred.push_back(ingredientsInfo[i]);

	}

}