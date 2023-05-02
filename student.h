//
// Created by Pavlo on 29.04.2023.
//
#include <iostream>

using namespace std;

#ifndef TASK2_STUDENT_H
#define TASK2_STUDENT_H


class student {
private:
    string name, surname;
    int age, avg_grade;
public:
    student() {};

    void showDetails();

    string getName();
    void setName(string newName);

    string getSurname();
    void setSurname(string newSurname);

    int getAge();
    void setAge(int newAge);

    int getAvgGrade();
    void setAvgGrade(int newAvgGrade);
};


#endif //TASK2_STUDENT_H
