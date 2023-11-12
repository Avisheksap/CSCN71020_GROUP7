// CSCN71020-GROUP7

// Including necessary header files
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "triangleSolver.h"

// Function for analyzing a triangle based on its sides and angles
char* analyzeTriangle(int side1, int side2, int side3, double angle1, double angle2, double angle3) {
    char* result = ""; // Initializing result string

    // Checking if the sides or angles make it impossible to be a triangle
    if (side1 <= 0 || side2 <= 0 || side3 <= 0 || (angle1 == 0 && angle2 == 0 && angle3 == 0)) {
        result = "Not a triangle";
    }
    // Checking for an equilateral triangle
    else if (side1 == side2 && side1 == side3) {
        result = "Equilateral triangle";
    }
    // Checking for an isosceles triangle
    else if ((side1 == side2 && side1 != side3) || (side1 == side3 && side1 != side2) || (side2 == side3 && side2 != side1)) {
        result = "Isosceles triangle";
    }
    // If none of the above, it's a scalene triangle
    else {
        result = "Scalene triangle";
    }

    return result;
}

// Function for calculating angles of a triangle given its sides
void calculateTriangleAngles(double side1, double side2, double side3, double* angle1, double* angle2, double* angle3) {
    // Checking if the sides form a valid triangle using the triangle inequality theorem
    if ((side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1)) {
        // Computing angles using the Law of Cosines
        *angle1 = acos((side2 * side2 + side3 * side3 - side1 * side1) / (2 * side2 * side3));
        *angle2 = acos((side1 * side1 + side3 * side3 - side2 * side2) / (2 * side1 * side3));
        *angle3 = acos((side1 * side1 + side2 * side2 - side3 * side3) / (2 * side1 * side2));
    }
    else {
        // If the sides do not form a valid triangle, setting angles to zero
        *angle1 = *angle2 = *angle3 = 0.0;
    }
}

// Function to get coordinates of four points for a rectangle
void getRectangleInfo(double* x1, double* y1, double* x2, double* y2, double* x3, double* y3, double* x4, double* y4) {
    printf_s("Enter the coordinates of four points (x, y) in order (x1 y1 x2 y2 x3 y3 x4 y4):\n");

    while (1) {
        // Reading user input
        if (scanf_s("%lf %lf %lf %lf %lf %lf %lf %lf", x1, y1, x2, y2, x3, y3, x4, y4) != 8) {
            printf_s("Invalid input. Please enter eight numeric values.\n");

            // Clearing the input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            // Asking the user to enter the values again
            continue;
        }
        break; // Valid input received
    }
}


// Function for analyzing a set of coordinates and determine if it's a rectangle
char* analyzeRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    double side4 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

    // Checking if the lengths of opposite sides are equal
    if (side1 == side3 && side2 == side4) {
        // Checking if the diagonals are equal, which would indicate a rectangle
        double diagonal1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
        double diagonal2 = sqrt(pow(x4 - x2, 2) + pow(y4 - y2, 2));
        if (diagonal1 == diagonal2) {
            return "Rectangle";
        }
        else {
            return "Not a rectangle";
        }
    }

    // If the lengths of opposite sides are not equal, it's not a rectangle
    return "Not a rectangle";
}

// Function to calculate the perimeter of a rectangle
double calculateRectanglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    double side4 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

    // Perimeter of a rectangle is the sum of all four sides
    return side1 + side2 + side3 + side4;
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));

    // Area of a rectangle is the product of two adjacent sides
    return side1 * side2;
}
