#include <iostream>
using namespace std;

class Student {
    int roll;
    string name;

public:
    
    friend istream& operator >> (istream& in, Student& s);


    friend ostream& operator << (ostream& out, const Student& s);
};


istream& operator >> (istream& in, Student& s) {
    cout << "Enter Roll Number: ";
    in >> s.roll;
    in.ignore(); 
    cout << "Enter Name: ";
    getline(in, s.name);
    return in;
}


ostream& operator << (ostream& out, const Student& s) {
    out << "Roll Number: " << s.roll << endl;
    out << "Name: " << s.name << endl;
    return out;
}

int main() {
    Student s1;

  
    cin >> s1;
    cout << "\nStudent Details:\n";
    cout << s1;

    return 0;
}
