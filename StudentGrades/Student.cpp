#include<iostream>
#include"Student.h"
//�����������(������� �� ������� ������) - �������������
Student::Student(const char* studentName, const int studentMarkCount, const int* studentMarks){
    //������������ �����(���������� ��� ��������)
    createName(studentName);

    //������������ ������ ������
    marks = new int[studentMarkCount];
    for (int i = 0; i < studentMarkCount; i++) {
        marks[i] = studentMarks[i];
   }
    markCount = studentMarkCount;
}
//������������ �����
void Student::createName(const char* studentName) {
    int nameLength = strlen(studentName);
    name = new char[nameLength + 1];
    for (int i = 0; i <= nameLength; i++) {
        name[i] = studentName[i];
    }
}
//������ �����
void Student::setName(const char* studentName) {
    delete[]name;
    createName(studentName);
}
//������ ��������� ������� marks
void Student::setMark(int mark, int index) {
    //�������� �������
    if (index < 0 or index >= markCount) {
        return;
    }

    //������������ � ��������� ������
    if (mark < 1 or mark > 12) {
        mark = 0;
    }
    marks[index] = mark;
}

//���������� ������ ���������� �������� �����
double Student::getAver() {//����� ������
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += marks[i];
    }
    return sum / markCount;
}

//����������
Student::~Student() {
    std::cout << "��������� ���������� " << name << std::endl;
    //������������ ������ ��� �����
    if (name != nullptr) {
        delete[]name;
    }

    //������������ ������ ��� ������ ������
    if (marks != nullptr) {
        delete[]marks;
    }
   
    system("pause");
}