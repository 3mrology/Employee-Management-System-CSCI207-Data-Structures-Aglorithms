#include <iostream>
#include <string>
using namespace std;
class Employee{
private:
    string Full_Name;
    string Email;
    string Phone;
    string Position;
    double Salary;
public:
    Employee(string name, string email, string phone,string position,double salary){
    Full_Name = name;
    Email = email;
    Phone = phone;
    Position = position;
    Salary = salary;
    }
    Employee(){
        Full_Name = "\0";
        Email = "\0";
        Phone = "\0";
        Position = "\0";
        Salary = NULL;
    }
    void setName(string N){
        Full_Name = N;
    }
    void setEmail(string E){
        Email = E;
    }
    void setPhone(string P){
        Phone = P;
    }
    void setPosition(string posi){
        Position = posi;
    }
    void setSalary(double S){
        Salary = S;
    }
    string getName(){
        return Full_Name;
    }
    string getEmail(){
        return Email;
    }
    string getPhone(){
        return Phone;
    }
    string getPosition(){
        return Position;
    }
    double getSalary(){
        return Salary;
    }
    void display_employee_info(){
        cout<<"Name: "<<getName()<<endl;
        cout<<"Email: "<<getEmail()<<endl;
        cout<<"Phone: "<<getPhone()<<endl;
        cout<<"Position: "<<getPosition()<<endl;
        cout<<"Salary: "<<getSalary()<<endl;
    }
};
class Node{
private:
    Employee emp;
    Node * next;
public:
    void setEmployee(string name, string email, string phone, string position, double salary){
        emp = Employee(name,email,phone,position,salary);
    }
    void setName2(string N){
        emp.setName(N);
    }
    void setEmail2(string E){
        emp.setEmail(E);
    }
    void setPhone2(string P){
        emp.setPhone(P);
    }
    void setPosition2(string posi){
        emp.setPosition(posi);
    }
    void setSalary2(double S){
        emp.setSalary(S);
    }
    string getName2(){
        return emp.getName();
    }
    string getEmail2(){
        return emp.getEmail();
    }
    string getPhone2(){
        return emp.getPhone();
    }
    string getPosition2(){
        return emp.getPosition();
    }
    double getSalary2(){
        return emp.getSalary();
    }
    void setNext(Node * n){
        next = n;
    }
    void displayInfo(){
        emp.display_employee_info();
    }
    Node * getNext(){
        return next;
    }
    Node(){
    emp = Employee("\0","\0","\0","\0",NULL);
    next = NULL;
    }
    Node(string name, string email, string phone, string position, double salary, Node * n = NULL){
        emp = Employee(name,email,phone,position,salary);
        next = n;
    }
};
class EmployeeList{
private:
    Node * head;
public:
    EmployeeList(){
        head = NULL;
    }
    void setHead(Node * h){
        head = h;
    }
    Node * getHead(){
        return head;
    }
//    insert new node , take data as parameter
    bool insertion(string name, string email, string phone, string position, double salary){
        Node * here = head;
        Node * emp = new Node(name,email,phone,position,salary);
        if(head == NULL){
            setHead(emp);
            cout<<"Head inserted"<<endl;
            return 0;
        } else{
            while (here->getNext() != NULL)
            {
                if(here->getEmail2() == email){
                    cout<<"Employee already exists"<<endl;
                    return 0;
                } else{
                    here = here->getNext();
                }
                }
            here->setNext(emp);
            cout<<"Insertion done"<<endl;
            return 1;
        }
    }
    bool checkHead(string email){
        if(head->getEmail2()==email){
            return true;
        } else{
            return false;
        }
    }
    void display() {
        Node * here= head;
        while (here != NULL) {
            here->displayInfo();
            here = here->getNext();
        }
    }
    bool editSalary(string email, double salary){
        Node * here = head;
        while (here != NULL)
        {
            if(here->getEmail2() == email){
                here->setSalary2(salary);
                cout<<"Salary edited"<<endl;
                return 1;
            } else{
                here = here->getNext();
            }
        }
        cout<<"Email doesn't exist"<<endl;
        return 0;
    }
    bool deleteEmployee(string email) {
        Node *here = head;
        if (checkHead(email)) {
            Node *temp = head;
            head = head->getNext();
            delete temp;
        } else {
            while (here != NULL) {
                if (here->getNext()->getEmail2() == email) {
                    Node *temp = here->getNext();
                    here->setNext(here->getNext()->getNext());
                    delete temp;
                    return 1;
                } else {
                    here = here->getNext();
                }
            }
            cout << "Email doesn't exist" << endl;
            return 0;
        }
    }
    bool isEmpty(){
        if(getHead()==NULL){
            return true;
        } else{
            return false;
        }
    }
    bool update_info(string email) {
        if (isEmpty()) {
            cout << "Please insert an employee first..." << endl;
        } else {
            Node *here = head;
            while (here != NULL) {
                int operation;
                if (here->getEmail2() == email) {
                    cout << "//                 Edit employee's info                      //" << endl;
                    cout << "//              Please select an operation:                  //" << endl;
                    cout << "//                   1-edit name                             //" << endl;
                    cout << "//                   2-edit email                            //" << endl;
                    cout << "//                   3-edit phone number                     //" << endl;
                    cout << "//                   4-edit position                         //" << endl;
                    cout << "//                   5-edit salary                           //" << endl;
                    cout << "Enter operation number: ";
                    cin >> operation;
                    if (operation == 1) {
                        string name;
                        cout << "Please enter new name: ";
                        cin >> name;
                        here->setName2(name);
                        cout << "Name edited successfully!" << endl;
                        here->displayInfo();
                        return 1;
                    }
                    else if (operation == 2) {
                        string email;
                        cout << "Please enter new email: ";
                        cin >> email;
                        here->setEmail2(email);
                        cout << "Email edited successfully!" << endl;
                        here->displayInfo();
                        return 1;
                    }
                    else if (operation == 3) {
                        string phone;
                        cout << "Please enter new phone number: ";
                        cin >> phone;
                        here->setPhone2(phone);
                        cout << "Phone edited successfully!" << endl;
                        here->displayInfo();
                        return 1;
                    }
                    else if (operation == 4) {
                        string position;
                        cout << "Please enter new position: ";
                        cin >> position;
                        here->setPosition2(position);
                        cout << "Position edited successfully!" << endl;
                        here->displayInfo();
                        return 1;
                    }
                    else if (operation == 5) {
                        double salary;
                        cout << "Please enter new salary: ";
                        cin >> salary;
                        here->setSalary2(salary);
                        cout << "Salary edited successfully!" << endl;
                        here->displayInfo();
                        return 1;
                    }
                    else{
                        cout<<"Invalid input"<<endl;
                    }
                }
                else {
                    here = here->getNext();
                }
            }
            cout << "Email doesn't exist" << endl;
            return 0;
        }
    }
    };
