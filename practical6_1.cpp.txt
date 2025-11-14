#include <iostream>
using namespace std;

// Base class: Student
class Student {
protected:
    int rollNo;
    string name;

public:
    void getStudentInfo() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
    }

    void displayStudentInfo() {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
    }
};

// Derived class: StudentExam (inherits from Student)
class StudentExam : public Student {
protected:
    float marks1, marks2, marks3;

public:
    void getMarks() {
        cout << "Enter marks in 3 subjects: ";
        cin >> marks1 >> marks2 >> marks3;
    }

    void displayMarks() {
        cout << "\nMarks: " << marks1 << ", " << marks2 << ", " << marks3;
    }
};

// Derived class: Result (inherits from StudentExam)
class Result : public StudentExam {
    float total, average;

public:
    void calculateResult() {
        total = marks1 + marks2 + marks3;
        average = total / 3;
    }

    void displayResult() {
        displayStudentInfo();
        displayMarks();
        cout << "\nTotal Marks: " << total;
        cout << "\nAverage: " << average;
    }
};

// Main function
int main() {
    Result r;
    r.getStudentInfo();
    r.getMarks();
    r.calculateResult();
    r.displayResult();
    return 0;
}