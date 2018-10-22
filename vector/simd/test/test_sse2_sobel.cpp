
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
#define SIMD_SSE2_ENABLE
#include "Test/TestContour.h"
#undef SIMD_SSSE3_ENABLE
#include "Test/TestFilter.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
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
bool AutoTest2()    {
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
bool AutoTest3()    {
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
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_3

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
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
