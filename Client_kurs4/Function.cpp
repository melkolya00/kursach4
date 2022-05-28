#include "Function.h"

void printfHistory(Server& obj)
{
	system("cls");
	cout << "История  " << endl;
	while (true)
	{
		int ch;
		char buf[100];
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		ch = atoi(buf);
		if (ch == -1)
		{
			break;
		}
		else
		{
			char nameCredit[100], buf[100], buf1[100], date[100], status[100];
			int sum, procent;
			recv(obj.getConnetc(), date, sizeof(date), 0);
			recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			procent = atoi(buf);
			recv(obj.getConnetc(), buf, sizeof(buf), 0);
			sum = atoi(buf);
			cout << "################################" << endl;
			cout << "Дата создания заявки : " << date << endl;
			cout << "Наименование носителя : " << nameCredit << endl;
			cout << "Количество : " << procent << endl;
			cout << "Стоимость : " << sum << endl;
		}
	}
}

void printf_money(Server& obj)
{
	cout << "Меню вывода средств >> " << endl;
	cout << "Введите сумму : ";
	int sum;
	cin >> sum;
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	int ch = atoi(buf);
	if (ch = -1)
	{
		cout << "У вас недостаточно средств " << endl;
	}
	else
	{
		cout << "Транзакция прошла успешно " << endl;
	}
}

