// This is the implementation file for the Order class.
// For function behaviors and details about the methods used, please refer to this file.
// The corresponding header file, Order.h, provides the class structure and function declarations.

//
//  Order.cpp
//


#include "Order.h"

// Default constructor, initializes default values for an Order
Order::Order() {
    customerName = "unknown";    // Customer name defaulted to "unknown"
    totalPrice = 0.0;           // Total price starts at 0.0
    status = "pending";         // Order status is set to "pending"
    itemCount = 0;              // No items initially
}

// Constructor with customer name, initializes an order for a specific customer
Order::Order(const string& name) {
    customerName = name;        // Assigns the provided customer name
    totalPrice = 0.0;           // Total price starts at 0.0
    status = "pending";         // Order status is set to "pending"
    itemCount = 0;              // No items initially
}

// Copy constructor, creates a deep copy of an existing Order
Order::Order(const Order& other) {
    customerName = other.customerName;  // Copies customer name
    totalPrice = other.totalPrice;      // Copies total price
    status = other.status;              // Copies order status
    itemCount = other.itemCount;        // Copies the item count
    orderId = other.orderId;            // Copies the order ID

    // Copies items array if there are items
    if (itemCount > 0) {
        items = new MenuItem[itemCount];
        for (int i = 0; i < itemCount; ++i) {
            items[i] = other.items[i];
        }
    } else {
        items = NULL;  // No items to copy
    }
}

// Adds a menu item to the order by index
bool Order::addItem(int index, const MenuItem& item, const DynamicArrayList& menuList) {
    if (index < 0 || index > menuList.getSize()) {  // Validates index
        cout << "Invalid index. Item not added." << endl;
        return false;
    }

    // Expands the items array to include the new item
    MenuItem* temp = new MenuItem[itemCount + 1];
    for (int i = 0; i < itemCount; ++i) {
        temp[i] = items[i];  // Copies existing items
    }
    temp[itemCount] = item;  // Adds the new item
    delete[] items;          // Deletes old array
    items = temp;            // Updates pointer to new array
    totalPrice += item.getPrice();  // Adds item's price to total
    itemCount++;             // Increments item count
    return true;
}

// Returns the total price of the order
double Order::getTotalPrice() const {
    return totalPrice;
}

// Sets the order ID
void Order::setOrderId(int orderId) {
    this->orderId = orderId;
}

// Gets the order ID
int Order::getOrderId() const {
    return orderId;
}

// Sets the customer name for the order
void Order::setCustomerName(const string& customerName) {
    this->customerName = customerName;
}

// Gets the customer name for the order
const string& Order::getCustomerName() const {
    return customerName;
}

// Sets the status of the order
void Order::setStatus(const string& status) {
    this->status = status;
}

// Gets the status of the order
const string& Order::getStatus() const {
    return status;
}

// Assignment operator overload, performs a deep copy
Order& Order::operator=(const Order& other) {
    if (this == &other)  // Self-assignment check
        return *this;

    delete[] items;  // Deletes current items

    customerName = other.customerName;  // Copies customer name
    totalPrice = other.totalPrice;      // Copies total price
    status = other.status;              // Copies order status
    itemCount = other.itemCount;        // Copies item count
    orderId = other.orderId;            // Copies order ID

    // Copies items array if there are items
    if (itemCount > 0) {
        items = new MenuItem[itemCount];
        for (int i = 0; i < itemCount; ++i) {
            items[i] = other.items[i];
        }
    } else {
        items = NULL;  // No items to copy
    }

    return *this;
}

// Displays the order details
void Order::displayOrder(ostream& out) const {
    out << "Order ID: " << orderId << ", Customer: " << customerName << endl;
    out << "Items:" << endl;
    for (int i = 0; i < itemCount; ++i) {
        out << "- " << items[i].getName() << " ($" << items[i].getPrice() << ")" << endl;
    }
    out << "Status: " << status << endl;
}

// Overloads the output stream operator to display order details
ostream& operator<<(ostream& out, const Order& order) {
    order.displayOrder(out);
    return out;
}
