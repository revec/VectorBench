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
			typedef void(*FuncPtr)(const uint8_t * src, size_t width, size_t height, size_t srcStride, uint8_t * bayer, size_t bayerStride, SimdPixelFormatType bayerFormat);
			FuncPtr func;
			String description;

			Func(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & src, View & dst) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(src.data, src.width, src.height, src.stride, dst.data, dst.stride, (SimdPixelFormatType)dst.format);
			}
		};	
	}

#define FUNC(func) Func(func, #func)

    bool AnyToBayerAutoTest(int width, int height, View::Format srcType, View::Format dstType, const Func & f1, const Func & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " for size [" << width << "," << height << "] of " << FormatDescription(dstType) << ".");

        View src(width, height, srcType, NULL, TEST_ALIGN(width));
        FillRandom(src);

        View dst1(width, height, dstType, NULL, TEST_ALIGN(width));
        View dst2(width, height, dstType, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, dst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, dst2));

        result = result && Compare(dst1, dst2, 0, true, 64);

        return result;
    }

    bool AnyToBayerAutoTest(View::Format srcType, const Func & f1, const Func & f2)
    {
        bool result = true;

        for(View::Format dstType = View::BayerGrbg; dstType <= View::BayerBggr; dstType = View::Format(dstType + 1))
        {
            result = result && AnyToBayerAutoTest(W, H, srcType, dstType, f1, f2);
            result = result && AnyToBayerAutoTest(W + E, H - E, srcType, dstType, f1, f2);
            result = result && AnyToBayerAutoTest(W - E, H + E, srcType, dstType, f1, f2);
        }

        return result;
    }
}
