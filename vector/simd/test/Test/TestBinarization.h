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
		struct Func1
		{
			typedef void (*FuncPtr)(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
				 uint8_t value, uint8_t positive, uint8_t negative, uint8_t * dst, size_t dstStride, SimdCompareType type);

			FuncPtr func;
			String description;

			Func1(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & src, uint8_t value, uint8_t positive, uint8_t negative, View & dst, SimdCompareType type) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(src.data, src.stride, src.width, src.height, value, positive, negative, dst.data, dst.stride, type);
			}
		};
	}

#define ARGS1(width, height, type, function1, function2) \
    width, height, type, \
    Func1(function1.func, function1.description + CompareTypeDescription(type)), \
    Func1(function2.func, function2.description + CompareTypeDescription(type))

#define FUNC1(function) \
    Func1(function, std::string(#function))

	bool BinarizationAutoTest(int width, int height, SimdCompareType type, const Func1 & f1, const Func1 & f2)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

		View src(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(src);

		uint8_t value = Random(256);
		uint8_t positive = Random(256);
		uint8_t negative = Random(256);

		View d1(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		View d2(width, height, View::Gray8, NULL, TEST_ALIGN(width));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, value, positive, negative, d1, type));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, value, positive, negative, d2, type));

		result = result && Compare(d1, d2, 0, true, 32);

		return result;
	}

    bool BinarizationAutoTest(const Func1 & f1, const Func1 & f2)
    {
        bool result = true;

        for(SimdCompareType type = SimdCompareEqual; type <= SimdCompareLesserOrEqual && result; type = SimdCompareType(type + 1))
        {
            result = result && BinarizationAutoTest(ARGS1(W, H, type, f1, f2));
            result = result && BinarizationAutoTest(ARGS1(W + O, H - O, type, f1, f2));
            result = result && BinarizationAutoTest(ARGS1(W - O, H + O, type, f1, f2));
        }

        return result;
    }


    namespace
    {
        struct Func2
        {
            typedef void (*FuncPtr)(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
                uint8_t value, size_t neighborhood, uint8_t threshold, uint8_t positive, uint8_t negative, 
                uint8_t * dst, size_t dstStride, SimdCompareType type);

            FuncPtr func;
            String description;

            Func2(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, uint8_t value, size_t neighborhood, uint8_t threshold, uint8_t positive, uint8_t negative, View & dst, SimdCompareType type) const
            {
                TEST_PERFORMANCE_TEST(description);
                func(src.data, src.stride, src.width, src.height, value, neighborhood, threshold, positive, negative, dst.data, dst.stride, type);
            }
        };
    }

#define ARGS2(width, height, type, function1, function2) \
    width, height, type, \
    Func2(function1.func, function1.description + CompareTypeDescription(type)), \
    Func2(function2.func, function2.description + CompareTypeDescription(type))

#define FUNC2(function) \
    Func2(function, std::string(#function))

    bool AveragingBinarizationAutoTest(int width, int height, SimdCompareType type, const Func2 & f1, const Func2 & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        View src(width, height, View::Gray8, NULL, TEST_ALIGN(width));
        FillRandom(src);

        uint8_t value = 127;
        size_t neighborhood = 17;
        uint8_t threshold = 128;
        uint8_t positive = 7;
        uint8_t negative = 3;

        View d1(width, height, View::Gray8, NULL, TEST_ALIGN(width));
        View d2(width, height, View::Gray8, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, value, neighborhood, threshold, positive, negative, d1, type));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, value, neighborhood, threshold, positive, negative, d2, type));

        result = result && Compare(d1, d2, 0, true, 64);

        return result;
    }

    bool AveragingBinarizationAutoTest(const Func2 & f1, const Func2 & f2)
    {
        bool result = true;

        for(SimdCompareType type = SimdCompareEqual; type <= SimdCompareLesserOrEqual && result; type = SimdCompareType(type + 1))
        {
            result = result && AveragingBinarizationAutoTest(ARGS2(W, H, type, f1, f2));
            result = result && AveragingBinarizationAutoTest(ARGS2(W + O, H - O, type, f1, f2));
            result = result && AveragingBinarizationAutoTest(ARGS2(W - O, H + O, type, f1, f2));
        }

        return result;
    }


}
