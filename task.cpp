#include <iostream>
#include <vector>
#include <string>

void displayMenu() {
    std::cout << "To-Do List Manager" << std::endl;
    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. View tasks" << std::endl;
    std::cout << "3. Delete a task" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void addTask(std::vector<std::string>& tasks) {
    std::cin.ignore();
    std::string task;
    std::cout << "Enter the task: ";
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully." << std::endl;
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
    } else {
        std::cout << "Current tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete." << std::endl;
        return;
    }

    viewTasks(tasks);
    size_t taskIndex;
    std::cout << "Enter the number of the task to delete: ";
    std::cin >> taskIndex;

    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task deleted successfully." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

int main() {
    std::vector<std::string> tasks;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
