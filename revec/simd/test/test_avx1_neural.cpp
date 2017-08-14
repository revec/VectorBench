
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
#define SIMD_AVX_ENABLE
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
bool AutoTest3()	{
		bool result = true;

		result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Base::NeuralRoughSigmoid), FUNC_AF(SimdNeuralRoughSigmoid));

#ifdef SIMD_SSE_ENABLE
		if (Simd::Sse::Enable)
			result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Sse::NeuralRoughSigmoid), FUNC_AF(SimdNeuralRoughSigmoid));
#endif 

#ifdef SIMD_AVX_ENABLE
		if (Simd::Avx::Enable)
			result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Avx::NeuralRoughSigmoid), FUNC_AF(SimdNeuralRoughSigmoid));
#endif

#ifdef SIMD_VSX_ENABLE
		if (Simd::Vsx::Enable)
			result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Vsx::NeuralRoughSigmoid), FUNC_AF(SimdNeuralRoughSigmoid));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Neon::NeuralRoughSigmoid), FUNC_AF(SimdNeuralRoughSigmoid));
#endif

		return result;
	}
bool AutoTest4()    {
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
bool AutoTest5()    {
        bool result = true;

        result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Base::NeuralRoughTanh), FUNC_AF(SimdNeuralRoughTanh));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Sse::NeuralRoughTanh), FUNC_AF(SimdNeuralRoughTanh));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Avx::NeuralRoughTanh), FUNC_AF(SimdNeuralRoughTanh));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 1.1f, FUNC_AF(Simd::Neon::NeuralRoughTanh), FUNC_AF(SimdNeuralRoughTanh));
#endif

        return result;
    }
bool AutoTest6()    {
        bool result = true;

        result = result && NeuralActivateFunctionAutoTest(EPS, false, 0.5f, FUNC_AF(Simd::Base::NeuralRelu), FUNC_AF(SimdNeuralRelu));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 0.5f, FUNC_AF(Simd::Sse::NeuralRelu), FUNC_AF(SimdNeuralRelu));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 0.5f, FUNC_AF(Simd::Avx::NeuralRelu), FUNC_AF(SimdNeuralRelu));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateFunctionAutoTest(EPS, false, 0.5f, FUNC_AF(Simd::Neon::NeuralRelu), FUNC_AF(SimdNeuralRelu));
#endif

        return result;
    }
bool AutoTest7()    {
        bool result = true;

        result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Base::NeuralDerivativeSigmoid), FUNC_AD(SimdNeuralDerivativeSigmoid));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Sse::NeuralDerivativeSigmoid), FUNC_AD(SimdNeuralDerivativeSigmoid));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Avx::NeuralDerivativeSigmoid), FUNC_AD(SimdNeuralDerivativeSigmoid));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Neon::NeuralDerivativeSigmoid), FUNC_AD(SimdNeuralDerivativeSigmoid));
#endif

        return result;
    }
bool AutoTest8()    {
        bool result = true;

        result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Base::NeuralDerivativeTanh), FUNC_AD(SimdNeuralDerivativeTanh));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Sse::NeuralDerivativeTanh), FUNC_AD(SimdNeuralDerivativeTanh));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Avx::NeuralDerivativeTanh), FUNC_AD(SimdNeuralDerivativeTanh));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 3.0f, FUNC_AD(Simd::Neon::NeuralDerivativeTanh), FUNC_AD(SimdNeuralDerivativeTanh));
#endif

        return result;
    }
bool AutoTest9()    {
        bool result = true;

        result = result && NeuralActivateDerivativeAutoTest(EPS, true, 0.5f, FUNC_AD(Simd::Base::NeuralDerivativeRelu), FUNC_AD(SimdNeuralDerivativeRelu));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 0.5f, FUNC_AD(Simd::Sse::NeuralDerivativeRelu), FUNC_AD(SimdNeuralDerivativeRelu));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 0.5f, FUNC_AD(Simd::Avx::NeuralDerivativeRelu), FUNC_AD(SimdNeuralDerivativeRelu));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralActivateDerivativeAutoTest(EPS, true, 0.5f, FUNC_AD(Simd::Neon::NeuralDerivativeRelu), FUNC_AD(SimdNeuralDerivativeRelu));
