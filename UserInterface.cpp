//
// Created by Robert Fjellin on 9/23/24.
//

#include <string>
#include <iostream>
#include <limits>
#include "UserInterface.h"

// Main menu loop
void UserInterface::displayMenu() {
    char userInput;
    std::string name;
    std::string description;
    bool continueLoop = true;

    do {
        std::cout << "Select an option to continue.\n"
                  << "1. Add an item\n"
                  << "2. Remove an item\n"
                  << "3. Search for a specific item\n"
                  << "4. Display all items\n"
                  << "5. Save the file\n"
                  << "6. Load a file\n"
                  << "9. Quit\n";

        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userInput) {
            case '1':
                addItemMenu();
                break;
            case '2':
                removeItemMenu();
                break;
            case '3':
                searchItemMenu();
                break;
            case '4':
                displayAll();
                break;
            case '5':
                saveFileMenu();
                break;
            case '6':
                loadFileMenu();
                break;
            case '9':
                continueLoop = false;
                break;
            default:
                std::cout << "That was not a valid input. Please try again.\n";
                break;
        }
    } while (continueLoop);
}

// Menu for adding a new item
void UserInterface::addItemMenu() {
    std::string name, description;
    double price;
    int quantity;

    std::cout << "Enter the name: ";
    std::getline(std::cin, name);
    std::cout << "Enter a description: ";
    std::getline(std::cin, description);
    price = getValidDoubleInput("Enter the price: ");
    quantity = getValidIntInput("Enter the quantity: ");

    addItemPrompt(name, description, price, quantity);
}

// Menu for removing an item
void UserInterface::removeItemMenu() {
    std::string name;
    std::cout << "Enter the name of the item you'd like to remove: ";
    std::getline(std::cin, name);
    if (store.removeItem(name)) {
        std::cout << "Item removal successful.\n";
    } else {
        std::cout << "Invalid item name.\n";
    }
}

// Menu for searching an item
void UserInterface::searchItemMenu() {
    std::string name;
    std::cout << "Enter the name: ";
    std::getline(std::cin, name);
    Item* item = store.findItem(name);
    if (item) {
        std::cout << item->display() << std::endl;
    } else {
        std::cout << "Item not found.\n";
    }
}

// Menu for saving to a file
void UserInterface::saveFileMenu() {
    std::string name;
    std::cout << "Enter the name of the file you'd like to save this to: ";
    std::cin >> name;
    saveFile(name);
}

// Menu for loading from a file
void UserInterface::loadFileMenu() {
    std::string name;
    std::cout << "Enter the name of the file you'd like to load: ";
    std::cin >> name;
    loadFile(name);
}

// Helper function to get valid double input
double UserInterface::getValidDoubleInput(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Helper function to get valid integer input
int UserInterface::getValidIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "Invalid input. Please enter an integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void UserInterface::addItemPrompt(const std::string& name, const std::string& description, const double& price, const int& quantity) {
    store.addItem(name, description, price, quantity);
}

void UserInterface::displayAll() {
    store.displayAll();
}

void UserInterface::loadFile(const std::string &file) {
    store.loadFromFile(file);
}

void UserInterface::saveFile(const std::string &file) {
    store.saveToFile(file);
}