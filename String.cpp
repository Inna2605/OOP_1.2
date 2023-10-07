/*�������� � ������ MyString (��. ���������� ��) �������� ������������ ������������, ����������� ����������� 
� �������� ������������ ������������. � ����� � ������ MyString ����������� ������ ���� ����������, 
����������� �����������, �������� ������������ ������������, ����������� ����������� � �������� ������������ ������������
(������� ����).*/

#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include<cstring>
#include<iostream>
using namespace std;

int String::N{ 0 };//����������� ����

int String::Counter()//����������� ������� ����
{	
	return N;
}

String::String() : String(80){}//����������� �� ���������, ����������� ������� ����� �� 80 �������� � �������������

String::String(int L)//����������� � ����� ����������, ����������� ������� ����� ������������� �������
{
	Len = L;
	Str = new char[Len + 1];
	N++;
}

String::String(char* S) : String(strlen(S)) //����������� ������� ����� � ��������������
                                          //��� ������ ���������� �� ������������ � �������������
{
	strcpy(Str, S);
}
String::String(const char* S)//����������� � ����� ����������� ����������
{
	Len = strlen(S);
	Str = new char[Len + 1];
	strcpy(Str, S);
}

String::String(const char* S, int n) : String(S)//����������� � ����� �����������
{
	Len = n;
}

String::String(const String& Std)//����������� �����������
{
	Str = new char[strlen(Std.Str) + 1];
	strcpy(Str, Std.Str);
	Len = Std.Len;
}

String::String(String&& obj)//����������� �����������
{
	Str = obj.Str;
	obj.Str = nullptr;
	Len = obj.Len;
	obj.Len = 0;
}

String Func()
{
	String H("World!");
	return H;
}

void String::setLen(int L)
{
	Len = L;
	Str[Len] = '\0';
}

void String::setStr(char* S)
{
	Str = new char[strlen(S) + 1];
	strcpy(Str, S);
	Len = strlen(S) + 1;
}

int String::getLen()
{
	return Len;
}

char* String::getStr()
{
	return Str;
}

void String::Input()//����� ��� �������� ����� � ����������
{
	cout << "������� ������: ";
	if (Str != NULL)
		delete[]Str;

	char S[1000];
	cin.getline(S, 1000);

	Len = strlen(S) + 1;

	Str = new char[Len];
	strcpy(Str, S);
}

void String::Output()//����� ��� ����� ����� �� �����
{
	cout << Str;
}

String String::operator++() //��������++ � ���������� ����� (���������� "�" � ����� ������)
{
	Len++;
	char* StrX;
	StrX = new char[Len + 1];
	strcpy(StrX, Str);
	StrX[Len - 2] = 'x';
	StrX[Len - 1] = '\0';
	delete[]Str;
	Str = StrX;
	StrX = nullptr;
	return *this;
}

String String::operator--() //��������-- � ���������� ����� (�������� ������ ������� �� ����� ������)
{
	Len--;
	char* StrX;
	StrX = new char[Len - 1];
	Str[Len - 1] = '\0';
	strcpy(StrX, Str);
	delete[]Str;
	Str = StrX;
	StrX = nullptr;
	return *this;
}

String String::operator+(int quantity) //���������� ������������� ���������� "�" � ����� ������
{
	String NewStr;
	NewStr.Len = Len + quantity;
	NewStr.Str = new char[NewStr.Len];
	strcpy(NewStr.Str, Str);
	for (int i = Len - 1; i < quantity + (Len - 1); i++) {
		NewStr.Str[i] = 'x';
	}
	NewStr.Str[NewStr.Len - 1] = '\0';
	return NewStr;
}

String String::operator-(int quantity) //�������� ������������� ���������� �������� �� ����� ������
{
	String NewStr1;
	NewStr1.Len = Len;
	NewStr1.Str = new char[NewStr1.Len];
	strcpy(NewStr1.Str, Str);
	NewStr1.Str[NewStr1.Len - 1 - quantity] = '\0';
	String NewStr;
	NewStr.Len = Len - quantity;
	NewStr.Str = new char[NewStr.Len];
	strcpy(NewStr.Str, NewStr1.Str);
	return NewStr;
}

String String::operator++(int) //��������++ � ����������� ����� (���������� "�" � ����� ������)
{
	String NewStr;
//��������� ���������� ������ ������� � ������ NewStr
	NewStr.Len = Len;         
	NewStr.Str = new char[Len];
	strcpy(NewStr.Str, Str);
//�������� ���� ������ �������
	Len++;
	char* StrX;
	StrX = new char[Len + 1];
	strcpy(StrX, Str);
	StrX[Len - 2] = 'x';
	StrX[Len - 1] = '\0';
	delete[]Str;
	Str = StrX;
	StrX = nullptr;
//���������� ��� ������ ����������� � ������� NewStr
	return NewStr;  
}

String String::operator--(int) //��������-- � ����������� ����� (�������� ������ ������� �� ����� ������)
{
	String NewStr;
//��������� ���������� ������ ������� � ������ NewStr
	NewStr.Len = Len;                  
	NewStr.Str = new char[Len];
	strcpy(NewStr.Str, Str);
//�������� ���� ������ �������
	Len--;                            
	Str[Len - 1] = '\0';
//���������� ��� ������ ����������� � ������� NewStr
	return NewStr;                     
}

String& String::operator=(String&& obj)//�������� ������������ � ������������
{
	if (this != &obj) {
		delete[]Str;
		Str = obj.Str;
		Len = obj.Len;
		obj.Str = nullptr;
		obj.Len = 0;
	}
	return *this;
}
String& String::operator=(const String& obj)//�������� ������������ � ������������
{
	if (this != &obj) {
		if (obj.Str != nullptr) {
			delete[]Str;
		}
		if (obj.Str == nullptr) {
			Str = nullptr;
			Len = obj.Len;
			return *this;
		}
		Str = new char[strlen(obj.Str) + 1];
		strcpy(Str, obj.Str);
		Len = obj.Len;
	}
	return *this;
}

//���������� ���������� ���������+
String operator+(int quantity, String& Str)//���������� ���������+ int+String(���������� � ������ ������ ������������� ���������� ��������'x')
{
	String* NewStr = new String(Str.getLen() + quantity);
	
	for (int i = 0; i < quantity; i++) {
		NewStr->getStr()[i] = 'x';
	}
	strcpy(NewStr->getStr() + quantity, Str.getStr());
	NewStr->getStr()[NewStr->getLen() - 1] = '\0';
	return *NewStr;
}

//������������� ���������� ���������<<
ostream& operator<<(ostream& os, const String& NewStr)//���������� ���������<< ��� ������ �� ����� ������� ���� String.
{
	cout << "\n������ � ������:\nLen (������ � '\\0') = ";
	os << NewStr.Len;
	cout <<"\nStr = ";
	os << NewStr.Str;
	cout << endl;
	return os;
}

String::~String()//����������
{
	delete[]Str;
}
