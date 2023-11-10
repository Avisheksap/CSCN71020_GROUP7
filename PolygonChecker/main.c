// CSCN71020-GROUP7

#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include "triangleSolver.h"
#include <math.h>

#define M_PI 3.14159265358979323846

int main() {
    double side1, side2, side3, angle1, angle2, angle3;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    bool continueProgram = true;
    while (continueProgram) {
        printWelcome();

        int shapeChoice = printShapeMenu();

        switch (shapeChoice) {
        case 1:
            printf_s("Triangle selected.\n");
            getTriangleInfo(&side1, &side2, &side3);
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);
            char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);
            printf_s("%s\n", result);
            if (strcmp(result, "Not a triangle") != 0) {
                printf_s("Inside angles (in degrees): %.2lf, %.2lf, %.2lf\n",
                    angle1 * (180.0 / M_PI), angle2 * (180.0 / M_PI), angle3 * (180.0 / M_PI));
            }
            break;
        case 2:
            printf_s("Rectangle selected.\n");
            getRectangleInfo(&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
            char* rectangleResult = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
            printf_s("%s\n", rectangleResult);
            if (strcmp(rectangleResult, "Rectangle") == 0) {
                double perimeter = calculateRectanglePerimeter(x1, y1, x2, y2, x3, y3, x4, y4);
                double area = calculateRectangleArea(x1, y1, x2, y2, x3, y3, x4, y4);
                printf_s("Perimeter: %.2lf\n", perimeter);
                printf_s("Area: %.2lf\n", area);
            }
            break;
        case 0:
            continueProgram = false;
            break;
        default:
            printf_s("Invalid value entered.\n");
            break;
        }
    }
    return 0;
}

void printWelcome() {
    printf_s("\n");
    printf_s(" **********************\n");
    printf_s("**     Welcome to     **\n");
    printf_s("**   Polygon Checker  **\n");
    printf_s(" **********************\n");
}

int printShapeMenu() {
    printf_s("1. Triangle\n");
    printf_s("2. Rectangle\n");  // Added Rectangle option
    printf_s("0. Exit\n");

    int shapeChoice;

    printf_s("Enter number:");
    scanf_s("%d", &shapeChoice);  // Using %d to read an integer

    return shapeChoice;
}


// Function to get the triangle sides and compute angles
void getTriangleInfo(double* side1, double* side2, double* side3) {
    while (1) {
        printf_s("Enter the three side lengths of the triangle:\n");

        // Reading and validating the input for triangle sides
        if (scanf_s("%lf %lf %lf", side1, side2, side3) == 3) {
            // Check if the sides are positive
            if (*side1 <= 0 || *side2 <= 0 || *side3 <= 0) {
                printf_s("Side lengths must be positive. Please try again.\n");
            }
            else {
                break; // Valid side lengths entered
            }
        }
        else {
            printf_s("Invalid input. Please enter three numeric values separated by spaces.\n");

            // Clearing the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}