void replenih_account(Server& obj)
{
	cout << "Меню пополнения счета >>" << endl;
	cout << "Введите сумму для поплнения : ";
	int sum;
	cin >> sum;
	char buf[100];
	itoa(sum, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Сумма зачислена " << endl;
}

void assesmentExpert(Server& obj)
{
	int cher;
	char msg[100];
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	cher = atoi(msg);
	if (cher == 1)
	{
		cout << "Нет ни одной оценки либо ни одного носителя !" << endl;
	}
	else
	{

		char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
		int sum, procent;
		recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		procent = atoi(buf);
		recv(obj.getConnetc(), buf1, sizeof(buf1), 0);
		sum = atoi(buf1);
		cout << "ЛУЧШИЙ РЕКЛАМНЫЙ НОСИТЕЛЬ" << endl;
		cout << "Название : " << nameCredit << endl;
		cout << "Количество : " << procent << endl;
		cout << "Итоговая стоимость : " << sum << endl;
	}
}

void checkImput(int i)
{
	while (true)
	{

		if (!cin)
		{
			cout << "Ошибка ввода ,введите число !" << endl;
			cin.clear();
			while (cin.get() != '\n');
		}
		else break;

	}
}

void Repay(Server& obj)
{
	int repay;
	int check;
	int ch;
	char date[100];
	char buf[100], msg[100], che[100];
	recv(obj.getConnetc(), che, sizeof(che), 0);
	ch = atoi(che);
	if (ch == 1)
	{
		cout << "Нет заявок" << endl;
	}
	else
	{
		cout << "Введите дату оформления заявки: ";
		cin >> date;
		cout << "Введите сумму, которую желаете внести в кач-ве оплаты: ";
		cin >> repay;
		itoa(repay, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		send(obj.getConnetc(), date, sizeof(date), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		check = atoi(msg);
		if (check == 0)
		{
			int sum;
			char buf2[100];
			recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
			sum = atoi(buf2);
			cout << "Остаток задолженности по оплате за рекламный носитель: " << sum << endl;
		}
		if (check == 1)
		{
			cout << "Сумма оплачена полностью." << endl;
		}
		if (check == 2)
		{
			char buf2[100];
			int sum;
			recv(obj.getConnetc(), buf2, sizeof(buf2), 0);
			sum = atoi(buf2);
			cout << "Излишек оплаты в размере" << sum << " будет зачислен на ваш банковский счёт." << endl;
		}
	}
}

void Make_Credit(Server& obj)
{

}

void addCredit(Server& obj)
{
	int check;
	char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
	int sum, procent;
	cout << "Меню добавления носителя ---------------" << endl;
	cout << "Введите название носителя : ";
	cin >> nameCredit;
	send(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
	cout << "Введите количество носителей: ";
	cin >> procent;
	itoa(procent, buf, 10);
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите стоимость оформления носителей: ";
	cin >> procent;
	itoa(procent, buf1, 10);
	send(obj.getConnetc(), buf1, sizeof(buf1), 0);
	system("cls");
	cout << "Рекламный носитель успешно добавлен." << endl;
	cout << "Наименование рекламного носителя: " << nameCredit << endl;
	cout << "Кол-во носителей: " << procent << endl;
	system("pause");
	system("cls");
}

void addRating(Server& obj)
{
	PrintfIntoCredit(obj);
	char siz[100];
	int size;
	recv(obj.getConnetc(), siz, sizeof(siz), 0);
	size = atoi(siz);
	cout << "Выберите нужный тип рекламного носителя: " << endl;
	cout << "Для выхода нажмите 0 " << endl;
	int ch;
	while (true)
	{
		cin >> ch;
		if (ch<0 || ch>size)
		{

			cout << "Ошибка, нет такого варианта." << endl;
		}

		else break;
	}
	if (ch == 0)
	{
		ch = -1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
	}
	else
	{
		ch = ch - 1;
		char buf[100];
		itoa(ch, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		cout << "Эксперт, поставьте носителю оценку 1-10:" << endl;
		int rating;
		while (true)
		{
			cin >> rating;
			checkImput(rating);
			if (rating < 0 || rating>10)
			{
				cout << "Оценка должна находиться в диапазоне 1-10 " << endl;
			}
			else break;
		}
		itoa(rating, buf, 10);
		send(obj.getConnetc(), buf, sizeof(buf), 0);
		cout << "Оценка была выставлена успешно. " << endl;
	}
}

void addClient(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистрация -----------------" << endl;
	cout << "Введите имя :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите номер телефона : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите номер паспорта : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте пароль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "Клиент успешно зарегистрирован " << endl;
	system("pause");
	system("cls");
}

void addAdmin(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистрация -------------------" << endl;
	cout << "Введите имя :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите номер телефона : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите номер паспорта : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте пароль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Администратор успешно зарегистрирован " << endl;
	system("pause");
	system("cls");
}

void addExpert(Server& obj)
{
	system("cls");
	char buf[100];
	cout << "Регистрация -----------------" << endl;
	cout << "Введите имя :";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите номер телефона : +375";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите номер паспорта : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте логин : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Придумайте пароль : ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);

	cout << "Эксперт успешно зарегистрирован. " << endl;
	system("pause");
	system("cls");
}

void AutorizationUser(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации пользователя ----------------" << endl;
	cout << " Введите логин ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите пароль: ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "Убедитесь в правильности введённых данных" << endl;
		Menu m;
		m.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Уважаемый" << name << ", вы вошли в систему." << endl;
	}
}

void AutorizationAdmin(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации ---------------" << endl;
	cout << "Введите логин. ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите пароль. ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "Убедитесь в правильности введённых данных." << endl;
		Menu m;
		m.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Уважаемый " << name << ", вы вошли в систему в качестве администратора." << endl;
	}
}

void AutorizationExpert(Server& obj)
{
	char buf[100];
	cout << "Меню авторизации -----------------" << endl;
	cout << "Введите логин: ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	cout << "Введите пароль: ";
	cin >> buf;
	send(obj.getConnetc(), buf, sizeof(buf), 0);
	char buff[100];
	recv(obj.getConnetc(), buff, sizeof(buff), 0);
	int ch = atoi(buff);
	if (ch == 0)
	{
		cout << "Убедитесь в правильности введённых данных." << endl;
		Menu m;
		m.startMenu(obj);
	}
	else
	{
		system("cls");
		char name[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		cout << "Уважаемый" << name << ", вы вошли в систему в качестве эксперта." << endl;
	}
}

void PrintfUserInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "Имя \t" << "Телефон \t" << "Паспорт \t" << "Логин \t" << "Пароль \t" << "Счёт в банке " << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << cash << endl;
	}
	system("pause");
	system("cls");
}

void PrintfAdminInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "Имя \t" << "Телефон \t" << "Паспорт \t" << "Логин \t" << "Пароль \t" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << endl;
	}
	system("pause");
	system("cls");
}

