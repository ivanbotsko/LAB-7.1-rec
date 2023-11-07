#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 7.1 rec/PR 7.1 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourMatrixFunctionsTests
{
    TEST_CLASS(CreateFunctionTests)
    {
    public:

        TEST_METHOD(TestCreateFunction)
        {
            const int rowCount = 7;
            const int colCount = 6;
            const int Low = 9;
            const int High = 61;

            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

            Create(matrix, rowCount, colCount, Low, High);

            for (int i = 0; i < rowCount; i++)
            {
                for (int j = 0; j < colCount; j++)
                {
                    Assert::IsTrue(matrix[i][j] >= Low && matrix[i][j] <= High);
                }
            }

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}
