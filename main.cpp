#include "UserInterface.h"

int main()
{
    UserInterface sample;
    sample.loadFile("Store1.txt");
    sample.addItemPrompt("Strawberry and Banana Smoothie", "Smoothly blended strawberry, bananas and cream for a high vitamin snack.", 4.99, 10);
    sample.displayAll();
    sample.displayMenu();
    return 0;
}
