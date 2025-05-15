/*--------------------------------------------------------------------------
   This is the header file for the MenuItem class implementation.
   For function implementations and detailed behavior, please refer to the
   corresponding .cpp file MenuItem.cpp where the logic of each method is fully defined.
   MenuItem.h contains the declaration of the MenuItem class.
   This class represents a single menu item in a restaurant's menu, encapsulating
   its unique identifier, name, description, and price. It provides functionality
   to access, modify, and display details of a menu item.

   Basic operations:
     - Default Constructor: Initializes a menu item with default values.
     - Parameterized Constructor: Creates a menu item with specified name, description, and price.
     - setId:    Sets the unique ID of the menu item.
     - setName:  Sets the name of the menu item.
     - setDesc:  Sets the description of the menu item.
     - setPrice: Sets the price of the menu item.
     - getId:    Retrieves the unique ID of the menu item.
     - getName:  Retrieves the name of the menu item.
     - getDesc:  Retrieves the description of the menu item.
     - getPrice: Retrieves the price of the menu item.
     - display:  Outputs all details of the menu item in a formatted manner.

   Overloaded operators:
     - ostream& operator<<: Overloads the `<<` operator for displaying menu item details
       directly, ensuring a consistent format.

   Data members:
     - id:    A unique identifier for the menu item.
     - name:  The name of the menu item.
     - desc:  A brief description of the menu item.
     - price: The price of the menu item.

--------------------------------------------------------------------------*/

#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
public:
    MenuItem();
    /*------------------------------------------------------------------------
        Purpose:       Constructs a default MenuItem with empty name, description, and price 0.

        Precondition:  None.
        Postcondition: A MenuItem object is created with default values (unknown name,
                       no description, and price set to 0).
    ------------------------------------------------------------------------*/
    MenuItem( string, string, double);
    /*------------------------------------------------------------------------
         Purpose:       Constructs a MenuItem with the given name, description, and price.

         Precondition:  A valid name (string), description (string), and price (double)
                        are provided.
         Postcondition: A MenuItem object is created with the given name, description,
                        and price set.
       ------------------------------------------------------------------------*/
    void setId(int);
    /*------------------------------------------------------------------------
          Sets the ID of the menu item.

          Precondition:  A valid integer ID is provided.
          Postcondition: The ID of the MenuItem is updated with the provided value.
        ------------------------------------------------------------------------*/
    void setName(string);
    /*------------------------------------------------------------------------
          Purpose:       Sets the name of the menu item.

          Precondition:  A valid name (string) is provided.
          Postcondition: The name of the MenuItem is updated with the provided value.
        ------------------------------------------------------------------------*/
    void setDesc(string);
    /*------------------------------------------------------------------------
          Purpose:       Sets the description of the menu item.

          Precondition:  A valid description (string) is provided.
          Postcondition: The description of the MenuItem is updated with the provided value.
        ------------------------------------------------------------------------*/
    void setPrice(double);
    /*------------------------------------------------------------------------
          Purpose:       Sets the price of the menu item.

          Precondition:  A valid price (double) is provided.
          Postcondition: The price of the MenuItem is updated with the provided value.
        ------------------------------------------------------------------------*/
    int getId() const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the ID of the menu item.

          Precondition:  None.
          Postcondition: Returns the ID of the MenuItem object.
        ------------------------------------------------------------------------*/
    string getName() const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the name of the menu item.

          Precondition:  None.
          Postcondition: Returns the name of the MenuItem object.
        ------------------------------------------------------------------------*/
    string getDesc() const;
    /*------------------------------------------------------------------------
          Purpose:       Returns the description of the menu item.

          Precondition:  None.
          Postcondition: Returns the description of the MenuItem object.
        ------------------------------------------------------------------------*/
    double getPrice() const;
    /*------------------------------------------------------------------------
         Purpose:       Returns the price of the menu item.

         Precondition:  None.
         Postcondition: Returns the price of the MenuItem object.
       ------------------------------------------------------------------------*/
    void display(ostream&) const;
    /*------------------------------------------------------------------------
          Purpose:       Displays the details of the menu item (ID, name, description, and price) to
                         the provided output stream.

          Precondition:  An open output stream (ostream) is provided.
          Postcondition: The details of the MenuItem are printed to the output stream.
        ------------------------------------------------------------------------*/
private:
    int id;           // The ID of the menu item.
    string name;      // The name of the menu item.
    string desc;      // The description of the menu item.
    double price;     // The price of the menu item.

};

// Overloaded output operator to display MenuItem details.
ostream& operator<<(ostream&, const MenuItem &);

#endif /* MENUITEM_H */

