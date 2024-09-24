//
// Created by Robert Fjellin on 9/21/24.
//

#include "Inventory.h"
#include "Item.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>

// Adds a new item to the inventory object
void Inventory::addItem(const std::string& name, const std::string& description, const double& price, const int& quantity) {
    Item item1(name, description, price, quantity);
    items.push_back(item1);
}

// Removes an item from the inventory object and returns a boolean based on its success
bool Inventory::removeItem(const std::string &name) {
    bool success = false;
    const auto it = remove_if(items.begin(), items.end(),
        [&name](const Item& item) {return item.getName() == name; });
    if (it != items.end()) {
        items.erase(it, items.end());
        success = true;
    }
    return success;
}

// Find an item by name. Returns a pointer to item if found, otherwise returns nullptr
Item* Inventory::findItem(const std::string &name) {
    const auto it = std::find_if(items.begin(), items.end(),
        [&name](const Item& item) {return item.getName() == name; });
    return (it != items.end()) ? &(*it) : nullptr;
}

// Sorts the inventory by name in ascending order
void Inventory::sortByName() {
    std::sort(items.begin(), items.end(),
        [](const Item& a, const Item& b) {return a.getName() < b.getName();});
}

// Sorts inventory by price in ascending order
void Inventory::sortByPrice() {
    std::sort(items.begin(), items.end(),
        [](const Item& a, const Item& b) {return a.getPrice() < b.getPrice();});
}

// Saves inventory to file, throws runtime error if file cannot be opened
void Inventory::saveToFile(const std::string& fileName) const {
    std::ofstream myFile;
    myFile.open(fileName);
    if (!myFile.is_open()) {
        throw std::runtime_error("File not open");
    }
    for (const auto& item : items) {
        myFile << item << "\n";
    }
    myFile.close();
}

// Loads inventory from file, Each line should represent one item, Commas are delimiters
void Inventory::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, description, priceStr, quantityStr;

        std::getline(iss, name, ',');
        std::getline(iss, description, ',');
        std::getline(iss, priceStr, ',');
        std::getline(iss, quantityStr, ',');

        double price = std::stod(priceStr);
        int quantity = std::stoi(quantityStr);

        items.emplace_back(name, description, price, quantity);
    }
    file.close();
}

// Displays all items in the inventory
void Inventory::displayAll() {
    for (const auto& item : items) {
        std::cout << item.display() << "\n";
    }
}






