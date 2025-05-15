// This is the implementation file for the CompletedOrdersStack class.
// For function behaviors and details about the methods used, please refer to this file.
// The corresponding header file, CompletedOrdersStack.h, provides the class structure and function declarations.

//
//  CompletedOrdersStack.cpp
//

#include "CompletedOrdersStack.h"
#include <cassert>

// Node constructor, initializes the order and sets the next pointer to NULL
CompletedOrdersStack::Node::Node(const Order& order) {
    this->order = order;  // Assign the order to the node
    this->next = NULL;    // Initialize next to NULL
}

// Default constructor, initializes an empty stack
CompletedOrdersStack::CompletedOrdersStack() {
    firstOrder = NULL;  // First order pointer is NULL
    size = 0;           // Stack size is initially 0
    top = NULL;         // Top of the stack is NULL
}

// Destructor, clears all nodes in the stack
CompletedOrdersStack::~CompletedOrdersStack() {
    while (!isEmpty()) {
        Node* temp = top;  // Temporarily hold the top node
        top = top->next;   // Move top to the next node
        delete temp;       // Delete the old top node
    }
}

// Returns the current size of the stack
int CompletedOrdersStack::getSize() const {
    return size;
}

// Pushes a new order onto the stack
void CompletedOrdersStack::push(const Order& order) {
    NodePtr newOrder = new Node(order);  // Create a new node for the order
    if (isEmpty()) {
        firstOrder = newOrder;  // If the stack is empty, set firstOrder and top to the new node
        top = newOrder;
    } else {
        top->next = newOrder;  // Otherwise, link the new node to the current top and update top
        top = newOrder;
    }
    size++;  // Increment the stack size
}

// Checks if the stack is empty
bool CompletedOrdersStack::isEmpty() const {
    return firstOrder == NULL;  // Return true if firstOrder is NULL
}

// Pops the top order from the stack and returns it
const Order& CompletedOrdersStack::pop() {
    assert(!isEmpty());  // Ensure the stack is not empty

    // If there is only one order in the stack
    if (firstOrder->next == NULL) {
        const Order& popOrder = firstOrder->order;  // Retrieve the order
        delete firstOrder;  // Delete the single node
        firstOrder = NULL;  // Reset pointers
        top = NULL;
        size--;  // Decrement the stack size
        return popOrder;
    }

    // Traverse the stack to find the second-to-last node
    NodePtr temp = firstOrder;
    while (temp->next != top) {
        temp = temp->next;
    }
    const Order& popOrder = top->order;  // Retrieve the top order
    temp->next = NULL;  // Update the second-to-last node's next pointer
    delete top;  // Delete the old top node
    top = temp;  // Update the top pointer
    size--;  // Decrement the stack size
    return popOrder;
}

// Displays the prices of all completed orders
void CompletedOrdersStack::displayOrderPrice() {
    NodePtr temp = firstOrder;  // Start from the first order
    while (temp != NULL) {
        cout << "Order " << temp->order.getOrderId() << ": $"
             << temp->order.getTotalPrice() << endl;  // Display order ID and price
        temp = temp->next;  // Move to the next node
    }
}

// Calculates the total revenue from all completed orders
double CompletedOrdersStack::calculateTotalRevenue() const {
    double totalPrice = 0;  // Initialize total revenue
    if (isEmpty()) {
        return 0;  // Return 0 if the stack is empty
    }
    NodePtr temp = firstOrder;  // Start from the first order
    while (temp != NULL) {
        totalPrice += temp->order.getTotalPrice();  // Accumulate order prices
        temp = temp->next;  // Move to the next node
    }
    return totalPrice;  // Return the total revenue
}

// Displays all completed orders
void CompletedOrdersStack::displayCompletedOrders() const {
    if (isEmpty()) {
        cout << "No completed orders." << endl;  // Display message if the stack is empty
        return;
    }
    NodePtr temp = firstOrder;  // Start from the first order
    while (temp != NULL) {
        cout << temp->order << endl;  // Display the order details
        temp = temp->next;  // Move to the next node
    }
}

// Prints the current date to the provided output stream
void CompletedOrdersStack::printTime(ostream& out) const {
    time_t now = time(0);  // Get the current time
    tm* localTime = localtime(&now);  // Convert to local time

    // Format the date as YYYY-MM-DD
    char dateBuffer[11];
    strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", localTime);
    out << "Date: " << dateBuffer << endl;  // Output the date
}

// Saves all completed orders to a file
bool CompletedOrdersStack::saveCompletedOrdersToFile(const string& filename) const {
    ofstream file(filename.c_str());  // Open the file
    if (!file) {
        cerr << "Error opening file: " << filename << endl;  // Display error message if file can't be opened
        return false;
    }

    printTime(file);  // Print the date to the file
    file << "--- Completed Orders ---\n";  // Write a header to the file
    NodePtr temp = firstOrder;  // Start from the first order
    while (temp != NULL) {
        file << temp->order << endl;  // Write each order to the file
        temp = temp->next;  // Move to the next node
    }

    file.close();  // Close the file
    cout << "Orders have been saved to " << filename << endl;  // Display success message
    return true;  // Return true on success
}
