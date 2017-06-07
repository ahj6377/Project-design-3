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



};	//DB���� �߰��Ҷ�

void Transaction:: PrintInfo()
{
	cout << orderID << ". " << orderedMenu->getDescription();
	/*switch (MenuIndex)
	{
	case 1:
		cout << "��ǰ";
		break;
	case 2:
		cout << "�޺�";
		break;
	case 3:
		cout << "��Ʈ";
		break;
	}
	
	for (int i = 0; i < ingredientsInfo.size(); i++)
	{	cout << " + ";
		switch (ingredientsInfo[i])
		{
		case 1:
			cout << "���� ";
			break;
		case 2:
			cout << "�ҽ���";
			break;
		case 3:
			cout << "���� Ƣ��";
			break;
		case 4:
			cout << "�����";
			break;
		}
	}*/
	cout << ",  ����: " << orderedMenu->getCost() << "��" << endl;
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