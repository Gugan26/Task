#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addTask() {
    ofstream fout("todo.txt", ios::app);
    string task;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, task);
    fout << task << endl;
    fout.close();
    cout << "Task added successfully.\n";
}

void viewTasks() {
    ifstream fin("todo.txt");
    string task;
    int count = 1;
    cout << "\n--- Your Tasks ---\n";
    while (getline(fin, task)) {
        cout << count++ << ". " << task << endl;
    }
    fin.close();
}

void clearTasks() {
    ofstream fout("todo.txt", ios::out); 
    fout.close();
    cout << "All tasks cleared.\n";
}

int main() {
    int choice;
    do {
        cout << "\n------ To-Do List Manager ------\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Clear All Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: clearTasks(); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
