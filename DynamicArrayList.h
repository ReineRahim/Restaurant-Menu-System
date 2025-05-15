/*--------------------------------------------------------------------------
   This is the header file for the DynamicArrayList class implementation.
   For function implementations and detailed behavior, please refer to the
   corresponding .cpp file DynamicArrayList.cpp where the logic of each method is fully defined.
   DynamicArrayList.h contains the declaration of the DynamicArrayList class.
   This class represents a dynamic array data structure designed to manage
   a collection of menu items efficiently. It supports operations such as
   addition, deletion, searching, and file handling for menu persistence.

   Basic operations:
     - Constructor: Constructs an empty DynamicArrayList with a specified capacity.
     - Copy Constructor: Creates a deep copy of an existing DynamicArrayList.
     - Destructor:  Releases dynamically allocated memory associated with the array.
     - getSize:     Returns the current number of menu items in the list.
     - setCapacity: Adjusts the capacity of the array as needed.
     - getCapacity: Returns the maximum number of items the array can hold.
     - loadMenuFromFile: Loads menu data from a file into the dynamic array.
     - saveMenuToFile:  Saves the current menu items to a file for future use.
     - addMenuItem: Adds a new menu item to the dynamic array.
     - deleteMenuItem: Deletes a menu item by its unique ID.
     - resetMenu: Clears the menu, removing all menu items.
     - displayMenu: Displays all menu items currently in the array.
     - findMenuItem: Searches for a menu item by ID and returns a pointer to it.
     - Assignment Operator: Overloads the `=` operator for deep copying DynamicArrayList objects.

   Private utility:
     - The class uses dynamic memory allocation to resize the array when the
       current capacity is exceeded, ensuring efficient use of memory.

   Data members:
     - items: A dynamically allocated array storing MenuItem objects.
     - capacity: The current maximum capacity of the array.
     - size: The number of items currently stored in the array.
     - nextItemId: A counter used to assign unique IDs to new menu items.

--------------------------------------------------------------------------*/


#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H

#include <iostream>
#include <fstream>
#include <string>
#include "MenuItem.h"
using namespace std;

class DynamicArrayList {
public:
    DynamicArrayList(int);
    /*------------------------------------------------------------------------
      Purpose:       Constructs a DynamicArrayList with a given initial capacity.

      Precondition:  `initialCapacity` is a positive integer.
      Postcondition: An empty list is created with the specified capacity,
                     and the `size` is initialized to 0.
    ------------------------------------------------------------------------*/
    
    DynamicArrayList(const DynamicArrayList&);
    /*------------------------------------------------------------------------
      Purpose:       Copy constructor: Creates a deep copy of another DynamicArrayList object.

      Precondition:  the other object is a valid DynamicArrayList object.
      Postcondition: A new list is created with the same capacity, size, and
                     elements as `other`.
    ------------------------------------------------------------------------*/
    
    ~DynamicArrayList();
    /*------------------------------------------------------------------------
      Purpose:       Destructor: Releases allocated memory used by the list.

      Precondition:  The DynamicArrayList exists.
      Postcondition: All dynamically allocated memory is released, and the
                     object is cleaned up.
    ------------------------------------------------------------------------*/
    
    int getSize() const;
    /*------------------------------------------------------------------------
      Purpose:       Returns the current number of items in the list.

      Precondition:  None.
      Postcondition: Returns the number of menu items in the list.
    ------------------------------------------------------------------------*/
    
    void setCapacity(int);
    /*------------------------------------------------------------------------
         Purpose:       Updates the capacity of the list.

         Precondition:  the new capacity is greater than or equal to the current size.
         Postcondition: The list capacity is updated, and memory is reallocated
                        if necessary. Existing items are preserved.
       ------------------------------------------------------------------------*/
    
    int getCapacity() const;
    /*------------------------------------------------------------------------
      Purpose:       Returns the current capacity of the list.

      Precondition:  None.
      Postcondition: Returns the maximum number of items the list can hold
                     without resizing.
    ------------------------------------------------------------------------*/
    
    bool loadMenuFromFile(const string&);
    /*------------------------------------------------------------------------
          Purpose:       Loads menu items from a specified file.

          Precondition:  the filename is a valid file path.
          Postcondition: Reads menu item data from the file and populates the list.
                         Returns true if successful, false if an error occurs (e.g., file
                         not found or invalid format).
        ------------------------------------------------------------------------*/
    
    bool saveMenuToFile(const string&);
    /*------------------------------------------------------------------------
      Purpose:       Saves the current menu items to a specified file.

      Precondition:  the filename is a valid file path.
      Postcondition: Writes all menu items in the list to the file in a
                     structured format. Returns true if successful, false otherwise.
    ------------------------------------------------------------------------*/
    
    void addMenuItem(const MenuItem&);
    /*------------------------------------------------------------------------
      Purpose:       Adds a new menu item to the list.

      Precondition:  The list is not at capacity, and the new item is valid.
      Postcondition: New Item is added to the end of the list, and `size`
                     is incremented by 1. If necessary, the list is resized.
    ------------------------------------------------------------------------*/
    
    bool deleteMenuItem(int);
    /*------------------------------------------------------------------------
      Purpose:       Deletes a menu item from the list based on its ID.

      Precondition:  Item Id corresponds to an existing menu item.
      Postcondition: The item is removed, and the remaining items are shifted
                     to fill the gap. Returns true if successful, false otherwise.
    ------------------------------------------------------------------------*/

    bool resetMenu(const string&);
    /*------------------------------------------------------------------------
      Purpose:       Resets the menu by clearing all items in the list.

      Precondition:  None.
      Postcondition: The list is cleared, and `size` is set to 0.
    ------------------------------------------------------------------------*/

    void displayMenu();
    /*------------------------------------------------------------------------
         Purpose:       Displays all menu items currently in the list.

         Precondition:  None.
         Postcondition: Outputs the details of each menu item to the console.
       ------------------------------------------------------------------------*/
    MenuItem* findMenuItem(int);
    /*------------------------------------------------------------------------
      Purpose:       Finds a menu item in the list based on its ID.

      Precondition:  Item Id corresponds to an existing menu item.
      Postcondition: Returns a pointer to the menu item if found, or nullptr
                     if no item with the given ID exists.
    ------------------------------------------------------------------------*/
    DynamicArrayList& operator=(const DynamicArrayList&);
    /*------------------------------------------------------------------------
      Purpose:       Assigns one DynamicArrayList to another.

      Precondition:  The other Object is a valid DynamicArrayList object.
      Postcondition: The current list is replaced with a deep copy of `other`.
                     Any previously allocated memory is released.
    ------------------------------------------------------------------------*/
private:
    MenuItem* items;  // Pointer to the dynamically allocated array of menu items.
    int capacity;     // Maximum number of items the list can hold.
    int size;         // Current number of items in the list.
    int nextItemId;   // ID to assign to the next menu item.
};

#endif /* DYNAMICARRAYLIST_H */
