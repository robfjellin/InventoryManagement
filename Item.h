//
// Created by Robert Fjellin on 9/21/24.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
private:
    std::string name;
    std::string description;
    double price;
    int quantity;

public:
    Item(std::string name, std::string description, double price, int quantity);

    // Getters
    std::string getName() const;
    std::string getDescription() const;
    double getPrice() const;
    int getQuantity() const;

    // Setters
    void setPrice(const double& newPrice);
    void setQuantity(const int& newQuant);

    // Display
    std::string display() const;

    // Operator overload
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
};



#endif //ITEM_H
