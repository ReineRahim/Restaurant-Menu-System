// This is the implementation file for the ActiveOrdersQueue class.
// For function behaviors and details about the methods used, please refer to this file.
// The corresponding header file, ActiveOrdersQueue.h, provides the class structure and function declarations.

//
//  ActiveOrdersQueue.cpp
//


#include "ActiveOrdersQueue.h"

// Constructor for Node class, initializes the order data and next pointer
ActiveOrdersQueue::Node::Node(Order data) {
    this->data = data;  // Assign the order data to the node
    this->next = NULL;   // Set the next pointer to NULL
}

// Constructor for ActiveOrdersQueue class, initializes the queue
ActiveOrdersQueue::ActiveOrdersQueue() {
    myFront = NULL;     // Front of the queue is initially NULL
    myBack = NULL;      // Back of the queue is initially NULL
    size = 0;           // Queue is initially empty, so size is 0
    nextOrderId = 1;    // First order will have ID 1
}

// Destructor for ActiveOrdersQueue class, clears the queue when destroyed
ActiveOrdersQueue::~ActiveOrdersQueue() {
    // Keep dequeuing until the queue is empty
    while (!isEmpty()) {
        Order temp;
        dequeue(temp);  // Remove an order and store it in temp (unused here)
    }
    size = 0;  // Reset size to 0 after clearing the queue
}

// Enqueue method to add a new order to the back of the queue
void ActiveOrdersQueue::enqueue(const Order& newOrder) {
    // Create a new node to hold the order
    NodePtr newNode = new Node(newOrder);
    newNode->data.setOrderId(nextOrderId);  // Set the order ID for the new order
    nextOrderId++;  // Increment the next available order ID
    
    // If the queue is empty, set both front and back to the new node
    if (isEmpty()) {
        myFront = myBack = newNode;
    } else {
        // Otherwise, add the new node to the end of the queue and update the back pointer
        myBack->next = newNode;
        myBack = newNode;
    }
    
    size++;  // Increment the size of the queue
}

// Dequeue method to remove and return the front order from the queue
bool ActiveOrdersQueue::dequeue(Order& processedOrder) {
    // If the queue is empty, return false
    if (isEmpty()) {
        return false;
    }
    
    // Temporarily hold the front node
    NodePtr temp = myFront;
    processedOrder = myFront->data;  // Set the processed order to the data of the front node
    myFront = myFront->next;  // Move the front pointer to the next node
    delete temp;  // Delete the old front node to free memory
    size--;  // Decrease the size of the queue
    
    // If the queue is now empty, set the back pointer to NULL
    if (myFront == NULL) {
        myBack = NULL;
    }
    return true;  // Successfully dequeued an order
}

// Returns the current size of the queue
int ActiveOrdersQueue::getSize() const {
    return size;
}

// Method to delete a specific order by order ID
bool ActiveOrdersQueue::deleteOrder(int orderId) {
    // If the queue is empty, return false
    if (isEmpty()) {
        return false;
    }
    
    // Start with the front node
    NodePtr temp = myFront;
    NodePtr prev = NULL;  // To track the previous node for deletion
    
    // Traverse the queue to find the order by its ID
    while (temp != NULL) {
        // If the current node's order ID matches the given order ID
        if (temp->data.getOrderId() == orderId) {
            // If the order to delete is at the front
            if (prev == NULL) {
                myFront = temp->next;  // Move the front pointer to the next node
            } else {
                prev->next = temp->next;  // Remove the node from the list
            }
            
            // If the order to delete is at the back, update the back pointer
            if (temp == myBack) {
                myBack = prev;
            }
            nextOrderId--;  // Decrement the next available order ID
            delete temp;  // Free the memory of the deleted node
            size--;  // Decrease the size of the queue
            
            // Reassign order IDs starting from 1 after the deletion
            NodePtr current = myFront;
            int newId = 1;
            while (current != NULL) {
                current->data.setOrderId(newId);  // Reset the order ID for each remaining order
                ++newId;
                current = current->next;
            }
            
            return true;  // Order was successfully deleted
        }
        prev = temp;  // Move the previous pointer to the current node
        temp = temp->next;  // Move to the next node in the queue
    }
    
    return false;  // Order with the given ID was not found
}

// Method to display all active orders in the queue
void ActiveOrdersQueue::displayActiveOrders() {
    // If the queue is empty, output a message
    if (isEmpty()) {
        cout << "No active orders." << endl;
        return;
    }
    // Traverse the queue and display each order
    NodePtr temp = myFront;
    while (temp != NULL) {
        temp->data.displayOrder(cout);  // Display the order's details
        temp = temp->next;  // Move to the next node
    }
}

// Helper method to check if the queue is empty
bool ActiveOrdersQueue::isEmpty() {
    return myFront == NULL;  // Return true if the front pointer is NULL (empty queue)
}

