
//This program implements a Restaurant Order Management System that allows
//users to manage a dynamic menu, handle active and completed orders, and
//calculate total revenue. It provides functionalities such as adding,
//deleting, and resetting menu items, managing customer orders, processing
//orders, and saving completed orders to a file

//
//  main.cpp
//
//
 

#include <cstdlib>
#include <iostream>
#include <string>
#include "DynamicArrayList.h"       // Header for managing the restaurant's menu.
#include "ActiveOrdersQueue.h"      // Header for handling active orders using a queue.
#include "MenuItem.h"               // Header defining the structure and attributes of menu items.
#include "CompletedOrdersStack.h"   // Header for managing completed orders using a stack.
#include "Order.h"                  // Header for managing individual orders.

using namespace std;

// Displays the main menu for the Restaurant Order Management System.
void showMenu() {
    cout << "\n--- Restaurant Order Management System ---\n";
    cout << "1. Display Menu\n";
    cout << "2. Add Menu Item\n";
    cout << "3. Delete Menu Item\n";
    cout << "4. Reset Menu\n";
    cout << "5. Add New Order\n";
    cout << "6. Process Next Order\n";
    cout << "7. Display Orders\n";
    cout << "8. Delete Order\n";
    cout << "9. Calculate Total Amount of Sold Orders\n";
    cout << "10. Save Completed Orders to File\n";
    cout << "11. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    // Initialize main system components.
    DynamicArrayList menu(10);             // Menu is managed using a dynamic array.
    ActiveOrdersQueue activeOrders;        // Active orders are handled in a queue.
    CompletedOrdersStack completedOrders;  // Completed orders are stored in a stack.

    // Load the menu from a file and notify if loading fails.
    if (!menu.loadMenuFromFile("/Users/reine/Downloads/menu.txt")) {
        cout << "Failed to load Menu" << endl;
    }

    int choice;  // Variable for storing user input.
    do {
        showMenu();  // Display the main menu.
        cin >> choice;

        // Validate input to ensure it's numeric.
        while (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid number: " << endl;
            cout << "Choice : " << endl;
            cin >> choice;
        }

        switch (choice) {
            case 1: // Display the menu.
                if (menu.loadMenuFromFile("/Users/reine/Downloads/menu.txt")) {
                    menu.displayMenu();
                } else {
                    cout << "Failed to load the menu.\n";
                }
                break;

            case 2: // Add a new menu item.
            {
                string name, description;
                double price;

                // Collect menu item details from the user.
                cout << "Enter new menu item details:\n";
                cin.ignore();
                cout << "Name: ";
                getline(cin, name);
                cout << "Description: ";
                getline(cin, description);
                cout << "Price in $: ";
                cin >> price;

                // Validate price input.
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid price. Please try again." << endl;
                    cout << "Price: ";
                    cin >> price;
                }
                cin.ignore();

                // Add the item to the menu and save to file.
                menu.addMenuItem(MenuItem(name, description, price));
                cout << "Menu item added successfully.\n";
                menu.saveMenuToFile("/Users/reine/Downloads/menu.txt");  // Save to file.
                break;
            }

            case 3: // Delete a menu item by ID.
            {
                menu.loadMenuFromFile("/Users/reine/Downloads/menu.txt");  // Reload menu.
                int id;
                cout << "Enter the ID of the menu item to delete: ";
                cin >> id;
                cin.ignore();

                // Attempt to delete the item and save changes.
                if (menu.deleteMenuItem(id)) {
                    cout << "Menu item deleted successfully.\n";
                    menu.saveMenuToFile("/Users/reine/Downloads/menu.txt");
                } else {
                    cout << "Menu item not found.\n";
                }
                break;
            }

            case 4: // Reset the menu to its initial state.
                menu.resetMenu("/Users/reine/Downloads/menu.txt");
                cout << "Menu reset successfully.\n";
                break;

            case 5: // Add a new order.
            {
                string customerName;
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, customerName);

                int itemIds[30]; // Array to store item IDs (max capacity 30).
                int itemId, itemCount = 0;
                double totalPrice = 0.0;

                cout << "Enter item IDs (0 to finish): ";
                while (cin >> itemId && itemId != 0 && itemCount < 30) {
                    // Validate item ID input.
                    while (cin.fail() || itemId < 0 || itemId > menu.getSize()) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index. Please try again." << endl;
                        cout << "Enter item IDs (0 to finish): ";
                        cin >> itemId;
                    }
                    itemIds[itemCount++] = itemId;
                }

                Order order(customerName);  // Create a new order.
                for (int i = 0; i < itemCount; i++) {
                    int id = itemIds[i];
                    MenuItem* item = menu.findMenuItem(id);
                    if (item) {
                        order.addItem(id, *item, menu);
                        totalPrice += item->getPrice();
                    } else {
                        cout << "Item with ID " << id << " not found in menu.\n";
                    }
                }

                activeOrders.enqueue(order);  // Add order to the queue.
                cout << "Order added successfully.\n";
                cout << "Total Price: $" << totalPrice << endl;
                break;
            }

            case 6: // Process the next order.
            {
                Order processedOrder;
                if (activeOrders.dequeue(processedOrder)) {
                    processedOrder.setStatus("completed");
                    completedOrders.push(processedOrder);
                    cout << "Order processed successfully.\n";
                } else {
                    cout << "No active orders to process.\n";
                }
                break;
            }

            case 7: // Display active and completed orders.
                cout << "--- Active Orders ---\n";
                activeOrders.displayActiveOrders();
                cout << "--- Completed Orders ---\n";
                completedOrders.displayCompletedOrders();
                break;

            case 8: // Delete an order by ID.
            {
                int orderId;
                cout << "Enter the ID of the order to delete: ";
                cin >> orderId;

                // Validate order ID.
                while (cin.fail() || orderId < 0 || orderId > activeOrders.getSize()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid order ID. Please try again.\n";
                    cin >> orderId;
                }

                // Attempt to delete the order.
                if (activeOrders.deleteOrder(orderId)) {
                    cout << "Order deleted successfully.\n";
                } else {
                    cout << "Order not found.\n";
                }
                break;
            }

            case 9: // Calculate and display total revenue from completed orders.
            {
                double totalRevenue = completedOrders.calculateTotalRevenue();
                cout << "--- Total Revenue ---\n";
                if (completedOrders.isEmpty()) {
                    cout << "No completed orders." << endl;
                }
                completedOrders.displayOrderPrice();
                cout << "Total Sold: $" << totalRevenue << endl;
                break;
            }

            case 10: // Save completed orders to a file.
                if (completedOrders.saveCompletedOrdersToFile("/Users/reine/Downloads/completedOrders.txt")) {
                    cout << "Orders saved successfully!\n";
                } else {
                    cout << "Error saving completed orders.\n";
                }
                break;

            case 11: // Exit the program.
                cout << "Exiting the program... Goodbye!\n";
                break;

            default: // Handle invalid menu options.
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 11);

    return 0;
}
