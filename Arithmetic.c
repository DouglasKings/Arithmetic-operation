#include <stdio.h>//Header file containing input/output operations

// Function prototype declaration
double arithmeticOperation(double firstNumber, double secondNumber, char Operator);

int main() {
    // Declare variables to hold user inputs and calculation result
    double firstNumber, secondNumber, Calculation;
    char Operator;

    // Prompt the user to enter two numbers and an arithmetic operation
    printf("Enter the first number: ");
    scanf("%lf", &firstNumber);
    printf("Enter the second number: ");
    scanf("%lf", &secondNumber);
    printf("Enter the arithmetic operation (+, -, *, /, %): ");
    scanf(" %c", &Operator); 

    // Call the arithmeticOperation function with the entered values
    Calculation = arithmeticOperation(firstNumber, secondNumber, Operator);

    // Display the entered numbers and the result of the operation
    if(Calculation == -1){
        printf("An error occurred during the operation. Please check the operator and try again.\n");
    }
    else{
        printf("The first number is %.2f\n", firstNumber);
        printf("The second number is %.2f\n", secondNumber);
        printf("The arithmetic operation is %.2f\n", Calculation);
    }

    return 0;
}

// Function definition to perform arithmetic operations based on the operator
double arithmeticOperation(double firstNumber, double secondNumber, char Operator) {
    double result; // Variable to store the result of the operation

    // Use a switch statement to select the operation based on the operator character
    switch (Operator) {
        case '+': // Addition
            result = firstNumber + secondNumber;
            break;
        case '-': // Subtraction
            result = firstNumber - secondNumber;
            break;
        case '*': // Multiplication
            result = firstNumber * secondNumber;
            break;
        case '/': // Division
            if (secondNumber != 0) { // Check for division by zero
                result = firstNumber / secondNumber;
            } else {
                printf("Error! Division by zero is not allowed.\n");
                return -1;
            }
            break;
        case '%': // Modulus
            if (secondNumber != 0) { // Check for modulus by zero
                result = (int)firstNumber % (int)secondNumber; // Casting to int for modulus operation
            } else {
                printf("Error! Modulus operation by zero is not defined.\n");
                return -1;
            }
            break;
        default: // Invalid operator
            printf("Invalid operator!\n");
            return -1;
            break;
    }

    return result; // Return the result of the operation
}
