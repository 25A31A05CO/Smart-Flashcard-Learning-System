# Smart Flashcard Learning System

A console-based flashcard application built in C++ that helps you study and memorize topics using digital flashcards.

---

## Features

- Add Flashcards — Create flashcards with subject, question, answer, and difficulty level
- View Flashcards — Display all saved flashcards
- Study Mode — Go through flashcards one by one and track your accuracy
- Search Flashcard — Search flashcards by subject or keyword
- Modify Flashcard — Edit an existing flashcard by ID
- Delete Flashcard — Remove a flashcard by ID
- Show Statistics — View total flashcards broken down by difficulty level
- Data Persistence — Flashcards are saved to `flashcards.txt` automatically

---

## Requirements

- Windows OS
- [MSYS2](https://www.msys2.org/) with g++ (ucrt64)
- Visual Studio Code (optional, for editing and debugging)

---

## Installation

### 1. Install MSYS2 and g++

Download and install MSYS2 from https://www.msys2.org

Open the MSYS2 UCRT64 terminal and run:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S mingw-w64-ucrt-x86_64-gdb
```

Add `C:\msys64\ucrt64\bin` to your Windows System PATH.

### 2. Clone or Download the Project

Place `flash.cpp` in a folder, for example:

```
C:\Projects\SMART FLASHCARD LEARNING SYSTEM\
```

---

## How to Compile

Open Command Prompt and navigate to the project folder:

```cmd
cd "C:\Projects\SMART FLASHCARD LEARNING SYSTEM"
C:\msys64\ucrt64\bin\g++.exe flash.cpp -o flash.exe
```

---

## How to Run

```cmd
cd "C:\Projects\SMART FLASHCARD LEARNING SYSTEM"
flash.exe
```

Or press **F5** in Visual Studio Code (with the provided `.vscode` configuration).

---

## VS Code Configuration

The project includes three VS Code config files inside `.vscode/`:

| File | Purpose |
|---|---|
| `tasks.json` | Builds `flash.cpp` using g++ |
| `launch.json` | Runs and debugs `flash.exe` using GDB |
| `c_cpp_properties.json` | Configures IntelliSense for MSYS2 g++ |

---

## Usage

When you run the program, a menu appears:

```
====================================================
        SMART FLASHCARD LEARNING SYSTEM
====================================================
1. Add Flashcard
2. View Flashcards
3. Study Flashcards
4. Search Flashcard
5. Modify Flashcard
6. Delete Flashcard
7. Show Statistics
8. Exit
```

Enter the number corresponding to your choice and follow the prompts.

### Difficulty Levels

| Level | Category |
|---|---|
| 1 - 2 | Easy |
| 3 | Medium |
| 4 - 5 | Hard |

---

## Data Storage

Flashcards are automatically saved to `flashcards.txt` in the project folder every time you add, modify, or delete a card. The file is loaded automatically on startup.

---

## Project Structure

```
SMART FLASHCARD LEARNING SYSTEM/
├── flash.cpp           # Main source code
├── flash.exe           # Compiled executable
├── flashcards.txt      # Data file (auto-generated)
├── README.md           # This file
└── .vscode/
    ├── tasks.json
    ├── launch.json
    └── c_cpp_properties.json
```

---

## Author

Smart Flashcard Learning System — C++ Console Application
