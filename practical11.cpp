#include <iostream>
using namespace std;

class Employee {
public:
    virtual void calculateSalary() = 0;
};

class SalariedEmployee : public Employee {
    double monthlySalary;
public:
    SalariedEmployee(double s) { monthlySalary = s; }
    void calculateSalary() {
        cout << "Salaried Employee Salary: " << monthlySalary << endl;
    }
};

class HourlyEmployee : public Employee {
    double hoursWorked, hourlyRate;
public:
    HourlyEmployee(double h, double r) {
        hoursWorked = h;
        hourlyRate = r;
    }
    void calculateSalary() {
        cout << "Hourly Employee Salary: " << hoursWorked * hourlyRate << endl;
    }
};

class CommissionEmployee : public Employee {
    double sales, commissionRate;
public:
    CommissionEmployee(double s, double r) {
        sales = s;
        commissionRate = r;
    }
    void calculateSalary() {
        cout << "Commission Employee Salary: " << sales * commissionRate << endl;
    }
};

int main() {
    Employee* e1 = new SalariedEmployee(50000);
    Employee* e2 = new HourlyEmployee(160, 200);
    Employee* e3 = new CommissionEmployee(100000, 0.1);

    e1->calculateSalary();
    e2->calculateSalary();
    e3->calculateSalary();

    delete e1;
    delete e2;
    delete e3;
    return 0;
}