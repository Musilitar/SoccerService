#include "stdafx.h"
#include "CppUnitTest.h"
#include "Match.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace main_test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
#ifndef Databank_Offline
			Match* m1 = new Match("12/12/2012", 1, 12, 120);
			Assert::AreEqual("12/12/2012", m1 -> getMatchDatum().c_str(), true);
			Assert::AreEqual(1, m1->getStadionID(), 0);
			Assert::AreEqual(12, m1->getTegenstanderID(), 0);
			Assert::AreEqual(120, m1->getMatchID(), 0);
			delete m1;
#endif
		}
	};
}