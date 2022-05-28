#include "Bank.h"

void Bank::setNameCredit(char* name)
{
	strcpy_s(nameCredit, sizeof(nameCredit), name);
}

void Bank::setNameExpert(char* name)
{
	strcpy_s(nameExpert, sizeof(nameExpert), name);
}

void Bank::setLoginExpert(char* name)
{
	strcpy_s(loginExpert, sizeof(loginExpert), name);
}

void Bank::setProcent(int a)
{
	procent = a;
}

void Bank::setSum(int a)
{
	sum = a;
}

char* Bank::getNameCredit()
{
	return nameCredit;
}

char* Bank::getNameExpert()
{
	return nameExpert;
}

char* Bank::getLoginExpert()
{
	return loginExpert;
}

int Bank::getProcent()
{
	return procent;
}

int Bank::getSum()
{
	return sum;
}

istream& operator>>(istream& os, Bank& obj)
{
	os >> obj.nameCredit >> obj.procent >> obj.sum >> obj.nameExpert >> obj.loginExpert;
	return os;
}
