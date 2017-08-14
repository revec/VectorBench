
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
#undef SIMD_SSE2_ENABLE
#undef SIMD_AVX2_ENABLE
#undef SIMD_VMX_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_AVX2_ENABLE
#include "Test/TestConditional.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && ConditionalCount8uAutoTest(FUNC_C8U(Simd::Base::ConditionalCount8u), FUNC_C8U(SimdConditionalCount8u));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && ConditionalCount8uAutoTest(FUNC_C8U(Simd::Sse2::ConditionalCount8u), FUNC_C8U(SimdConditionalCount8u));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ConditionalCount8uAutoTest(FUNC_C8U(Simd::Avx2::ConditionalCount8u), FUNC_C8U(SimdConditionalCount8u));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ConditionalCount8uAutoTest(FUNC_C8U(Simd::Vmx::ConditionalCount8u), FUNC_C8U(SimdConditionalCount8u));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ConditionalCount8uAutoTest(FUNC_C8U(Simd::Neon::ConditionalCount8u), FUNC_C8U(SimdConditionalCount8u));
#endif 

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && ConditionalCount16iAutoTest(FUNC_C16I(Simd::Base::ConditionalCount16i), FUNC_C16I(SimdConditionalCount16i));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && ConditionalCount16iAutoTest(FUNC_C16I(Simd::Sse2::ConditionalCount16i), FUNC_C16I(SimdConditionalCount16i));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ConditionalCount16iAutoTest(FUNC_C16I(Simd::Avx2::ConditionalCount16i), FUNC_C16I(SimdConditionalCount16i));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ConditionalCount16iAutoTest(FUNC_C16I(Simd::Vmx::ConditionalCount16i), FUNC_C16I(SimdConditionalCount16i));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ConditionalCount16iAutoTest(FUNC_C16I(Simd::Neon::ConditionalCount16i), FUNC_C16I(SimdConditionalCount16i));
#endif

        return result;
    }
bool AutoTest3()    {
        bool result = true;

        result = result && ConditionalSumAutoTest(FUNC_S(Simd::Base::ConditionalSum), FUNC_S(SimdConditionalSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Sse2::ConditionalSum), FUNC_S(SimdConditionalSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Avx2::ConditionalSum), FUNC_S(SimdConditionalSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Vmx::ConditionalSum), FUNC_S(SimdConditionalSum));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ConditionalSumAutoTest(FUNC_S(Simd::Neon::ConditionalSum), FUNC_S(SimdConditionalSum));
#endif 

        return result;
    }
bool AutoTest4()    {
        bool result = true;

        result = result && ConditionalSumAutoTest(FUNC_S(Simd::Base::ConditionalSquareSum), FUNC_S(SimdConditionalSquareSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Sse2::ConditionalSquareSum), FUNC_S(SimdConditionalSquareSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Avx2::ConditionalSquareSum), FUNC_S(SimdConditionalSquareSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Vmx::ConditionalSquareSum), FUNC_S(SimdConditionalSquareSum));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ConditionalSumAutoTest(FUNC_S(Simd::Neon::ConditionalSquareSum), FUNC_S(SimdConditionalSquareSum));
#endif

        return result;
    }
bool AutoTest5()    {
        bool result = true;

        result = result && ConditionalSumAutoTest(FUNC_S(Simd::Base::ConditionalSquareGradientSum), FUNC_S(SimdConditionalSquareGradientSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Sse2::ConditionalSquareGradientSum), FUNC_S(SimdConditionalSquareGradientSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Avx2::ConditionalSquareGradientSum), FUNC_S(SimdConditionalSquareGradientSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ConditionalSumAutoTest(FUNC_S(Simd::Vmx::ConditionalSquareGradientSum), FUNC_S(SimdConditionalSquareGradientSum));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ConditionalSumAutoTest(FUNC_S(Simd::Neon::ConditionalSquareGradientSum), FUNC_S(SimdConditionalSquareGradientSum));
#endif 

        return result;
    }
bool AutoTest6()	{
		bool result = true;

		result = result && ConditionalFillAutoTest(FUNC_F(Simd::Base::ConditionalFill), FUNC_F(SimdConditionalFill));

#ifdef SIMD_SSE2_ENABLE
		if (Simd::Sse2::Enable)
			result = result && ConditionalFillAutoTest(FUNC_F(Simd::Sse2::ConditionalFill), FUNC_F(SimdConditionalFill));
#endif 

#ifdef SIMD_AVX2_ENABLE
		if (Simd::Avx2::Enable)
			result = result && ConditionalFillAutoTest(FUNC_F(Simd::Avx2::ConditionalFill), FUNC_F(SimdConditionalFill));
#endif 

#ifdef SIMD_VMX_ENABLE
		if (Simd::Vmx::Enable)
			result = result && ConditionalFillAutoTest(FUNC_F(Simd::Vmx::ConditionalFill), FUNC_F(SimdConditionalFill));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ConditionalFillAutoTest(FUNC_F(Simd::Neon::ConditionalFill), FUNC_F(SimdConditionalFill));
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
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
