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
            typedef void (*FuncPtr)(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uint8_t value);

            FuncPtr func;
            String description;

            Func(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(View & dst, uint8_t value) const
            {
                TEST_PERFORMANCE_TEST(description);
                func(dst.data, dst.stride, dst.width, dst.height, dst.PixelSize(), value);
            }
        };
    }

#define FUNC(function) \
    Func(function, std::string(#function))

    bool FillAutoTest(View::Format format, int width, int height, const Func & f1, const Func & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        uint8_t value = Random(256);

        View d1(width, height, format, NULL, TEST_ALIGN(width));
        View d2(width, height, format, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(d1, value));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(d2, value));

        result = result && Compare(d1, d2, 0, true, 32);

        return result;
    }

    bool FillAutoTest(const Func & f1, const Func & f2)
    {
        bool result = true;

        for(View::Format format = View::Gray8; format <= View::BayerBggr; format = View::Format(format + 1))
        {
            if(format == View::Float || format == View::Double)
                continue;

            Func f1c = Func(f1.func, f1.description + ColorDescription(format));
            Func f2c = Func(f2.func, f2.description + ColorDescription(format));

            result = result && FillAutoTest(format, W, H, f1c, f2c);
            result = result && FillAutoTest(format, W + O, H - O, f1c, f2c);
            result = result && FillAutoTest(format, W - O, H + O, f1c, f2c);
        }

        return result;
    }

    bool FillAutoTest()
    {
        bool result = true;

        result = result && FillAutoTest(FUNC(Simd::Base::Fill), FUNC(SimdFill));

        return result;
    }

    namespace
    {
        struct FuncF
        {
            typedef void (*FuncPtr)(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize, 
                size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t value);

            FuncPtr func;
            String description;

            FuncF(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(View & dst, const Rect & frame, uint8_t value) const
            {
                TEST_PERFORMANCE_TEST(description);
                func(dst.data, dst.stride, dst.width, dst.height, dst.PixelSize(), 
                    frame.left, frame.top, frame.right, frame.bottom, value);
            }
        };
    }

#define FUNC_F(function) \
    FuncF(function, std::string(#function))

    bool FillFrameAutoTest(View::Format format, int width, int height, const FuncF & f1, const FuncF & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        uint8_t value = Random(256);
        Rect frame(width*1/15, height*2/15, width*11/15, height*12/15);

        View d1(width, height, format, NULL, TEST_ALIGN(width));
        View d2(width, height, format, NULL, TEST_ALIGN(width));
        Simd::Fill(d1, 0);
        Simd::Fill(d2, 0);

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(d1, frame, value));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(d2, frame, value));

        result = result && Compare(d1, d2, 0, true, 32);

        return result;
    }

    bool FillFrameAutoTest(const FuncF & f1, const FuncF & f2)
    {
        bool result = true;

        for(View::Format format = View::Gray8; format <= View::BayerBggr; format = View::Format(format + 1))
        {
            if(format == View::Float || format == View::Double)
                continue;

            FuncF f1c = FuncF(f1.func, f1.description + ColorDescription(format));
            FuncF f2c = FuncF(f2.func, f2.description + ColorDescription(format));

            result = result && FillFrameAutoTest(format, W, H, f1c, f2c);
            result = result && FillFrameAutoTest(format, W + O, H - O, f1c, f2c);
            result = result && FillFrameAutoTest(format, W - O, H + O, f1c, f2c);
        }

        return result;
    }

    bool FillFrameAutoTest()
    {
        bool result = true;

        result = result && FillFrameAutoTest(FUNC_F(Simd::Base::FillFrame), FUNC_F(SimdFillFrame));

        return result;
    }

	namespace
	{
		struct FuncBgra
		{
			typedef void (*FuncPtr)(uint8_t * dst, size_t stride, size_t width, size_t height, uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha);

			FuncPtr func;
			String description;

			FuncBgra(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(View & dst, uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(dst.data, dst.stride, dst.width, dst.height, blue, green, red, alpha);
			}
		};
	}

#define FUNC_BGRA(function) \
	FuncBgra(function, std::string(#function))

	bool FillBgraAutoTest(int width, int height, const FuncBgra & f1, const FuncBgra & f2)
	{
		bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        uint8_t blue = Random(256);
        uint8_t green = Random(256);
        uint8_t red = Random(256);
        uint8_t alpha = Random(256);

		View d1(width, height, View::Bgra32, NULL, TEST_ALIGN(width));
		View d2(width, height, View::Bgra32, NULL, TEST_ALIGN(width));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(d1, blue, green, red, alpha));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(d2, blue, green, red, alpha));

		result = result && Compare(d1, d2, 0, true, 32);

		return result;
	}

    bool FillBgraAutoTest(const FuncBgra & f1, const FuncBgra & f2)
    {
        bool result = true;

        result = result && FillBgraAutoTest(W, H, f1, f2);
        result = result && FillBgraAutoTest(W + O, H - O, f1, f2);
        result = result && FillBgraAutoTest(W - O, H + O, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncBgr
        {
            typedef void (*FuncPtr)(uint8_t * dst, size_t stride, size_t width, size_t height, uint8_t blue, uint8_t green, uint8_t red);

            FuncPtr func;
            String description;

            FuncBgr(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(View & dst, uint8_t blue, uint8_t green, uint8_t red) const
            {
                TEST_PERFORMANCE_TEST(description);
                func(dst.data, dst.stride, dst.width, dst.height, blue, green, red);
            }
        };
    }

#define FUNC_BGR(function) \
    FuncBgr(function, std::string(#function))

    bool FillBgrAutoTest(int width, int height, const FuncBgr & f1, const FuncBgr & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        uint8_t blue = Random(256);
        uint8_t green = Random(256);
        uint8_t red = Random(256);

        View d1(width, height, View::Bgr24, NULL, TEST_ALIGN(width));
        View d2(width, height, View::Bgr24, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(d1, blue, green, red));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(d2, blue, green, red));

        result = result && Compare(d1, d2, 0, true, 32);

        return result;
    }

    bool FillBgrAutoTest(const FuncBgr & f1, const FuncBgr & f2)
    {
        bool result = true;

        result = result && FillBgrAutoTest(W, H, f1, f2);
        result = result && FillBgrAutoTest(W + O, H - O, f1, f2);
        result = result && FillBgrAutoTest(W - O, H + O, f1, f2);

        return result;
    }


 
}
