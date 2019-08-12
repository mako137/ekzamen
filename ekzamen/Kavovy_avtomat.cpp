#include "Kavovy_avtomat.h"




Kavovy_avtomat::Kavovy_avtomat(int water, int sugar, int milk, int tea, int coffe, int cappucino) :
	water(water), sugar(sugar), milk(milk), tea(tea), coffe(coffe), capuccino(cappucino)
{
	password = "1";
	money = 0;
}

Kavovy_avtomat::~Kavovy_avtomat()
{
}



void Kavovy_avtomat::AddIngridients()
{
	int choice;
	cout << "Choose what to add:\n";
	cout << "1 - Water\n";
	cout << "2 - Sugar\n";
	cout << "3 - Milk\n";
	cout << "4 - Tea\n";
	cout << "5 - Coffee\n";
	cout << "6 - Cappucino\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		this->water += AdeOneIngrid();
		break;
	}
	case 2:
	{
		this->sugar += AdeOneIngrid();
		break;
	}
	case 3:
	{
		this->milk += AdeOneIngrid();
		break;
	}
	case 4:
	{
		tea.setnumbOfDrink(tea.getnumbOfDrink() + AdeOneIngrid());
		break;
	}
	case 5:
	{
		coffe.setnumbOfDrink(coffe.getnumbOfDrink() + AdeOneIngrid());
		break;
	}
	case 6:
	{
		capuccino.setnumbOfDrink(capuccino.getnumbOfDrink() + AdeOneIngrid());
		break;
	}
	default:
		break;
	}
}

void Kavovy_avtomat::ChangePrice()
{
	int choice, price;
	cout << "Choose drink to change price:\n";
	cout << "1 - Tea\n";
	cout << "2 - Coffee\n";
	cout << "3 - Cappucino\n";
	cin >> choice;
	cout << "Enter price:\n";
	cin >> price;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore();
		cout << "Wrong value!\n";
		cin >> price;
	}
	switch (choice)
	{
	case 1:
	{
		tea.SetMoney(price);
		break;
	}
	case 2:
	{
		coffe.SetMoney(price);
		break;
	}
	case 3:
	{
		capuccino.SetMoney(price);
		break;
	}
	default:
		break;
	}
}



int Kavovy_avtomat::AdeOneIngrid()
{
	int ingridient;
	cout << "Enter how much to add:";
	cin >> ingridient;
	return ingridient;
}

void Kavovy_avtomat::Menu()
{
	int choice;
	while (true)
	{
		system("cls");
		cout << "Welcom to Drink AUTOMAT 2042\n";
		cout << "1 - Order a drink\n";
		cout << "2 - Login as admin\n";
		cout << "3 - Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			UserMenu();
			break;
		}
		case 2:
		{
			string password;
			cout << "Enter password: ";
			cin.ignore();
			getline(cin, password);
			if (isAdmin(password))
				AdminMenu();
			else
				cout << "Wrong Password!\n";
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}

void Kavovy_avtomat::UserMenu()
{
	int choice, price;
	cout << "Choose drink:\n";
	cout << "1 - Tea " << tea.getMoney() << " UAN" << endl;
	cout << "2 - Coffee " << coffe.getMoney() << " UAN" << endl;
	cout << "3 - Cappucino " << capuccino.getMoney() << " UAN" << endl;;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (CanCook(&tea))
			Prodaj(&tea);
		else
			cout << "Sorry, not enough ingridients\n";
		break;
	}
	case 2:
	{
		if (CanCook(&coffe))
			Prodaj(&coffe);
		else
			cout << "Sorry, not enough ingridients\n";
		break;
	}
	case 3:
	{
		if (CanCook(&capuccino))
			Prodaj(&capuccino);
		else
			cout << "Sorry, not enough ingridients\n";
		break;
	}
	default:
		break;
	}

}

void Kavovy_avtomat::AdminMenu()
{
	int choice;
	while (true)
	{
		system("cls");
		cout << "Admin menu:\n";
		cout << "1 - Add ingridients.\n";
		cout << "2 - Information.\n";
		cout << "3 - Change price.\n";
		cout << "4 - Take money.\n";
		cout << "5 - Change Password.\n";
		cout << "6 - Go back.\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			AddIngridients();
			break;
		}
		case 2:
		{
			ShowStatistick();
			break;
		}
		case 3:
		{
			ChangePrice();
			break;
		}
		case 4:
		{
			if (money > 0)
			{
				cout << "You took " << money << " UAN\n";
				money = 0;
			}
			else
				cout << "0 UAN in Drink Automat\n";
			break;
		}
		case 5:
		{
			ChangePassword();
			break;
		}
		case 6:
		{
			return;
			break;
		}
		default:
			break;
		}
		system("pause");
	}
}

