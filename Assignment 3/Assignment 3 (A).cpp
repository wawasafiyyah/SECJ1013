// NAME: WARDINA SAFIAH BINTI HARUN
// MATRIC NUMBER: A24CS0209
// DATE: 10/1/2025

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
void getInput(const string&, string[], int[], int[], int[], int&);
int calTotal(const int[], int);
int getLowest(const int[], int);
int getHighest(const int[], int);
void writeOutput(const string&, const string[], const int[], const int[], const int[], int);

int main() {

    // Arrays to store university information
    const int MAX_SIZE = 100;
    string universities[MAX_SIZE];
    int intake[MAX_SIZE], enrolment[MAX_SIZE], output[MAX_SIZE];
    int size = 0;

    // Read input from file
    const string inputFile = "input.txt";
    const string outputFile = "output.txt";
    getInput(inputFile, universities, intake, enrolment, output, size);

    // Write the report to the output file
    writeOutput(outputFile, universities, intake, enrolment, output, size);

    return 0;
}

// Task 1
void getInput(const string &filename, string universities[], int intake[], int enrolment[], int output[], int &size) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cout << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    while (inputFile >> universities[size] >> intake[size] >> enrolment[size] >> output[size]) {
        size++;
    }

    inputFile.close();
}



// Task 2
int calTotal(const int array[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += array[i];
    }
    return total;
}

// Task 3
int getLowest(const int array[], int size) {
    int lowIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] < array[lowIndex]) {
            lowIndex = i;
        }
    }
    return lowIndex;
}

// Task 4
int getHighest(const int array[], int size) {
    int highIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > array[highIndex]) {
            highIndex = i;
        }
    }
    return highIndex;
}



// Task 5
void writeOutput(const string &filename, const string universities[], const int intake[], const int enrolment[], const int output[], int size) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cout << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    // Output table header
    outputFile << "        NUMBER OF STUDENTS' INTAKE, ENROLMENT AND OUTPUT\n";
    outputFile << "                IN PUBLIC UNIVERSITIES (2023)\n\n";
    outputFile << string(70, '-') << "\n";
    outputFile << " UNIVERSITY             INTAKE       ENROLMENT        OUTPUT\n";
    outputFile << string(70, '-') << "\n";

    for (int i = 0; i < size; ++i) {
        outputFile << "     "
                   << left 
                   << setw(15) << universities[i]
                   << right 
                   << setw(10) << intake[i]
                   << setw(16) << enrolment[i]
                   << setw(14) << output[i] << "\n";
    }

    outputFile << string(70, '-') << "\n";

    // Task 6
    // Calculate totals and averages
    int totalIntake = calTotal(intake, size);
    int totalEnrolment = calTotal(enrolment, size);
    int totalOutput = calTotal(output, size);

    double avgIntake = static_cast<double>(totalIntake) / size;
    double avgEnrolment = static_cast<double>(totalEnrolment) / size;
    double avgOutput = static_cast<double>(totalOutput) / size;

    outputFile << "     TOTAL" 
               << setw(20) << totalIntake
               << setw(16) << totalEnrolment
               << setw(14) << totalOutput << "\n";
    outputFile << "     AVERAGE" 
               << fixed << setprecision(2) 
               << setw(18) << avgIntake
               << setw(16) << avgEnrolment
               << setw(14) << avgOutput << "\n";
    outputFile << string(70, '-') << "\n";

    // Task 7
    // Highest and lowest values
    int lowestIntake = getLowest(intake, size);
    int highestIntake = getHighest(intake, size);

    int lowestEnrolment = getLowest(enrolment, size);
    int highestEnrolment = getHighest(enrolment, size);

    int lowestOutput = getLowest(output, size);
    int highestOutput = getHighest(output, size);

    outputFile << " THE LOWEST NUMBER OF STUDENTS' INTAKE    = " << intake[lowestIntake] << " (" << universities[lowestIntake] << ")\n";
    outputFile << " THE LOWEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[lowestEnrolment] << " (" << universities[lowestEnrolment] << ")\n";
    outputFile << " THE LOWEST NUMBER OF STUDENTS' OUTPUT    = " << output[lowestOutput] << " (" << universities[lowestOutput] << ")\n\n";

    outputFile << " THE HIGHEST NUMBER OF STUDENTS' INTAKE    = " << intake[highestIntake] << " (" << universities[highestIntake] << ")\n";
    outputFile << " THE HIGHEST NUMBER OF STUDENTS' ENROLMENT = " << enrolment[highestEnrolment] << " (" << universities[highestEnrolment] << ")\n";
    outputFile << " THE HIGHEST NUMBER OF STUDENTS' OUTPUT    = " << output[highestOutput] << " (" << universities[highestOutput] << ")\n\n";

    // Calculate ranges
    int rangeIntake = intake[highestIntake] - intake[lowestIntake];
    int rangeEnrolment = enrolment[highestEnrolment] - enrolment[lowestEnrolment];
    int rangeOutput = output[highestOutput] - output[lowestOutput];

    outputFile << " THE RANGE OF NUMBER OF STUDENTS' INTAKE    = " << rangeIntake << "\n";
    outputFile << " THE RANGE OF NUMBER OF STUDENTS' ENROLMENT = " << rangeEnrolment << "\n";
    outputFile << " THE RANGE OF NUMBER OF STUDENTS' OUTPUT    = " << rangeOutput << "\n";

    outputFile << string(70, '-') << "\n";

    outputFile.close();
}
