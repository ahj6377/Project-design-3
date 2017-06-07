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
	cout << "�θ��� �ֹ� ���� ���α׷�" << endl;
	while (1)
	{
		cout << "----------------�ֹ� ���-------------------" << endl;
		//tm->printTransaction();
		readTransaction();
		cout << "--------------------------------------------" << endl;
		cout << "1. �ֹ� �߰�" << endl;
		cout << "2, �ֹ� ���" << endl;
		cout << "3. �ֹ� ó��" << endl;
		cout << "0. ����" << endl;
		int a;
		cout << "--------------------------------------------" << endl;
		cin >> a;
		if (a == 1)
		{
			writeTransaction();
			
			
		}
		else if (a == 2)
		{
			cout << "����� �޴�" << endl;
			int b;
			cin >> b;
			tm->deleteTransaction(b);
		}
		else if (a == 3)
			tm->processFrontTransaction();
		else if (a == 0)
			break;
		else
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;


	
	}

}

void App::writeTransaction()
{
	cout << "�ֹ� �޴�" << endl;
	cout << "---------------------------------------" << endl;
	cout << "�޴� ����" << endl;
	cout << "1. ��ǰ (�θ���, 3000��)" << endl;
	cout << "2. �޺� (�θ��� + ����, 3700��)" << endl;
	cout << "3. ��Ʈ (�θ��� + ���� + ����Ƣ��, 5500��)" << endl;
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