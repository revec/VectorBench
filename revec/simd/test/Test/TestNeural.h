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
	const float ROUGH_SIGMOID_ERROR = 0.0025f;

	namespace
	{
		struct FuncC1
		{
			typedef void(*FuncPtr)(const uint8_t * src, size_t stride, size_t width, size_t height, float * dst, int inversion);

			FuncPtr func;
			String description;
			bool inversion;

			FuncC1(const FuncPtr & f, const String & d, bool i) : func(f), description(d + (i ? "[1]" : "[0]")), inversion(i) {}

			void Call(const View & src, View & dst) const
			{
				TEST_PERFORMANCE_TEST(description);
				func(src.data, src.stride, src.width, src.height, (float*)dst.data, inversion ? 1 : 0);
			}
		};
	}
#define FUNC_C1(function, inversion) FuncC1(function, #function, inversion)

	bool NeuralConvertAutoTest(int width, int height, float eps, const FuncC1 & f1, const FuncC1 & f2)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

		View src(width, height, View::Gray8, NULL, TEST_ALIGN(width));
		FillRandom(src);

		View dst1(width*height, 1, View::Float, NULL, TEST_ALIGN(width));
		View dst2(width*height, 1, View::Float, NULL, TEST_ALIGN(width));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, dst1));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, dst2));

		result = Compare(dst1, dst2, eps, true, 32);

		return result;
	}

	bool NeuralConvertAutoTest(float eps, const FuncC1 & f1, const FuncC1 & f2)
	{
		bool result = true;

		result = result && NeuralConvertAutoTest(W, H, eps, f1, f2);
		result = result && NeuralConvertAutoTest(W - O, H + O, eps, f1, f2);
		result = result && NeuralConvertAutoTest(W + O, H - O, eps, f1, f2);

		return result;
	}


	namespace
	{
        struct FuncPS
        {
            typedef void (*FuncPtr)(const float * a, const float * b, size_t size, float * sum);

            FuncPtr func;
            String description;

            FuncPS(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & a, const View & b, float * sum) const
            {
                TEST_PERFORMANCE_TEST(description);
                func((float*)a.data, (float*)b.data, a.width, sum);
            }
        };
	}
