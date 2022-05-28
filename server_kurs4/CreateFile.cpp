#include "CreateFile.h"
void FileCreator::write_vector_User(vector<Human>& vec)
{
	int check = 0;
	ofstream file(FileClient);
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Admin(vector<Human>& vec)
{
	ofstream file(FileAdmin);
	int check = 0;
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Bank(vector<Bank>& vec)
{
	ofstream file(FileBank);
	int check = 0;
	for (vector<Bank>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getNameCredit() << "\t" << i->getProcent() << "\t" << i->getSum() << "\t" << i->getNameExpert() << "\t" << i->getLoginExpert();
		}
		else
		{
			file << i->getNameCredit() << "\t" << i->getProcent() << "\t" << i->getSum() << "\t" << i->getNameExpert() << "\t" << i->getLoginExpert() << endl;
		}
		check++;
	}
	file.close();
}



void FileCreator::write_vector_Expert(vector<Human>& vec)
{
	ofstream file(FileExpert);
	int check = 0;
	for (vector<Human>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash();
		}
		else
		{
			file << i->getName() << "\t" << i->getTel() << "\t" << i->getPas_info() << "\t" << i->getlogin() << "\t" << i->getPassword() << "\t" << i->getCash() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Statistick(vector<Statistick>& vec)
{
	ofstream file(FileStats);
	int check = 0;
	for (vector<Statistick>::iterator i = vec.begin(); i != vec.end(); i++)
	{

		if (check == vec.size() - 1)
		{
			file << i->getDate() << i->getNameClietn() << "\t" << i->getPas_info() << "\t" << i->getTel() << "\t" << i->getNameCredit() << "\t" << i->getProcent() << "\t" << i->getSum();
		}
		else
		{
			file << i->getDate() << i->getNameClietn() << "\t" << i->getPas_info() << "\t" << i->getTel() << "\t" << i->getNameCredit() << "\t" << i->getProcent() << "\t" << i->getSum() << endl;
		}
		check++;
	}
	file.close();
}

void FileCreator::write_vector_Rating(vector<Rating>& vec)
{
	int check = 0;
	ofstream file(FileRating);
	for (vector<Rating>::iterator i = vec.begin(); i != vec.end(); i++)
	{
		if (check == vec.size() - 1)
		{
			file << i->getRating() << "\t" << i->getNameExpert() << "\t" << i->getPosition();
		}
		else
		{
			file << i->getRating() << "\t" << i->getNameExpert() << "\t" << i->getPosition() << endl;
		}
		check++;
	}
	file.close();
}
