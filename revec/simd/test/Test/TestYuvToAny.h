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
			typedef void (*FuncPtr)(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride, 
				size_t width, size_t height, uint8_t * dst, size_t dstStride);

			FuncPtr func;
			String description;

			Func(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & y, const View & u, const View & v, View & dst) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(y.data, y.stride, u.data, u.stride, v.data, v.stride, y.width, y.height, dst.data, dst.stride);
			}
		};	
	}

#define FUNC(function) Func(function, #function)

	bool YuvToAnyAutoTest(int width, int height, int dx, int dy, View::Format dstType, const Func & f1, const Func & f2, int maxDifference)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

		const int uvWidth = width/dx;
		const int uvHeight = height/dy;

		View y(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(y);
		View u(uvWidth, uvHeight, View::Gray8, NULL, TEST_ALIGN(uvWidth));
		FillRandom(u);
		View v(uvWidth, uvHeight, View::Gray8, NULL, TEST_ALIGN(uvWidth));
		FillRandom(v);

		View dst1(width, height, dstType, NULL, TEST_ALIGN(width));
		View dst2(width, height, dstType, NULL, TEST_ALIGN(width));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(y, u, v, dst1));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(y, u, v, dst2));

		result = result && Compare(dst1, dst2, maxDifference, true, 64, 255);

		return result;
	}

    bool YuvToAnyAutoTest(int dx, int dy, View::Format dstType, const Func & f1, const Func & f2, int maxDifference = 0)
    {
        bool result = true;

        result = result && YuvToAnyAutoTest(W, H, dx, dy, dstType, f1, f2, maxDifference);
        result = result && YuvToAnyAutoTest(W + O*dx, H - O*dy, dx, dy, dstType, f1, f2, maxDifference);
        result = result && YuvToAnyAutoTest(W - O*dx, H + O*dy, dx, dy, dstType, f1, f2, maxDifference);

        return result;
    }

}

#if defined(SIMD_NEON_ENABLE) && (SIMD_NEON_RCP_ITER > -1)
	const int MAX_DIFFERECE = 1;
#else
	const int MAX_DIFFERECE = 0;
#endif
