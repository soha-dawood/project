#include <iostream>
using namespace std;
class Person{
    int id;
    string name;
    string password;
public:
    void SetName(string Name){
      if(Name.size()<=20&&Name.size()>=5){
            name = Name;
       }
       else{
          cout<<"name must be 5:20 chars\n";
          name =" ";
       }
    }
    void SetPassword(string Password)
    {
        if(Password.size()<=20&&Password.size()>=8){
            password= Password;
       }
       else{
          cout<<"password must be 8:20\n";
          password =" ";
    }
    }
    string GetName()
    {
    return name;
    }
    string GetPassword()
    {
        return password;
    }
};
class Clint :public Person
{
private:
      double balance;
public:

};
int main ()
{
   string h;
   cin>>h;
   Person c1;
   c1.SetName(h);
   cout<<c1.GetName()<<endl;
   c1.SetPassword("dfghdfgjk");
   cout<<c1.GetPassword();
    return 0;
}
