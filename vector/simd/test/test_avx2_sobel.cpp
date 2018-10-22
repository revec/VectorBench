
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
#undef SIMD_SSSE3_ENABLE
#undef SIMD_AVX2_ENABLE
#undef SIMD_VMX_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_AVX2_ENABLE
#include "Test/TestStatistic.h"
#include "Test/TestContour.h"
#undef SIMD_SSE2_ENABLE
#include "Test/TestFilter.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && SumAutoTest(FUNC4(Simd::Base::SobelDxAbsSum), FUNC4(SimdSobelDxAbsSum));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Ssse3::SobelDxAbsSum), FUNC4(SimdSobelDxAbsSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Avx2::SobelDxAbsSum), FUNC4(SimdSobelDxAbsSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Vmx::SobelDxAbsSum), FUNC4(SimdSobelDxAbsSum));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SumAutoTest(FUNC4(Simd::Neon::SobelDxAbsSum), FUNC4(SimdSobelDxAbsSum));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && SumAutoTest(FUNC4(Simd::Base::SobelDyAbsSum), FUNC4(SimdSobelDyAbsSum));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Ssse3::SobelDyAbsSum), FUNC4(SimdSobelDyAbsSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Avx2::SobelDyAbsSum), FUNC4(SimdSobelDyAbsSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Vmx::SobelDyAbsSum), FUNC4(SimdSobelDyAbsSum));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SumAutoTest(FUNC4(Simd::Neon::SobelDyAbsSum), FUNC4(SimdSobelDyAbsSum));
#endif

        return result;
    }

  //sobel completes here

bool AutoTest3()    {
        bool result = true;

        result = result && ContourMetricsMaskedAutoTest(FUNC_M1(Simd::Base::ContourMetricsMasked), FUNC_M1(SimdContourMetricsMasked));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && ContourMetricsMaskedAutoTest(FUNC_M1(Simd::Ssse3::ContourMetricsMasked), FUNC_M1(SimdContourMetricsMasked));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ContourMetricsMaskedAutoTest(FUNC_M1(Simd::Avx2::ContourMetricsMasked), FUNC_M1(SimdContourMetricsMasked));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ContourMetricsMaskedAutoTest(FUNC_M1(Simd::Vmx::ContourMetricsMasked), FUNC_M1(SimdContourMetricsMasked));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ContourMetricsMaskedAutoTest(FUNC_M1(Simd::Neon::ContourMetricsMasked), FUNC_M1(SimdContourMetricsMasked));
#endif

        return result;
    }
bool AutoTest4()    {
        bool result = true;

        result = result && ContourAnchorsAutoTest(FUNC_A1(Simd::Base::ContourAnchors), FUNC_A1(SimdContourAnchors));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && ContourAnchorsAutoTest(FUNC_A1(Simd::Sse2::ContourAnchors), FUNC_A1(SimdContourAnchors));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && ContourAnchorsAutoTest(FUNC_A1(Simd::Avx2::ContourAnchors), FUNC_A1(SimdContourAnchors));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && ContourAnchorsAutoTest(FUNC_A1(Simd::Vmx::ContourAnchors), FUNC_A1(SimdContourAnchors));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && ContourAnchorsAutoTest(FUNC_A1(Simd::Neon::ContourAnchors), FUNC_A1(SimdContourAnchors));
#endif

        return result;
    }
bool AutoTest5()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::SobelDx), FUNC_G(SimdSobelDx));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Sse2::SobelDx), FUNC_G(SimdSobelDx));
#endif 

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::SobelDx), FUNC_G(SimdSobelDx));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::SobelDx), FUNC_G(SimdSobelDx));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::SobelDx), FUNC_G(SimdSobelDx));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::SobelDx), FUNC_G(SimdSobelDx));
#endif

        return result;
    }
bool AutoTest6()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::SobelDxAbs), FUNC_G(SimdSobelDxAbs));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::SobelDxAbs), FUNC_G(SimdSobelDxAbs));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::SobelDxAbs), FUNC_G(SimdSobelDxAbs));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::SobelDxAbs), FUNC_G(SimdSobelDxAbs));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::SobelDxAbs), FUNC_G(SimdSobelDxAbs));
#endif

        return result;
    }
bool AutoTest7()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::SobelDy), FUNC_G(SimdSobelDy));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Sse2::SobelDy), FUNC_G(SimdSobelDy));
#endif 

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::SobelDy), FUNC_G(SimdSobelDy));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::SobelDy), FUNC_G(SimdSobelDy));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::SobelDy), FUNC_G(SimdSobelDy));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::SobelDy), FUNC_G(SimdSobelDy));
#endif

        return result;
    }
bool AutoTest8()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::SobelDyAbs), FUNC_G(SimdSobelDyAbs));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::SobelDyAbs), FUNC_G(SimdSobelDyAbs));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::SobelDyAbs), FUNC_G(SimdSobelDyAbs));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::SobelDyAbs), FUNC_G(SimdSobelDyAbs));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::SobelDyAbs), FUNC_G(SimdSobelDyAbs));
#endif

        return result;
    }
bool AutoTest9()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::ContourMetrics), FUNC_G(SimdContourMetrics));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::ContourMetrics), FUNC_G(SimdContourMetrics));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::ContourMetrics), FUNC_G(SimdContourMetrics));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::ContourMetrics), FUNC_G(SimdContourMetrics));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::ContourMetrics), FUNC_G(SimdContourMetrics));
#endif

        return result;
    }
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_9

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
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
