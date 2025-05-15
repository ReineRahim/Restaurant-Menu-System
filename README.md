# Restaurant Management System

## Project Overview
The Restaurant Management System is a C++ application designed to efficiently handle menu items and customer orders for restaurants. 
It utilizes custom data structures such as dynamic arrays, linked lists, stacks, and queues to ensure smooth operations. 
The system is file-based and interactive, making it user-friendly for restaurant staff.

## Features

### Menu Management:
•⁠  ⁠Load menu items from a file into a dynamic array.
•⁠  ⁠Display all menu items.
•⁠  ⁠Add new items to the menu.
•⁠  ⁠Remove existing menu items.
•⁠  ⁠Reset the menu by clearing all items.
•⁠  ⁠Save the updated menu back to a file.

### Order Management:
•⁠  ⁠Add customer orders, which may contain multiple menu items, to a queue of active orders.
•⁠  ⁠Process and serve orders, removing them from the queue and storing them in a stack of completed orders.
•⁠  ⁠Display active and completed orders.
•⁠  ⁠Cancel an active order.

### Revenue Management:
•⁠  ⁠Calculate total revenue from completed orders.
•⁠  ⁠Save completed order details to a file for record-keeping.

## Data Structures Used
•⁠  ⁠*Dynamic Array:* Manages menu items efficiently.
•⁠  ⁠*Queue:* Implemented using a linked list to handle active orders.
•⁠  ⁠*Stack:* Built with a linked list to store completed orders.
•⁠  ⁠*Linked List:* Used as the underlying structure for both the queue and stack.

## Project Structure

### Key Files:
•⁠  ⁠⁠ RestaurantOrderManagementSystem.h & RestaurantOrderManagementSystem.cpp ⁠: The main entry point of the application.
•⁠  ⁠⁠ main.cpp ⁠: Calls the RestaurantOrderManagementSystem to start the system.
•⁠  ⁠⁠ Menu.cpp & Menu.h ⁠: Handles menu operations.
•⁠  ⁠⁠ Order.cpp & Order.h ⁠: Manages customer orders.
•⁠  ⁠⁠ CompletedOrder.cpp & CompletedOrder.h ⁠: Deals with completed orders.
•⁠  ⁠⁠ CustomOrder.cpp & CustomOrder.h ⁠: Manages custom orders.
•⁠  ⁠⁠ MenuItem.cpp & MenuItem.h ⁠: Represents individual menu items.
•⁠  ⁠⁠ Node.cpp & Node.h ⁠: Implements linked list nodes for queue and stack operations.

### Additional Files:
•⁠  ⁠⁠ menu.txt ⁠: Stores the list of menu items.
•⁠  ⁠⁠ completed_orders.txt ⁠: Logs completed orders.
•⁠  ⁠⁠ Makefile ⁠: Automates the build process.

## Setup Instructions

### Requirements:
•⁠  ⁠A C++ compiler (e.g., GCC).
•⁠  ⁠Make utility (optional, for using the Makefile).

### Build & Run Steps:
Clone or download the project files.

Open a terminal and navigate to the project directory.

## Usage
### Menu Operations:
•⁠  ⁠Load menu items from menu.txt.
•⁠  ⁠Add, delete, or reset menu items interactively.
•⁠  ⁠Save updated menu items back to menu.txt.
### Order Operations:
•⁠  ⁠Add customer orders to the queue.
•⁠  ⁠Serve and complete orders, moving them to the stack.
•⁠  ⁠Cancel active orders if needed.
### View & Save:
•⁠  ⁠Display active and completed orders.
•⁠  ⁠Calculate total revenue from completed orders.
•⁠  ⁠Save completed order details to completed_orders.txt.