void PrintfExpertInfo(Server& obj)
{
	char buf[100];
	int size;
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	size = atoi(buf);
	system("cls");
	cout << "Имя \t" << "Телефон \t" << "Паспорт \t" << "Логин \t" << "Пароль \t" << endl;
	for (int i = 0; i < size; i++)
	{
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << name << "\t" << tel << "\t" << pas_info << "\t" << setw(13) << login << "\t" << password << "\t" << endl;
	}
	system("pause");
	system("cls");
}

void PrintfIntoCredit(Server& obj)
{
	system("cls");
	int check;
	char msg[100];
	recv(obj.getConnetc(), msg, sizeof(msg), 0);
	check = atoi(msg);
	cout << "№ \t" << "Наименование носителя \t" << "Количество \t" << "Стоимость оформления \t" << endl;
	for (int i = 0; i < check; i++)
	{
		char nameCredit[100], nameExpert[100], loginExpert[100], buf[100], buf1[100];
		int sum, procent;
		recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		procent = atoi(buf);
		recv(obj.getConnetc(), buf1, sizeof(buf1), 0);
		sum = atoi(buf1);
		cout << i + 1 << "\t" << nameCredit << "\t" << setw(9) << procent << "\t" << setw(19) << sum << "\t" << endl;
	}
	system("pause");
}

void PriintfStatistick(Server& obj)
{
	int che;
	char bue[100];
	recv(obj.getConnetc(), bue, sizeof(bue), 0);
	che = atoi(bue);
	if (che == 1)
	{
		cout << "Заказов нет!" << endl;
	}
	else
	{
		int check;
		char buf[100];
		recv(obj.getConnetc(), buf, sizeof(buf), 0);
		check = atoi(buf);
		for (int i = 0; i < check; i++)
		{
			char date[100];
			char nameClient[100];
			char pas_info[100];
			char tel[100], msg[100], bufproc[100], bufsum[100];
			char nameCredit[100];
			int procen;
			int sum;
			recv(obj.getConnetc(), date, sizeof(date), 0);
			recv(obj.getConnetc(), nameClient, sizeof(nameClient), 0);
			recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
			recv(obj.getConnetc(), tel, sizeof(tel), 0);
			recv(obj.getConnetc(), nameCredit, sizeof(nameCredit), 0);
			recv(obj.getConnetc(), bufproc, sizeof(bufproc), 0);
			recv(obj.getConnetc(), bufsum, sizeof(bufsum), 0);
			procen = atoi(bufproc);
			sum = atoi(bufsum);
			cout << "**************************************************" << endl;
			cout << "Дата оформления заявки :" << date << endl;
			cout << "Имя клиента :" << nameClient << endl;
			cout << "Паспортные данные клиента:" << pas_info << endl;
			cout << "Номер телефона клиента :" << tel << endl;
			cout << "Наименование носителя :" << nameCredit << endl;
			cout << "Количество носителей :" << procen << endl;
			cout << "Всего к оплате заказчику :" << sum << "руб." << endl;

		}
	}
}

void DelClient(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления пользователя " << endl;
	cout << "Введите логин пользователя: ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер паспорта пользователя: ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "Убедитесь в правильности введённых данных " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Пользователь:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "Имя: " << name << endl;
		cout << "Номер телефона: " << tel << endl;
		cout << "Номер паспорта: " << pas_info << endl;
		cout << "Деньги на счету: " << cash << endl;
		cout << "Логин: " << login << endl;
		cout << "Пароль: " << password << endl;
		cout << "Успешно удалён." << endl;
		system("pause");
		system("cls");
	}
}

