#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to check if a username already exists
bool isUsernameTaken(const string& username) {
    ifstream infile("users.txt");
    string storedUsername, storedPassword;
    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            return true;
        }
    }
    return false;
}

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    // Check if the username is already taken
    if (isUsernameTaken(username)) {
        cout << "Username already taken. Please choose a different username.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    // Store the username and password in the file
    ofstream outfile("users.txt", ios::app);
    outfile << username << ' ' << password << '\n';
    cout << "Registration successful!\n";
}

// Function to log in an existing user
void loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream infile("users.txt");
    string storedUsername, storedPassword;
    bool loginSuccess = false;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            loginSuccess = true;
            break;
        }
    }

    if (loginSuccess) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

// Function to retrieve a forgotten password
void forgotPassword() {
    string username;

    cout << "Enter your username: ";
    cin >> username;

    ifstream infile("users.txt");
    string storedUsername, storedPassword;
    bool userFound = false;

    while (infile >> storedUsername >> storedPassword) {
        if (storedUsername == username) {
            cout << "Your password is: " << storedPassword << '\n';
            userFound = true;
            break;
        }
    }

    if (!userFound) {
        cout << "Username not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Forgot Password\n";
        cout << "4. Exit\n";
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
                forgotPassword();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

