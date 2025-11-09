# 🚗 Vehicle Registration System (VRS)

Description (less than 350 characters): A robust, console-based application built in C for managing vehicle records. It demonstrates fundamental data structures, efficient CRUD operations (Create, Read, Update, Delete), and file persistence for long-term data storage.

# 🚀 Key Features

This system provides a full set of functionalities necessary for effective record management:

Data Entry: Quickly add new vehicle records, capturing the Registration ID, Owner Name, Make, and Year of registration.

Search & Retrieval: Fast lookup of specific records using a unique Registration ID as the primary key.

Data Modification (Update): Allows comprehensive editing of existing vehicle data, giving the user the flexibility to modify all associated fields, including the ID itself.

Efficient Deletion: Implements a memory-efficient method by shifting array elements to permanently delete a record and immediately reduce the overall record count.

Persistence: Records are automatically loaded from the records.txt file on startup and saved securely upon program exit, ensuring data integrity across sessions.

# 💻 Technical Implementation Highlights

This project is a strong demonstration of foundational C programming concepts:

Data Structuring: Uses an Array of Structures (struct Vehicle) to manage and organize complex data objects in memory.

Input Handling: Employs advanced scanf format specifiers (%[^\n]) for clean, space-inclusive string input.

Control Flow: Comprehensive use of switch statements and do-while loops to create a user-friendly, menu-driven experience.

File I/O: Utilizes FILE pointers and stream functions (fopen, fscanf, fprintf) for reliable reading and writing of data to the persistent file storage.
