//
// Created by Robert Fjellin on 9/21/24.
//

#include "Item.h"
#include <string>
#include <iostream>
#include <sstream>

// Constructor
Item::Item(std::string name, std::string description, double price, int quantity)
        : name(name), description(description), price(price), quantity(quantity) {}

// Getters
std::string Item::getName() const {
        return name;
}

std::string Item::getDescription() const {
        return description;
}

double Item::getPrice() const {
        return price;
}

int Item::getQuantity() const {
        return quantity;
}

// Setters
void Item::setPrice(const double& newPrice) {
        price = newPrice;
}

void Item::setQuantity(const int& newQuant) {
        quantity = newQuant;
}

// Returns a formatted string representation of the item
std::string Item::display() const {
        std::ostringstream oss;
        oss << "Product name: " << name
        << "\nDescription: " << description
        << "\nPrice: $" << price
        << "\nQuantity: " << quantity
        << "\n";
        return oss.str();
}

// Overloaded stream insertion operator for easy output
std::ostream& operator<<(std::ostream& os, const Item& item) {
        os << item.getName() << ", " << item.getDescription() << ", "
           << item.getPrice() << ", " << item.getQuantity();
        return os;
}






