
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
#define SIMD_VMX_ENABLE
#include "Test/TestBackground.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()	{
		bool result = true;

		result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Base::BackgroundGrowRangeSlow), FUNC1(SimdBackgroundGrowRangeSlow));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Sse2::BackgroundGrowRangeSlow), FUNC1(SimdBackgroundGrowRangeSlow));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Avx2::BackgroundGrowRangeSlow), FUNC1(SimdBackgroundGrowRangeSlow));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Vmx::BackgroundGrowRangeSlow), FUNC1(SimdBackgroundGrowRangeSlow));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Neon::BackgroundGrowRangeSlow), FUNC1(SimdBackgroundGrowRangeSlow));
#endif 

		return result;
	}
bool AutoTest2()	{
        bool result = true;

        result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Base::BackgroundGrowRangeFast), FUNC1(SimdBackgroundGrowRangeFast));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Sse2::BackgroundGrowRangeFast), FUNC1(SimdBackgroundGrowRangeFast));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Avx2::BackgroundGrowRangeFast), FUNC1(SimdBackgroundGrowRangeFast));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Vmx::BackgroundGrowRangeFast), FUNC1(SimdBackgroundGrowRangeFast));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Neon::BackgroundGrowRangeFast), FUNC1(SimdBackgroundGrowRangeFast));
#endif
        return result;
	}
bool AutoTest3()	{
		bool result = true;

		result = result && BackgroundIncrementCountAutoTest(FUNC2(Simd::Base::BackgroundIncrementCount), FUNC2(SimdBackgroundIncrementCount));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundIncrementCountAutoTest(FUNC2(Simd::Sse2::BackgroundIncrementCount), FUNC2(SimdBackgroundIncrementCount));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundIncrementCountAutoTest(FUNC2(Simd::Avx2::BackgroundIncrementCount), FUNC2(SimdBackgroundIncrementCount));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundIncrementCountAutoTest(FUNC2(Simd::Vmx::BackgroundIncrementCount), FUNC2(SimdBackgroundIncrementCount));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundIncrementCountAutoTest(FUNC2(Simd::Neon::BackgroundIncrementCount), FUNC2(SimdBackgroundIncrementCount));
#endif 

		return result;
	}
bool AutoTest4()	{
		bool result = true;

		result = result && BackgroundAdjustRangeAutoTest(FUNC3(Simd::Base::BackgroundAdjustRange), FUNC3(SimdBackgroundAdjustRange));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundAdjustRangeAutoTest(FUNC3(Simd::Sse2::BackgroundAdjustRange), FUNC3(SimdBackgroundAdjustRange));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundAdjustRangeAutoTest(FUNC3(Simd::Avx2::BackgroundAdjustRange), FUNC3(SimdBackgroundAdjustRange));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundAdjustRangeAutoTest(FUNC3(Simd::Vmx::BackgroundAdjustRange), FUNC3(SimdBackgroundAdjustRange));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundAdjustRangeAutoTest(FUNC3(Simd::Neon::BackgroundAdjustRange), FUNC3(SimdBackgroundAdjustRange));
#endif
		return result;
	}
bool AutoTest5()    {
        bool result = true;

        result = result && BackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Base::BackgroundAdjustRangeMasked), FUNC4(SimdBackgroundAdjustRangeMasked));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Sse2::BackgroundAdjustRangeMasked), FUNC4(SimdBackgroundAdjustRangeMasked));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Avx2::BackgroundAdjustRangeMasked), FUNC4(SimdBackgroundAdjustRangeMasked));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Vmx::BackgroundAdjustRangeMasked), FUNC4(SimdBackgroundAdjustRangeMasked));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundAdjustRangeMaskedAutoTest(FUNC4(Simd::Neon::BackgroundAdjustRangeMasked), FUNC4(SimdBackgroundAdjustRangeMasked));
#endif 
		
		return result;
    }
bool AutoTest6()	{
		bool result = true;

		result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Base::BackgroundShiftRange), FUNC1(SimdBackgroundShiftRange));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Sse2::BackgroundShiftRange), FUNC1(SimdBackgroundShiftRange));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Avx2::BackgroundShiftRange), FUNC1(SimdBackgroundShiftRange));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Vmx::BackgroundShiftRange), FUNC1(SimdBackgroundShiftRange));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundChangeRangeAutoTest(FUNC1(Simd::Neon::BackgroundShiftRange), FUNC1(SimdBackgroundShiftRange));
#endif 

		return result;
	}
bool AutoTest7()	{
		bool result = true;

		result = result && BackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Base::BackgroundShiftRangeMasked), FUNC5(SimdBackgroundShiftRangeMasked));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Sse2::BackgroundShiftRangeMasked), FUNC5(SimdBackgroundShiftRangeMasked));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Avx2::BackgroundShiftRangeMasked), FUNC5(SimdBackgroundShiftRangeMasked));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Vmx::BackgroundShiftRangeMasked), FUNC5(SimdBackgroundShiftRangeMasked));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundShiftRangeMaskedAutoTest(FUNC5(Simd::Neon::BackgroundShiftRangeMasked), FUNC5(SimdBackgroundShiftRangeMasked));
#endif 

		return result;
	}
bool AutoTest8()	{
		bool result = true;

		result = result && BackgroundInitMaskAutoTest(FUNC6(Simd::Base::BackgroundInitMask), FUNC6(SimdBackgroundInitMask));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && BackgroundInitMaskAutoTest(FUNC6(Simd::Sse2::BackgroundInitMask), FUNC6(SimdBackgroundInitMask));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && BackgroundInitMaskAutoTest(FUNC6(Simd::Avx2::BackgroundInitMask), FUNC6(SimdBackgroundInitMask));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && BackgroundInitMaskAutoTest(FUNC6(Simd::Vmx::BackgroundInitMask), FUNC6(SimdBackgroundInitMask));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && BackgroundInitMaskAutoTest(FUNC6(Simd::Neon::BackgroundInitMask), FUNC6(SimdBackgroundInitMask));
#endif 

		return result;
	}
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_8

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
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