#endif

        return result;
    }
bool AutoTest10()    {
        bool result = true;

        result = result && NeuralUpdateWeightsAutoTest(EPS, false, FUNC_UW(Simd::Base::NeuralUpdateWeights), FUNC_UW(SimdNeuralUpdateWeights));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralUpdateWeightsAutoTest(EPS, false, FUNC_UW(Simd::Sse::NeuralUpdateWeights), FUNC_UW(SimdNeuralUpdateWeights));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralUpdateWeightsAutoTest(EPS, false, FUNC_UW(Simd::Avx::NeuralUpdateWeights), FUNC_UW(SimdNeuralUpdateWeights));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralUpdateWeightsAutoTest(EPS, false, FUNC_UW(Simd::Neon::NeuralUpdateWeights), FUNC_UW(SimdNeuralUpdateWeights));
#endif

        return result;
    }
bool AutoTest11()    {
        bool result = true;

        result = result && NeuralAdaptiveGradientUpdateAutoTest(EPS, false, FUNC_AGU(Simd::Base::NeuralAdaptiveGradientUpdate), FUNC_AGU(SimdNeuralAdaptiveGradientUpdate));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAdaptiveGradientUpdateAutoTest(EPS, false, FUNC_AGU(Simd::Sse::NeuralAdaptiveGradientUpdate), FUNC_AGU(SimdNeuralAdaptiveGradientUpdate));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAdaptiveGradientUpdateAutoTest(EPS, false, FUNC_AGU(Simd::Avx::NeuralAdaptiveGradientUpdate), FUNC_AGU(SimdNeuralAdaptiveGradientUpdate));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAdaptiveGradientUpdateAutoTest(EPS, false, FUNC_AGU(Simd::Neon::NeuralAdaptiveGradientUpdate), FUNC_AGU(SimdNeuralAdaptiveGradientUpdate));
#endif

        return result;
    }
bool AutoTest12()    {
        bool result = true;

        result = result && NeuralAddConvolutionAutoTest(EPS, 1, true, FUNC_C2(Simd::Base::NeuralAddConvolution3x3), FUNC_C2(SimdNeuralAddConvolution3x3));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 1, true, FUNC_C2(Simd::Sse::NeuralAddConvolution3x3), FUNC_C2(SimdNeuralAddConvolution3x3));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 1, true, FUNC_C2(Simd::Avx::NeuralAddConvolution3x3), FUNC_C2(SimdNeuralAddConvolution3x3));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 1, true, FUNC_C2(Simd::Neon::NeuralAddConvolution3x3), FUNC_C2(SimdNeuralAddConvolution3x3));
#endif

        return result;
    }
bool AutoTest13()    {
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
bool AutoTest14()    {
        bool result = true;

        result = result && NeuralAddConvolutionAutoTest(EPS, 1, false, FUNC_C2(Simd::Base::NeuralAddConvolution3x3Back), FUNC_C2(SimdNeuralAddConvolution3x3Back));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 1, false, FUNC_C2(Simd::Sse::NeuralAddConvolution3x3Back), FUNC_C2(SimdNeuralAddConvolution3x3Back));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 1, false, FUNC_C2(Simd::Avx::NeuralAddConvolution3x3Back), FUNC_C2(SimdNeuralAddConvolution3x3Back));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 1, false, FUNC_C2(Simd::Neon::NeuralAddConvolution3x3Back), FUNC_C2(SimdNeuralAddConvolution3x3Back));
#endif

        return result;
    }
