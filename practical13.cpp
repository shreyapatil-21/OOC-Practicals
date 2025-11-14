#include <iostream>
using namespace std;

class Divide {
public:
    void performDivision(int a, int b) {
        try {
            if (b == 0)
                throw b; // Throw exception if divisor is zero
            else
                cout << "Result: " << (float)a / b << endl;
        }
        catch (int) {
            cout << "Error: Division by zero is not allowed!" << endl;
        }
    }
};

int main() {
    Divide obj;
    int num, den;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> den;

    obj.performDivision(num, den);

    cout << "Program executed successfully." << endl;
    return 0;
}
