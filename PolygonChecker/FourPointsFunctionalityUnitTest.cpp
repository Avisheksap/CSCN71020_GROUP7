#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeRectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
extern "C" double calculateRectanglePerimeter(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
extern "C" double calculateRectangleArea(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FourPointsFunctionalityUnitTest
{
	TEST_CLASS(FourPointsFunctionalityUnitTest)
	{
	public:
		

        // Test for valid rectangle
        TEST_METHOD(TestValidRectangle)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 4.0;
            double x3 = 3.0, y3 = 4.0;
            double x4 = 3.0, y4 = 0.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        // Test for invalid rectangle (not a rectangle)
        TEST_METHOD(TestNotRectangle)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 4.0;
            double x3 = 3.0, y3 = 4.0;
            double x4 = 4.0, y4 = 0.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        // Test for perimeter calculation
        TEST_METHOD(TestRectanglePerimeter)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 4.0;
            double x3 = 3.0, y3 = 4.0;
            double x4 = 3.0, y4 = 0.0;

            // Act
            double perimeter = calculateRectanglePerimeter(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual(14.0, perimeter);
        }

        // Test for area calculation
        TEST_METHOD(TestRectangleArea)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 4.0;
            double x3 = 3.0, y3 = 4.0;
            double x4 = 3.0, y4 = 0.0;

            // Act
            double area = calculateRectangleArea(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual(12.0, area);
        }

        // Test for valid square
        TEST_METHOD(TestValidSquare)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 2.0;
            double x3 = 2.0, y3 = 2.0;
            double x4 = 2.0, y4 = 0.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        // Test for rectangle with sides in reverse order
        TEST_METHOD(TestRectangleInReverseOrder)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 3.0, y2 = 0.0;
            double x3 = 3.0, y3 = 4.0;
            double x4 = 0.0, y4 = 4.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        // Test for rectangle with sides of different lengths
        TEST_METHOD(TestRectangleDifferentSideLengths)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 4.0;
            double x3 = 3.0, y3 = 3.0;
            double x4 = 3.0, y4 = 0.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        // Test for points forming a parallelogram (not a rectangle)
        TEST_METHOD(TestParallelogramNotRectangle)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 1.0, y2 = 3.0;
            double x3 = 4.0, y3 = 3.0;
            double x4 = 3.0, y4 = 0.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        // Test for degenerate rectangle (points on the same line)
        TEST_METHOD(TestDegenerateRectangle)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 2.0;
            double x3 = 0.0, y3 = 4.0;
            double x4 = 0.0, y4 = 6.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        // Test for points forming a line (not a rectangle)
        TEST_METHOD(TestPointsFormingLine)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 1.0, y2 = 1.0;
            double x3 = 2.0, y3 = 2.0;
            double x4 = 3.0, y4 = 3.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        // Test for NaN coordinates
        TEST_METHOD(TestNaNCoordinates)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 1.0, y2 = 1.0;
            double x3 = NAN, y3 = 2.0;
            double x4 = 3.0, y4 = 3.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Not a rectangle", result);
        }

        // Test for points forming a rectangle with very large coordinates
        TEST_METHOD(TestLargeCoordinates)
        {
            // Arrange
            double x1 = DBL_MAX, y1 = DBL_MAX;
            double x2 = DBL_MAX, y2 = DBL_MAX - 1;
            double x3 = DBL_MAX - 1, y3 = DBL_MAX - 1;
            double x4 = DBL_MAX - 1, y4 = DBL_MAX;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        // Test for points forming a rectangle with very small coordinates
        TEST_METHOD(TestSmallCoordinates)
        {
            // Arrange
            double x1 = DBL_MIN, y1 = DBL_MIN;
            double x2 = DBL_MIN, y2 = DBL_MIN + 1;
            double x3 = DBL_MIN + 1, y3 = DBL_MIN + 1;
            double x4 = DBL_MIN + 1, y4 = DBL_MIN;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreEqual("Rectangle", result);
        }

        // Test for not a rectangle (line) not equal to another shape
        TEST_METHOD(TestNotRectangleNotEqualSquare)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 1.0, y2 = 1.0;
            double x3 = 2.0, y3 = 2.0;
            double x4 = 3.0, y4 = 3.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreNotEqual("Rectangle", result);
        }

        // Test for degenerate rectangle (points on the same line) not equal to another shape
        TEST_METHOD(TestDegenerateRectangleNotEqualSquare)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 2.0;
            double x3 = 0.0, y3 = 4.0;
            double x4 = 0.0, y4 = 6.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreNotEqual("Rectangle", result);
        }

        

        // Test for rectangle with sides of different lengths not equal to another shape
        TEST_METHOD(TestRectangleDifferentSideLengthsNotEqualSquare)
        {
            // Arrange
            double x1 = 0.0, y1 = 0.0;
            double x2 = 0.0, y2 = 4.0;
            double x3 = 3.0, y3 = 3.0;
            double x4 = 3.0, y4 = 0.0;

            // Act
            char* result = analyzeRectangle(x1, y1, x2, y2, x3, y3, x4, y4);

            // Assert
            Assert::AreNotEqual("Square", result);
        }

    };
}

