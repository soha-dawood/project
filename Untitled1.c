#include <iostream>
#include <fstream>
using namespace std;

class Employee :public Person
 {
private:
    double salary;
    Client clients[1000];
    int clientCount;

public:

    Employee() {
        clientCount = 0;
    }

    void setName(string EMPName) {
        name = EMPName;
    }

    void setId(int EMPId) {
        id = EMPId;
    }

    void setPassword(string EMPPassword) {
        password = EMPPassword;
    }

    void setSalary(double EMPSalary) {
        salary = EMPSalary;
    }

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    string getPassword() {
        return password;
    }

    double getSalary() {
        return salary;
    }

    bool login(int EMPId, string EMPPassword ) {
        return (id == EMPId && password == EMPPassword);
    }

    void addClient(int clientId, string clientName, string clientAddress) {
        if (clientCount < 1000) {
            clients[clientCount].setClientID(clientId);
            clients[clientCount].setClientName(clientName);
            clients[clientCount].setClientAddress(clientAddress);
            clientCount++;
            cout << "Client added successfully!" << endl;
        } else {
            cout << "Client list is full!" << endl;
        }
    }

    void searchClientById(int clientId) {
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].getClientID() == clientId) {
                cout << "Client found:" << endl;
                clients[i].displayInfo();
                return;
            }
        }
        cout << "Client not found!" << endl;
    }

    void listAllClients() {
        if (clientCount == 0) {
            cout << "No clients found!" << endl;
            return;
        }
        cout << "List of Clients:" << endl;
        for (int i = 0; i < clientCount; i++) {
            clients[i].displayInfo();
            cout << "-" << endl;
        }
    }

    void editClientInfo(int clientId, string newClientName, string newClientAddress) {
        for (int i = 0; i < clientCount; i++) {
            if (clients[i].getClientID() == clientId) {
                clients[i].setClientName(newClientName);
                clients[i].setClientAddress(newClientAddress);
                cout << "Client information updated successfully!" << endl;
                return;
            }
        }
        cout << "Client not found!" << endl;
    }


    void displayEmployeeInfo() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {

    Employee EMP;
    EMP.setName("MO");
    EMP.setId(111);
    EMP.setPassword("password000");
    EMP.setSalary(7000.00);

    int EMPId;
    string EMPPassword;
    cout << "Enter Employee ID: ";
    cin >> EMPId;
    cout << "Enter Password: ";
    cin >> EMPPassword;

    if (EMP.login(EMPId, empPassword)) {
        cout << "Login successful!" << endl;


        EMP.addClient(1, "tota", "124 ad st");
        EMP.addClient(2, "shimaa", "150 gg st");


      EMP.searchClientById(1);


        EMP.listAllClients();


        EMP.editClientInfo(1, "tota ", "124 ad St");


        EMP.listAllClients();

        EMP.displayEmployeeInfo();
    } else {
        cout << " login failed!" << endl;
    }

    return 0;
