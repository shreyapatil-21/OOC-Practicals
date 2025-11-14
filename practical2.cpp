#include<iostream>
using namespace std;
class complex
{
    int real;
    int imag;
    public:
    void get()
    {
        cout<<"enter the real number";
        cin>>real;
        cout<<"enter the imag number";
        cin>>imag;
    }
    public:
    void display()
    {
        cout<<real<<"+"<<imag<<"i"<<endl;
    }
    
    complex add(complex c)
    {
        complex temp;
        temp.real=real+c.real;
        temp.imag=imag+c.imag;
        return temp;
    }
    complex sub(complex c)
    {
        complex temp;
        temp.real=real-c.real;
        temp.imag=imag-c.imag;
        return temp;
    }
};
int main()
{
    complex c1,c2,c3;
    cout<<"enter the first complex number";
    c1.get();
    cout<<"enter the second complex number";
    c2.get();
    cout<<"addition";
    c3=c1.add(c2);
    c3.display();
     cout<<"substraction";
    c3=c1.sub(c2);
    c3.display();
    return 0;
}
    
    
