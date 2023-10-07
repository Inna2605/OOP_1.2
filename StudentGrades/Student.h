#pragma once
#include<iostream>
class Student {
public:
    //���������� ������������(��������)
    Student(const char* studentName,
        const int studentMarkCount,
        const int* studentMarks);
private:
    //���� �������
    char* name;//���� �����(���������� ����� ������)
    int* marks;//���� ������(���������� ����� ������)
    int markCount;//����� ������

    //��������� �������, ������� ����������� �����������
    //������������ ������, �.�. ����� ������������ ����������
    //������� �������� �������� ����� ��������
    //� ���� ������� ����� ��������
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

    //����������
    ~Student();

};//�����