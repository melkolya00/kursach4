#include "Stats.h"

void Statistick::setStatus(char* a)
{
	strcpy_s(status, sizeof(status), a);
}

char* Statistick::getStatus()
{
	return status;
}

void Statistick::setDate(char* a)
{
	strcpy_s(date, sizeof(date), a);
}

void Statistick::setNameClient(char* a)
{
	strcpy_s(nameClient, sizeof(nameClient), a);
}

void Statistick::setPas_info(char* a)
{
	strcpy_s(pas_info, sizeof(pas_info), a);
}

void Statistick::setTel(char* a)
{
	strcpy_s(tel, sizeof(tel), a);
}

void Statistick::setNameCredit(char* a)
{
	strcpy_s(nameCredit, sizeof(nameCredit), a);
}

void Statistick::setProcent(int a)
{
	procen = a;
}

void Statistick::setSum(int a)
{
	sum = a;
}

char* Statistick::getDate()
{
	return date;
}

char* Statistick::getNameClietn()
{
	return nameClient;
}

char* Statistick::getPas_info()
{
	return pas_info;
}

char* Statistick::getTel()
{
	return tel;
}

char* Statistick::getNameCredit()
{
	return nameCredit;
}

int Statistick::getProcent()
{
	return procen;
}

int Statistick::getSum()
{
	return sum;
}

ostream& operator<<(ostream& os, Statistick& obj)
{
	os << "******************************************" << endl;
	os << "Дата оформления заявки :" << obj.getDate() << endl;
	os << "Имя клиента: " << obj.getNameClietn() << endl;
	os << "Номер паспорта клиента: " << obj.getPas_info() << endl;
	os << "Номер телефона клиента: " << obj.getTel() << endl;
	os << "Наименование рекламного носителя: " << obj.getNameCredit() << endl;
	os << "Количество носителей: " << obj.getProcent() << endl;
	os << "Итоговая стоимость: " << obj.getSum() << "руб." << endl;
	os << "Статус: " << obj.getStatus() << endl;
	return os;
}

istream& operator>>(istream& os, Statistick& obj)
{
	os >> obj.date >> obj.nameClient >> obj.pas_info >> obj.tel >> obj.nameCredit >> obj.procen >> obj.sum;
	return os;
}