#define FUNC_PS(function) FuncPS(function, #function)

    bool NeuralProductSumAutoTest(int size, float eps, const FuncPS & f1, const FuncPS & f2)
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

    bool NeuralProductSumAutoTest(float eps, const FuncPS & f1, const FuncPS & f2)
    {
        bool result = true;

        result = result && NeuralProductSumAutoTest(W*H, eps, f1, f2);
        result = result && NeuralProductSumAutoTest(W*H + O, eps, f1, f2);
        result = result && NeuralProductSumAutoTest(W*H - O, eps, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncAVMV
        {
            typedef void(*FuncPtr)(const float * src, size_t size, const float * value, float * dst);

            FuncPtr func;
            String description;

            FuncAVMV(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, float value, const View & dstSrc, View & dstDst) const
            {
                Simd::Copy(dstSrc, dstDst);
                TEST_PERFORMANCE_TEST(description);
                func((float*)src.data, src.width, &value, (float*)dstDst.data);
            }
        };
    }
#define FUNC_AVMV(function) FuncAVMV(function, #function)

    bool NeuralAddVectorMultipliedByValueAutoTest(int size, float eps, const FuncAVMV & f1, const FuncAVMV & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

        View src(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(src);

        View dstSrc(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(dstSrc);

        const float value = 0.3f;

        View dstDst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View dstDst2(size, 1, View::Float, NULL, TEST_ALIGN(size));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, value, dstSrc, dstDst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, value, dstSrc, dstDst2));

        result = Compare(dstDst1, dstDst2, eps, true);

        return result;
    }

    bool NeuralAddVectorMultipliedByValueAutoTest(float eps, const FuncAVMV & f1, const FuncAVMV & f2)
    {
        bool result = true;

        result = result && NeuralAddVectorMultipliedByValueAutoTest(W*H, eps, f1, f2);
        result = result && NeuralAddVectorMultipliedByValueAutoTest(W*H + O, eps, f1, f2);
        result = result && NeuralAddVectorMultipliedByValueAutoTest(W*H - O, eps, f1, f2);

        return result;
    }


	namespace
	{
		struct FuncAF
		{
			typedef void(*FuncPtr)(const float * src, size_t size, const float * slope, float * dst);

			FuncPtr func;
			String description;

			FuncAF(const FuncPtr & f, const String & d) : func(f), description(d) {}

			void Call(const View & src, float slope, View & dst) const
			{
				TEST_PERFORMANCE_TEST(description);
				func((float*)src.data, src.width, &slope, (float*)dst.data);
			}
		};
	}
#define FUNC_AF(function) FuncAF(function, #function)

	bool NeuralActivateFunctionAutoTest(int size, float error, bool relative, float slope, const FuncAF & f1, const FuncAF & f2)
	{
		bool result = true;

		TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

		View src(size, 1, View::Float, NULL, TEST_ALIGN(size));
		FillRandom32f(src, -10.0f, 10.0f);

		View dst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
		View dst2(size, 1, View::Float, NULL, TEST_ALIGN(size));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, slope, dst1));

		TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, slope, dst2));

		result = Compare(dst1, dst2, error, true, 32, relative);

		return result;
	}

	bool NeuralActivateFunctionAutoTest(float error, bool relative, float slope, const FuncAF & f1, const FuncAF & f2)
	{
		bool result = true;

		result = result && NeuralActivateFunctionAutoTest(W*H, error, relative, slope, f1, f2);
		result = result && NeuralActivateFunctionAutoTest(W*H + O, error, relative, slope, f1, f2);
		result = result && NeuralActivateFunctionAutoTest(W*H - O, error, relative, slope, f1, f2);

		return result;
	}

	bool NeuralSigmoidAutoTest()
	{
		bool result = true;

		result = result && NeuralActivateFunctionAutoTest(EPS, false, 3.0f, FUNC_AF(Simd::Base::NeuralSigmoid), FUNC_AF(SimdNeuralSigmoid));

		return result;
	}



    namespace
    {
        struct FuncAD
        {
            typedef void(*FuncPtr)(const float * src, size_t size, const float * slope, float * dst);

            FuncPtr func;
            String description;

            FuncAD(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, float slope, const View & dstSrc, View & dstDst) const
            {
                Simd::Copy(dstSrc, dstDst);
                TEST_PERFORMANCE_TEST(description);
                func((float*)src.data, src.width, &slope, (float*)dstDst.data);
            }
        };
    }
