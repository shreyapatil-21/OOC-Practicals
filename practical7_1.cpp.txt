#include <iostream>
using namespace std;


class Student {
protected:
    string name;
    int rollNo;
public:
    void getStudentInfo() {
        cout << "Enter Student Name: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> rollNo;
    }
};


class Marks {
protected:
    float m1, m2, m3;
public:
    void getMarks() {
        cout << "Enter marks of 3 subjects: ";
        cin >> m1 >> m2 >> m3;
    }
};


class Result : public Student, public Marks {
    float total, average;
public:
    void calculateResult() {
        total = m1 + m2 + m3;
        average = total / 3;
    }

    void displayResult() {
        cout << "\n--- Student Result ---";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nTotal Marks: " << total;
        cout << "\nAverage: " << average << endl;
    }
};


int main() {
    Result r;
    r.getStudentInfo();
    r.getMarks();
    r.calculateResult();
    r.displayResult();
    return 0;
}