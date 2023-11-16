// CSCN71020_GROUP7

#include "pch.h"
#include "CppUnitTest.h"

// Declaring the C function to be tested
extern "C" char* analyzeTriangle(int side1, int side2, int side3, double angle1, double angle2, double angle3);

// Using the Microsoft Visual Studio testing framework
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TypeOfTraingleFunctionalityUnitTest
{
	TEST_CLASS(TypeOfTraingleFunctionalityUnitTest)
	{
	public:

		// Testing for Equilateral Triangle
		TEST_METHOD(TestEquilateralTriangle)
		{
			// Arrange
			int side1 = 5;
			int side2 = 5;
			int side3 = 5;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Equilateral triangle", result);
		}

		// Testing for Isosceles Triangle
		TEST_METHOD(TestIsoscelesTriangle)
		{
			// Arrange
			int side1 = 4;
			int side2 = 4;
			int side3 = 5;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Isosceles triangle", result);
		}

		// Testing for Scalene Triangle
		TEST_METHOD(TestScaleneTriangle)
		{
			// Arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Scalene triangle", result);
		}

		// Testing for Not a Triangle
		TEST_METHOD(TestNotATriangle)
		{
			// Arrange
			int side1 = 1;
			int side2 = 2;
			int side3 = 3;
			double angle1 = 0;
			double angle2 = 0;
			double angle3 = 0;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result);
		}

		// Testing for Invalid Side Length
		TEST_METHOD(TestInvalidSideLength)
		{
			// Arrange
			int side1 = -2;
			int side2 = 4;
			int side3 = 5;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result);
		}

		// Testing for Zero Angles
		TEST_METHOD(TestZeroAngles)
		{
			// Arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			double angle1 = 0;
			double angle2 = 0;
			double angle3 = 0;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result);
		}

		// Testing for Negative Angle
		TEST_METHOD(TestNegativeAngle)
		{
			// Arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			double angle1 = -10;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result);
		}

		// Testing for Zero Side Length
		TEST_METHOD(TestZeroSideLength)
		{
			// Arrange
			int side1 = 0;
			int side2 = 2;
			int side3 = 3;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result);
		}

		// Testing for Sum of Two Sides Equal to Third
		TEST_METHOD(TestSumOfTwoSidesEqualToThird)
		{
			// Arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 7; // Sum of side1 and side2
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result, "The sum of two sides should not be equal to the third side.");
		}

		// Testing for Not Equal Cases for Invalid Side Length
		TEST_METHOD(TestNotEqualInvalidSideLength)
		{
			// Arrange
			int side1 = -2;
			int side2 = 4;
			int side3 = 5;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreNotEqual("Equilateral triangle", result);
			Assert::AreNotEqual("Isosceles triangle", result);
			Assert::AreNotEqual("Scalene triangle", result);
		}

		// Testing for Not Equal Cases for Zero Angles
		TEST_METHOD(TestNotEqualZeroAngles)
		{
			// Arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 5;
			double angle1 = 0;
			double angle2 = 0;
			double angle3 = 0;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreNotEqual("Equilateral triangle", result);
			Assert::AreNotEqual("Isosceles triangle", result);
			Assert::AreNotEqual("Scalene triangle", result);
		}

		// Testing for  Not Equal Cases for Not a Triangle
		TEST_METHOD(TestNotEqualNotATriangle)
		{
			// Arrange
			int side1 = 1;
			int side2 = 2;
			int side3 = 3;
			double angle1 = 0;
			double angle2 = 0;
			double angle3 = 0;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreNotEqual("Equilateral triangle", result);
			Assert::AreNotEqual("Isosceles triangle", result);
			Assert::AreNotEqual("Scalene triangle", result);
		}
	};
}
