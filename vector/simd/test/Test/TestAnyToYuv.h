/*
* Tests for Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2016 Yermalayeu Ihar,
*               2014-2015 Antonenka Mikhail.
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
			typedef void (*FuncPtr)(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * y, size_t yStride,
				uint8_t * u, size_t uStride, uint8_t * v, size_t vStride);

			FuncPtr func;
			String description;

			Func(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & bgr, View & y, View & u, View & v) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(bgr.data, bgr.width, bgr.height, bgr.stride, y.data, y.stride, u.data, u.stride, v.data, v.stride);
			}
		};	
	}

#define FUNC(function) Func(function, #function)

	bool AnyToYuvAutoTest(int width, int height, View::Format srcType, int dx, int dy, const Func & f1, const Func & f2)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        const int uvWidth = width/dx;
        const int uvHeight = height/dy;

		View src(width, height, srcType, NULL, TEST_ALIGN(width));
		FillRandom(src);

		View y1(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		View u1(uvWidth, uvHeight, View::Gray8, NULL, TEST_ALIGN(uvWidth));
		View v1(uvWidth, uvHeight, View::Gray8, NULL, TEST_ALIGN(uvWidth));

		View y2(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		View u2(uvWidth, uvHeight, View::Gray8, NULL, TEST_ALIGN(uvWidth));
		View v2(uvWidth, uvHeight, View::Gray8, NULL, TEST_ALIGN(uvWidth));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, y1, u1, v1));
		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, y2, u2, v2));

		result = result && Compare(y1, y2, 0, true, 64, 0, "y");
		result = result && Compare(u1, u2, 0, true, 64, 0, "u");
		result = result && Compare(v1, v2, 0, true, 64, 0, "v");

		return result;
	}

	bool AnyToYuvAutoTest(View::Format srcType, int dx, int dy, const Func & f1, const Func & f2)
	{
		bool result = true;

		result = result && AnyToYuvAutoTest(W, H, srcType, dx, dy, f1, f2);
		result = result && AnyToYuvAutoTest(W + O*dx, H - O*dy, srcType, dx, dy, f1, f2);
		result = result && AnyToYuvAutoTest(W - O*dx, H + O*dy, srcType, dx, dy, f1, f2);
		
		return result;
	}

 
}
