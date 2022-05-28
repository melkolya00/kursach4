#pragma once
#include"Human.h"
#include"Server.h"
#include"Bank.h"
#include"Stats.h"
#include<vector>
#include "CreateFile.h"
#include"Rating.h"
class User
{
protected:
	vector<Rating>vecRating;
	vector<Statistick>vecStats;
	vector<Bank>vecBank;
	vector<Human>vecHuman;
	vector<Human>vecAdmin;
	vector<Human>vecExpert;
public:
	User();
	void printfHistory(int i, Server& obj);
	void  printf_money(int i, Server& obj);
	void replenih_account(Server& obj, int i);
	void  opinionExpert(Server& obj, int i);
	void replenish(Server& obj, int i);
	void receptionExpert(int i, Server& obj);
	void reception(int i, Server& obj);
	int AutorizationAdmin(Server& obj);
	int AutorizationClient(Server& obj);
	int AutorizationExpert(Server& obj);
	void TakeCredit(Server& obj, char* buf, int client);
	void addCredit(Server& obj, int i);
	void addRating(Server& obj, int i);
	void addClient(Server& obj);
	void addAdmin(Server& obj);
	void addExpert(Server& obj);
	void delClient(Server& obj);
	void delAdmin(Server& obj);
	void delExpert(Server& obj);
	void findUser(Server& obj);
	void findAdmin(Server& obj);
	void findExpert(Server& obj);
	void PrintfStatistick(Server& obj);
	void printf_infoCredin(Server& obj);
	void printf_infoClient(Server& obj);
	void printf_infoAdmin(Server& obj);
	void printf_infoExpert(Server& obj);
	void save_info_Stats();
	void save_info_bank();
	void seve_info_Client();
	void save_info_Admin();
	void save_info_Expert();
	void save_info_Rating();
	~User();
};
