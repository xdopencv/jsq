#include <stdio.h>
#include <math.h>

// Function prototypes
void add();
void subtract();
void multiply();
void divide();
void power();
void square_root();
void trigonometric_functions();
void absolute_value();
void logarithm();

int main() {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Power\n");
        printf("6. Square Root\n");
        printf("7. Trigonometric Functions\n");
        printf("8. Absolute Value\n");
        printf("9. Logarithm\n");
        printf("10. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: power(); break;
            case 6: square_root(); break;
            case 7: trigonometric_functions(); break;
            case 8: absolute_value(); break;
            case 9: logarithm(); break;
            case 10: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 10);
    return 0;
}

void add() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf\n", a + b);
}

void subtract() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf\n", a - b);
}

void multiply() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    printf("Result: %.2lf\n", a * b);
}

void divide() {
    double a, b;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &a, &b);
    if (b != 0)
        printf("Result: %.2lf\n", a / b);
    else
        printf("Error: Division by zero!\n");
}

void power() {
    double base, exp;
    printf("Enter base and exponent: ");
    scanf("%lf %lf", &base, &exp);
    printf("Result: %.2lf\n", pow(base, exp));
}

void square_root() {
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);
    if (number >= 0)
        printf("Result: %.2lf\n", sqrt(number));
    else
        printf("Error: Negative number!\n");
}

void trigonometric_functions() {
    double angle;
    printf("Enter angle in degrees: ");
    scanf("%lf", &angle);
    angle = angle * (M_PI / 180); // Convert to radians
    printf("sin: %.2lf\n", sin(angle));
    printf("cos: %.2lf\n", cos(angle));
    printf("tan: %.2lf\n", tan(angle));
}

void absolute_value() {
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);
    printf("Result: %.2lf\n", fabs(number));
}

void logarithm() {
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);
    if (number > 0)
        printf("Result: %.2lf\n", log(number));
    else
        printf("Error: Number must be positive!\n");
}