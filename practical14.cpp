
#include <iostream>
#include<list>
using namespace std;
int main()
{
    list<int>gqlist{12,45,8,6};
    for (auto i:gqlist){
        cout<<i;
    }
    return 0;
    
}

#include <iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int>mp;
      mp["one"]=1;
      mp["two"]=2;
      mp["three"]=3;
      map<string,int>::iterator it=mp.begin();
      while(it!=mp.end()){
          cout<<"key"<<it->first<<"value:"<<it->second<<endl;
          ++it;
          
      }
      return 0;
}      