bool Kavovy_avtomat::isAdmin(string password)
{
	return this->password == password;
}

void Kavovy_avtomat::Prodaj(Napiy* napiy)
{
	if (!CanCook(napiy))
		return;

	this->milk -= napiy->getMilk();
	this->sugar -= napiy->getSugar();
	this->water -= napiy->getWater();
	switch (napiy->getType())
	{
	case TEA:
	{
		--tea;
		money += tea.getMoney();
		break;
	}
	case COFFE:
	{
		--coffe;
		money += coffe.getMoney();
		break;
	}
	case CAPUCCINO:
	{
		--capuccino;
		money += capuccino.getMoney();
		break;
	}
	default:
		break;
	}

	cout << "Sound of working mashine\n";
	for (int i = 0; i < 3; i++)
	{
		Sleep(500);
		cout << ".";
	}
	cout << endl << "Here's your drink. Have a nice day!\n";
}

void Kavovy_avtomat::ChangePassword()
{
	string new_password;
	cout << "Enter old password\n";
	cin.ignore();
	getline(cin, new_password);
	if (isAdmin(new_password))
	{
		cout << "Enter new password\n";
		getline(cin, new_password);
		this->password = new_password;
	}
	else
		cout << "Wrong password!\n";
}

void Kavovy_avtomat::ShowStatistick()
{

	cout << "Milk - " << milk << endl;
	cout << "Sugar - " << sugar << endl;
	cout << "Water - " << water << endl;
	cout << "Tea - " << tea.getnumbOfDrink() << ", price - " << tea.getMoney() << " UAN." << endl;
	cout << "Coffe - " << coffe.getnumbOfDrink() << ", price - " << coffe.getMoney() << " UAN." << endl;
	cout << "Cappucino - " << capuccino.getnumbOfDrink() << ", price - " << capuccino.getMoney() << " UAN." << endl;
	cout << "Money in cash - " << money << " UAN." << endl;

}




Tea::Tea(int numberofdring, int price, int water, int sugar, int milk) :Napiy(numberofdring, price, water, sugar, milk)
{
	SetName();
}




void Tea::SetName()
{
	this->name = TEA;
}

string Tea::getName() const
{
	return "Tea";
}

Tea::~Tea()
{
}


Napiy::Napiy(int numbofdrink, int price, int water, int sugar, int milk) :numbOfDrink(numbofdrink), money(price), water(water), sugar(sugar), milk(milk)
{
}

Napiy::~Napiy()
{
}

bool Kavovy_avtomat::CanCook(Napiy* napiy) const
{

	if (this->water < napiy->getWater()
		|| this->sugar < napiy->getSugar()
		|| this->milk < napiy->getMilk())
		return false;

	switch (napiy->getType())
	{
	case TEA:
	{
		if (tea.getnumbOfDrink() < napiy->getnumbOfDrink())
			return false;
		break;
	}
	case COFFE:
	{
		if (coffe.getnumbOfDrink() < napiy->getnumbOfDrink())
			return false;
		break;
	}
	case CAPUCCINO:
	{
		if (capuccino.getnumbOfDrink() < napiy->getnumbOfDrink())
			return false;
		break;
	}
	default:
		break;
	}
	return true;
}

void Napiy::SetMoney(int price)
{
	this->money = price;
}

void Napiy::setMilk(int milk)
{
	this->milk = milk;
}

void Napiy::setWater(int water)
{
	this->water = water;
}

void Napiy::setSugar(int sugar)
{
	this->sugar = sugar;
}

void Napiy::setnumbOfDrink(int drink)
{
	this->numbOfDrink = drink;
}

int Napiy::getMoney() const
{
	return money;
}

int Napiy::getWater() const
{
	return water;
}

int Napiy::getSugar() const
{
	return sugar;
}

int Napiy::getMilk() const
{
	return milk;
}

int Napiy::getnumbOfDrink() const
{
	return numbOfDrink;
}

type Napiy::getType() const
{
	return name;
}

Napiy& Napiy::operator--()
{
	--numbOfDrink;
	return *this;
}



Coffe::Coffe(int numberofdrink, int price, int water, int sugar, int milk) :Napiy(numberofdrink, price, water, sugar, milk)
{
	SetName();
}

void Coffe::SetName()
{
	this->name = COFFE;
}

string Coffe::getName() const
{
	return "Coffe";
}

Coffe::~Coffe()
{
}



Kapucino::Kapucino(int numberofdrink, int price, int water, int sugar, int milk) :Napiy(numberofdrink, price, water, sugar, milk)
{
	SetName();
}

void Kapucino::SetName()
{
	this->name = CAPUCCINO;
}

string Kapucino::getName() const
{
	return "Cappucino";
}

Kapucino::~Kapucino()
{
}
