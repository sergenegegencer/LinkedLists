# LinkedLists

This is a C++ console application that demonstrates the implementation and usage of **Singly**, **Doubly**, and **Circular** linked lists.  
The project is modular and interactive, using a menu-driven interface.

## Project Structure

LinkedLists/
├── Circular.h / Circular.cpp          # Circular linked list implementation  
├── Doubly.h / Doubly.cpp              # Doubly linked list implementation  
├── Singly.h / Singly.cpp              # Singly linked list implementation  
├── Menu.h / Menu.cpp                  # Console menu system to interact with the lists  
├── LinkedListOperationEnums.h         # Enum definitions for list operations  
├── Main.cpp                           # Entry point, connects everything together  
├── LinkedLists.vcxproj / .filters     # Visual Studio project files  

## Features

- Add, delete, search, and display operations on all three list types  
- Fully modular: list types are implemented in separate classes/files  
- Interactive menu to choose list type and perform operations  
- Enum-based operation selection for better readability and maintenance  
- Proper memory management and error handling (e.g. empty list exceptions)  

## Technologies Used

- Language: C++  
- IDE: Visual Studio 2022  
- Build System: MSBuild  
- Version Control: Git  

## How to Run

1. Clone the repository:
   git clone https://github.com/yourusername/LinkedLists.git

2. Open `LinkedLists.sln` in Visual Studio.

3. Build and run the project (Ctrl+F5 or F5).

## What I Learned

- How to build different types of linked lists from scratch  
- The benefits of modularizing code for maintainability and readability  
- Using `enum class` to manage operations in a clean and type-safe way  
- Structuring a small but real-world C++ console application  
- Practicing Git for version control  

## Next Steps

- Add file I/O to save and load list data  
- Improve user interface with command-line flags or better input validation  
- Add unit tests with a lightweight test framework (like Catch2)  

## 📸 Screenshots

(I'll add later.)
