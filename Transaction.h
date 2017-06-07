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
	/*Transaction(int OID,int MIndex, int arr[])		//동적할당사용해서 넘기기, 일단 내비둠
	{
		orderID = OID;
		for (int i = 0; i < sizeof(arr) / 4; i++)
		{
			ingredientsInfo.insert(ingredientsInfo.end(), arr[i]);

		}
		orderedMenu = new BaseBurito();
		MenuIndex = MIndex;
	};*/
	Transaction(int OID, int MIndex ,Burito* B);//이건 프로그램으로 추가
	Transaction(int OID, int MIndex, vector<int> Ingred);//이놈은 DB에서 불러온걸읽음


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
	int MenuIndex;	//단품,콤보,세트를 구분하는 변수 순서대로 1, 2, 3
	vector<int> ingredientsInfo;	//1점보 2소시지 3튀김 4음료
	Burito* orderedMenu;
};

