#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "constants.h"

#define N 40								// preprocessor directive to set the size of the evaluation table

/*
The program summarizes the results of the work quality assessments of 14 employees
and performs an analysis:
-the average of the assessments,
-how many employees received each assessment,
-calculates which assessment the employees received the most times and writes them out,
-calculates the median and
-draws a histogram of the number of individual groups.
*/

using namespace std;

void logError(const string& error) {
    ofstream logFile(Constants::LOG_FILE, ios::app);
    if (logFile) {
        time_t now = time(nullptr);
        logFile << ctime(&now) << error << endl;
    }
}

void displayHeader() {
    system("cls");
    cout << Constants::CYAN;
    cout << "+================================================+\n";
    cout << "|         Employee Work Quality Assessment         |\n";
    cout << "|            Created by Adrian Lesniak            |\n";
    cout << "+================================================+\n\n";
    cout << Constants::RESET;
}

void displayMenu() {
    cout << Constants::YELLOW;
    cout << "Available options:\n";
    cout << "1. Generate random grades\n";
    cout << "2. View all grades\n";
    cout << "3. Calculate statistics\n";
    cout << "4. Display histogram\n";
    cout << "5. Save grades to file\n";
    cout << "6. Load grades from file\n";
    cout << "0. Exit\n\n";
    cout << "Select option: ";
    cout << Constants::RESET;
}

double srednia_ocena( int *oceny, int n ) // take the pointer to the scoreboard and return the average of all the scores{
{
    double suma = 0;
    for(int i = 0; i < n; i++)
    {
        suma += oceny[i];
    }
    return suma/n;							// returned number of "double" type, n denoting the number of all evaluations}
}

void zliczenie_ocen( int ilosc_ocen[], int *oceny, int n )   // a function that counts the occurrence of individual values from the evaluation table in the "number of grades" table
{
    for(int i = 0; i < n; i++)
    {
        ilosc_ocen[ oceny[i] ]++;	// going through all the evaluations, we increase the quantity by 1 in a given position corresponding to it
    }
}

int najwieksza_ocena( int ilosc_ocen[] )  // the function determines the most frequently occurring evaluation
{
    int max_ = ilosc_ocen[0];             // variable to hold the largest value from the table, set to the value of 1 item
    for(int i = 1; i < 11; i++)
    {
        if( ilosc_ocen[i] > max_ )
        {
            max_ = ilosc_ocen[i];         // replace when next element is greater than max_
        }
    }
    return max_;					      // the most occurrence of scores is returned, not the value of the most frequent value itself
}

double mediana_ocen( int *oceny, int n )     // returns the median from the ordered array
{
    for(int i = 0; i < n; i++)                // sorted array using bubble sort algorithm
        for(int j = 1; j < n-i; j++)
            if(oceny[j-1] > oceny[j])      // checking on the fly if the element in the previous position is larger than the next one
            {
                int pom = oceny[j-1];      // using an auxiliary variable to swap two elements of an array
                oceny[j-1] = oceny[j];
                oceny[j] = pom;
            }
    return (double)(oceny[n/2] + oceny[n/2-1]) / 2;  // double median, as the arithmetic mean of the two middle elements
}

