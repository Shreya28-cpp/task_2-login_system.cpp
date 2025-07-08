#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "✅ Registration successful!\n";
}

bool loginUser() {
    string username, password, u, p;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    bool success = false;
    while (file >> u >> p) {
        if (u == username && p == password) {
            success = true;
            break;
        }
    }
    file.close();
    if (success) {
        cout << "✅ Login successful!\n";
        return true;
    } else {
        cout << "❌ Invalid username or password.\n";
        return false;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}