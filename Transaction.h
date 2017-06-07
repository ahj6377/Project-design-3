#pragma once
#include <vector>
#include "Burito.h"
#include"BaseBurito.h"
#include"Drink.h"
#include"Fries.h"
#include"Jumbo.h"
#include"Sausage.h"
#include"ComboDiscount.h"
#include"SetDiscount.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Transaction
{
public:
	Transaction() {
		orderID = 0;
		orderedMenu = NULL;
		MenuIndex = 1;
	};
	~Transaction() {};
	/*Transaction(int OID,int MIndex, int arr[])		//�����Ҵ����ؼ� �ѱ��, �ϴ� �����
	{
		orderID = OID;
		for (int i = 0; i < sizeof(arr) / 4; i++)
		{
			ingredientsInfo.insert(ingredientsInfo.end(), arr[i]);

		}
		orderedMenu = new BaseBurito();
		MenuIndex = MIndex;
	};*/
	Transaction(int OID, int MIndex ,Burito* B);//�̰� ���α׷����� �߰�
	Transaction(int OID, int MIndex, vector<int> Ingred);//�̳��� DB���� �ҷ��°�����


	void IDMinus() {
		orderID--;
	};
	void PrintInfo();
	void addIngred(int Ingred) {
		ingredientsInfo.push_back(Ingred);
	
	};
	void getInfoforSave(int& Mindex, vector<int>& ingred);
private:
	int orderID;
	int MenuIndex;	//��ǰ,�޺�,��Ʈ�� �����ϴ� ���� ������� 1, 2, 3
	vector<int> ingredientsInfo;	//1���� 2�ҽ��� 3Ƣ�� 4����
	Burito* orderedMenu;
};

