#include "Menu.h"

void Menu::CheckImputSwitch(int check)
{
	while (true)
	{
		if (!cin)
		{
			cout << "������. ��������� �������." << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}

void Menu::displayExpert(Server& obj)
{
	cout << "�������: ";
	char name[100], tel[100], pas_info[100], login[100], password[100];
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << name << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "*****************************************" << endl;
	cout << "������������ ������: " << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
	cout << "���: " << name << endl;
	cout << "����� ��������:" << pas_info << endl;
	cout << "����� ��������: " << tel << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
	system("pause");
}

void Menu::displayClient(Server& obj)
{
	cout << "������: ";
	char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
	int cash;
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << name << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	cash = atoi(msg);
	cout << "*******************************************" << endl;
	cout << "������������ ������: " << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
	cout << "���: " << name << endl;
	cout << "����� ��������: " << pas_info << endl;
	cout << "����� �� �����: " << cash << endl;
	cout << "����� ��������: " << tel << endl;
	cout << "�����: " << login << endl;
	cout << "������: " << password << endl;
	system("pause");
}

void Menu::TakeCreditMenu(Server& obj)
{
	int ch = 0;

	int check = 0;
	char buf[100], buf2[100];
	cout << "�������� ��� ���������� ��������. " << endl;
	PrintfIntoCredit(obj);
	cout << "������� ������������ ��������, ������� ������ ������� " << endl;
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
	check = atoi(buf2);
	if (check == 0)
	{
		cout << "��������� � ������������ �������� ������." << endl;
	}
	else
	{
		cout << "������� ����������� ����:" << endl;
		char date[100];
		cin >> date;
		send(obj.getConnetc(), date, sizeof(date), 0);
		cout << "������ ��������." << endl;
		ch = 2;
	}

}

void Menu::MenuChangeUser(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "�������� ����������� �������� -------------" << endl;
		cout << "1)��� " << endl;
		cout << "2)����� �������� " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)����� " << endl;
		cout << "5)������ " << endl;
		cout << "6)����� " << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "������� ����� ���: ";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "��� ������� ��������. " << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "������� ����� ����� ��������: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "����� �������� ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ����� ��������: +375 ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "����� �������� ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� ����� ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "����� ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 6:MenuUser(obj);
		}
	}
}

void Menu::MenuChangeExpert(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "�������� ����������� ��������: " << endl;
		cout << "1)��� " << endl;
		cout << "2)����� �������� " << endl;
		cout << "3)����� �������� " << endl;
		cout << "4)����� " << endl;
		cout << "5)������ " << endl;
		cout << "6)����� " << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "������� ����� ���: ";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "��� ������� ��������. " << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "������� ����� ����� ��������: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "����� �������� ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "������� ����� ����� ��������: +375 ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "����� �������� ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "������� ����� �����: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "����� ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "������� ����� ������: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "������ ������� ������. " << endl;
			system("pause");
			system("cls");
			break;
		case 6:ExpertMenu(obj);
		}
	}
}

void Menu::MenuExpertrewvie(Server& Connection)
{
	system("cls");
	char nameCredit[100], bufproc[100], bufsum[100];
	int proc;
	int sum;
	cout << "��������� ��������� �������� � ����� ������ ���������: ";
	recv(Connection.getConnetc(), nameCredit, sizeof(nameCredit), 0);
	cout << nameCredit << endl;
	cout << "��������� ��������:" << endl;
	recv(Connection.getConnetc(), bufproc, sizeof(bufproc), 0);
	proc = atoi(bufproc);
	cout << "���������� ���������: " << proc << endl;
	recv(Connection.getConnetc(), bufsum, sizeof(bufsum), 0);
	sum = atoi(bufsum);
	cout << "�������� ���������: " << sum << endl;
	system("pause");
}

void Menu::MenuUser(Server& Connection)
{

	while (true)
	{
		char buf[100];
		int ch;
		cout << endl;
		cout << "1)���������� ������ �� ��������� �������� " << endl;
		cout << "2)������ ���������� ������� �� �������� " << endl;
		cout << "3)���������� ����� " << endl;
		cout << "4)����� ������� " << endl;
		cout << "5)�������� ������� ������ " << endl;
		cout << "6)��������� �������� " << endl;
		cout << "7)��������� ���������� �������� " << endl;
		cout << "8)������ ��������� � ������ ����. ���������" << endl;
		cout << "9)�����" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:TakeCreditMenu(Connection); break;
		case 2:Repay(Connection); break;
		case 3:replenih_account(Connection); break;
		case 4:printf_money(Connection); break;
		case 5:printfHistory(Connection); break;
		case 6:displayClient(Connection); break;
		case 7:MenuChangeUser(Connection); break;
		case 8: assesmentExpert(Connection); break;
		case 9:startMenu(Connection);
		}
	}
}

void Menu::startMenu(Server& Connection)
{
	while (1)
	{
		char buf[100];
		int ch;
		cout << "1)����������� " << endl;
		cout << "2)����������� ������� " << endl;
		cout << "3)A���������� �������������� " << endl;
		cout << "4)����������� �������� " << endl;
		cout << "5)����� " << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addClient(Connection); break;
		case 2:AutorizationUser(Connection); MenuUser(Connection); break;
		case 3:AutorizationAdmin(Connection); MenuAdmin(Connection); break;
		case 4:AutorizationExpert(Connection); ExpertMenu(Connection);
		case 5:exit(1);
		}
	}
}

void Menu::MenuAdmin(Server& Connection)
{
	while (1)
	{
		cout << "1)����� ���������� � ���� ������������� " << endl;
		cout << "2)����� ���������� � ���� ��������������� " << endl;
		cout << "3)����� ������������ " << endl;
		cout << "4)����� �������������� " << endl;
		cout << "5)�������� �������������� " << endl;
		cout << "6)�������� ������������ " << endl;
		cout << "7)���������� ��������������" << endl;
		cout << "8)���������� �������� " << endl;
		cout << "9)���������� ��������� ��������" << endl;
		cout << "10)����� ���������� �� ���������" << endl;
		cout << "11)�������� �������� " << endl;
		cout << "12)����� �������� " << endl;
		cout << "13)����� ������ ������� " << endl;
		cout << "14)����� " << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:PrintfUserInfo(Connection); break;
		case 2:PrintfAdminInfo(Connection); break;
		case 3:findClient(Connection); break;
		case 4:findAdmin(Connection); break;
		case 5:DelAdmin(Connection); break;
		case 6:DelClient(Connection); break;
		case 7:addAdmin(Connection); break;
		case 8:addExpert(Connection); break;
		case 9:addCredit(Connection); break;
		case 10:PrintfExpertInfo(Connection); break;
		case 11:DelExpert(Connection); break;
		case 12:findExpert(Connection); break;
		case 13:PriintfStatistick(Connection); break;
		case 14:startMenu(Connection); break;
		}
	}
}

void Menu::ExpertMenu(Server& Connection)
{
	while (true)
	{
		char buf[100];
		int ch;
		//displayExpert(Connection);
		cout << endl;
		
		cout << "1)����������� � ���������� ��������� " << endl;
		cout << "2)����� ���������� �������� " << endl;
		cout << "3)�������������� ���������� �������� " << endl;
		cout << "4)�����" << endl;
		cin >> ch;
		CheckImputSwitch(ch);
		_itoa(ch, buf, 10);
		send(Connection.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:addRating(Connection); break;
		case 2:displayExpert(Connection); break;
		case 3:MenuChangeExpert(Connection); break;
		case 4:startMenu(Connection);
		}
	}
}
