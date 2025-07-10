#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed = false;
};

vector<Task> todoList;

void addTask() {
    string desc;
    cout << "📝 Enter task: ";
    cin.ignore();
    getline(cin, desc);
    todoList.push_back({desc, false});
    cout << "✅ Task added!\n";
}

void viewTasks() {
    if (todoList.empty()) {
        cout << "📭 No tasks in the list.\n";
        return;
    }
    cout << "\n📋 To-Do List:\n";
    for (size_t i = 0; i < todoList.size(); ++i) {
        cout << i + 1 << ". [" << (todoList[i].completed ? "✔" : " ") << "] " << todoList[i].description << "\n";
    }
}

void markTaskCompleted() {
    int index;
    cout << "Enter task number to mark completed: ";
    cin >> index;
    if (index > 0 && index <= (int)todoList.size()) {
        todoList[index - 1].completed = true;
        cout << "✅ Task marked as completed.\n";
    } else {
        cout << "❌ Invalid task number.\n";
    }
}

void removeTask() {
    int index;
    cout << "Enter task number to remove: ";
    cin >> index;
    if (index > 0 && index <= (int)todoList.size()) {
        todoList.erase(todoList.begin() + index - 1);
        cout << "🗑 Task removed.\n";
    } else {
        cout << "❌ Invalid task number.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n📌 TO-DO LIST MENU 📌\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "👋 Exiting To-Do List.\n"; break;
            default: cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}