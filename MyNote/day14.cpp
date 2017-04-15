
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include"Printer.h"

using namespace std;


class Person;

class Fruit
{
	friend class Person;
public:

	Fruit()
	{
		this->Area = "中国";
		this->Name = "苹果";
		this->Price = 2.5;
	}
	double Price;

private:
	string Area;
	string Name;
};




class Person
{
public:
	Person()
	{
		this->Height = 176.3;
		this->Weight = 63.1;
		this->Name = "Tom";
	}
	~Person()
	{

	}
	static void SeeName()
	{
		cout << Name << endl;//静态函数中不可以用this指针，因为静态函数是共享的，到时候调用的时候没有具体的对象（即this）。
	}

	void SeeHeight()
	{
		cout << this->Height << endl;
	}

	static double Weight;

	void ConstFunc() const //const修饰的函数叫常函数，在它的函数内不允许修改类内的任何成员
	{
		//this->Age = 3;//因为是常函数，所以这条语句会报错。
		this->Height = 179.5;//如果真的需要修改类内部的成员 那么此成员前要加上 mutable关键字
	}
	
	
	static void ShowFruit()
	{
		cout << "名字：" << fruit->Name << endl;
	}


private:
	static Fruit* fruit;
	int Age;
	static string Name;
	mutable double Height;

};
double Person::Weight = 63.8;
string Person::Name = "ladjg";
Fruit* Person::fruit = new Fruit;//虽然声明是私有的成员，但是这样初始化编译器会认为是在类内进行的。
                                 //假如上面的Fruit只是声明，而实现部分在这条语句以后，那么会报错，编译器会认为没有找到合适的构造函数。因没有实现




int main(int argc, char* argv[])
{
	Person::Weight = 65.1;
	Person::SeeName();
	
	Printer* p = Printer::GetInstance();
	Printer* p1 = Printer::GetInstance();

	if (p == p1)
	{
		cout << "aldkj" << endl;
	}
	Fruit f;
     Person person;//静态函数没有this指针
	//person.SeeHeight();//因为person是const修饰的 就意味着不能通过person修改任何类内的成员，因为调用方法可能会发生修改类内的成员的事情，所以不让调用。
	person.ConstFunc();//常量可以访问常函数。
	person.SeeName();//可以访问静态函数 因为静态函数内不可以访问类内的其他非静态和非常量的成员。
	Person::ShowFruit();



	system("pause");
	return EXIT_SUCCESS;
}