void DelAdmin(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления администратора:" << endl;
	cout << "Введите логин: ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер паспорта: ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "Убедитесь в правильности введённых данных" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Администратор:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя: " << name << endl;
		cout << "Номер телефона: " << tel << endl;
		cout << "Номер паспорта: " << pas_info << endl;
		cout << "Логин: " << login << endl;
		cout << "Пвроль: " << password << endl;
		cout << "Успешно удалён." << endl;
		system("pause");
		system("cls");
	}
}

void DelExpert(Server& obj)
{
	system("cls");
	int ch = 0;
	cout << "Меню удаления эксперта" << endl;
	cout << "Введите логин: ";
	char log[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер паспорта: ";
	char pas[100];
	cin >> pas;
	send(obj.getConnetc(), pas, sizeof(pas), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	ch = atoi(buf);
	if (ch == 0)
	{
		system("cls");
		cout << "Убедитесь в правльности введённых данных." << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Эксперт:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100];
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя: " << name << endl;
		cout << "Номер телефона: " << tel << endl;
		cout << "Номер паспорта: " << pas_info << endl;
		cout << "Логин: " << login << endl;
		cout << "Пороль: " << password << endl;
		cout << "Успешно удалён" << endl;
		system("pause");
		system("cls");
	}
}

void findClient(Server& obj)
{
	system("cls");
	cout << "Меню поиска клиента ------------------" << endl;
	cout << "Введите логин клиента: ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "Убедитесь в правильности введённых данныз" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		recv(obj.getConnetc(), msg, sizeof(msg), 0);
		cash = atoi(msg);
		cout << "Имя: " << name << endl;
		cout << "Номер телефона: " << tel << endl;
		cout << "Номер паспорта: " << pas_info << endl;
		cout << "Денег на счету: " << cash << endl;
		cout << "Логин: " << login << endl;
		cout << "Пароль: " << password << endl;
		system("pause");
		system("cls");
	}
}

void findAdmin(Server& obj)
{
	system("cls");
	cout << "Меню поиска администратора -------------------------" << endl;
	cout << "Введите логин администратора : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "Убедитесь в правильности введённых данных. " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя: " << name << endl;
		cout << "Номер телефона: " << tel << endl;
		cout << "Номер паспорта: " << pas_info << endl;
		cout << "Логин: " << login << endl;
		cout << "Пароль: " << password << endl;
		system("pause");
		system("cls");
	}
}

void findExpert(Server& obj)
{
	system("cls");
	cout << "Меню поиска экспертов -----------------------" << endl;
	cout << "Введите логин эксперта : ";
	int check = 0;
	char log[100], tel[100];
	cin >> log;
	send(obj.getConnetc(), log, sizeof(log), 0);
	cout << "Введите номер телефона :+375";
	cin >> tel;
	send(obj.getConnetc(), tel, sizeof(tel), 0);
	char buf[100];
	recv(obj.getConnetc(), buf, sizeof(buf), 0);
	check = atoi(buf);
	if (check == 0)
	{
		system("cls");
		cout << "Убедитесь в правильности введённых данных " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "Результаты поиска:" << endl;
		char name[100], tel[100], pas_info[100], login[100], password[100], msg[100];
		float cash;
		recv(obj.getConnetc(), name, sizeof(name), 0);
		recv(obj.getConnetc(), tel, sizeof(tel), 0);
		recv(obj.getConnetc(), pas_info, sizeof(pas_info), 0);
		recv(obj.getConnetc(), login, sizeof(login), 0);
		recv(obj.getConnetc(), password, sizeof(password), 0);
		cout << "Имя: " << name << endl;
		cout << "Номер телефона: " << tel << endl;
		cout << "Номер паспорта: " << pas_info << endl;
		cout << "Логин: " << login << endl;
		cout << "Пароль: " << password << endl;
		system("pause");
		system("cls");
	}
}
