/*Добавить к классу MyString (см. предыдущие ДЗ) оператор присваивания копированием, конструктор перемещения
и оператор присваивания перемещением. В итоге в классе MyString обязательно должны быть деструктор,
конструктор копирования, оператор присваивания копированием, конструктор перемещения и оператор присваивания перемещением
(правило пяти).*/
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
	String(const String& Std);//конструктор копирования
	String(String&& obj);//конструктор перемещения

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
	String& operator=(String&& obj);//оператор присваивания с перемещением
	String& operator=(const String& obj);//оператор присваивания с копированием

	friend std::ostream& operator<<(std::ostream& os, const String& NewStr);//дружественная перегрузка оператора<<

	~String();
};
String operator+(int quantity, String& NewStr);//глобальная перегрузка оператора+
String Func();