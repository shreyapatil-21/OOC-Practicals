
#include <iostream>
using namespace std;
class Rectangle
{
    private:
            double length;
            double width;
    public:
            Rectangle():length(1.0),width(1.0){}
            Rectangle(double len,double wid):length(len),width(wid){}
            ~Rectangle(){
                cout<<"Rectangle object destroyed"<<endl;
            }
              double getlength() const
              {
                  return length;
              }
            double getwidth() const{
                return width;
            } 
            void setlength(double len){
                length=len;
            }
              void setwidth(double wid){
                width=wid;
            }
            double calculatearea() const{
                return length*width;
            }
            double calculateperimeter()const{
                return 2*(length+width);
            }
                   
            
            
};
int main(){
    Rectangle rect(4.0,40.0);
    cout<<"Rectangle Properties:"<<endl;
    cout<<"length:"<<rect.getlength()<<endl;
    cout<<"width:"<<rect.getwidth()<<endl;
    cout<<"Area:"<<rect.calculatearea()<<endl;
    cout<<"Perimeter:"<<rect.calculateperimeter()<<endl;
    return 0;
}