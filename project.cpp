#include <iostream>
using namespace std;
class Person{
    int id;
    string name;
    string password;
public:
    void SetId(int Id)
    {
        id=Id;
    }
    int GetId()
    {
        return id;
    }
    void SetName(string Name)
    {
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
      Clint();
      Clint(int Id,string Name,string Password, double Balance)
      {
          SetId(Id);
          SetName(Name);
          SetPassword(Password);
          balance = Balance;
      }
      void SetBalance(double Balance)
      {
          if(Balance>=1500){
            balance = Balance;
          }else {
          balance= 0;
          cout<<" min balance is 1500"<<endl;
          }
      }
      double GetBalance()
      {
      return balance;
      }
      void Deposit(double Amount)
      {
       balance +=Amount;
      }
      void Withdraw(double Amount)
      {
      if(balance>Amount){
        balance-=Amount;
      }else if(balance<Amount){
          cout<<"balance isn't enough"<<endl;
          }
      else{
          cout<<"you have withdrawn your entire balance"<<endl;
          }
      }
      double TransferTo(double Amount,Clint &r1)
      {
       if(balance > Amount){
        balance -=Amount;
        r1.balance+=Amount;
      }else {
          cout<<"balance isn't enough"<<endl;
      }
      }
      void CheckBalance()
      {
      cout<<"your balance is "<<balance<<endl;
      }
      void DisPlay()
      {
          cout<<"name = "<<GetName()<<endl;
          cout<<"id = "<<GetId()<<endl;
          cout<<"password = "<<GetPassword()<<endl;
          cout<<"balance = "<<balance<<endl;
      }
};
int main ()
{
  Clint c(51,"sohadawood","8451316465",20000);
  Clint c1(6546,"ahmedmohamed","846511115",20000);
  c1.CheckBalance();
  c.CheckBalance();
  c.TransferTo(1000,c1);
  c.DisPlay();
  c1.DisPlay();


    return 0;
}
