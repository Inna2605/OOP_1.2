#include <iostream>
#include<conio.h>
#include <iomanip>
#include <cmath>
#include <limits>
#include "Student.h"
#include "Student2.h"
using namespace std;

int main(){
    setlocale(LC_ALL, "");
    cout << "Успеваемость студента." << endl << endl;
   // Student student("Петров А.И.", 3, new int[3]{11, 9, 10});//объект
   
    const int size = 2;

    //создание и инициализация динамического массива объектов
    Student* students = new Student[size]{
        {"Студент 1", 3, new int[3]{11, 9, 10}},
        {"Студент 2", 3, new int[3]{8, 12, 9}}
    };
        //работа с массивом объектов
    double sum = 0;
    for (Student* stud = students; stud < students + size; stud++) {
        double aver = stud->getAver();
        cout << "Средний балл " << stud->getName()
            << " : " << fixed << setprecision(2)
            << aver << endl;
        sum += aver;
    }

    //Присвоение значений объекту
   // student.setMark(10, 0);
   // student.setMark(12, 1);
   // student.setMark(9, 2);

    

   // double aver = student.getAver();//выполнение метода объекта
  //  char* Ivan = ((Student2*)student)->Color;

   // strcpy_s(Ivan, 20, "black");
    //получение значений объекта
    cout << "Средний балл по группе: "
        << " : " << fixed << setprecision(2)
        << sum / size << endl;

    delete[]students;

    _getch();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
