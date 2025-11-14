#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
  
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }

   
    Complex operator + (Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

   
    Complex operator ++ () {     
        ++real;
        ++imag;
        return *this;
    }

    Complex operator - () {     
        Complex temp;
        temp.real = -real;
        temp.imag = -imag;
        return temp;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2), c3;

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

 
    c3 = c1 + c2;
    cout << "\nAfter Binary Operator (+): ";
    c3.display();

    ++c1;
    cout << "\nAfter Unary Operator (++): ";
    c1.display();

    
    c3 = -c2;
    cout << "\nAfter Unary Operator (-): ";
    c3.display();

    return 0;
}
