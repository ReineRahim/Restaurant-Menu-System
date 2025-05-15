/*--------------------------------------------------------------------------
   This is the header file for the ActiveOrdersQueue class implementation.
   For function implementations and detailed behavior, please refer to the corresponding .cpp file
   ActiveOrdersQueue.cpp where the logic of each method is fully defined.ActiveOrdersQueue.h contains the declaration
   of the  ActiveOrdersQueue class.
   This class manages a dynamic queue of orders, where each order is represented
   by a node in a linked list. The queue follows the FIFO (First-In-First-Out) principle,
   where orders are added to the back and removed from the front.

   Basic operations:
     - Constructor: Constructs an empty ActiveOrdersQueue.
     - Destructor:  Releases all dynamically allocated memory used by the queue.
     - enqueue:     Adds a new order to the back of the queue.
     - dequeue:     Removes the order at the front of the queue.
     - deleteOrder: Deletes a specific order by its unique identifier.
     - displayActiveOrders: Displays all active orders in the queue with their details.
     - isEmpty:     Checks if the queue contains any orders.
     - getSize:     Retrieves the total number of orders currently in the queue.

   Private utility:
     - Node: Represents a single node in the queue, storing an Order object and a pointer
             to the next node in the sequence.

   Data members:
     - myFront: Pointer to the front node of the queue (first order).
     - myBack:  Pointer to the back node of the queue (last order).
     - size:    Tracks the number of orders currently in the queue.
     - nextOrderId: Keeps a counter for assigning unique order IDs (if applicable).
 
--------------------------------------------------------------------------*/

#ifndef ACTIVEORDERSQUEUE_H
#define ACTIVEORDERSQUEUE_H

#include <iostream>
#include "Order.h"
using namespace std;

class ActiveOrdersQueue {
public:
    ActiveOrdersQueue();
    /*------------------------------------------------------------------------
      Purpose:       Construct an empty ActiveOrdersQueue object.

      Precondition:  None.
      Postcondition: An empty queue has been created with myFront and myBack
                     and size set to 0 and the nextItemId is set to 1.
     -----------------------------------------------------------------------*/
    ~ActiveOrdersQueue();
    /*------------------------------------------------------------------------
      Purpose:       Destructor for ActiveOrdersQueue.

      Precondition:  None.
      Postcondition: All memory allocated for the queue has been released
                     and size is set to 0.
     -----------------------------------------------------------------------*/
    void enqueue(const Order&);
    /*------------------------------------------------------------------------
      Purpose:       Add a new order to the back of the queue.

      Precondition:  newOrder is a valid Order object.
      Postcondition: The newOrder has been added to the back of the queue.
     -----------------------------------------------------------------------*/
    bool dequeue(Order&);
    /*------------------------------------------------------------------------
      Purpose:       Remove the order from the front of the queue.

      Precondition:  The queue is not empty.
      Postcondition: The front order has been removed, and its data is stored
                     in frontOrder. Returns true if successful, false otherwise.
     -----------------------------------------------------------------------*/
    bool deleteOrder(int);
    /*------------------------------------------------------------------------
      Purpose:       Delete a specific order by its ID.

      Precondition:  orderId is a valid integer.
      Postcondition: The order with the specified ID has been removed if found.
                     Returns true if the order was found and deleted,
                     false otherwise.
     -----------------------------------------------------------------------*/
    void displayActiveOrders();
    /*------------------------------------------------------------------------
      Purpose:       Display all active orders in the queue.

      Precondition:  None.
      Postcondition: Outputs all active orders in the queue to the console.
     -----------------------------------------------------------------------*/
    bool isEmpty();
    /*------------------------------------------------------------------------
      Purpose:       Get the number of orders in the queue.

      Precondition:  None.
      Postcondition: Returns the size of the queue.
     -----------------------------------------------------------------------*/
    int getSize()const;
    /*------------------------------------------------------------------------
      Purpose:       Get the number of orders in the queue.

      Precondition:  None.
      Postcondition: Returns the size of the queue.
     -----------------------------------------------------------------------*/
    
private:
    class Node {
    public:
        Node(Order data);
        /*------------------------------------------------------------------------
          Purpose:       Constructs a Node object containing an Order and a pointer to the next node.

          Precondition:  A valid Order object is provided.
          Postcondition: A Node is created with `order` set to the Order object and
                         `next` set to nullptr.
        ------------------------------------------------------------------------*/
        Order data; // The order stored in the node.
        Node* next; // Pointer to the next node in the queue.
    };
    typedef Node* NodePtr;
    
    NodePtr myFront; // Pointer to the front node of the queue.
    NodePtr myBack; // Pointer to the back node of the queue.
    int size; // Number of orders in the queue.
    int nextOrderId; // Identifier for the next order.
};
#endif /* ACTIVEORDERSQUEUE_H */
