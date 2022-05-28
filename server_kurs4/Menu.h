#pragma once
#include"Server.h"
#include"User.h"
class Menu :public User
{
	void CheckAutorization(int i, Server& obj);
public:
	void TakeCreditMenu(Server& obj, User& user, int i);
	void ExpertMenu(Server& obj, int i, User& user);
	void AdminMenu(Server& obj, int i);
	void UserMenu(Server& obj, int i, User user);
	void startMenu(Server& obj);
	void MenuExpertRewvie(Server& obj);
	void MenuChangeUser(Server& obj, int i, User& user);
	void MenuChangeExpert(Server& obj, int i, User& user);
};
