# Movie-BookingSystem.c
This is a CLI based Movie Tickets booking system that is build using pointers and structures.
# 🎬 Movie Ticket Booking System (C)

A simple Command Line Interface (CLI) based Movie Ticket Booking System written in C.
This project demonstrates the use of **structures, stack (linked list), file handling, and input validation**.

---

## 🚀 Features

* 🎥 Select from multiple movies
* 👤 User name input
* 📅 Date validation (dd/mm/yyyy)
* ⏰ Time validation (hh:mm)
* 🎟️ Book multiple tickets
* 💰 Automatic total calculation
* 📁 Stores bookings in a file (`bookings.txt`)
* 📦 Stack implementation using linked list

---

## 🛠️ Technologies Used

* C Programming Language
* Standard Libraries:

  * stdio.h
  * stdlib.h
  * string.h
  * ctype.h

---

## 📂 Project Structure

```
Movie-Booking-System/
│── main.c
│── bookings.txt (auto-generated)
│── README.md
```

---

## ▶️ How to Run

1. Compile the program:

```
gcc main.c -o booking
```

2. Run the program:

```
./booking
```

---

## 🧠 Concepts Used

* Structures (`struct`)
* Linked List (Stack implementation)
* File Handling (append mode)
* Input Validation
* Dynamic Memory Allocation (`malloc`)

---

## 📸 Sample Output

```
Welcome to the Movie Booking System!
Enter your name: John

Please select a movie:
1. Frozen - Rs.100.00
2. Dhurandar - The Revenge - Rs.120.00
3. Gudiya Patole - Rs.150.00

Enter your choice: 1
Enter date (dd/mm/yyyy): 12/05/2026
Enter time (hh:mm): 18:30
Enter the number of tickets: 2

====================
       TICKET
====================
Name: John
Date: 12/05/2026
Time: 18:30
Movie: Frozen
Tickets: 2
Total: Rs.200.00
====================
```

---

## 🔥 Future Improvements

* Add multiple bookings per session
* Show booking history
* Cancel tickets (pop from stack)
* GUI version (using C++ / Python)
* Login system for users

---

## 👩‍💻 Author

* Your Name

---

## ⭐ If you like this project

Give it a star ⭐ on GitHub!
