#include <iostream>
#include <cmath>  
using namespace std;


class Shape {
public:
    
    virtual void area() {
        cout << "Area of shape not defined.\n";
    }
};


class Rectangle : public Shape {
    float length, breadth;
public:
    void getData() {
        cout << "Enter length and breadth of rectangle: ";
        cin >> length >> breadth;
    }

    void area() override {
        cout << "Area of Rectangle = " << (length * breadth) << endl;
    }
};
class Circle : public Shape {
    float radius;
public:
    void getData() {
        cout << "Enter radius of circle: ";
        cin >> radius;
    }

    void area() override {
        cout << "Area of Circle = " << (M_PI * radius * radius) << endl;
    }
};


int main() {
    Shape *shape;   

    Rectangle rect;
    rect.getData();
    shape = &rect;  
    shape->area();   

    Circle cir;
    cir.getData();
    shape = &cir;    
    shape->area();  

    return 0;
}