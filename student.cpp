//
// Created by Pavlo on 29.04.2023.
//

#include "student.h"

using namespace std;

void student::showDetails() {
    cout << "Name: " << name << '\n';
    cout << "Surname: " << surname << '\n';
    cout << "Age: " << age << '\n';
    cout << "Average grade: " << avg_grade << '\n';
}

void student::setName(std::string newName) {
    name = newName;
}

string student::getName() {
    return name;
}

void student::setSurname(std::string newSurname) {
    surname = newSurname;
}

string student::getSurname() {
    return surname;
}

void student::setAge(int newAge) {
    age = newAge;
}

int student::getAge() {
    return age;
}

void student::setAvgGrade(int newAvgGrade) {
    avg_grade = newAvgGrade;
}

int student::getAvgGrade() {
    return avg_grade;
}