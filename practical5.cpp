#include <iostream>
using namespace std;

class Area {
public:
   
    float calculate(float radius) {
        return 3.1415 * radius * radius;
    }

    int calculate(int length, int breadth) {
        return length * breadth;
    }

    float calculate(float base, float height) {
        return 0.5 * base * height;
    }
};

int main() {
    Area a;
    int l, b;
    float r, base, h;

    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of Circle = " << a.calculate(r) << endl;

    cout << "\nEnter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of Rectangle = " << a.calculate(l, b) << endl;

    cout << "\nEnter base and height of triangle: ";
    cin >> base >> h;
    cout << "Area of Triangle = " << a.calculate(base, h) << endl;

    return 0;
}
