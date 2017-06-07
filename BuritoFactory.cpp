#include"BuritoFactory.h"

Burito* BuritoFactory::makeOrderedMenu(int type, vector<int>& Ingred)
{
	
		Burito* ordered = new BaseBurito();
		vector<int> makeorder;




		switch (type)
		{
		case 1: //��ǰ

			break;
		case 2: //�޺�
			
			ordered = new Drink(ordered);
			ordered = new ComboDiscount(ordered);
		
			break;
		case 3: //��Ʈ
			
			ordered = new Drink(ordered);
			ordered = new Fries(ordered);
			ordered = new SetDiscount(ordered);
			
			break;

		}
		while (1)
		{
			cout << "�߰� �޴� ����" << endl;
			cout << "1. ���� (1000��)" << endl;
			cout << "2. �Ҽ��� (1000��)" << endl;
			cout << "3. ���� Ƣ�� (2000��)" << endl;
			cout << "4. ����� (1000��)" << endl;
			cout << "0. �׸� �߰�" << endl;
			cout << "---------------------------------------" << endl;
			cout << ": ";
			int b;
			cin >> b;
			if (b == 0)
				break;
			else
				makeorder.push_back(b);
		}
		for (int i = 0; i < makeorder.size(); i++)
		{
			switch (makeorder[i])
			{
			case 1:
				ordered = new Jumbo(ordered);
				break;
			case 2:
				ordered = new Sausage(ordered);
				break;
			case 3:
				ordered = new Fries(ordered);
				break;
			case 4:
				ordered = new Drink(ordered);
				break;
			default:
				break;
			}
		}
		Ingred = makeorder;
		return ordered;
}