/*
* Tests for Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2016 Yermalayeu Ihar.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#include "Test/TestUtils.h"
#include "Test/TestPerformance.h"
#include "Test/TestData.h"

namespace Test
{
	namespace
	{
		struct FuncS
		{
			typedef void (*FuncPtr)(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
				size_t width, size_t height, uint64_t * sum);

			FuncPtr func;
			String description;

			FuncS(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & a, const View & b, uint64_t * sum) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(a.data, a.stride, b.data, b.stride, a.width, a.height, sum);
			}
		};

		struct FuncM
		{
			typedef void (*FuncPtr)(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
				const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum);

			FuncPtr func;
			String description;

			FuncM(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & a, const View & b, const View & mask, uint8_t index, uint64_t * sum) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(a.data, a.stride, b.data, b.stride, mask.data, mask.stride, index, a.width, a.height, sum);
			}
		};

        struct FuncF
        {
            typedef void (*FuncPtr)(const float * a, const float * b, size_t size, float * sum);

            FuncPtr func;
            String description;

            FuncF(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & a, const View & b, float * sum) const
            {
                TEST_PERFORMANCE_TEST(description);
                func((float*)a.data, (float*)b.data, a.width, sum);
            }
        };
	}

#define FUNC_S(function) FuncS(function, #function)
#define FUNC_M(function) FuncM(function, #function)
#define FUNC_F(function) FuncF(function, #function)

	bool DifferenceSumsAutoTest(int width, int height, const FuncS & f1, const FuncS & f2, int count)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

		View a(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(a);

		View b(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(b);

        Sums64 s1(count, 0), s2(count, 0);

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(a, b, s1.data()));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(a, b, s2.data()));

        result = Compare(s1, s2, 0, true, count);

		return result;
	}

    bool DifferenceSumsAutoTest(const FuncS & f1, const FuncS & f2, int count)
    {
        bool result = true;

        result = result && DifferenceSumsAutoTest(W, H, f1, f2, count);
        result = result && DifferenceSumsAutoTest(W + O, H - O, f1, f2, count);
        result = result && DifferenceSumsAutoTest(W - O, H + O, f1, f2, count);

        return result;
    }

	bool DifferenceSumsMaskedAutoTest(int width, int height, const FuncM & f1, const FuncM & f2, int count)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

		View a(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(a);

		View b(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(b);

		View m(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		 uint8_t index = Random(256);
		FillRandomMask(m, index);

        Sums64 s1(count, 0), s2(count, 0);

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(a, b, m, index, s1.data()));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(a, b, m, index, s2.data()));

        result = Compare(s1, s2, 0, true, count);

		return result;
	}

    bool DifferenceSumsMaskedAutoTest(const FuncM & f1, const FuncM & f2, int count)
    {
        bool result = true;

        result = result && DifferenceSumsMaskedAutoTest(W, H, f1, f2, count);
        result = result && DifferenceSumsMaskedAutoTest(W + O, H - O, f1, f2, count);
        result = result && DifferenceSumsMaskedAutoTest(W - O, H + O, f1, f2, count);

        return result;
    }

    bool DifferenceSum32fAutoTest(int size, float eps, const FuncF & f1, const FuncF & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

        View a(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(a);

        View b(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(b);

        float s1, s2;

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(a, b, &s1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(a, b, &s2));

        result = Compare(s1, s2, eps, true);

        return result;
    }

    bool DifferenceSum32fAutoTest(float eps, const FuncF & f1, const FuncF & f2)
    {
        bool result = true;

        result = result && DifferenceSum32fAutoTest(W*H, eps, f1, f2);
        result = result && DifferenceSum32fAutoTest(W*H + O, eps, f1, f2);
        result = result && DifferenceSum32fAutoTest(W*H - O, eps, f1, f2);

        return result;
    }


}
