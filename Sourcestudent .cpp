#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void addStudent();
void viewAllStudents();
void searchStudent();
void updateStudent();
void deleteRecord();

int main() {
    int choice;
    do {
        cout << "\n------- STUDENT MANAGEMENT SYSTEM -------\n";
        cout << "1. Add Student Record\n";
        cout << "2. View All Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Update Student GPA\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: viewAllStudents(); break;
        case 3: searchStudent(); break;
        case 4: updateStudent(); break;
        case 5: deleteRecord(); break;
        case 6: cout << "Exiting the program...\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void addStudent() {
    string name, rollnum, department;
    float cgpa;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    getline(cin, rollnum);
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter GPA: ";
    cin >> cgpa;
    while (cin.fail() || cgpa < 0 || cgpa > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid GPA. Enter again (0 - 4): ";
        cin >> cgpa;
    }

    ofstream fout("student.txt", ios::app);
    fout << name << "," << rollnum << "," << department << "," << cgpa << endl;
    fout.close();

    cout << "Student record added successfully!\n";
}
void viewAllStudents() {
    ifstream file("student.txt");
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool hasData = false;
    cout << "\nName\t\tRoll No\t\tDepartment\tGPA\n";
    cout << "----------------------------------------------------------\n";
    while (getline(file, line)) {
        hasData = true;
        size_t pos = 0;
        string data[4];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 4) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        cout << data[0] << "\t\t" << data[1] << "\t\t" << data[2] << "\t" << data[3] << endl;
    }

    if (!hasData)
        cout << "No student records found.\n";

    file.close();
}

void searchStudent() {
    string rollnum;
    cout << "Enter Roll Number to search: ";
    cin >> rollnum;

    ifstream fin("student.txt");
    string line;
    bool found = false;

    while (getline(fin, line)) {
        size_t pos = 0;
        string data[4];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 4) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        if (rollnum == data[1]) {
            cout << "\nStudent found!\n";
            cout << "Name: " << data[0] << "\n";
            cout << "Roll No: " << data[1] << "\n";
            cout << "Department: " << data[2] << "\n";
            cout << "GPA: " << data[3] << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }

    fin.close();
}


void updateStudent() {
    string rollnum;
    cout << "Enter the Roll Number to update GPA: ";
    cin >> rollnum;

    ifstream fin("student.txt");
    ofstream fout("temp.txt");
    if (!fin) {
        cout << "Error opening file.\n";
        return;
    }

    string line;
    bool updated = false;

    while (getline(fin, line)) {
        size_t pos = 0;
        string data[4];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 4) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        if (data[1] == rollnum) {
            cout << "Enter new GPA: ";
            cin >> data[3];

           
            while (cin.fail() || stof(data[3]) < 0 || stof(data[3]) > 4) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid GPA. Enter again (0 - 4): ";
                cin >> data[3];
            }

            updated = true;
        }

        fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << endl;
    }

    fin.close();
    fout.close();

    if (updated) {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "Student record updated successfully!\n";
    }
    else {
        remove("temp.txt");
        cout << "Student not found.\n";
    }
}

void deleteRecord() {
    string rollnum;
    cout << "Enter the Roll Number to delete: ";
    cin >> rollnum;

    ifstream fin("student.txt");
    ofstream fout("temp.txt");
    string line;
    bool deleted = false;

    while (getline(fin, line)) {
        size_t pos = 0;
        string data[4];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 4) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        data[i] = line;

        if (data[1] != rollnum) {
            fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << endl;
        }
        else {
            deleted = true;
        }
    }

    fin.close();
    fout.close();

    if (deleted) {
        remove("student.txt");
        rename("temp.txt", "student.txt");
        cout << "Student record deleted successfully!\n";
    }
    else {
        remove("temp.txt");
        cout << "Student not found.\n";
    }
}