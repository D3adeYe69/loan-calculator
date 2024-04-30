#include <stdio.h>
#include <stdlib.h>


float calculateLoan(float price, int loanType, int bankChoice, int loanTermMonths) {
    float interestRate;
    float maxLoanAmount;
    float minLoanAmount;
    int minLoanTermMonths = 6;
    int maxLoanTermMonths;

    
    if (bankChoice == 1) {
        
        maxLoanAmount = 300000; 
        maxLoanTermMonths = 60; 
        if (price < minLoanAmount || price > maxLoanAmount) {
            printf("Loan amount for Credit Express at MAIB must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
            return -1; 
        }
        if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
            printf("Loan term for Credit Express at MAIB must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
            return -1; 
        }
        interestRate = 0.095; 
    }
    
 
    
    else if (bankChoice == 2) {
        if (loanType == 3) { 
            maxLoanAmount = 100000; 
            minLoanAmount = 1000; 
            maxLoanTermMonths = 60; 
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for ONLINE loan must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; 
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for ONLINE loan must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; 
            }
            interestRate = 0.0999; 
        } else if (loanType == 4) { 
            maxLoanAmount = 150000; 
            minLoanAmount = 1000; 
            maxLoanTermMonths = 60; 
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for variable interest rate loan must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; 
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for variable interest rate loan must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; 
            }
            
            if (price <= 10000) {
                interestRate = 0.0699; 
            } else if (price > 10000 && price <= 50000) {
                interestRate = 0.0999; 
            } else {
                interestRate = 0.1999; 
            }
        } else {
            printf("Invalid loan type for Bank B.\n");
            return -1; 
        }
    }
  
    else if (bankChoice == 3) {
       
        if (loanType == 5) { 
            maxLoanAmount = 1800000; 
            minLoanAmount = 0; 
            maxLoanTermMonths = 60; 
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for Credit Garantat de consum at VictoriaBank must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; 
            }
            if (loanTermMonths < 13 || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for Credit Garantat de consum at VictoriaBank must be between 13 and %d months.\n", maxLoanTermMonths);
                return -1; 
            }
            interestRate = 0.085; 
        } else if (loanType == 6) { 
            maxLoanAmount = 300000; 
            minLoanAmount = 0; 
            maxLoanTermMonths = 60; 
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for Credit Negarantat de consum at VictoriaBank must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; 
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for Credit Negarantat de consum at VictoriaBank must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; 
            }
            interestRate = 0.105; 
        } else if (loanType == 7) { 
            maxLoanAmount = 300000; 
            minLoanAmount = 1000; 
            maxLoanTermMonths = 60; 
            if (price < minLoanAmount || price > maxLoanAmount) {
                printf("Loan amount for Credit Express at VictoriaBank must be between %.2f and %.2f.\n", minLoanAmount, maxLoanAmount);
                return -1; 
            }
            if (loanTermMonths < minLoanTermMonths || loanTermMonths > maxLoanTermMonths) {
                printf("Loan term for Credit Express at VictoriaBank must be between %d and %d months.\n", minLoanTermMonths, maxLoanTermMonths);
                return -1; 
            }
            interestRate = 0.098; 
        } else {
            printf("Invalid loan type for VictoriaBank.\n");
            return -1; 
        }
    } else {
        printf("Bank not found.\n");
        return -1; 
    }

    
    float totalLoan = price * (1 + (interestRate * loanTermMonths / 12.0));
    return totalLoan;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <price> <loanType> <bankChoice> <loanTermMonths>\n", argv[0]);
        return 1;
    }

    float price = atof(argv[1]);  
    int loanType = atoi(argv[2]);
    int bankChoice = atoi(argv[3]);
    int loanTermMonths = atoi(argv[4]);

    if (price <= 0 || (bankChoice != 1 && bankChoice != 2 && bankChoice != 3) ||
        (loanType != 1 && loanType != 2 && loanType != 3 && loanType != 4 && loanType != 5 && loanType != 6 && loanType !=7) ||
        loanTermMonths <= 0) {
        printf("Invalid input values. Please provide valid inputs.\n");
        return 1;
    }

    
    float totalLoan = calculateLoan(price, loanType, bankChoice, loanTermMonths);

    if (totalLoan == -1) {
        printf("Loan calculation failed.\n");
        return 1;
    }

    float monthlyPayment = totalLoan / loanTermMonths;

    
    printf("Total Loan Amount: %.2f\n", totalLoan);
    printf("Monthly Payment: %.2f\n", monthlyPayment);

    return 0;
}
