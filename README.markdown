# Employee Grade Analyzer

## Description
A C++ console application for analyzing work quality grades of 14 employees. Generates random grades (0-10), calculates averages, medians, and most frequent grades, and displays histograms. Supports file I/O and error logging. Created by Adrian Lesniak.

## Features
- Generate random grades for 40 evaluations
- Calculate average and median grades
- Count occurrences of each grade
- Identify most frequent grades
- Display grade histogram
- Save/load grades to/from file
- Colorful console interface
- Error logging to file

## Requirements
- C++ compiler (e.g., g++)
- Header file: `constants.h` (not provided)
- Windows OS (uses `windows.h` and `conio.h`)

## Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
2. Ensure `constants.h` is in the project directory.
3. Compile the program:
   ```bash
   g++ main.cpp -o employee_grade_analyzer
   ```

## Usage
1. Run the program:
   ```bash
   ./employee_grade_analyzer
   ```
2. Choose options 0-6 from the menu:
   - 1: Generate random grades
   - 2: View all grades
   - 3: Calculate statistics (average, grade counts, most frequent, median)
   - 4: Display histogram
   - 5: Save grades to file
   - 6: Load grades from file
   - 0: Exit
3. Grades are saved to a file defined in `constants.h` (e.g., `DATA_FILE`).

## Notes
- Requires `constants.h` for color codes, file paths (e.g., `LOG_FILE`, `DATA_FILE`), and other constants.
- Supports 40 evaluations (defined by `N`).
- Errors are logged to a file specified in `constants.h`.
- Histogram displays grade distribution visually.

## Author
Adrian Lesniak

## License
MIT License