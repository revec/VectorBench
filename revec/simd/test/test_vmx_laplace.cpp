
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
#define SIMD_VMX_ENABLE
#include "Test/TestStatistic.h"
#undef SIMD_SSE2_ENABLE
#include "Test/TestFilter.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && SumAutoTest(FUNC4(Simd::Base::LaplaceAbsSum), FUNC4(SimdLaplaceAbsSum));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Ssse3::LaplaceAbsSum), FUNC4(SimdLaplaceAbsSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Avx2::LaplaceAbsSum), FUNC4(SimdLaplaceAbsSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Vmx::LaplaceAbsSum), FUNC4(SimdLaplaceAbsSum));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SumAutoTest(FUNC4(Simd::Neon::LaplaceAbsSum), FUNC4(SimdLaplaceAbsSum));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::Laplace), FUNC_G(SimdLaplace));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Sse2::Laplace), FUNC_G(SimdLaplace));
#endif 

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::Laplace), FUNC_G(SimdLaplace));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::Laplace), FUNC_G(SimdLaplace));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::Laplace), FUNC_G(SimdLaplace));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::Laplace), FUNC_G(SimdLaplace));
#endif 

        return result;
    }
bool AutoTest3()    {
        bool result = true;

        result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Base::LaplaceAbs), FUNC_G(SimdLaplaceAbs));

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Ssse3::LaplaceAbs), FUNC_G(SimdLaplaceAbs));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Avx2::LaplaceAbs), FUNC_G(SimdLaplaceAbs));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Vmx::LaplaceAbs), FUNC_G(SimdLaplaceAbs));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GrayFilterAutoTest(View::Int16, FUNC_G(Simd::Neon::LaplaceAbs), FUNC_G(SimdLaplaceAbs));
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
