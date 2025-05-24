# 📊📈 Employee Performance Analyzer Pro 🏆
_A C++ console tool for insightful analysis of employee work quality grades, featuring statistics, histograms, and file operations._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📝 Project Description

**Employee Performance Analyzer Pro** is a robust C++ console application designed to assist in evaluating and understanding employee work quality. The program generates or loads a set of work quality grades (typically for a series of evaluations), then provides comprehensive statistical analysis including averages, medians, and the most frequent grades. A key feature is its ability to visually represent grade distribution through a histogram. The application also supports saving and loading grade data to/from files and includes error logging for reliable operation. Its colorful user interface makes data interpretation more accessible.

## ✨ Key Features

*   🎲 **Random Grade Generation**: Simulate work quality grades (0-10) for a defined number of evaluations (e.g., 40).
*   📊 **Statistical Analysis**:
    *   Calculate the **average** grade.
    *   Determine the **median** grade.
    *   Count **occurrences** of each grade (0-10).
    *   Identify the **most frequent** grade(s) (mode).
*   📉 **Grade Histogram**: Visually display the distribution of grades, offering a quick understanding of performance trends.
*   💾 **File Input/Output**:
    *   Save the current set of grades to a data file.
    *   Load previously saved grades from a data file.
*   🌈 **Colorful Console Interface**: Enhanced user experience with colored text output for better readability (Windows-specific).
*   📄 **Error Logging**: Log any operational errors to a dedicated file for troubleshooting.
*   📋 **Menu-Driven Operation**: Easy-to-use menu for accessing different functionalities.

## 🖼️ Screenshots

**Coming soon!**

_In the future, screenshots showcasing the menu, statistical output, and histogram will be added here._

## ⚙️ System Requirements

*   **Operating System**: Windows (due to the use of `windows.h` for console color manipulation and `conio.h` for functions like `_getch()`).
*   **C++ Compiler**: Any modern C++ compiler that supports C++11 or newer (e.g., g++, MinGW, Clang, MSVC).
*   📄 **`constants.h` Header File (User-Provided)**: This project **requires** a header file named `constants.h`. **This file is not included in the repository and must be created by the user.** It should define essential constants used throughout the program. See the "Installation and Running" section for more details on what to include.

## 🛠️ Installation and Running

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    ```
    (Replace `<repository-url>` with the actual URL of your repository)

2.  **Navigate to the Project Directory**:
    ```bash
    cd <repository-directory>
    ```
    (Replace `<repository-directory>` with the name of the cloned folder)

3.  **Create `constants.h`**:
    Before compiling, you **must** create a file named `constants.h` in the project's root directory. This file should define necessary constants. Here's an example of what it might contain:
    ```cpp
    #ifndef CONSTANTS_H
    #define CONSTANTS_H

    // Example: Number of evaluations/grades to process
    const int N_EVALUATIONS = 40; // Or any other number as per your design

    // Example: File paths
    #define DATA_FILE_PATH "grades_data.dat"
    #define LOG_FILE_PATH "analyzer_errors.log"

    // Example: Console Color Codes (Windows-specific)
    // These values might correspond to SetConsoleTextAttribute arguments
    const int CLR_DEFAULT = 7;
    const int CLR_MENU_HEADER = 11; // Light Cyan
    const int CLR_HIGHLIGHT = 14;   // Yellow
    const int CLR_ERROR = 12;       // Light Red
    // Add other color codes as needed by your program

    // Other constants your program might need
    // const int MAX_GRADE = 10;
    // const int MIN_GRADE = 0;

    #endif // CONSTANTS_H
    ```
    *Adjust the constants (especially file paths and `N_EVALUATIONS`) to fit your program's logic.*

4.  **Compile the Program**:
    Open a terminal (like Command Prompt or PowerShell) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ main.cpp -o employee_grade_analyzer.exe -static-libgcc -static-libstdc++
    ```
    *(Assuming your main source code file is `main.cpp` and it includes `constants.h`)*

5.  **Run the Application**:
    After successful compilation, execute the generated program:
    ```bash
    ./employee_grade_analyzer.exe
    ```
    or simply in CMD:
    ```bash
    employee_grade_analyzer.exe
    ```

## ▶️ How to Use

Upon running the application, you will be presented with a main menu. Enter the number corresponding to your desired action:

*   **1: Generate random grades**: Fills the data set with randomly generated grades (0-10) for the defined number of evaluations.
*   **2: View all grades**: Displays all current grades in the data set.
*   **3: Calculate statistics**: Computes and displays:
    *   Average grade
    *   Count of each grade (0-10)
    *   Most frequent grade(s)
    *   Median grade
*   **4: Display histogram**: Shows a text-based histogram representing the frequency distribution of grades.
*   **5: Save grades to file**: Saves the current set of grades to the data file specified in `constants.h` (e.g., `DATA_FILE_PATH`).
*   **6: Load grades from file**: Loads grades from the data file into the application, overwriting any current data.
*   **0: Exit**: Terminates the application.

## 💡 Technical Details & Program Logic

*   **Grade Generation**: Uses C++ random number generation (seeded, typically with `time(NULL)`) to produce grades within the 0-10 range for `N_EVALUATIONS`.
*   **Statistical Calculations**: Implements standard algorithms for calculating mean (average), median (middle value in a sorted set), and mode (most frequent value). Grade occurrences are counted using an array or map.
*   **Histogram Display**: Generates a simple text-based bar chart in the console, where the length or height of bars (often made of characters like `*` or `#`) represents the frequency of each grade.
*   **File Operations**: Utilizes C++ file streams (`fstream`) to read from and write grade data to a binary or text file, as defined by `DATA_FILE_PATH` in `constants.h`.
*   **Error Logging**: Writes error messages (e.g., file open failures) to a log file, specified by `LOG_FILE_PATH` in `constants.h`, often with timestamps.
*   **Console Manipulation**: Employs Windows-specific functions from `windows.h` (like `SetConsoleTextAttribute`) for colored output and `conio.h` (like `_getch()`) for simple keypress handling.
*   **`constants.h`**: This user-provided header is crucial for defining program-wide constants, making the code more maintainable and configurable (e.g., number of evaluations, file names, color codes).

## 🤝 Contributing

Contributions to the **Employee Performance Analyzer Pro** are welcome! If you'd like to suggest improvements, add new analytical features, or refine existing ones:

1.  Fork the repository.
2.  Create a new branch for your changes: `git checkout -b feature/your-analytical-idea`
3.  Implement your changes and commit them: `git commit -m "Feature: Implement your analytical idea"`
4.  Push your changes to your branch: `git push origin feature/your-analytical-idea`
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to the existing style.

## ✍️ Author

**Adrian Lesniak**
_C++ Developer & Data Analysis Enthusiast_

(You can add a link to your GitHub/LinkedIn profile, e.g., `[Adrian Lesniak](https://github.com/yourusername)`)

## 📃 License

This project is licensed under the **MIT License**.
The full text of the license is available at: [https://opensource.org/licenses/MIT](https://opensource.org/licenses/MIT)

---
🔍 _Unlock insights from data to foster growth and excellence!_
