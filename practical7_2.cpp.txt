#include <iostream>
using namespace std;


class Person {
protected:
    string name;
public:
    void getName() {
        cout << "Enter Name: ";
        cin >> name;
    }
};


class Student : public Person {
protected:
    int rollNo;
public:
    void getRollNo() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
    }
};


class Marks {
protected:
    float m1, m2;
public:
    void getMarks() {
        cout << "Enter marks in two subjects: ";
        cin >> m1 >> m2;
    }
};


class Result : public Student, public Marks {
public:
    void display() {
        float avg = (m1 + m2) / 2;
        cout << "\n--- Student Result ---";
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nAverage Marks: " << avg << endl;
    }
};


int main() {
    Result r;
    r.getName();
    r.getRollNo();
    r.getMarks();
    r.display();
    return 0;
}