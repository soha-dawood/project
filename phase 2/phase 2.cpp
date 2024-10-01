#include <fstream>
#include "DataSourceInterface.h"
#include "FileHelper.h"

class FilesHelper {
private:
	static void saveLast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}
public:
	static int getLast(string fileName) {
		ifstream file;
		file.open(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveClient(Client c) {
		int id = getLast("ClientLastId.txt");
		fstream file;
		file.open("Clients.txt", ios::app);
		file << id + 1 << '$$' << c.getName() << '$$' << c.getPassword() << '$$' << c.getBalance() << "\n";
		file.close();
		saveLast("ClientLastId.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		int id = getLast("employeelastid.txt");
		fstream file;
		file.open("employees.txt", ios::app);
		file << id + 1 << '$$' << e.getName() << '$$' << e.getPassword() << '$$' << e.getSalary() << "\n";
		file.close();
		saveLast("employeelastid.txt", id + 1);
	}
	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		while (getline(file, line)) {
			Client c = Parser::parseToClient(line);
			allClients.push_back(c);
		}
		file.close();
	}
	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		while (getline(file, line)) {
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
		}
		file.close();
	}
	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		while (getline(file, line)) {
			Admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}
	static void clearFile(string fileName, string lastIdFile) {
		fstream file1, file2;
		file1.open(fileName, ios::out);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
};
class FileManager : public DataSourceInterface {
private:
	static void addClient(Client client) {
		FilesHelper::saveClient(client);
	}
	static void addEmployee(Employee employee) {
		FilesHelper::saveEmployee("Employees.txt", "EmployeeLastId.txt", employee);
	}
	static void addAdmin(Admin admin) {
		FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
	}
	static void getAllClients() {
		FilesHelper::getClients();
	}
	static void getAllEmployees() {
		FilesHelper::getEmployees();
	}
	static void getAllAdmins() {
		FilesHelper::getAdmins();
	}
	static void removeAllClients() {
		FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
	}
	static void removeAllEmployees() {
		FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");
	}
	static void removeAllAdmins() {
		FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");
	}
public:
	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

};

/*
static vector <client> allclients;
static vector <employee> allemployees;
static vector <admin> alladmins;
*/
