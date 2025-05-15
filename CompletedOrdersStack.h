/*--------------------------------------------------------------------------
   This is the header file for the CompletedOrdersStack class implementation.
   For function implementations and detailed behavior, please refer to the corresponding .cpp file
   CompletedOrdersStack.cpp where the logic of each method is fully defined.
   CompletedOrdersStack.h contains the declaration of the CompletedOrdersStack class.
   This class represents a stack data structure for managing completed orders, where
   the most recently completed order is always at the top of the stack. The stack follows
   the LIFO (Last-In-First-Out) principle, providing efficient management of completed
   orders.

   Basic operations:
     - Constructor: Constructs an empty CompletedOrdersStack.
     - Destructor:  Releases all dynamically allocated memory used by the stack.
     - getSize:     Returns the total number of orders in the stack.
     - push:        Adds a new order to the top of the stack.
     - pop:         Removes and retrieves the order at the top of the stack.
     - isEmpty:     Checks if the stack contains any orders.
     - calculateTotalRevenue: Computes the total revenue generated from all completed orders.
     - displayCompletedOrders: Displays all orders in the stack with their details.
     - displayOrderPrice: Displays the price of each order in the stack.
     - printTime:   Outputs the completion times of all orders.
     - saveCompletedOrdersToFile: Saves all completed orders to a specified file for record-keeping.

   Private utility:
     - Node: Represents a single node in the stack, storing an Order object and a pointer
             to the next node in the sequence.

   Data members:
     - firstOrder: Pointer to the first order in the stack (used for traversal if needed).
     - top:        Pointer to the top node of the stack (most recently added order).
     - size:       Tracks the total number of orders currently in the stack.

   Overloaded operators:
     - ostream& operator<<: Overloads the `<<` operator for printing order details, ensuring
       clear and readable output when displaying completed orders.

--------------------------------------------------------------------------*/

#ifndef COMPLETEDORDERSSTACK_H
#define COMPLETEDORDERSSTACK_H
#include <iostream>
#include "Order.h"
using namespace std;

class CompletedOrdersStack{
public:
    CompletedOrdersStack();
    /*------------------------------------------------------------------------
        Purpose:       Constructs an empty CompletedOrdersStack.

        Precondition:  None.
        Postcondition: An empty stack has been created, with `top` set to nullptr
                     and `size` initialized to 0.
    ------------------------------------------------------------------------*/
    ~CompletedOrdersStack();
    /*------------------------------------------------------------------------
        Purpose:       Destructor: Destroys the stack and releases all allocated memory.

        Precondition:  The stack exists.
        Postcondition: All nodes in the stack have been deallocated, and the
                        stack is empty.
       ------------------------------------------------------------------------*/
    int getSize()const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the current size of the stack.

          Precondition:  None.
          Postcondition: Returns the number of orders currently in the stack.
        ------------------------------------------------------------------------*/
    void push(const Order&);
    /*------------------------------------------------------------------------
         Purpose:       Adds a new order to the top of the stack.

         Precondition:  A valid Order object `newOrder` is provided.
         Postcondition: `newOrder` is added to the top of the stack, and `size`
                        is incremented by 1.
       ------------------------------------------------------------------------*/
    const Order& pop();
    /*------------------------------------------------------------------------
          Purpose:       Removes and returns the order at the top of the stack.

          Precondition:  The stack is not empty.
          Postcondition: The top order is removed, `size` is decremented by 1,
                         and the removed order is returned.
        ------------------------------------------------------------------------*/
    bool isEmpty()const;
    /*------------------------------------------------------------------------
          Purpose:       Checks if the stack is empty.

          Precondition:  None.
          Postcondition: Returns true if the stack is empty (size == 0), and
                         false otherwise.
        ------------------------------------------------------------------------*/
    double calculateTotalRevenue() const;
    /*------------------------------------------------------------------------
        Purpose:       Calculates the total revenue generated by all completed orders.

        Precondition:  None.
        Postcondition: Returns the sum of the prices of all orders in the stack.
    ------------------------------------------------------------------------*/
    void displayCompletedOrders()const;
    /*------------------------------------------------------------------------
        Purpose:       Displays the details of all completed orders in the stack.

        Precondition:  None.
        Postcondition: Outputs the details of each order to the console, starting
                         from the top of the stack and moving downward.
        ------------------------------------------------------------------------*/
    void displayOrderPrice();
    /*------------------------------------------------------------------------
         Purpose:       Displays the price of each order in the stack.

         Precondition:  None.
         Postcondition: Outputs the price of each order to the console.
       ------------------------------------------------------------------------*/
    void printTime(ostream&)const;
    /*------------------------------------------------------------------------
          Purpose:       Prints the timestamps of all completed orders.

          Precondition:  The provided ostream `out` is open.
          Postcondition: The completion times of all orders are output to `out`.
        ------------------------------------------------------------------------*/
    bool saveCompletedOrdersToFile(const string&) const;
    /*------------------------------------------------------------------------
          Purpose:      Saves the details of all completed orders to a specified file.

          Precondition:  A valid file path is provided.
          Postcondition: Writes the details of all orders to the specified file
                         in a readable format. Returns true if successful, and false
                         if an error occurs.
        ------------------------------------------------------------------------*/
private:
    class Node{
    public:
        Node(const Order&);
        /*------------------------------------------------------------------------
          Purpose:       Constructs a Node object containing an Order and a pointer to the next node.

          Precondition:  A valid Order object is provided.
          Postcondition: A Node is created with `order` set to the Order object and
                         `next` set to nullptr.
        ------------------------------------------------------------------------*/
        Order order; // The order stored in the node.
        Node* next; // Pointer to the next node in the queue.
    };
    typedef Node* NodePtr;
    NodePtr firstOrder;     // Pointer to the first order.
    NodePtr top;            // Pointer to the top order in the stack.
    int size;               // Current number of orders in the stack.

};
// Overloaded output operator to display MenuItem details.
ostream& operator<<(ostream&, const Order&);

#endif /* COMPLETEDORDERSSTACK_H */
