/*Добавить к классу MyString (см. предыдущие ДЗ) оператор присваивания копированием, конструктор перемещения 
и оператор присваивания перемещением. В итоге в классе MyString обязательно должны быть деструктор, 
конструктор копирования, оператор присваивания копированием, конструктор перемещения и оператор присваивания перемещением
(правило пяти).*/

#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include<cstring>
#include<iostream>
using namespace std;

int String::N{ 0 };//статическое поле

int String::Counter()//статическая функция член
{	
	return N;
}

String::String() : String(80){}//Конструктор по умолчанию, позволяющий создать рядок на 80 символов и делегирование

String::String(int L)//Конструктор с одним параметром, позволяющий создать рядок произвольного размера
{
	Len = L;
	Str = new char[Len + 1];
	N++;
}

String::String(char* S) : String(strlen(S)) //Конструктор создает рядок и инициализирует
                                          //его рядком полученным от пользователя и делегирование
{
	strcpy(Str, S);
}
String::String(const char* S)//Конструктор с одним константным параметром
{
	Len = strlen(S);
	Str = new char[Len + 1];
	strcpy(Str, S);
}

String::String(const char* S, int n) : String(S)//конструктор с двумя параметрами
{
	Len = n;
}

String::String(const String& Std)//конструктор копирования
{
	Str = new char[strlen(Std.Str) + 1];
	strcpy(Str, Std.Str);
	Len = Std.Len;
}

String::String(String&& obj)//конструктор перемещения
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

void String::Input()//метод для введения рядка с клавиатуры
{
	cout << "Введите строку: ";
	if (Str != NULL)
		delete[]Str;

	char S[1000];
	cin.getline(S, 1000);

	Len = strlen(S) + 1;

	Str = new char[Len];
	strcpy(Str, S);
}

void String::Output()//метод для вывод рядка на екран
{
	cout << Str;
}

String String::operator++() //оператор++ в префиксной форме (добавление "х" в конец строки)
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

String String::operator--() //оператор-- в префиксной форме (удаление одного символа из конца строки)
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

String String::operator+(int quantity) //добавление определенного количества "х" в конец строки
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

String String::operator-(int quantity) //удаление определенного количества символов из конца строки
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

String String::operator++(int) //оператор++ в постфиксной форме (добавление "х" в конец строки)
{
	String NewStr;
//сохраняем содержимое нашего объекта в объект NewStr
	NewStr.Len = Len;         
	NewStr.Str = new char[Len];
	strcpy(NewStr.Str, Str);
//изменяем поля нашего объекта
	Len++;
	char* StrX;
	StrX = new char[Len + 1];
	strcpy(StrX, Str);
	StrX[Len - 2] = 'x';
	StrX[Len - 1] = '\0';
	delete[]Str;
	Str = StrX;
	StrX = nullptr;
//возвращаем наш объект сохраненный в объекте NewStr
	return NewStr;  
}

String String::operator--(int) //оператор-- в постфиксной форме (удаление одного символа из конца строки)
{
	String NewStr;
//сохраняем содержимое нашего объекта в объект NewStr
	NewStr.Len = Len;                  
	NewStr.Str = new char[Len];
	strcpy(NewStr.Str, Str);
//изменяем поля нашего объекта
	Len--;                            
	Str[Len - 1] = '\0';
//возвращаем наш объект сохраненный в объекте NewStr
	return NewStr;                     
}

String& String::operator=(String&& obj)//оператор присваивания с перемещением
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
String& String::operator=(const String& obj)//оператор присваивания с копированием
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

//глобальная перегрузка оператора+
String operator+(int quantity, String& Str)//Перегрузка оператора+ int+String(добавление к началу строки определенного количества символов'x')
{
	String* NewStr = new String(Str.getLen() + quantity);
	
	for (int i = 0; i < quantity; i++) {
		NewStr->getStr()[i] = 'x';
	}
	strcpy(NewStr->getStr() + quantity, Str.getStr());
	NewStr->getStr()[NewStr->getLen() - 1] = '\0';
	return *NewStr;
}

//дружественная перегрузка оператора<<
ostream& operator<<(ostream& os, const String& NewStr)//Перегрузка оператора<< для вывода на экран объекта типа String.
{
	cout << "\nОбъект с полями:\nLen (вместе с '\\0') = ";
	os << NewStr.Len;
	cout <<"\nStr = ";
	os << NewStr.Str;
	cout << endl;
	return os;
}

String::~String()//Деструктор
{
	delete[]Str;
}
