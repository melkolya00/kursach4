#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Bank
{
	char nameCredit[100];
	char nameExpert[100];
	char loginExpert[100];
	int procent;
	int sum;
public:
	void setNameCredit(char* name);
	void setNameExpert(char* name);
	void setLoginExpert(char* name);
	void setProcent(int a);
	void setSum(int a);
	char* getNameCredit();
	char* getNameExpert();
	char* getLoginExpert();
	int getProcent();
	int getSum();
	friend istream& operator>>(istream& os, Bank& obj);
};