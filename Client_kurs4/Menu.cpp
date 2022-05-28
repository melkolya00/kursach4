#include "Menu.h"

void Menu::CheckImputSwitch(int check)
{
	while (true)
	{
		if (!cin)
		{
			cout << "Ошибка. Повторите попытку." << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;
	}
}

void Menu::displayExpert(Server& obj)
{
	cout << "Эксперт: ";
	char name[100], tel[100], pas_info[100], login[100], password[100];
	recv(obj.getConnetc(), name, sizeof(name), 0);
	recv(obj.getConnetc(), tel, sizeof(tel), 0);
	recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
	recv(obj.getConnetc(), login, sizeof(login), 0);
	cout << name << endl;
	recv(obj.getConnetc(), password, sizeof(password), 0);
	cout << "*****************************************" << endl;
	cout << "Персональные данные: " << endl;
	cout << "Логин: " << login << endl;
	cout << "Пароль: " << password << endl;
	cout << "Имя: " << name << endl;
	cout << "Номер паспорта:" << pas_info << endl;
	cout << "Номер телефона: " << tel << endl;
	cout << "Логин: " << login << endl;
	cout << "Пароль: " << password << endl;
	system("pause");
}

void Menu::displayClient(Server& obj)
{
	cout << "Клиент: ";
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
	cout << "Персональные данные: " << endl;
	cout << "Логин: " << login << endl;
	cout << "Пароль: " << password << endl;
	cout << "Имя: " << name << endl;
	cout << "Номер паспорта: " << pas_info << endl;
	cout << "Денег на счету: " << cash << endl;
	cout << "Номер телефона: " << tel << endl;
	cout << "Логин: " << login << endl;
	cout << "Пароль: " << password << endl;
	system("pause");
}

void Menu::TakeCreditMenu(Server& obj)
{
	int ch = 0;

	int check = 0;
	char buf[100], buf2[100];
	cout << "Выберите тип рекламного носителя. " << endl;
	PrintfIntoCredit(obj);
	cout << "Введите наименование носителя, который хотите выбрать " << endl;
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
	check = atoi(buf2);
	if (check == 0)
	{
		cout << "Убедитесь в правильности введённых данных." << endl;
	}
	else
	{
		cout << "Введите сегодняшнюю дату:" << endl;
		char date[100];
		cin >> date;
		send(obj.getConnetc(), date, sizeof(date), 0);
		cout << "Заявка одобрена." << endl;
		ch = 2;
	}

}

void Menu::MenuChangeUser(Server& obj)
{
	while (true)
	{
		system("cls");
		cout << "Выберите необходимый параметр -------------" << endl;
		cout << "1)Имя " << endl;
		cout << "2)Номер паспорта " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин " << endl;
		cout << "5)Пароль " << endl;
		cout << "6)Выход " << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя: ";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено. " << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новый номер паспорта: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Номер паспорта успешно изменён. " << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новый номер телефона: +375 ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Номер телефона успешно изменён. " << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый логин ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Логин успешно изменён. " << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пароль: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Пароль успешно изменён. " << endl;
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
		cout << "Выберите необходимый параметр: " << endl;
		cout << "1)Имя " << endl;
		cout << "2)Номер паспорта " << endl;
		cout << "3)Номер телефона " << endl;
		cout << "4)Логин " << endl;
		cout << "5)Пароль " << endl;
		cout << "6)Выход " << endl;
		int ch;
		char buf[100];
		cin >> ch;
		CheckImputSwitch(ch);
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		switch (ch)
		{
		case 1:cout << "Введите новое имя: ";
			char name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Имя успешно изменено. " << endl;
			system("pause");
			system("cls");
			break;
		case 2:cout << "Введите новый номер паспорта: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Номер паспорта успешно изменён. " << endl;
			system("pause");
			system("cls");
			break;
		case 3:cout << "Введите новый номер телефона: +375 ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Номер телефона успешно изменён. " << endl;
			system("pause");
			system("cls");
			break;
		case 4:cout << "Введите новый логин: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Логин успешно изменён. " << endl;
			system("pause");
			system("cls");
			break;
		case 5:cout << "Введите новый пароль: ";
			name[100];
			cin >> name;
			send(obj.getConnetc(), name, sizeof(name), 0);
			cout << "Пароль успешно изменён. " << endl;
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
	cout << "Наилучший рекламный носитель с точки зрения экспертов: ";
	recv(Connection.getConnetc(), nameCredit, sizeof(nameCredit), 0);
	cout << nameCredit << endl;
	cout << "Параметры носителя:" << endl;
	recv(Connection.getConnetc(), bufproc, sizeof(bufproc), 0);
	proc = atoi(bufproc);
	cout << "Количество носителей: " << proc << endl;
	recv(Connection.getConnetc(), bufsum, sizeof(bufsum), 0);
	sum = atoi(bufsum);
	cout << "Итоговая стоимость: " << sum << endl;
	system("pause");
}

void Menu::MenuUser(Server& Connection)
{

	while (true)
	{
		char buf[100];
		int ch;
		cout << endl;
		cout << "1)Оформление заявки на рекламный носитель " << endl;
		cout << "2)Оплата размещения рекламы на носителе " << endl;
		cout << "3)Пополнение счёта " << endl;
		cout << "4)Вывод средств " << endl;
		cout << "5)Просмотр истории заявок " << endl;
		cout << "6)Параметры аккаунта " << endl;
		cout << "7)Изменение параметров аккаунта " << endl;
		cout << "8)Мнение экспертов о лучших рекл. носителях" << endl;
		cout << "9)Выход" << endl;
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
		cout << "1)Регистрация " << endl;
		cout << "2)Авторизация клиента " << endl;
		cout << "3)Aвторизация администратора " << endl;
		cout << "4)Авторизация эксперта " << endl;
		cout << "5)Выход " << endl;
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
		cout << "1)Вывод информации о всех пользователях " << endl;
		cout << "2)Вывод информации о всех администраторах " << endl;
		cout << "3)Поиск пользователя " << endl;
		cout << "4)Поиск администратора " << endl;
		cout << "5)Удаление администратора " << endl;
		cout << "6)Удаление пользователя " << endl;
		cout << "7)Добавление администратора" << endl;
		cout << "8)Добавление эксперта " << endl;
		cout << "9)Добавление рекламный носитель" << endl;
		cout << "10)Вывод информации об экспертах" << endl;
		cout << "11)Удаление эксперта " << endl;
		cout << "12)Поиск эксперта " << endl;
		cout << "13)Вывод списка заказов " << endl;
		cout << "14)Выход " << endl;
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
		
		cout << "1)Отображение и оценивание носителей " << endl;
		cout << "2)Вывод параметров аккаунта " << endl;
		cout << "3)Редактирование параметров аккаунта " << endl;
		cout << "4)Выход" << endl;
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
