
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
#include "Test/TestEdgeBackground.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Base::EdgeBackgroundGrowRangeSlow), FUNC1(SimdEdgeBackgroundGrowRangeSlow));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Sse2::EdgeBackgroundGrowRangeSlow), FUNC1(SimdEdgeBackgroundGrowRangeSlow));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Avx2::EdgeBackgroundGrowRangeSlow), FUNC1(SimdEdgeBackgroundGrowRangeSlow));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Vmx::EdgeBackgroundGrowRangeSlow), FUNC1(SimdEdgeBackgroundGrowRangeSlow));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Neon::EdgeBackgroundGrowRangeSlow), FUNC1(SimdEdgeBackgroundGrowRangeSlow));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Base::EdgeBackgroundGrowRangeFast), FUNC1(SimdEdgeBackgroundGrowRangeFast));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Sse2::EdgeBackgroundGrowRangeFast), FUNC1(SimdEdgeBackgroundGrowRangeFast));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Avx2::EdgeBackgroundGrowRangeFast), FUNC1(SimdEdgeBackgroundGrowRangeFast));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Vmx::EdgeBackgroundGrowRangeFast), FUNC1(SimdEdgeBackgroundGrowRangeFast));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Neon::EdgeBackgroundGrowRangeFast), FUNC1(SimdEdgeBackgroundGrowRangeFast));
#endif

        return result;
    }
bool AutoTest3()	{
		bool result = true;

		result = result && EdgeBackgroundIncrementCountAutoTest(FUNC2(Simd::Base::EdgeBackgroundIncrementCount), FUNC2(SimdEdgeBackgroundIncrementCount));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundIncrementCountAutoTest(FUNC2(Simd::Sse2::EdgeBackgroundIncrementCount), FUNC2(SimdEdgeBackgroundIncrementCount));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundIncrementCountAutoTest(FUNC2(Simd::Avx2::EdgeBackgroundIncrementCount), FUNC2(SimdEdgeBackgroundIncrementCount));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundIncrementCountAutoTest(FUNC2(Simd::Vmx::EdgeBackgroundIncrementCount), FUNC2(SimdEdgeBackgroundIncrementCount));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundIncrementCountAutoTest(FUNC2(Simd::Neon::EdgeBackgroundIncrementCount), FUNC2(SimdEdgeBackgroundIncrementCount));
#endif 

		return result;
	}
bool AutoTest4()	{
		bool result = true;

		result = result && EdgeBackgroundAdjustRangeAutoTest(FUNC3(Simd::Base::EdgeBackgroundAdjustRange), FUNC3(SimdEdgeBackgroundAdjustRange));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundAdjustRangeAutoTest(FUNC3(Simd::Sse2::EdgeBackgroundAdjustRange), FUNC3(SimdEdgeBackgroundAdjustRange));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundAdjustRangeAutoTest(FUNC3(Simd::Avx2::EdgeBackgroundAdjustRange), FUNC3(SimdEdgeBackgroundAdjustRange));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundAdjustRangeAutoTest(FUNC3(Simd::Vmx::EdgeBackgroundAdjustRange), FUNC3(SimdEdgeBackgroundAdjustRange));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundAdjustRangeAutoTest(FUNC3(Simd::Neon::EdgeBackgroundAdjustRange), FUNC3(SimdEdgeBackgroundAdjustRange));
#endif 

		return result;
	}
bool AutoTest5()	{
		bool result = true;

		result = result && EdgeBackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Base::EdgeBackgroundAdjustRangeMasked), FUNC4(SimdEdgeBackgroundAdjustRangeMasked));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Sse2::EdgeBackgroundAdjustRangeMasked), FUNC4(SimdEdgeBackgroundAdjustRangeMasked));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Avx2::EdgeBackgroundAdjustRangeMasked), FUNC4(SimdEdgeBackgroundAdjustRangeMasked));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Vmx::EdgeBackgroundAdjustRangeMasked), FUNC4(SimdEdgeBackgroundAdjustRangeMasked));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Neon::EdgeBackgroundAdjustRangeMasked), FUNC4(SimdEdgeBackgroundAdjustRangeMasked));
#endif 

		return result;
	}
bool AutoTest6()    {
        bool result = true;

        result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Base::EdgeBackgroundShiftRange), FUNC1(SimdEdgeBackgroundShiftRange));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Sse2::EdgeBackgroundShiftRange), FUNC1(SimdEdgeBackgroundShiftRange));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Avx2::EdgeBackgroundShiftRange), FUNC1(SimdEdgeBackgroundShiftRange));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Vmx::EdgeBackgroundShiftRange), FUNC1(SimdEdgeBackgroundShiftRange));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundChangeRangeAutoTest(FUNC1(Simd::Neon::EdgeBackgroundShiftRange), FUNC1(SimdEdgeBackgroundShiftRange));
#endif

        return result;
    }
bool AutoTest7()    {
        bool result = true;

        result = result && EdgeBackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Base::EdgeBackgroundShiftRangeMasked), FUNC5(SimdEdgeBackgroundShiftRangeMasked));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && EdgeBackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Sse2::EdgeBackgroundShiftRangeMasked), FUNC5(SimdEdgeBackgroundShiftRangeMasked));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && EdgeBackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Avx2::EdgeBackgroundShiftRangeMasked), FUNC5(SimdEdgeBackgroundShiftRangeMasked));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && EdgeBackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Vmx::EdgeBackgroundShiftRangeMasked), FUNC5(SimdEdgeBackgroundShiftRangeMasked));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && EdgeBackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Neon::EdgeBackgroundShiftRangeMasked), FUNC5(SimdEdgeBackgroundShiftRangeMasked));
#endif 

        return result;
    }
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_7

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
