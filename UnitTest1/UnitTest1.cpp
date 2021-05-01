#include "pch.h"
#include "CppUnitTest.h"
#include "../9_3/9_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Rep* f = new Rep[1];
			f->math = 3.0;
			int N = 1;
			bool x = StudThree(f, N);
			Assert::AreEqual(x, true);
		}
	};
}
