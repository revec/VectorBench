/*
* Tests for Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2017 Yermalayeu Ihar.
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
        struct FuncM1
        {
            typedef void (*FuncPtr)(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
                const uint8_t * mask, size_t maskStride, uint8_t indexMin, uint8_t * dst, size_t dstStride);

            FuncPtr func;
            String description;

            FuncM1(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, const View & mask, uint8_t indexMin, View & dst) const
            {
                TEST_PERFORMANCE_TEST(description);
                func(src.data, src.stride, src.width, src.height, mask.data, mask.stride, indexMin, dst.data, dst.stride);
            }
        };
    }

#define FUNC_M1(function) \
    FuncM1(function, std::string(#function))

    bool ContourMetricsMaskedAutoTest(int width, int height, const FuncM1 & f1, const FuncM1 & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        View s(width, height, View::Gray8, NULL, TEST_ALIGN(width));
        FillRandom(s);

        View m(width, height, View::Gray8, NULL, TEST_ALIGN(width));
        FillRandom(m);

        View d1(width, height, View::Int16, NULL, TEST_ALIGN(width));
        View d2(width, height, View::Int16, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(s, m, 128, d1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(s, m, 128, d2));

        result = result && Compare(d1, d2, 0, true, 64);

        return result;
    }

    bool ContourMetricsMaskedAutoTest(const FuncM1 & f1, const FuncM1 & f2)
    {
        bool result = true;

        result = result && ContourMetricsMaskedAutoTest(W, H, f1, f2);
        result = result && ContourMetricsMaskedAutoTest(W + O, H - O, f1, f2);
        result = result && ContourMetricsMaskedAutoTest(W - O, H + O, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncA1
        {
            typedef void (*FuncPtr)(const uint8_t * src, size_t srcStride, size_t width, size_t height, 
                size_t step, int16_t threshold, uint8_t * dst, size_t dstStride);

            FuncPtr func;
            String description;

            FuncA1(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, size_t step, int16_t threshold, View & dst) const
            {
                TEST_PERFORMANCE_TEST(description);
                func(src.data, src.stride, src.width, src.height, step, threshold, dst.data, dst.stride);
            }
        };
    }

#define FUNC_A1(function) \
    FuncA1(function, std::string(#function))

    bool ContourAnchorsAutoTest(int width, int height, const FuncA1 & f1, const FuncA1 & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        View s(width, height, View::Int16, NULL, TEST_ALIGN(width));
        FillRandom(s);

        View d1(width, height, View::Gray8, NULL, TEST_ALIGN(width));
        View d2(width, height, View::Gray8, NULL, TEST_ALIGN(width));
        Simd::Fill(d1, 0);
        Simd::Fill(d2, 0);

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(s, 3, 0, d1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(s, 3, 0, d2));

        result = result && Compare(d1, d2, 0, true, 64);

        return result;
    }

    bool ContourAnchorsAutoTest(const FuncA1 & f1, const FuncA1 & f2)
    {
        bool result = true;

        result = result && ContourAnchorsAutoTest(W, H, f1, f2);
        result = result && ContourAnchorsAutoTest(W + O, H - O, f1, f2);
        result = result && ContourAnchorsAutoTest(W - O, H + O, f1, f2);

        return result;
    }



}




