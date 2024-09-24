//
// Created by Robert Fjellin on 9/21/24.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>



class Inventory {
private:
    std::vector<Item> items;
public:
    void addItem(const std::string& name, const std::string& description, const double& price, const int& quantity);
    bool removeItem(const std::string& name);
    void displayAll();
    void sortByName();
    void sortByPrice();
    Item* findItem(const std::string& name);
    void saveToFile(const std::string& fileName) const;
    void loadFromFile(const std::string& fileName);

    // Overloaded operator
};



#endif //INVENTORY_H
