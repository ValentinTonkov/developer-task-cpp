#include <iostream>

using namespace std;

class Employee {
private:
    string name;
    string address;
    string email;
    double salary;
    int internshipMonths = 0;

public:
    Employee(const string &name, const string &address, const string &email, double salary, int internshipMonths) {
        this->name = name;
        this->address = address;
        this->email = email;
        this->salary = salary;
        this->internshipMonths = internshipMonths;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Employee::name = name;
    }

    const string &getAddress() const {
        return address;
    }

    void setAddress(const string &address) {
        Employee::address = address;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Employee::email = email;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double salary) {
        Employee::salary = salary;
    }

    int getInternshipMonths() const {
        return internshipMonths;
    }

    void setInternshipMonths(int internshipMonths) {

        Employee::internshipMonths = internshipMonths;
    }
};


class Developer : public Employee {
private:
    bool homeOffice;
public:
    Developer(const string &name, const string &address, const string &email, double salary, int internshipMonths)
            : Employee(name, address, email, salary, internshipMonths) {
        homeOffice = false;
    }

    bool isHomeOffice() const {
        return homeOffice;
    }

    void setHomeOffice(bool homeOffice) {
        Developer::homeOffice = homeOffice;
    }

    double getSalary() const{
        int months = getInternshipMonths();
        double salary = Employee::getSalary();
        if (months < 12) {
            return salary;
        } else if (months <= 24) {
            return salary * 1.1;
        } else if (months <= 48) {
            return salary * 1.3;
        } else {
            return salary * 1.6;
        }
    }
};

void printDevInfo(const Developer & developer) {
    cout<<developer.getName()<<", "<<developer.getAddress()<<", email: "<<developer.getEmail();
    cout<<", internship:"<<developer.getInternshipMonths()<<" months, salary:"<<developer.getSalary();
    if (developer.isHomeOffice() == true){
        cout<<" home office";
    }
    cout<<endl;
}

int main() {

    Developer d1 ("Ivan Ivanov", "VT ul. Ivan Asen", "ivan@gmail.com", 1600, 25);
    Developer d2 ("Stoyan Stoyanov", "Sofia ul. Ivan Vazov", "stoyan@gmail.com", 2000, 2);

    printDevInfo(d1);
    printDevInfo(d2);


    return 0;
}
