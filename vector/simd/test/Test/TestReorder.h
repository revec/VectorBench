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
		struct Func
		{
			typedef void (*FuncPtr)(const uint8_t * src, size_t size, uint8_t * dst);

			FuncPtr func;
			String description;

			Func(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & src, View & dst) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(src.data, src.width, dst.data);
			}
		};
	}

#define FUNC(function) Func(function, #function)

	bool ReorderAutoTest(int size, const Func & f1, const Func & f2)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

		View s(size, 1, View::Gray8, NULL, TEST_ALIGN(size));
		FillRandom(s);

		View d1(size, 1, View::Gray8, NULL, TEST_ALIGN(size));
		View d2(size, 1, View::Gray8, NULL, TEST_ALIGN(size));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(s, d1));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(s, d2));

		result = result && Compare(d1, d2, 0, true, 64);

		return result;
	}

    bool ReorderAutoTest(const Func & f1, const Func & f2, int bytes)
    {
        bool result = true;

        result = result && ReorderAutoTest(W*H, f1, f2);
        result = result && ReorderAutoTest(W*H + O*bytes, f1, f2);
        result = result && ReorderAutoTest(W*H - O*bytes, f1, f2);

        return result;
    }


}
