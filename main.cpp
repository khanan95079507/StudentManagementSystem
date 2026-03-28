#include<iostream>
using namespace std;

class Student {
public:
    int id;
    string name;
    int marks;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }
};

int main() {
    Student s[100];
    int count = 0;
    int choice;

    while(true) {
        cout << "\n\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            s[count].input();
            count++;
            cout << "Student Added!\n";
        }

        else if(choice == 2) {
            if(count == 0) {
                cout << "No records found!\n";
            } else {
                for(int i = 0; i < count; i++) {
                    s[i].display();
                }
            }
        }

        else if(choice == 3) {
            int searchId, found = 0;
            cout << "Enter ID to search: ";
            cin >> searchId;

            for(int i = 0; i < count; i++) {
                if(s[i].id == searchId) {
                    s[i].display();
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                cout << "Student not found!\n";
            }
        }

        else if(choice == 4) {
            int delId, found = 0;
            cout << "Enter ID to delete: ";
            cin >> delId;

            for(int i = 0; i < count; i++) {
                if(s[i].id == delId) {
                    for(int j = i; j < count-1; j++) {
                        s[j] = s[j+1];
                    }
                    count--;
                    cout << "Student Deleted!\n";
                    found = 1;
                    break;
                }
            }

            if(found == 0) {
                cout << "Student not found!\n";
            }
        }

        else if(choice == 5) {
            cout << "Exiting...";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
