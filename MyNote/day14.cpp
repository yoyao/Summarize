
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
		this->Area = "�й�";
		this->Name = "ƻ��";
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
		cout << Name << endl;//��̬�����в�������thisָ�룬��Ϊ��̬�����ǹ���ģ���ʱ����õ�ʱ��û�о���Ķ��󣨼�this����
	}

	void SeeHeight()
	{
		cout << this->Height << endl;
	}

	static double Weight;

	void ConstFunc() const //const���εĺ����г������������ĺ����ڲ������޸����ڵ��κγ�Ա
	{
		//this->Age = 3;//��Ϊ�ǳ������������������ᱨ��
		this->Height = 179.5;//��������Ҫ�޸����ڲ��ĳ�Ա ��ô�˳�ԱǰҪ���� mutable�ؼ���
	}
	
	
	static void ShowFruit()
	{
		cout << "���֣�" << fruit->Name << endl;
	}


private:
	static Fruit* fruit;
	int Age;
	static string Name;
	mutable double Height;

};
double Person::Weight = 63.8;
string Person::Name = "ladjg";
Fruit* Person::fruit = new Fruit;//��Ȼ������˽�еĳ�Ա������������ʼ������������Ϊ�������ڽ��еġ�
                                 //���������Fruitֻ����������ʵ�ֲ�������������Ժ���ô�ᱨ������������Ϊû���ҵ����ʵĹ��캯������û��ʵ��




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
     Person person;//��̬����û��thisָ��
	//person.SeeHeight();//��Ϊperson��const���ε� ����ζ�Ų���ͨ��person�޸��κ����ڵĳ�Ա����Ϊ���÷������ܻᷢ���޸����ڵĳ�Ա�����飬���Բ��õ��á�
	person.ConstFunc();//�������Է��ʳ�������
	person.SeeName();//���Է��ʾ�̬���� ��Ϊ��̬�����ڲ����Է������ڵ������Ǿ�̬�ͷǳ����ĳ�Ա��
	Person::ShowFruit();



	system("pause");
	return EXIT_SUCCESS;
}