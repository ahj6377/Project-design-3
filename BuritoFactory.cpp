#include"BuritoFactory.h"

Burito* BuritoFactory::makeOrderedMenu(int type, vector<int>& Ingred)
{
	
		Burito* ordered = new BaseBurito();
		vector<int> makeorder;




		switch (type)
		{
		case 1: //단품

			break;
		case 2: //콤보
			
			ordered = new Drink(ordered);
			ordered = new ComboDiscount(ordered);
		
			break;
		case 3: //세트
			
			ordered = new Drink(ordered);
			ordered = new Fries(ordered);
			ordered = new SetDiscount(ordered);
			
			break;

		}
		while (1)
		{
			cout << "추가 메뉴 선택" << endl;
			cout << "1. 점보 (1000원)" << endl;
			cout << "2. 소세지 (1000원)" << endl;
			cout << "3. 감자 튀김 (2000원)" << endl;
			cout << "4. 음료수 (1000원)" << endl;
			cout << "0. 그만 추가" << endl;
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