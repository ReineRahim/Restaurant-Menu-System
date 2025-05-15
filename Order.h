/* --------------------------------------------------------------------------
   This is the header file for the Order class implementation.
   For function implementations and detailed behavior, please refer to the
   corresponding .cpp file Order.cpp where the logic of each method is fully defined.
   Order.h contains the declaration of the Order class, which represents a customer's
   order in the restaurant management system. The class provides functionality
   for managing the details of the order, including the order's ID, customer name,
   the items included, total price, and order status.

   Basic operations:
     - Constructor: Constructs an Order object, either empty or with a specified customer name.
     - Copy constructor: Creates a new Order object by copying the data from an existing Order.
     - addItem: Adds a MenuItem to the order at a specific index and updates the total price.
     - getTotalPrice: Calculates and returns the total price of the items in the order.
     - setOrderId: Sets the order ID for the order.
     - getOrderId: Returns the order ID of the order.
     - setCustomerName: Sets the customer's name associated with the order.
     - getCustomerName: Returns the customer's name.
     - setStatus: Sets the status of the order (e.g., "Pending", "Completed").
     - getStatus: Returns the status of the order.
     - displayOrder: Outputs the order details in a readable format to an output stream.
     - Assignment operator: Assigns the data from one Order object to another.

   Data members:
     - orderId: The unique identifier for the order.
     - itemCount: The number of items included in the order.
     - customerName: The name of the customer who placed the order.
     - items: A pointer to an array of MenuItem objects that make up the order.
     - totalPrice: The total price of the order, calculated by summing the prices of all items.
     - status: The current status of the order (e.g., "Pending", "Completed").

   Overloaded operators:
     - ostream& operator<<: Overloads the `<<` operator for printing MenuItem details to an output stream.

-------------------------------------------------------------------------- */

#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include "DynamicArrayList.h"
using namespace std;

class Order {
public:
    Order();
    /*------------------------------------------------------------------------
          Purpose:       Constructs an empty Order object.

          Precondition:  None.
          Postcondition: An empty Order object is created with default values for
                          customerName (unknow), itemCount (0), totalPrice (0.0), and status
                         ("pending").
        ------------------------------------------------------------------------*/
        
    Order(const string&);
    /*------------------------------------------------------------------------
        Purpose:       Constructs an Order object with a specified customer name.

        Precondition:  A valid customer name string is provided.
        Postcondition: An Order object is created with the provided customer name,
                       itemCount (0), totalPrice (0.0), and status ("pending").
                       The `items` pointer is initialized to `nullptr`.
      ------------------------------------------------------------------------*/
    Order(const Order&);
    /*------------------------------------------------------------------------
          Purpose:       Copy constructor that creates a new Order object by copying the data
                         from an existing Order object.

          Precondition:  An existing Order object is provided.
          Postcondition: A new Order object is created with the same data as the
                         provided Order (orderId, itemCount, customerName, status,
                         items, and totalPrice).
        ------------------------------------------------------------------------*/
    
    bool addItem(int index, const MenuItem&, const DynamicArrayList&);
    /*------------------------------------------------------------------------
         Purpose:       Adds a MenuItem to the Order with a specified MenuItem index.

         Precondition:  A valid MenuItem object and DynamicArrayList object are provided.
                        The `index` must be within the valid range of the item list.
         Postcondition: The MenuItem is added to the Order's item list created at the specified
                        index, and the total price of the order is updated.
       ------------------------------------------------------------------------*/
    
    double getTotalPrice() const;
    /*------------------------------------------------------------------------
         Purpose:       Returns the total price of the order.

         Precondition:  The Order object exists and contains at least one item.
         Postcondition: Returns the total price of the Order, summing the prices
                        of all MenuItems added.
       ------------------------------------------------------------------------*/
    
    void setOrderId(int);
    /*------------------------------------------------------------------------
         Purpose:       Sets the order ID to a specified value.

         Precondition:  A valid order ID (positive integer) is provided.
         Postcondition: The orderId is set to the provided value.
       ------------------------------------------------------------------------*/

    int getOrderId()const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the order ID.

          Precondition:  The Order object exists.
          Postcondition: Returns the order ID of the Order object.
        ------------------------------------------------------------------------*/
    
    void setCustomerName(const string&);
    /*------------------------------------------------------------------------
          Purpose:       Sets the customer's name for the order.

          Precondition:  A valid string representing the customer name is provided.
          Postcondition: The customerName is set to the provided value.
        ------------------------------------------------------------------------*/
    
    const string& getCustomerName()const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the customer's name.

          Precondition:  The Order object exists.
          Postcondition: Returns the customer name associated with the Order.
        ------------------------------------------------------------------------*/
    
    void setStatus(const string&);
    /*------------------------------------------------------------------------
          Purpose:       Sets the status of the order.

          Precondition:  A valid status string (e.g., "Pending", "Completed") is provided.
          Postcondition: The status is set to the provided value.
        ------------------------------------------------------------------------*/
    const string& getStatus()const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the status of the order.

          Precondition:  The Order object exists.
          Postcondition: Returns the status string associated with the Order.
        ------------------------------------------------------------------------*/

    void displayOrder(ostream&) const;
    /*------------------------------------------------------------------------
         Purpose:       Displays the details of the Order object in a readable format.

         Precondition:  A valid output stream object (`ostream`) is provided.
         Postcondition: The details of the Order (ID, customer name, status, and items)
                        are output to the provided stream in a readable format.
       ------------------------------------------------------------------------*/

    Order& operator=(const Order&);
    /*------------------------------------------------------------------------
         Purpose:       Assignment operator to copy data from one Order object to another.

         Precondition:  A valid Order object is provided.
         Postcondition: The current Order object is updated with the same data
                        as the provided Order object (orderId, itemCount, customerName,
                        status, items, and totalPrice).
       ------------------------------------------------------------------------*/

private:
    int orderId;        // The unique identifier for the order.
    int itemCount;      // The total number of items in the order.
    string customerName; // The name of the customer who placed the order.
    MenuItem *items;    // Pointer to an array of MenuItem objects in the order.
    double totalPrice;  // The total price of the order, calculated from items' prices.
    string status;      // The current status of the order (e.g., "Pending", "Completed").
};
// Overloaded output operator to display MenuItem details.
ostream& operator<<(ostream&, const MenuItem &);


#endif /* ORDER_H */
