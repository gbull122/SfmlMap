#include "pch.h"
#include "CppUnitTest.h"
#include "../SfmlMap/BackingGrid.h"
#include "../SfmlMap/BackingGrid.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SfmlMapTests
{
	TEST_CLASS(BackingGrid_Tests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int expectedValue = 3;
			BackingGrid backingGrid = BackingGrid::BackingGrid(10, 10, 5.0);
			backingGrid.SetCell(1, 1, 3);
			int actualValue = backingGrid.GetCellValue(7, 7);
			Assert::AreEqual(expectedValue, actualValue);
		}
	};
}
