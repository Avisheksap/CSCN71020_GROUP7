#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>   // for isnan
#include <cfloat>   // for DBL_MAX

#define M_PI 3.14159265358979323846

extern "C" void calculateTriangleAngles(double side1, double side2, double side3, double* angle1, double* angle2, double* angle3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TriangleInsideAngleFunctionalityUnitTest
{
    TEST_CLASS(TriangleInsideAngleFunctionalityUnitTest)
    {
    public:
        // Test for equilateral triangle angles
        TEST_METHOD(TestEquilateralTriangleAngles)
        {
            // Arrange
            double side1 = 5.0;
            double side2 = 5.0;
            double side3 = 5.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(60.0, angle1 * (180.0 / M_PI), 0.0001);  // Increase precision
            Assert::AreEqual(60.0, angle2 * (180.0 / M_PI), 0.0001);
            Assert::AreEqual(60.0, angle3 * (180.0 / M_PI), 0.0001);
        }

        // Test for isosceles triangle angles
        TEST_METHOD(TestIsoscelesTriangleAngles)
        {
            // Arrange
            double side1 = 4.0;
            double side2 = 4.0;
            double side3 = 5.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(51.3178, angle1 * (180.0 / M_PI), 0.0001);  
            Assert::AreEqual(51.3178, angle2 * (180.0 / M_PI), 0.0001);
            Assert::AreEqual(77.3644, angle3 * (180.0 / M_PI), 0.0001);
        }



        // Test for scalene triangle angles
        TEST_METHOD(TestScaleneTriangleAngles)
        {
            // Arrange
            double side1 = 3.0;
            double side2 = 4.0;
            double side3 = 5.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(36.8699, angle1 * (180.0 / M_PI), 0.0001);
            Assert::AreEqual(53.1301, angle2 * (180.0 / M_PI), 0.0001);
            Assert::AreEqual(90.0, angle3 * (180.0 / M_PI));
        }

        // Functional Test: Zero Sides
        TEST_METHOD(TestZeroSides)
        {
            // Arrange
            double side1 = 0.0;
            double side2 = 0.0;
            double side3 = 0.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(0.0, angle1);
            Assert::AreEqual(0.0, angle2);
            Assert::AreEqual(0.0, angle3);
        }

        // Boundary Test: Maximum Side Length
        TEST_METHOD(TestMaximumSideLength)
        {
            // Arrange
            double side1 = DBL_MAX;
            double side2 = DBL_MAX;
            double side3 = DBL_MAX;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::IsTrue(std::isnan(angle1));
            Assert::IsTrue(std::isnan(angle2));
            Assert::IsTrue(std::isnan(angle3));
        }

        // Exception Test: Negative Side Length
        TEST_METHOD(TestNegativeSideLength)
        {
            // Arrange
            double side1 = -2.0;
            double side2 = 3.0;
            double side3 = 4.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(0.0, angle1); // Angle set to 0 for invalid sides
            Assert::AreEqual(0.0, angle2);
            Assert::AreEqual(0.0, angle3);
        }

        // Functional Test: Right-angled Triangle
        TEST_METHOD(TestRightAngledTriangle)
        {
            // Arrange
            double side1 = 3.0;
            double side2 = 4.0;
            double side3 = 5.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreEqual(36.8699, angle1 * (180.0 / M_PI), 0.0001);
            Assert::AreEqual(53.1301, angle2 * (180.0 / M_PI), 0.0001);
            Assert::AreEqual(90.0, angle3 * (180.0 / M_PI));
        }

        // Functional Test: Not Equal to 90 degrees for a right-angled triangle
        TEST_METHOD(TestNotEqualRightAngledTriangle)
        {
            // Arrange
            double side1 = 3.0;
            double side2 = 4.0;
            double side3 = 5.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreNotEqual(90.0, angle1 * (180.0 / M_PI));
            Assert::AreNotEqual(90.0, angle2 * (180.0 / M_PI));
            Assert::AreNotEqual(90.0, angle3 * (180.0 / M_PI));
        }

        // Functional Test: Not Equal to 60 degrees for an equilateral triangle
        TEST_METHOD(TestNotEqualEquilateralTriangle)
        {
            // Arrange
            double side1 = 2.0;
            double side2 = 2.0;
            double side3 = 2.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreNotEqual(60.0, angle1 * (180.0 / M_PI));
            Assert::AreNotEqual(60.0, angle2 * (180.0 / M_PI));
            Assert::AreNotEqual(60.0, angle3 * (180.0 / M_PI));
        }

        // Boundary Test: Not Equal to 0 degrees for invalid sides
        TEST_METHOD(TestNotEqualInvalidSides)
        {
            // Arrange
            double side1 = 0.0;
            double side2 = 0.0;
            double side3 = 0.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreNotEqual(0.0, angle1);
            Assert::AreNotEqual(0.0, angle2);
            Assert::AreNotEqual(0.0, angle3);
        }

        // Boundary Test: Not Equal to 180 degrees for an impossible triangle
        TEST_METHOD(TestNotEqualImpossibleTriangle)
        {
            // Arrange
            double side1 = 1.0;
            double side2 = 1.0;
            double side3 = 3.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreNotEqual(180.0, angle1 * (180.0 / M_PI));
            Assert::AreNotEqual(180.0, angle2 * (180.0 / M_PI));
            Assert::AreNotEqual(180.0, angle3 * (180.0 / M_PI));
        }

        // Exception Test: Not Equal to NaN for sides that cannot form a valid triangle
        TEST_METHOD(TestNotEqualInvalidTriangle)
        {
            // Arrange
            double side1 = 1.0;
            double side2 = 2.0;
            double side3 = 3.0;
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::IsTrue(std::isnan(angle1));
            Assert::IsTrue(std::isnan(angle2));
            Assert::IsTrue(std::isnan(angle3));
        }

        // Exception Test: Not Equal to 45 degrees for an isosceles right-angled triangle
        TEST_METHOD(TestNotEqualIsoscelesRightAngledTriangle)
        {
            // Arrange
            double side1 = 3.0;
            double side2 = 3.0;
            double side3 = 3.0 * sqrt(2); // Hypotenuse for a right-angled isosceles triangle
            double angle1, angle2, angle3;

            // Act
            calculateTriangleAngles(side1, side2, side3, &angle1, &angle2, &angle3);

            // Assert
            Assert::AreNotEqual(45.0, angle1 * (180.0 / M_PI));
            Assert::AreNotEqual(45.0, angle2 * (180.0 / M_PI));
            Assert::AreNotEqual(90.0, angle3 * (180.0 / M_PI));
        }
    };
}
