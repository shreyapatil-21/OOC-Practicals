#include<iostream>
using namespace std;
class student
{
    int roll_no;
    float marks;
    char name[20];
    public:
    void getdata()
    {
        cout<<"enter the student roll no";
        cin>>roll_no;
        cout<<"enter the student name";
        cin>>name;
        cout<<"enter the student marks";
        cin>>marks;
    
    }
    public:
    void display()
    {
        cout<<"student roll no:"<<roll_no<<endl;
        cout<<"student name:"<<name<<endl;
        cout<<"student marks:"<<marks;
    }
};
int main()
{
    student s;
    s.getdata();
    s.display();
    
}