bool AutoTest15()    {
        bool result = true;

        result = result && NeuralAddConvolutionAutoTest(EPS, 2, false, FUNC_C2(Simd::Base::NeuralAddConvolution5x5Back), FUNC_C2(SimdNeuralAddConvolution5x5Back));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, false, FUNC_C2(Simd::Sse::NeuralAddConvolution5x5Back), FUNC_C2(SimdNeuralAddConvolution5x5Back));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, false, FUNC_C2(Simd::Avx::NeuralAddConvolution5x5Back), FUNC_C2(SimdNeuralAddConvolution5x5Back));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralAddConvolutionAutoTest(EPS, 2, false, FUNC_C2(Simd::Neon::NeuralAddConvolution5x5Back), FUNC_C2(SimdNeuralAddConvolution5x5Back));
#endif

        return result;
    }
bool AutoTest16()    {
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
bool AutoTest17()    {
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
bool AutoTest18()    {
        bool result = true;

        result = result && NeuralMax2x2AutoTest(EPS, FUNC_M(Simd::Base::NeuralMax2x2), FUNC_M(SimdNeuralMax2x2));

#ifdef SIMD_SSE_ENABLE
        if (Simd::Sse::Enable)
            result = result && NeuralMax2x2AutoTest(EPS, FUNC_M(Simd::Sse::NeuralMax2x2), FUNC_M(SimdNeuralMax2x2));
#endif 

#ifdef SIMD_AVX_ENABLE
        if (Simd::Avx::Enable)
            result = result && NeuralMax2x2AutoTest(EPS, FUNC_M(Simd::Avx::NeuralMax2x2), FUNC_M(SimdNeuralMax2x2));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && NeuralMax2x2AutoTest(EPS, FUNC_M(Simd::Neon::NeuralMax2x2), FUNC_M(SimdNeuralMax2x2));
#endif

        return result;
    }
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_18

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
TEST_LOG_SS(Info,  "AutoTest8 is started :");
bool result8 = Test::AutoTest8();
TEST_LOG_SS(Info, "AutoTest8 is finished " << (result8 ? "successfully." : "with errors!") << std::endl);
if(!result8)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest9 is started :");
bool result9 = Test::AutoTest9();
TEST_LOG_SS(Info, "AutoTest9 is finished " << (result9 ? "successfully." : "with errors!") << std::endl);
if(!result9)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest10 is started :");
bool result10 = Test::AutoTest10();
TEST_LOG_SS(Info, "AutoTest10 is finished " << (result10 ? "successfully." : "with errors!") << std::endl);
if(!result10)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest11 is started :");
bool result11 = Test::AutoTest11();
TEST_LOG_SS(Info, "AutoTest11 is finished " << (result11 ? "successfully." : "with errors!") << std::endl);
if(!result11)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest12 is started :");
bool result12 = Test::AutoTest12();
TEST_LOG_SS(Info, "AutoTest12 is finished " << (result12 ? "successfully." : "with errors!") << std::endl);
if(!result12)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest13 is started :");
bool result13 = Test::AutoTest13();
TEST_LOG_SS(Info, "AutoTest13 is finished " << (result13 ? "successfully." : "with errors!") << std::endl);
if(!result13)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest14 is started :");
bool result14 = Test::AutoTest14();
TEST_LOG_SS(Info, "AutoTest14 is finished " << (result14 ? "successfully." : "with errors!") << std::endl);
if(!result14)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest15 is started :");
bool result15 = Test::AutoTest15();
TEST_LOG_SS(Info, "AutoTest15 is finished " << (result15 ? "successfully." : "with errors!") << std::endl);
if(!result15)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest16 is started :");
bool result16 = Test::AutoTest16();
TEST_LOG_SS(Info, "AutoTest16 is finished " << (result16 ? "successfully." : "with errors!") << std::endl);
if(!result16)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest17 is started :");
bool result17 = Test::AutoTest17();
TEST_LOG_SS(Info, "AutoTest17 is finished " << (result17 ? "successfully." : "with errors!") << std::endl);
if(!result17)
{
  return 1;
}
TEST_LOG_SS(Info,  "AutoTest18 is started :");
bool result18 = Test::AutoTest18();
TEST_LOG_SS(Info, "AutoTest18 is finished " << (result18 ? "successfully." : "with errors!") << std::endl);
if(!result18)
{
  return 1;
}
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
