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
      void SetBalance(double Balance)
      {
          if(Balance>=1500){
            balance = Balance;
          }else {
          balance= 0;
          cout<<" min balance is 1500";
          }
      }
      double GetBalance(){
      return balance;
      }
      void Deposit(double Amount){
       balance=GetBalance() +Amount;
      }
      void Withdraw(double Amount){
      if(balance>Amount){
        balance=GetBalance()-Amount;
        cout<<"your balance now is "<<balance;
      }else if(balance<Amount){
          cout<<"balance isn't enough";
          }
      else{
          cout<<"you have withdrawn your entire balance";
          }
      }

};
int main ()
{
  Clint c;
  c.SetBalance(2000);
  cout<<c.GetBalance()<<endl;
  c.Deposit( 2000 );
  cout<<c.GetBalance()<<endl;
  c.Withdraw(4000);
    return 0;
}
