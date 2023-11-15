#include "pch.h"
#include "CppUnitTest.h"

extern "C" char* analyzeTriangle(int side1, int side2, int side3, double angle1, double angle2, double angle3);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TypeOfTraingleFunctionalityUnitTest
{
	TEST_CLASS(TypeOfTraingleFunctionalityUnitTest)
	{
	public:
		
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

		TEST_METHOD(TestSumOfTwoSidesEqualToThird)
		{
			// Arrange
			int side1 = 3;
			int side2 = 4;
			int side3 = 7;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;

			// Act
			char* result = analyzeTriangle(side1, side2, side3, angle1, angle2, angle3);

			// Assert
			Assert::AreEqual("Not a triangle", result);
		}

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
