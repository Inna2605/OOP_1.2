#include<iostream>
#include"Student.h"
//конструктор(вынесен за пределы класса) - имплементация
Student::Student(const char* studentName, const int studentMarkCount, const int* studentMarks){
    //присваевание имени(объявление или прототип)
    createName(studentName);

    //присваивание списка оценок
    marks = new int[studentMarkCount];
    for (int i = 0; i < studentMarkCount; i++) {
        marks[i] = studentMarks[i];
   }
    markCount = studentMarkCount;
}
//присваевание имени
void Student::createName(const char* studentName) {
    int nameLength = strlen(studentName);
    name = new char[nameLength + 1];
    for (int i = 0; i <= nameLength; i++) {
        name[i] = studentName[i];
    }
}
//запись имени
void Student::setName(const char* studentName) {
    delete[]name;
    createName(studentName);
}
//запись элементов массива marks
void Student::setMark(int mark, int index) {
    //проверка индекса
    if (index < 0 or index >= markCount) {
        return;
    }

    //присваевание с проверкой оценки
    if (mark < 1 or mark > 12) {
        mark = 0;
    }
    marks[index] = mark;
}

//реализация метода вычесления среднего балла
double Student::getAver() {//метод класса
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += marks[i];
    }
    return sum / markCount;
}

//деструктор
Student::~Student() {
    std::cout << "Отработал деструктор " << name << std::endl;
    //освобождение памяти для имени
    if (name != nullptr) {
        delete[]name;
    }

    //освобождение памяти для списка оценок
    if (marks != nullptr) {
        delete[]marks;
    }
   
    system("pause");
}