#define FUNC_AD(function) FuncAD(function, #function)

    bool NeuralActivateDerivativeAutoTest(int size, float error, bool relative, float slope, const FuncAD & f1, const FuncAD & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

        View src(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(src, -10.0f, 10.0f);

        View dstSrc(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(dstSrc, -1.0f, 1.0f);

        View dstDst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View dstDst2(size, 1, View::Float, NULL, TEST_ALIGN(size));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, slope, dstSrc, dstDst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, slope, dstSrc, dstDst2));

        result = Compare(dstDst1, dstDst2, error, true, 32, relative);

        return result;
    }

    bool NeuralActivateDerivativeAutoTest(float error, bool relative, float slope, const FuncAD & f1, const FuncAD & f2)
    {
        bool result = true;

        result = result && NeuralActivateDerivativeAutoTest(W*H, error, relative, slope, f1, f2);
        result = result && NeuralActivateDerivativeAutoTest(W*H + O, error, relative, slope, f1, f2);
        result = result && NeuralActivateDerivativeAutoTest(W*H - O, error, relative, slope, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncUW
        {
            typedef void(*FuncPtr)(const float * x, size_t size, const float * a, const float * b, float * d, float * w);

            FuncPtr func;
            String description;

            FuncUW(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & x, float a, float b, const View & d, const View & w, View & dDst, View & wDst) const
            {
                Simd::Copy(d, dDst);
                Simd::Copy(w, wDst);
                TEST_PERFORMANCE_TEST(description);
                func((float*)x.data, x.width, &a, &b, (float*)dDst.data, (float*)wDst.data);
            }
        };
    }
#define FUNC_UW(function) FuncUW(function, #function)

    bool NeuralUpdateWeightsAutoTest(int size, float error, bool relative, const FuncUW & f1, const FuncUW & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

        View x(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View d(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View w(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(x, -10.0f, 10.0f);
        FillRandom32f(d, -10.0f, 10.0f);
        FillRandom32f(w, -10.0f, 10.0f);

        float a = 2.0, b = 3.0;

        View dDst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View wDst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View dDst2(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View wDst2(size, 1, View::Float, NULL, TEST_ALIGN(size));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(x, a, b, d, w, dDst1, wDst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(x, a, b, d, w, dDst2, wDst2));

        result = result && Compare(dDst1, dDst2, error, true, 32, relative, "d");
        result = result && Compare(wDst1, wDst2, error, true, 32, relative, "w");

        return result;
    }

    bool NeuralUpdateWeightsAutoTest(float error, bool relative, const FuncUW & f1, const FuncUW & f2)
    {
        bool result = true;

        result = result && NeuralUpdateWeightsAutoTest(W*H, error, relative, f1, f2);
        result = result && NeuralUpdateWeightsAutoTest(W*H + O, error, relative, f1, f2);
        result = result && NeuralUpdateWeightsAutoTest(W*H - O, error, relative, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncAGU
        {
            typedef void(*FuncPtr)(const float * delta, size_t size, size_t batch, const float * alpha, const float * epsilon, float * gradient, float * weight);

            FuncPtr func;
            String description;

            FuncAGU(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & delta, size_t batch, float alpha, float epsilon, const View & gradientSrc, const View & weightSrc, View & gradientDst, View & weightDst) const
            {
                Simd::Copy(gradientSrc, gradientDst);
                Simd::Copy(weightSrc, weightDst);
                TEST_PERFORMANCE_TEST(description);
                func((float*)delta.data, delta.width, batch, &alpha, &epsilon, (float*)gradientDst.data, (float*)weightDst.data);
            }
        };
    }
#define FUNC_AGU(function) FuncAGU(function, #function)

    bool NeuralAdaptiveGradientUpdateAutoTest(int size, float error, bool relative, const FuncAGU & f1, const FuncAGU & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << size << "].");

        View delta(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View gradientSrc(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View weightSrc(size, 1, View::Float, NULL, TEST_ALIGN(size));
        FillRandom32f(delta, -1.0f, 1.0f);
        FillRandom32f(gradientSrc, 0.0f, 0.0001f);
        FillRandom32f(weightSrc, -1.0f, 1.0f);

        const size_t batch = 2;
        const float alpha = 1.0f, epsilon = 0.0001f;

        View gradientDst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View weightDst1(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View gradientDst2(size, 1, View::Float, NULL, TEST_ALIGN(size));
        View weightDst2(size, 1, View::Float, NULL, TEST_ALIGN(size));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(delta, batch, alpha, epsilon, gradientSrc, weightSrc, gradientDst1, weightDst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(delta, batch, alpha, epsilon, gradientSrc, weightSrc, gradientDst2, weightDst2));

        result = result && Compare(gradientDst1, gradientDst2, error, true, 32, relative, "gradient");
        result = result && Compare(weightDst1, weightDst2, error, true, 32, relative, "weight");

        return result;
    }

    bool NeuralAdaptiveGradientUpdateAutoTest(float error, bool relative, const FuncAGU & f1, const FuncAGU & f2)
    {
        bool result = true;

        result = result && NeuralAdaptiveGradientUpdateAutoTest(W*H, error, relative, f1, f2);
        result = result && NeuralAdaptiveGradientUpdateAutoTest(W*H + O, error, relative, f1, f2);
        result = result && NeuralAdaptiveGradientUpdateAutoTest(W*H - O, error, relative, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncC2
        {
            typedef void(*FuncPtr)(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);

            FuncPtr func;
            String description;

            FuncC2(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, const Size& size, const float * weights, const View & dstSrc, View & dstDst) const
            {
                Simd::Copy(dstSrc, dstDst);
                TEST_PERFORMANCE_TEST(description);
                func((float*)src.data, src.stride/sizeof(float), size.x, size.y, weights, (float*)dstDst.data, dstDst.stride/sizeof(float));
            }
        };
    }
#define FUNC_C2(function) FuncC2(function, #function)

    bool NeuralAddConvolutionAutoTest(int width, int height, float eps, int half, bool forward, const FuncC2 & f1, const FuncC2 & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        Size size(width, height), border(half, half), s(size), d(size);
        if (forward)
            s += 2*border;
        else
            d += 2*border;

        View src(s.x, s.y, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(src, 0, 1);

        View weights(Simd::Square(1 + 2 * half), 1, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(weights, -1, 1);

        View dstSrc(d.x, d.y, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(dstSrc, -1000, 1000);

        View dstDst1(d.x, d.y, View::Float, NULL, TEST_ALIGN(width));
        View dstDst2(d.x, d.y, View::Float, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, size, (float*)weights.data, dstSrc, dstDst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, size, (float*)weights.data, dstSrc, dstDst2));

        result = Compare(dstDst1, dstDst2, eps, true, 32);

        return result;
    }

    bool NeuralAddConvolutionAutoTest(float eps, int half, bool forward, const FuncC2 & f1, const FuncC2 & f2)
    {
        bool result = true;

        result = result && NeuralAddConvolutionAutoTest(W, H, eps, half, forward, f1, f2);
        result = result && NeuralAddConvolutionAutoTest(W - O, H + O, eps, half, forward, f1, f2);
        result = result && NeuralAddConvolutionAutoTest(W + O, H - O, eps, half, forward, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncCS
        {
            typedef void(*FuncPtr)(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums);

            FuncPtr func;
            String description;

            FuncCS(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, const View & dst, const View & sumsSrc, View & sumsDst) const
            {
                Simd::Copy(sumsSrc, sumsDst);
                TEST_PERFORMANCE_TEST(description);
                func((float*)src.data, src.stride / sizeof(float), (float*)dst.data, dst.stride / sizeof(float), dst.width, dst.height, (float*)sumsDst.data);
            }
        };
    }
#define FUNC_CS(function) FuncCS(function, #function)

    bool NeuralAddConvolutionSumAutoTest(int width, int height, float eps, int half, const FuncCS & f1, const FuncCS & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        View src(width + 2*half, height + 2*half, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(src, -1, 1);

        View dst(width, height, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(dst, -1, 1);

        View sumsSrc(Simd::Square(1 + 2 * half), 1, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(sumsSrc, 2000, 3000);

        View sumsDst1(Simd::Square(1 + 2 * half), 1, View::Float, NULL, TEST_ALIGN(width));
        View sumsDst2(Simd::Square(1 + 2 * half), 1, View::Float, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, dst, sumsSrc, sumsDst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, dst, sumsSrc, sumsDst2));

        result = Compare(sumsDst1, sumsDst2, eps, true, 32);

        return result;
    }

    bool NeuralAddConvolutionSumAutoTest(float eps, int half, const FuncCS & f1, const FuncCS & f2)
    {
        bool result = true;

        result = result && NeuralAddConvolutionSumAutoTest(W, H, eps, half, f1, f2);
        result = result && NeuralAddConvolutionSumAutoTest(W - O, H + O, eps, half, f1, f2);
        result = result && NeuralAddConvolutionSumAutoTest(W + O, H - O, eps, half, f1, f2);

        return result;
    }


    namespace
    {
        struct FuncM
        {
            typedef void(*FuncPtr)(const float * src, size_t srcStride, size_t width, size_t height, float * dst, size_t dstStride);

            FuncPtr func;
            String description;

            FuncM(const FuncPtr & f, const String & d) : func(f), description(d) {}

            void Call(const View & src, View & dst) const
            {
                TEST_PERFORMANCE_TEST(description);
                func((float*)src.data, src.stride/sizeof(float), src.width, src.height, (float*)dst.data, dst.stride/sizeof(float));
            }
        };
    }
#define FUNC_M(function) FuncM(function, #function)

    bool NeuralMax2x2AutoTest(int width, int height, float eps, const FuncM & f1, const FuncM & f2)
    {
        bool result = true;

        TEST_LOG_SS(Info, "Test " << f1.description << " & " << f2.description << " [" << width << ", " << height << "].");

        View src(width, height, View::Float, NULL, TEST_ALIGN(width));
        FillRandom32f(src, -1, 1);

        View dst1(width / 2, height / 2, View::Float, NULL, TEST_ALIGN(width));
        View dst2(width / 2, height / 2, View::Float, NULL, TEST_ALIGN(width));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f1.Call(src, dst1));

        TEST_EXECUTE_AT_LEAST_MIN_TIME(f2.Call(src, dst2));

        result = Compare(dst1, dst2, eps, true, 32);

        return result;
    }

    bool NeuralMax2x2AutoTest(float eps, const FuncM & f1, const FuncM & f2)
    {
        bool result = true;

        result = result && NeuralMax2x2AutoTest(W, H, eps, f1, f2);
        result = result && NeuralMax2x2AutoTest(W - E, H + E, eps, f1, f2);
        result = result && NeuralMax2x2AutoTest(W + E, H - E, eps, f1, f2);

        return result;
    }


}


