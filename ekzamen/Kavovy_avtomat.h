#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
enum type { TEA, COFFE, CAPUCCINO };

class Napiy
{
public:
	Napiy() = default;
	Napiy(int numbofdrink, int price, int water, int sugar, int milk);
	virtual ~Napiy();

	virtual void SetName() = 0;
	void SetMoney(int price);
	void setMilk(int milk);
	void setWater(int water);
	void setSugar(int sugar);
	void setnumbOfDrink(int drink);

	virtual string getName() const = 0;
	int getMoney() const;
	int getWater() const;
	int getSugar() const;
	int getMilk() const;
	int getnumbOfDrink() const;
	type getType()const;
	Napiy& operator--();

protected:
	type name;
	int numbOfDrink;
	int money;
	int water;
	int sugar;
	int milk;
};

class Tea :public Napiy
{
public:
	Tea() = default;
	Tea(int numberofdrink, int price = 5, int water = 2, int sugar = 1, int milk = 0);
	virtual void SetName();
	virtual string getName() const;
	~Tea();
};
class Coffe :public Napiy
{
public:
	Coffe() = default;
	Coffe(int numberofdrink, int price = 7, int water = 1, int sugar = 2, int milk = 0);
	virtual void SetName();
	virtual string getName() const;
	~Coffe();
};

class Kapucino :public Napiy
{
public:
	Kapucino() = default;
	Kapucino(int numberofdrink, int price = 10, int water = 2, int sugar = 2, int milk = 1);
	virtual void SetName();
	virtual string getName() const;
	~Kapucino();
};
class Kavovy_avtomat
{
public:
	Kavovy_avtomat(int water, int sugar, int milk, int tea, int coffe, int cappucino);
	~Kavovy_avtomat();
	bool CanCook(Napiy*)const;
	void AddIngridients();
	void ChangePrice();
	int AdeOneIngrid();
	void Menu();
	void UserMenu();
	void AdminMenu();
	bool isAdmin(string password);
	void Prodaj(Napiy* napiy);
	void ChangePassword();
	void ShowStatistick();
private:
	int water;
	int money;
	int sugar;
	int milk;
	Tea tea;
	Kapucino capuccino;
	Coffe coffe;
	string password;

};

