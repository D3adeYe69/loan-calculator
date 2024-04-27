#include <stdio.h>
#include <stdlib.h>

// Define loan calculation function
float calculateLoan(float price, int loanType, int bankChoice, int loanTermMonths) {
    float interestRate;
    float maxLoanAmount;
    float minLoanAmount;
    int minLoanTermMonths = 6;
    int maxLoanTermMonths;

    // Bank A (MAIB) - Credit Express
    if (bankChoice == 1) {
        // Credit Express loan details for MAIB
        maxLoanAmount = 300000; // Maximum loan amount
        maxLoanTermMonths = 60; // Maximum loan term
        if (price < minLoanAmount || price > maxLoanAmount) {
            printf("Loan amount for Credit Express at MAIB must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
            return -1; // Return -1 to indicate invalid loan amount
        }
        if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
            printf("Loan term for Credit Express at MAIB must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
            return -1; // Return -1 to indicate invalid loan term
        }
        interestRate = 0.095; // 9.5% annual interest rate for Credit Express at MAIB
    }
    // Bank B (OtpBank) - Credit de Nevoi Personale
 
    // Bank B (Second Bank) - Credit de Nevoi Personale
    else if (bankChoice == 2) {
        if (loanType == 3) { // Credit de Nevoi Personale ONLINE
            maxLoanAmount = 100000; // Maximum loan amount for ONLINE loan
            minLoanAmount = 1000; // Minimum loan amount for ONLINE loan
            maxLoanTermMonths = 60; // Maximum loan term for ONLINE loan
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for ONLINE loan must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; // Return -1 to indicate invalid loan amount
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for ONLINE loan must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; // Return -1 to indicate invalid loan term
            }
            interestRate = 0.0999; // 9.99% annual interest rate for ONLINE loan
        } else if (loanType == 4) { // Credit de Nevoi Personale
            maxLoanAmount = 150000; // Maximum loan amount for variable interest rate loan
            minLoanAmount = 1000; // Minimum loan amount for variable interest rate loan
            maxLoanTermMonths = 60; // Maximum loan term for variable interest rate loan
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for variable interest rate loan must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; // Return -1 to indicate invalid loan amount
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for variable interest rate loan must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; // Return -1 to indicate invalid loan term
            }
            // Calculate interest rate based on loan amount
            if (price <= 10000) {
                interestRate = 0.0699; // 6.99% for loan amount <= 10000
            } else if (price > 10000 && price <= 50000) {
                interestRate = 0.0999; // 9.99% for loan amount > 10000 and <= 50000
            } else {
                interestRate = 0.1999; // 19.99% for loan amount > 50000
            }
        } else {
            printf("Invalid loan type for Bank B.\n");
            return -1; // Return -1 to indicate invalid loan type
        }
    }
    // Bank C (VictoriaBank)
    else if (bankChoice == 3) {
        // Credit Garantat de consum, Credit Negarantat de consum, Credit Express
        if (loanType == 5) { // Credit Garantat de consum
            maxLoanAmount = 1800000; // Maximum loan amount
            minLoanAmount = 0; // Minimum loan amount
            maxLoanTermMonths = 60; // Maximum loan term
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for Credit Garantat de consum at VictoriaBank must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; // Return -1 to indicate invalid loan amount
            }
            if (loanTermMonths < 13 || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for Credit Garantat de consum at VictoriaBank must be between 13 and %d months.\n", maxLoanTermMonths);
                return -1; // Return -1 to indicate invalid loan term
            }
            interestRate = 0.085; // 8.5% annual interest rate for Credit Garantat de consum at VictoriaBank
        } else if (loanType == 6) { // Credit Negarantat de consum
            maxLoanAmount = 300000; // Maximum loan amount
            minLoanAmount = 0; // Minimum loan amount
            maxLoanTermMonths = 60; // Maximum loan term
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for Credit Negarantat de consum at VictoriaBank must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; // Return -1 to indicate invalid loan amount
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for Credit Negarantat de consum at VictoriaBank must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; // Return -1 to indicate invalid loan term
            }
            interestRate = 0.105; // 10.5% annual interest rate for Credit Negarantat de consum at VictoriaBank
        } else if (loanType == 7) { // Credit Express
            maxLoanAmount = 300000; // Maximum loan amount
            minLoanAmount = 1000; // Minimum loan amount
            maxLoanTermMonths = 60; // Maximum loan term
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for Credit Express at VictoriaBank must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; // Return -1 to indicate invalid loan amount
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for Credit Express at VictoriaBank must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; // Return -1 to indicate invalid loan term
            }
            interestRate = 0.098; // 9.5% annual interest rate for Credit Express at VictoriaBank
        } else {
            printf("Invalid loan type for VictoriaBank.\n");
            return -1; // Return -1 to indicate invalid loan type
        }
    } else {
        printf("Bank not found.\n");
        return -1; // Return -1 to indicate bank not found
    }

    // Apply interest rate and calculate total loan
    float totalLoan = price * (1 + (interestRate * loanTermMonths / 12.0));
    return totalLoan;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <price> <loanType> <bankChoice> <loanTermMonths>\n", argv[0]);
        return 1;
    }

    float price = atof(argv[1]);  // Convert price argument to float
    int loanType = atoi(argv[2]);
    int bankChoice = atoi(argv[3]);
    int loanTermMonths = atoi(argv[4]);

    if (price <= 0 || (bankChoice != 1 && bankChoice != 2 && bankChoice != 3) ||
        (loanType != 1 && loanType != 2 && loanType != 3 && loanType != 4 && loanType != 5 && loanType != 6 && loanType !=7) ||
        loanTermMonths <= 0) {
        printf("Invalid input values. Please provide valid inputs.\n");
        return 1;
    }

    // Calculate total loan amount based on input values
    float totalLoan = calculateLoan(price, loanType, bankChoice, loanTermMonths);

    if (totalLoan == -1) {
        printf("Loan calculation failed.\n");
        return 1;
    }

    float monthlyPayment = totalLoan / loanTermMonths;

    // Display the loan calculation results
    printf("Total Loan Amount: %.2f\n", totalLoan);
    printf("Monthly Payment: %.2f\n", monthlyPayment);

    return 0;
}
