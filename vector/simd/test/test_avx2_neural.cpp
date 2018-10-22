
/*
* Tests for Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2017 Yermalayeu Ihar,
*               2014-2017 Antonenka Mikhail.
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
#include "Test/TestPerformance.h"
#include "Test/TestUtils.h"
#include "Test/TestLog.h"
#undef SIMD_SSE_ENABLE
#undef SIMD_AVX_ENABLE
#undef SIMD_AVX2_ENABLE
#undef SIMD_VSX_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_AVX2_ENABLE
#include "Test/TestNeural.h"
#undef SIMD_SSE3_ENABLE
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && NeuralProductSumAutoTest(EPS, FUNC_PS(Simd::Base::NeuralProductSum), FUNC_PS(SimdNeuralProductSum));

#ifdef SIMD_SSE_ENABLE
		if (Simd::Sse::Enable)
			result = result && NeuralProductSumAutoTest(EPS, FUNC_PS(Simd::Sse::NeuralProductSum), FUNC_PS(SimdNeuralProductSum));
#endif 

#ifdef SIMD_AVX_ENABLE
		if (Simd::Avx::Enable)
			result = result && NeuralProductSumAutoTest(EPS, FUNC_PS(Simd::Avx::NeuralProductSum), FUNC_PS(SimdNeuralProductSum));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && NeuralProductSumAutoTest(EPS, FUNC_PS(Simd::Avx2::NeuralProductSum), FUNC_PS(SimdNeuralProductSum));
#endif

#ifdef SIMD_VSX_ENABLE
		if (Simd::Vsx::Enable)
			result = result && NeuralProductSumAutoTest(EPS, FUNC_PS(Simd::Vsx::NeuralProductSum), FUNC_PS(SimdNeuralProductSum));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralProductSumAutoTest(EPS, FUNC_PS(Simd::Neon::NeuralProductSum), FUNC_PS(SimdNeuralProductSum));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && NeuralAddVectorMultipliedByValueAutoTest(EPS, FUNC_AVMV(Simd::Base::NeuralAddVectorMultipliedByValue), FUNC_AVMV(SimdNeuralAddVectorMultipliedByValue));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddVectorMultipliedByValueAutoTest(EPS, FUNC_AVMV(Simd::Sse::NeuralAddVectorMultipliedByValue), FUNC_AVMV(SimdNeuralAddVectorMultipliedByValue));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddVectorMultipliedByValueAutoTest(EPS, FUNC_AVMV(Simd::Avx::NeuralAddVectorMultipliedByValue), FUNC_AVMV(SimdNeuralAddVectorMultipliedByValue));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && NeuralAddVectorMultipliedByValueAutoTest(EPS, FUNC_AVMV(Simd::Avx2::NeuralAddVectorMultipliedByValue), FUNC_AVMV(SimdNeuralAddVectorMultipliedByValue));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddVectorMultipliedByValueAutoTest(EPS, FUNC_AVMV(Simd::Neon::NeuralAddVectorMultipliedByValue), FUNC_AVMV(SimdNeuralAddVectorMultipliedByValue));
#endif

        return result;
    }
bool AutoTest3()    {
        bool result = true;

        result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Base::NeuralRoughSigmoid2), FUNC_AF(SimdNeuralRoughSigmoid2));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Sse::NeuralRoughSigmoid2), FUNC_AF(SimdNeuralRoughSigmoid2));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Avx::NeuralRoughSigmoid2), FUNC_AF(SimdNeuralRoughSigmoid2));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Avx2::NeuralRoughSigmoid2), FUNC_AF(SimdNeuralRoughSigmoid2));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Neon::NeuralRoughSigmoid2), FUNC_AF(SimdNeuralRoughSigmoid2));
#endif

        return result;
    }
bool AutoTest4()    {
        bool result = true;

        result = result && NeuralAddConvolutionAutoTest(EPS, 2, true, FUNC_C2(Simd::Base::NeuralAddConvolution5x5), FUNC_C2(SimdNeuralAddConvolution5x5));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, true, FUNC_C2(Simd::Sse::NeuralAddConvolution5x5), FUNC_C2(SimdNeuralAddConvolution5x5));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, true, FUNC_C2(Simd::Avx::NeuralAddConvolution5x5), FUNC_C2(SimdNeuralAddConvolution5x5));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, true, FUNC_C2(Simd::Avx2::NeuralAddConvolution5x5), FUNC_C2(SimdNeuralAddConvolution5x5));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, true, FUNC_C2(Simd::Neon::NeuralAddConvolution5x5), FUNC_C2(SimdNeuralAddConvolution5x5));
#endif

        return result;
    }
bool AutoTest5()    {
        bool result = true;

        result = result && NeuralAddConvolutionSumAutoTest(EPS, 1, FUNC_CS(Simd::Base::NeuralAddConvolution3x3Sum), FUNC_CS(SimdNeuralAddConvolution3x3Sum));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 1, FUNC_CS(Simd::Sse::NeuralAddConvolution3x3Sum), FUNC_CS(SimdNeuralAddConvolution3x3Sum));
#endif 

#ifdef SIMD_SSE3_ENABLE
        if (Simd::Sse3::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 1, FUNC_CS(Simd::Sse3::NeuralAddConvolution3x3Sum), FUNC_CS(SimdNeuralAddConvolution3x3Sum));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 1, FUNC_CS(Simd::Avx::NeuralAddConvolution3x3Sum), FUNC_CS(SimdNeuralAddConvolution3x3Sum));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 1, FUNC_CS(Simd::Avx2::NeuralAddConvolution3x3Sum), FUNC_CS(SimdNeuralAddConvolution3x3Sum));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 1, FUNC_CS(Simd::Neon::NeuralAddConvolution3x3Sum), FUNC_CS(SimdNeuralAddConvolution3x3Sum));
#endif

        return result;
    }
bool AutoTest6()    {
        bool result = true;

        result = result && NeuralAddConvolutionSumAutoTest(EPS, 2, FUNC_CS(Simd::Base::NeuralAddConvolution5x5Sum), FUNC_CS(SimdNeuralAddConvolution5x5Sum));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 2, FUNC_CS(Simd::Sse::NeuralAddConvolution5x5Sum), FUNC_CS(SimdNeuralAddConvolution5x5Sum));
#endif 

#ifdef SIMD_SSE3_ENABLE
        if (Simd::Sse3::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 2, FUNC_CS(Simd::Sse3::NeuralAddConvolution5x5Sum), FUNC_CS(SimdNeuralAddConvolution5x5Sum));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 2, FUNC_CS(Simd::Avx::NeuralAddConvolution5x5Sum), FUNC_CS(SimdNeuralAddConvolution5x5Sum));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 2, FUNC_CS(Simd::Avx2::NeuralAddConvolution5x5Sum), FUNC_CS(SimdNeuralAddConvolution5x5Sum));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddConvolutionSumAutoTest(EPS, 2, FUNC_CS(Simd::Neon::NeuralAddConvolution5x5Sum), FUNC_CS(SimdNeuralAddConvolution5x5Sum));
#endif

        return result;
    }

bool AutoTest7()	{
		bool result = true;

		result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Base::NeuralConvert, true), FUNC_C1(SimdNeuralConvert, true));
		result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Base::NeuralConvert, false), FUNC_C1(SimdNeuralConvert, false));

#ifdef SIMD_SSE2_ENABLE
		if (Simd::Sse2::Enable)
		{
			result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Sse2::NeuralConvert, true), FUNC_C1(SimdNeuralConvert, true));
			result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Sse2::NeuralConvert, false), FUNC_C1(SimdNeuralConvert, false));
		}
#endif 

#ifdef SIMD_AVX2_ENABLE
		if (Simd::Avx2::Enable)
		{
			result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Avx2::NeuralConvert, true), FUNC_C1(SimdNeuralConvert, true));
			result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Avx2::NeuralConvert, false), FUNC_C1(SimdNeuralConvert, false));
		}
#endif

#ifdef SIMD_VSX_ENABLE
		if (Simd::Vsx::Enable)
		{
			result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Vsx::NeuralConvert, true), FUNC_C1(SimdNeuralConvert, true));
			result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Vsx::NeuralConvert, false), FUNC_C1(SimdNeuralConvert, false));
		}
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
        {
            result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Neon::NeuralConvert, true), FUNC_C1(SimdNeuralConvert, true));
            result = result && NeuralConvertAutoTest(EPS, FUNC_C1(Simd::Neon::NeuralConvert, false), FUNC_C1(SimdNeuralConvert, false));
        }
#endif

		return result;
}



//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_6

TEST_LOG_SS(Info,  "AutoTest1 is started :");
bool result1 = Test::AutoTest1();
TEST_LOG_SS(Info, "AutoTest1 is finished " << (result1 ? "successfully." : "with errors!") << std::endl);
if(!result1)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest2 is started :");
bool result2 = Test::AutoTest2();
TEST_LOG_SS(Info, "AutoTest2 is finished " << (result2 ? "successfully." : "with errors!") << std::endl);
if(!result2)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest3 is started :");
bool result3 = Test::AutoTest3();
TEST_LOG_SS(Info, "AutoTest3 is finished " << (result3 ? "successfully." : "with errors!") << std::endl);
if(!result3)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest4 is started :");
bool result4 = Test::AutoTest4();
TEST_LOG_SS(Info, "AutoTest4 is finished " << (result4 ? "successfully." : "with errors!") << std::endl);
if(!result4)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest5 is started :");
bool result5 = Test::AutoTest5();
TEST_LOG_SS(Info, "AutoTest5 is finished " << (result5 ? "successfully." : "with errors!") << std::endl);
if(!result5)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest6 is started :");
bool result6 = Test::AutoTest6();
TEST_LOG_SS(Info, "AutoTest6 is finished " << (result6 ? "successfully." : "with errors!") << std::endl);
if(!result6)
{
  return 1;
}

TEST_LOG_SS(Info,  "AutoTest7 is started :");
bool result7 = Test::AutoTest7();
TEST_LOG_SS(Info, "AutoTest7 is finished " << (result7 ? "successfully." : "with errors!") << std::endl);
if(!result7)
{
  return 1;
}

//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