void histogram(int ilosc_ocen[], int n) {
    int najczestsza_ocena = najwieksza_ocena(ilosc_ocen) + 1;
    for(int i = 0; i < najczestsza_ocena; i++) {
        // Add proper spacing for numbers
        if (najczestsza_ocena-i < 10) cout << " ";
        cout << najczestsza_ocena-i << " ";
        
        for(int j = 0; j < 11; j++) {
            if(najczestsza_ocena - i > ilosc_ocen[j])
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << "   0 1 2 3 4 5 6 7 8 9 10" << endl;  // Added one more space at the start
}

void saveToFile(int* oceny, int n) {
    try {
        ofstream file(Constants::DATA_FILE);
        if (!file) throw runtime_error("Cannot open file for writing");
        
        for (int i = 0; i < n; i++) {
            file << oceny[i] << " ";
        }
    }
    catch (const exception& e) {
        logError(e.what());
        cout << Constants::MAGENTA << "Error: " << e.what() << Constants::RESET << endl;
    }
}

// Change the function signature to return the number of elements read
int loadFromFile(int* oceny) {
    try {
        ifstream file(Constants::DATA_FILE);
        if (!file) throw runtime_error("Cannot open file for reading");
        
        int count = 0;
        while (file >> oceny[count] && count < N) {
            count++;
        }
        return count;
    }
    catch (const exception& e) {
        logError(e.what());
        cout << Constants::MAGENTA << "Error: " << e.what() << Constants::RESET << endl;
        return 0;
    }
}

// Add new function to check if grades were generated
bool areGradesInitialized(const int* oceny, int n) {
    for(int i = 0; i < n; i++) {
        if(oceny[i] != 0) return true;
    }
    return false;
}

int main()
{
    int *oceny = new int[N];      // dynamic scoreboard
    int ilosc_ocen[11] = {0};     // Grade count table set to 0
    int choice;
    
    // Initialize grades array with zeros
    for(int i = 0; i < N; i++) {
        oceny[i] = 0;
    }
    
    do {
        displayHeader();
        displayMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                for(int i = 0; i < N; i++)     // drawing numbers from the range <0-10>
                {
                    oceny[i] = rand()%11;
                }
                cout << "Random grades generated." << endl;
                break;
            case 2:
                if(!areGradesInitialized(oceny, N)) {
                    cout << Constants::MAGENTA << "\nPlease generate grades first using option 1!" << Constants::RESET << endl;
                } else {
                    cout << "All grades given to employees:" << endl;
                    for(int i = 0; i < N; i++)
                    {
                        cout << oceny[i] << ", ";
                    }
                    cout << endl;
                }
                break;
            case 3:
                if(!areGradesInitialized(oceny, N)) {
                    cout << Constants::MAGENTA << "\nPlease generate grades first using option 1!" << Constants::RESET << endl;
                } else {
                    cout << "\nAverage grade given to employees: " << srednia_ocena(oceny, N) << endl;
                    zliczenie_ocen( ilosc_ocen, oceny, N );

                    cout << "The number of each grades:" << endl;
                    for(int i = 0; i < 11; i++)
                    {
                        cout << i << ": " << ilosc_ocen[i] << endl;
                    }

                    cout << "\nThe most frequently given grade: ";
                    for(int i = 0; i < 11; i++)
                    {
                        if( ilosc_ocen[i] == najwieksza_ocena(ilosc_ocen) )
                            cout << i << " ";           // find which number has occurred as many times as the function returns
                    }
                    cout << endl;

                    cout << "Median grades: " << mediana_ocen( oceny, N ) << endl;
                }
                break;
            case 4:
                if(!areGradesInitialized(oceny, N)) {
                    cout << Constants::MAGENTA << "\nPlease generate grades first using option 1!" << Constants::RESET << endl;
                } else {
                    cout << "\nHISTOGRAM" << endl << endl;
                    histogram(ilosc_ocen, N);
                }
                break;
            case 5:
                if(!areGradesInitialized(oceny, N)) {
                    cout << Constants::MAGENTA << "\nPlease generate grades first using option 1!" << Constants::RESET << endl;
                } else {
                    saveToFile(oceny, N);
                    cout << "Grades saved to file." << endl;
                }
                break;
            case 6:
                {
                    int count = loadFromFile(oceny);
                    if(count > 0) {
                        cout << "Grades loaded from file. Read " << count << " grades." << endl;
                    } else {
                        cout << "No grades were loaded from file." << endl;
                    }
                }
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
        
        if (choice != 0) {
            cout << "\nPress any key to continue...";
            _getch();
        }
    } while (choice != 0);
    
    delete[] oceny;
    return 0;
}
