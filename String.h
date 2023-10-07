/*�������� � ������ MyString (��. ���������� ��) �������� ������������ ������������, ����������� �����������
� �������� ������������ ������������. � ����� � ������ MyString ����������� ������ ���� ����������,
����������� �����������, �������� ������������ ������������, ����������� ����������� � �������� ������������ ������������
(������� ����).*/
#include<iostream>
#pragma once
class String
{
private:
	char* Str;
	int Len;
	static int N ;
public:		
	static int Counter();
	String();
	String(int L);
	String(char* S);
	String(const char* S);
	String(const char* S, int n);
	String(const String& Std);//����������� �����������
	String(String&& obj);//����������� �����������

	void setLen(int L);
	void setStr(char* S);
	int getLen();
	char* getStr();

    void Input();
	void Output();

	String operator++();
	String operator--();
	String operator+(int quantity);
	String operator-(int quantity);
	String operator++(int);
	String operator--(int);
	String& operator=(String&& obj);//�������� ������������ � ������������
	String& operator=(const String& obj);//�������� ������������ � ������������

	friend std::ostream& operator<<(std::ostream& os, const String& NewStr);//������������� ���������� ���������<<

	~String();
};
String operator+(int quantity, String& NewStr);//���������� ���������� ���������+
String Func();