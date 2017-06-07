#include"TransactionManger.h"
#include<vector>
void TransactionManager::addTransaction(Transaction* newTransaction)
{
	//orderTransactions.insert(orderTransactions.end(), newTransaction);
	orderTransactions.push_back(*newTransaction);

	Onum = orderTransactions.size();//Onum�� �׻� ��������° ������

}
void TransactionManager::deleteTransaction(int index)
{	
	if (orderTransactions.size() == 0)
	{
		cout << "����� �ֹ��� �����ϴ�!" << endl;
	}
	else if(index > orderTransactions.size())
	{
	cout << "�߸��� �Է��Դϴ�!" << endl;
    }
	else
	{
		Onum = orderTransactions.size();
		for (int i = index - 1; i < orderTransactions.size(); i++)
		{
			orderTransactions[i].IDMinus();//Onum�� -1�Ǳ⶧���� index��° ���� ID�� ��� ���ܿ´�

		}
		orderTransactions.erase(orderTransactions.begin() + index - 1);//
	}
}
void TransactionManager::printMenu()
{	vector<int> makeorder;
	cout << "�ֹ� �޴�" << endl;
	cout << "---------------------------------------" << endl;
	cout << "�޴� ����" << endl;
	cout << "1. ��ǰ (�θ���, 3000��)" << endl;
	cout << "2. �޺� (�θ��� + ����, 3700��)" << endl;
	cout << "3. ��Ʈ (�θ��� + ���� + ����Ƣ��, 4500��)" << endl;
	cout << "---------------------------------------" << endl;
	cout << ": ";
	int a;
	cin >> a;
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
		cout << "ó���� �ֹ��� �����ϴ�!" << endl;
	}
	else
	{
		cout << "�ֹ� ó�� !" << endl;
		cout << "--------------�ֹ� ����--------------" << endl;
		cout << "1�� �ֹ�" << endl;

		orderTransactions[0].PrintInfo();

		for (int i = 1; i < orderTransactions.size(); i++)
		{
			orderTransactions[i].IDMinus();

		}
		orderTransactions.erase(orderTransactions.begin());
	}
}