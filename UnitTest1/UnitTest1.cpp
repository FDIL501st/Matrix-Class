#include "pch.h"
#include "CppUnitTest.h"
#include "../Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using mtx::Matrix;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int x = 1;
			Assert::AreEqual(x, 1);
		}

		TEST_METHOD(TestMethod2)
		{
			int x = 1;
			Assert::AreNotEqual(x, 2);
		}

		TEST_METHOD(TestMethod3)
		{
			double* x = new double[0];
			Assert::IsNotNull(x);
		}
	};
}
