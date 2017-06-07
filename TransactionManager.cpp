#include"TransactionManger.h"
#include<vector>
void TransactionManager::addTransaction(Transaction* newTransaction)
{
	//orderTransactions.insert(orderTransactions.end(), newTransaction);
	orderTransactions.push_back(*newTransaction);

	Onum = orderTransactions.size();//Onum는 항상 마지막번째 숫자임

}
void TransactionManager::deleteTransaction(int index)
{	
	if (orderTransactions.size() == 0)
	{
		cout << "취소할 주문이 없습니다!" << endl;
	}
	else if(index > orderTransactions.size())
	{
	cout << "잘못된 입력입니다!" << endl;
    }
	else
	{
		Onum = orderTransactions.size();
		for (int i = index - 1; i < orderTransactions.size(); i++)
		{
			orderTransactions[i].IDMinus();//Onum가 -1되기때문에 index번째 이후 ID를 모두 땡겨온다

		}
		orderTransactions.erase(orderTransactions.begin() + index - 1);//
	}
}
void TransactionManager::printMenu()
{	vector<int> makeorder;
	cout << "주문 메뉴" << endl;
	cout << "---------------------------------------" << endl;
	cout << "메뉴 선택" << endl;
	cout << "1. 단품 (부리또, 3000원)" << endl;
	cout << "2. 콤보 (부리또 + 음료, 3700원)" << endl;
	cout << "3. 세트 (부리또 + 음료 + 감자튀김, 4500원)" << endl;
	cout << "---------------------------------------" << endl;
	cout << ": ";
	int a;
	cin >> a;
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
			makeorder.push_back( b);
	}

	//addTransaction(new Transaction(Onum + 1, a));
}
void TransactionManager::printTransaction()
{
	for (int i = 0; i < orderTransactions.size(); i++)
	{
		orderTransactions[i].PrintInfo();
	}

}
void TransactionManager::processFrontTransaction()
{
	if (orderTransactions.size() == 0)
	{
		cout << "처리할 주문이 없습니다!" << endl;
	}
	else
	{
		cout << "주문 처리 !" << endl;
		cout << "--------------주문 내용--------------" << endl;
		cout << "1번 주문" << endl;

		orderTransactions[0].PrintInfo();

		for (int i = 1; i < orderTransactions.size(); i++)
		{
			orderTransactions[i].IDMinus();

		}
		orderTransactions.erase(orderTransactions.begin());
	}
}