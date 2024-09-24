//
// Created by Robert Fjellin on 9/23/24.
//

#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "Inventory.h"


class UserInterface {
private:
    Inventory store;

public:
    void displayMenu();
    void addItemPrompt(const std::string& name, const std::string& description, const double& price, const int& quantity);
    void addItemMenu();
    void removeItemPrompt(const std::string& item);
    void removeItemMenu();
    void searchItemPrompt(const std::string& item);
    void searchItemMenu();
    void saveFile(const std::string& file);
    void saveFileMenu();
    void loadFile(const std::string& file);
    void loadFileMenu();
    void displayAll();
    int getValidIntInput(const std::string& prompt);
    double getValidDoubleInput(const std::string& prompt);
};



#endif //USERINTERFACE_H
