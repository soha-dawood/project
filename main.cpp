#include <iostream>
#pragma once
#include <windows.h>
#include <string>
using namespace std;
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void clearScreen() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
    SetConsoleCursorPosition(hConsole, coord);
}

void printCenteredText(const string &text, int width) {
    int len = text.length();
    int spaces = (width - len) / 2;
    for (int i = 0; i < spaces; ++i) cout << " ";
    cout << text;
}

void printWelcomeToSSHBank() {
    cout <<"*                 *   * * * * *   *          *********   ***********  ***          ***  * * * * * "<<endl;
    cout <<"*                 *   *           *          *           *         *  *  *        *  *  *         "<<endl;
    cout <<"*       ***       *   *           *          *           *         *  *   *      *   *  *          "<<endl;
    cout <<"*     *     *     *   *********   *          *           *         *  *    *    *    *  *********  "<<endl;
    cout <<"*    *       *    *   *           *          *           *         *  *     *  *     *  *          "<<endl;
    cout <<"*   *         *   *   *           *          *           *         *  *      **      *  *          "<<endl;
    cout <<"*  *           *  *   *           *          *           *         *  *              *  *          "<<endl;
    cout <<"***             ***   * * * * *   *********  **********  ***********  *              *  * * * * *   "<<endl;

}

 /*class Validation{
 public:

 static bool validatename(string name){

      if(!(name.size()<=20&&name.size()>=5)){

            return false;
       }


       for (int i = 0; i < name.size(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z' || name[i] >= 'A' && name[i] <= 'Z')) {
				return false;
				}
				 }
				return true;
 }
 static bool validatepassword(string password){

    if(password.size()<=20&&password.size()>=8){
           return true;
       }
       else{
          cout<<"password must be 8:20\n";
          return false;
       }


 }

 static bool validatebalance(double balance){

  if(balance>=1500){
           return true;
          }
          else {
          cout<<" min balance is 1500"<<endl;
          return false;

          }
 }
 static bool validateSalary(double salary){

     if(salary>=5000){
           return true;
          }
          else {
          cout<<" min salary is 5000"<<endl;
          return false;

          }


 }
 };*/


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
     void display()
      {
          cout<<"name = "<<GetName()<<endl;
          cout<<"id = "<<GetId()<<endl;
          cout<<"password = "<<GetPassword()<<endl;

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
      void display()
      {
          cout<<"name = "<<GetName()<<endl;
          cout<<"id = "<<GetId()<<endl;
          cout<<"password = "<<GetPassword()<<endl;
          cout<<"balance = "<<balance<<endl;
      }
};

class Employee : public Person{
private:
	double salary;
public:

	  Employee();
      Employee(int Id,string Name,string Password, double Balance,double Salary)
      {
          SetId(Id);
          SetName(Name);
          SetPassword(Password);
          setSalary(salary);

      }

	void setSalary(double s) {
		  if(salary>=5000){
            salary = s;
          }else {
         salary= 0;
          cout<<" minSalary is 5000"<<endl;
          }}

	double getSalary() {
		return salary;
	}

	void display() {
		Person::display();
		cout << "Salary : " << salary << endl;
	}
};
class Admin : public Person{
    private:
	double salary;
public:

      Admin(int Id,string Name,string Password, double Balance,double Salary)
      {
          SetId(Id);
          SetName(Name);
          SetPassword(Password);
          setSalary(salary);

      }
	void setSalary(double s) {
		  if(salary>=5000){
            salary = s;
          }else {
         salary= 0;
          cout<<" minSalary is 5000"<<endl;
          }}

	double getSalary() {
		return salary;
	}

	void display() {
		Person::display();
		cout << "Salary : " << salary << endl;
	}

};

int main ()
{
     // Set text color (Light Green for this example)
  setColor(10);

    // Get console dimensions
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(hConsole, &csbi);
  int consoleWidth = csbi.dwSize.X;

    // Print centered text
  clearScreen(); // Clear screen before printing
  printWelcomeToSSHBank();

    // Wait for 5 seconds
  Sleep(5000);

  // Clear the screen before exiting
  clearScreen();

  // Reset color to default
  setColor(7); // Default color

  Clint c(51,"sohadawood","8451316465",20000);
  Clint c1(6546,"ahmedmohamed","846511115",2000);

  c1.CheckBalance();
  c.CheckBalance();
  c.TransferTo(1000,c1);
  c.display();
  c1.display();
  Employee e(5555,"alidawood","8451316465",10000,4000);
  e.display();


Clint c3(55,"soha","8451316465",20000);
    return 0;
}
