// NAME (1) : NURIN HAZWANI BINTI HUSSIN
// MATRIC NUMBER (1) : A24CS0171

// NAME (2) : WARDINA SAFIAH BINTI HARUN
// MATRIC NUMBER (2) : A24CS0209

// DATE : 28 DECEMBER 2024


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// Function to calculate monthly installment
double calculateMonthlyInstallment(double price, double downPayment, double interestRate, int years) {
    double principal = price - downPayment; // Loan amount
    double interest = (principal * interestRate * years) / 100; // Interest
    int totalMonths = years * 12; // Total months
    return (ceil(principal + interest) / totalMonths);
}

// Helper function to select variant and region
void selectVariantAndRegion(int basePrice1, int basePrice2, string variant1, string variant2,
                            int &price, string &variantName, string &paintType, string &regionName) {
    int variant, region;

    do {
        // Input: Variant
        cout << "Variants [1- " << variant1 << ", 2- " << variant2 << "]: ";
        cin >> variant;
        variantName = (variant == 1) ? variant1 : (variant == 2) ? variant2 : "Invalid";
        paintType = (variant == 1) ? "Solid" : (variant == 2) ? "Metallic" : "Invalid";
        price = (variant == 1) ? basePrice1 : (variant == 2) ? basePrice2 : 0;

        // Input: Region
        cout << "Region [1- Peninsular Malaysia, 2- East Malaysia]: ";
        cin >> region;
        regionName = (region == 1) ? "Peninsular Malaysia" : (region == 2) ? "East Malaysia" : "Invalid";

        // Adjust price for East Malaysia if region is valid
        if (region == 2) price += 2000;

        if (variantName == "Invalid" || regionName == "Invalid") {
            cout << "Invalid input. Please try again.\n";
        }
    } while (variantName == "Invalid" || regionName == "Invalid");
}


// Function for X50 pricing
void priceX50(int &price, string &variantName, string &paintType, string &regionName) {
    selectVariantAndRegion(86300, 101800, "1.5T Standard", "1.5T Premium", price, variantName, paintType, regionName);
}

// Function for Exora pricing
void priceExora(int &price, string &variantName, string &paintType, string &regionName) {
    selectVariantAndRegion(64600, 71800, "1.6T Executive CVT", "1.6T Premium CVT", price, variantName, paintType, regionName);
}

// Function for Persona pricing
void pricePersona(int &price, string &variantName, string &paintType, string &regionName) {
    selectVariantAndRegion(47800, 54600, "1.6L Standard CVT", "1.6L Premium CVT", price, variantName, paintType, regionName);
}

int main() {
    int model, years, price = 0;
    double downPayment, interestRate;
    string modelName, variantName, paintType, regionName;

    do {
        // Input: Car Model
        cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
        cin >> model;

        // Assigning Model Name and Price
        switch (model) {
            case 1: modelName = "X50";
                    priceX50(price, variantName, paintType, regionName);
                    break;
            case 2: modelName = "Exora";
                    priceExora(price, variantName, paintType, regionName);
                    break;
            case 3: modelName = "Persona";
                    pricePersona(price, variantName, paintType, regionName);
                    break;
            default: cout << "Invalid Model!\n";
                     continue;
        }

        // Display Car Info
        cout << "\nCar Info\n";
        cout << "Model: " << modelName << "\n";
        cout << "Variant: " << variantName << "\n";
        cout << "Region: " << regionName << "\n";
        cout << "Paint Type: " << paintType << "\n";
        cout << "Price (MYR): " << fixed << setprecision(2) << price << "\n";

        // Input: Down Payment, Interest Rate, Repayment Period
        cout << "\nEnter financial details:\n";
        cout << "Down Payment (MYR): ";
        cin >> downPayment;
        cout << "Interest Rate (%): ";
        cin >> interestRate;
        cout << "Repayment period (in years): ";
        cin >> years;

        // Calculate Monthly Installment
        double monthlyInstallment = calculateMonthlyInstallment(price, downPayment, interestRate, years);

        // Output
        cout << "\nMONTHLY INSTALLMENT (MYR): " << fixed << setprecision(2) << monthlyInstallment << "\n";

        // Prompt to continue or exit
        char choice;
        do {
        cout << "Do you want to enter other data? [Y @ N]: ";
        cin >> choice;
        if (toupper(choice) == 'Y'){
            break;
        } else if (toupper(choice) == 'N'){
            cout << "Thank you :)\n";
            return 0;
            } 
        } while (true);

    } while (true);

    system ("pause");
    return 0;
}