#pragma once
#include<iostream>
class Student {
public:
    //объявление конструктора(прототип)
    Student(const char* studentName,
        const int studentMarkCount,
        const int* studentMarks);
private:
    //поля объекта
    char* name;//поле имени(переменная члена класса)
    int* marks;//поле оценок(переменная члена класса)
    int markCount;//число оценок

    //служебная функция, которая запрашивает необходимую
    //динамическую память, т.к. объем конструктора увеличелся
    //функция копирует параметр имени студента
    //в поле объекта имени студента
    void createName(const char* studentName);

public:
    const char* getName() {
        return name;
    }
    int getMark(int index) {
        return marks[index];
    }

    double getAver();

    void setName(const char* studentName);
    void setMark(int mark, int index);

    //деструктор
    ~Student();

};//класс