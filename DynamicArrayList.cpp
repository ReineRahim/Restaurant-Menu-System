// This is the implementation file for the DynamicArrayList class.
// For function behaviors and details about the methods used, please refer to this file.
// The corresponding header file, DynamicArrayList.h, provides the class structure and function declarations.

//
//  DynamicArrayList.cpp
//

#include "DynamicArrayList.h"

// Constructor: Initializes the dynamic array with a specified capacity.
DynamicArrayList::DynamicArrayList(int capacity) {
    this->capacity = capacity;      // Set the initial capacity.
    this->size = 0;                 // Start with zero items.
    this->nextItemId = 1;           // Item IDs start at 1.
    items = new MenuItem[capacity]; // Allocate memory for the array.
}

// Copy constructor: Creates a deep copy of another DynamicArrayList object.
DynamicArrayList::DynamicArrayList(const DynamicArrayList& other) {
    capacity = other.capacity;                  // Copy the capacity.
    size = other.size;                          // Copy the size.
    items = new MenuItem[capacity];             // Allocate memory for the new array.

    for (int i = 0; i < size; ++i) {
        items[i] = other.items[i];              // Copy each menu item.
    }
}

// Destructor: Releases the dynamically allocated memory.
DynamicArrayList::~DynamicArrayList() {
    delete[] items; // Free the memory allocated for the array.
}

// Returns the current number of items in the list.
int DynamicArrayList::getSize() const {
    return size;
}

// Sets a new capacity for the dynamic array.
void DynamicArrayList::setCapacity(int capacity) {
    this->capacity = capacity;
}

// Returns the current capacity of the dynamic array.
int DynamicArrayList::getCapacity() const {
    return capacity;
}

// Loads menu items from a file into the dynamic array.
bool DynamicArrayList::loadMenuFromFile(const string& fileName) {
    ifstream file(fileName.c_str()); // Open the file for reading.
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl; // Handle file open failure.
        return false;
    }

    delete[] items;                  // Clear any existing menu items.
    items = new MenuItem[10];        // Allocate memory for a default capacity of 10.
    nextItemId = 1;                  // Reset the next item ID to 1.
    size = 0;                        // Reset the size.

    int id;
    string name, description;
    double price;

    // Read items from the file and add them to the list.
    while (file >> id) {
        file.ignore();               // Ignore whitespace or delimiters.
        getline(file, name, ',');    // Read the name.
        getline(file, description, ','); // Read the description.
        file >> price;               // Read the price.
        file.ignore();               // Ignore remaining characters on the line.
        MenuItem item(name, description, price);
        addMenuItem(item);           // Add the item to the list.
    }

    file.close(); // Close the file.
    return true;
}

// Saves the current menu items to a file.
bool DynamicArrayList::saveMenuToFile(const string& fileName) {
    ofstream file(fileName.c_str()); // Open the file for writing.
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl; // Handle file open failure.
        return false;
    }

    // Write each item to the file.
    for (int i = 0; i < size; ++i) {
        file << items[i].getId() << ','
             << items[i].getName() << ','
             << items[i].getDesc() << ','
             << items[i].getPrice() << '\n';
    }

    file.close(); // Close the file.
    cout << "Data saved successfully to " << fileName << endl;
    return true;
}

// Adds a new menu item to the list, resizing the array if needed.
void DynamicArrayList::addMenuItem(const MenuItem& item) {
    if (size == capacity) {                // Check if resizing is needed.
        capacity *= 2;                     // Double the capacity.
        MenuItem* temp = new MenuItem[capacity]; // Allocate a new larger array.
        for (int i = 0; i < size; i++) {
            temp[i] = items[i];            // Copy existing items to the new array.
        }
        delete[] items;                    // Free the old array.
        items = temp;                      // Update the pointer to the new array.
    }

    MenuItem newItem = item;               // Copy the new item.
    newItem.setId(nextItemId);             // Assign the next available ID.
    items[size++] = newItem;               // Add the item and increment the size.
    nextItemId++;                          // Increment the next available ID.
}

// Deletes a menu item at the specified index.
bool DynamicArrayList::deleteMenuItem(int index) {
    if (size == 0) {                       // Check if the list is empty.
        cout << "Menu is Empty" << endl;
        return false;
    }

    if (index < 0 || index > size) {       // Check for index out of bounds.
        cout << "Index out of bounds!" << endl;
        return false;
    }

    // Shift items to fill the gap left by the deleted item.
    for (int i = index - 1; i < size - 1; i++) {
        items[i] = items[i + 1];
    }

    size--;                                // Decrement the size.
    return true;
}

// Resets the menu by clearing all items and the file.
bool DynamicArrayList::resetMenu(const string& fileName) {
    delete[] items;                        // Clear the current items.
    items = new MenuItem[10];              // Allocate memory for a default capacity of 10.
    nextItemId = 1;                        // Reset the next item ID.
    size = 0;                              // Reset the size.

    ofstream file(fileName, ios::trunc);   // Open the file in truncation mode.
    if (!file.is_open()) {
        cerr << "Failed to open file: " << fileName << endl;
        return false;
    }

    // No need to write anything, truncation clears the file.
    file.close();                          // Close the file.

    cout << "All menu items cleared from file and memory." << endl;
    return true;
}

// Displays the current menu items to the console.
void DynamicArrayList::displayMenu() {
    cout << "--- Menu Items ---" << endl;
    for (int i = 0; i < size; i++) {
        cout << items[i];                  // Output each item.
    }
}

// Finds a menu item by its ID.
MenuItem* DynamicArrayList::findMenuItem(int id) {
    for (int i = 0; i < size; ++i) {
        if (items[i].getId() == id) {      // Check for a matching ID.
            return &items[i];              // Return a pointer to the matching item.
        }
    }
    return NULL;                           // Return NULL if not found.
}

// Assignment operator: Deep copies another DynamicArrayList object.
DynamicArrayList& DynamicArrayList::operator=(const DynamicArrayList& other) {
    if (this != &other) {                  // Check for self-assignment.
        delete[] items;                    // Clear the current items.

        capacity = other.capacity;         // Copy the capacity.
        size = other.size;                 // Copy the size.
        items = new MenuItem[capacity];    // Allocate memory for the new array.

        for (int i = 0; i < size; ++i) {
            items[i] = other.items[i];     // Copy each item.
        }
    }
    return *this;
}
