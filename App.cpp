#include"App.h"
#include<sstream>
App::App()
{
	OrderID = 0;
	tm = new TransactionManager();
	bf = new BuritoFactory();
	ifstream OpenOrder;
	OrderID = 1;
	OpenOrder.open("Order.txt");
	string Order1Line;
	Transaction* trs;
	int a;	
	

	while (getline(OpenOrder, Order1Line))
	{	vector<int> makeburito;
		int temp, MIndex;
		istringstream iss(Order1Line);
		iss >> temp >> MIndex;
		for (int i = 0; i < temp-1; i++)
		{
			int temp3;
			iss >> temp3;
			makeburito.push_back(temp3);
		}

		trs = new Transaction(OrderID, MIndex, makeburito);
		tm->addTransaction(trs);
		OrderID++;
	}
	

}
App::~App()
{

	ofstream OpenOrder;
	OpenOrder.open("Order.txt");
	OpenOrder << tm->getInfo();

}
void App::run()
{
	cout << "부리또 주문 관리 프로그램" << endl;
	while (1)
	{
		cout << "----------------주문 목록-------------------" << endl;
		//tm->printTransaction();
		readTransaction();
		cout << "--------------------------------------------" << endl;
		cout << "1. 주문 추가" << endl;
		cout << "2, 주문 취소" << endl;
		cout << "3. 주문 처리" << endl;
		cout << "0. 종료" << endl;
		int a;
		cout << "--------------------------------------------" << endl;
		cin >> a;
		if (a == 1)
		{
			writeTransaction();
			
			
		}
		else if (a == 2)
		{
			cout << "취소할 메뉴" << endl;
			int b;
			cin >> b;
			tm->deleteTransaction(b);
		}
		else if (a == 3)
			tm->processFrontTransaction();
		else if (a == 0)
			break;
		else
			cout << "잘못 입력하셨습니다" << endl;


	
	}

}

void App::writeTransaction()
{
	cout << "주문 메뉴" << endl;
	cout << "---------------------------------------" << endl;
	cout << "메뉴 선택" << endl;
	cout << "1. 단품 (부리또, 3000원)" << endl;
	cout << "2. 콤보 (부리또 + 음료, 3700원)" << endl;
	cout << "3. 세트 (부리또 + 음료 + 감자튀김, 5500원)" << endl;
	cout << "---------------------------------------" << endl;
	cout << ": ";
	int temp;
	cin >> temp;
	vector<int> Ingred;
	
	Burito* orderedBurito;
	orderedBurito = bf->makeOrderedMenu(temp, Ingred);
	Transaction* trs = new Transaction(OrderID, temp, orderedBurito);
	for (int i = 0; i < Ingred.size(); i++)
	{
		trs->addIngred(Ingred[i]);

	}
	tm->addTransaction(trs);
	OrderID++;
}
void App::readTransaction()
{
	tm->printTransaction();

}