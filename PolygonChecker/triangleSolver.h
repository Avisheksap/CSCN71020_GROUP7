#pragma once
char* analyzeTriangle(int side1, int side2, int side3, double angle1, double angle2, double angle3);
void calculateTriangleAngles(double side1, double side2, double side3, double* angle1, double* angle2, double* angle3);
void getRectangleInfo(double* x1, double* y1, double* x2, double* y2, double* x3, double* y3, double* x4, double* y4);
char* analyzeRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
double calculateRectanglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
double calculateRectangleArea(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
