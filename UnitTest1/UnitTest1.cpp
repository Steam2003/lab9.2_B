#include "pch.h"
#include "CppUnitTest.h"
#include "../lab9.2_B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s[0].prizv = "œ‡Ú˛Í";
			s[0].kurs = 1;
			s[0].specialty =  Õ;
			s[0].physics = 5;
			s[0].math = 5;
			s[0].programming = 5;

			double BestAvg = BestAverage(s, N);
			Assert::AreEqual(BestAvg, 5.0);
		}
	};
}
