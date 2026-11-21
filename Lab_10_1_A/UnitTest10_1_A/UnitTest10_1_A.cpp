#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10_1_A/Lab_10_1_A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
	TEST_CLASS(UnitTest101A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student p[3];
			p[0].informatyka = 5;
			p[1].informatyka = 5;
			p[2].informatyka = 3;
			int k = CountInformatykaMark(p, 3, 5);
			Assert::AreEqual(2, k);
		}
	};
}