int main() {
//    Amr Shaarawy-211001149
    EmployeeList L1;
    while (true) {
        int input;
        cout << "//             Welcome to employee mangement program         //" << endl;
        cout << "//                 Please select an operation:               //" << endl;
        cout << "//                   1-insert new employee                   //" << endl;
        cout << "//                   2-Edit employee's salary                //" << endl;
        cout << "//                   3-Delete an employee                    //" << endl;
        cout << "//                   4-Print all employees                   //" << endl;
        cout << "//                   5-Update employee info                  //" << endl;
        cout << "//                   6-close the program                     //" << endl;
        cout << "Enter operation number: ";
        cin >> input;
        if (input == 1) {
            string name, email, phone, position;
            double salary;
            cout << "//Warning: name should one word and should be entered without spaces//" << endl;
            cout << "Please enter employee name: ";
            cin >> name;
            cout << "Please enter employee email: ";
            cin >> email;
            cout << "Please enter employee phone number: ";
            cin >> phone;
            cout << "Please enter employee position: ";
            cin >> position;
            cout << "Please enter employee salary: ";
            cin >> salary;
            L1.insertion(name, email, phone, position, salary);
            L1.display();
        }
        else if(input == 2){
            string email;
            double salary;
        cout<<"Please enter email of employee: ";
        cin>>email;
        cout<<"Please enter new salary: ";
        cin>>salary;
        L1.editSalary(email,salary);
        L1.display();
        }
        else if(input == 3){
            string email;
            cout<<"Please enter email of employee you want to delete: ";
            cin>>email;
            L1.deleteEmployee(email);
            L1.display();
        } else if(input == 4){
            if(L1.isEmpty()){
                cout<<"List is empty"<<endl;
            }
            else{
                L1.display();
            }
        } else if(input == 5){
            string email;
            cout<<"Please enter email of the employee: ";
            cin>>email;
            L1.update_info(email);
        }
        else if(input == 6){
            cout<<"Closing program....."<<endl;
            break;
        } else{
            cout <<"Invalid input"<<endl;
        }
    }
}
