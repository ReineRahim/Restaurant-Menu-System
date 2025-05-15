// This is the implementation file for the MenuItem class.
// For function behaviors and details about the methods used, please refer to this file.
// The corresponding header file, MenuItem.h, provides the class structure and function declarations.

//
//  MenuItem.cpp
//

#include "MenuItem.h"

// Default constructor: Initializes a menu item with default values.
MenuItem::MenuItem() {
    id = 0;                     // Default ID is 0.
    name = "unknown";           // Default name is "unknown".
    desc = "no description";    // Default description is "no description".
    price = 0.0;                // Default price is 0.0.
}

// Parameterized constructor: Initializes a menu item with specified values.
MenuItem::MenuItem(string name, string desc, double price) {
    this->id = 0;               // ID is set to 0 by default; it will be assigned later.
    this->name = name;          // Assign the name.
    this->desc = desc;          // Assign the description.
    this->price = price;        // Assign the price.
}

// Sets the ID of the menu item.
void MenuItem::setId(int id) {
    this->id = id;
}

// Sets the name of the menu item.
void MenuItem::setName(string name) {
    this->name = name;
}

// Sets the description of the menu item.
void MenuItem::setDesc(string desc) {
    this->desc = desc;
}

// Sets the price of the menu item.
void MenuItem::setPrice(double price) {
    this->price = price;
}

// Returns the ID of the menu item.
int MenuItem::getId() const {
    return id;
}

// Returns the name of the menu item.
string MenuItem::getName() const {
    return name;
}

// Returns the description of the menu item.
string MenuItem::getDesc() const {
    return desc;
}

// Returns the price of the menu item.
double MenuItem::getPrice() const {
    return price;
}

// Displays the menu item's details to the provided output stream.
void MenuItem::display(ostream& out) const {
    out << "ID: " << id
        << ", Name: " << name
        << ", Description: " << desc
        << ", Price: $" << price
        << endl;
}

// Overloaded << operator: Outputs the menu item's details.
ostream& operator<<(ostream& out, const MenuItem& menu) {
    menu.display(out);  // Use the display method to format the output.
    return out;         // Return the output stream for chaining.
}
