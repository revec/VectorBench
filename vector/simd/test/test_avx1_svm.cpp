
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
#undef SIMD_VSX_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_AVX_ENABLE
#include "Test/TestSvm.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && SvmSumLinearAutoTest(FUNC_SL(Simd::Base::SvmSumLinear), FUNC_SL(SimdSvmSumLinear));

#ifdef SIMD_SSE_ENABLE
        if(Simd::Sse::Enable)
            result = result && SvmSumLinearAutoTest(FUNC_SL(Simd::Sse::SvmSumLinear), FUNC_SL(SimdSvmSumLinear));
#endif 

#ifdef SIMD_AVX_ENABLE
        if(Simd::Avx::Enable)
            result = result && SvmSumLinearAutoTest(FUNC_SL(Simd::Avx::SvmSumLinear), FUNC_SL(SimdSvmSumLinear));
#endif 

#ifdef SIMD_VSX_ENABLE
        if(Simd::Vsx::Enable)
            result = result && SvmSumLinearAutoTest(FUNC_SL(Simd::Vsx::SvmSumLinear), FUNC_SL(SimdSvmSumLinear));
#endif 

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && SvmSumLinearAutoTest(FUNC_SL(Simd::Neon::SvmSumLinear), FUNC_SL(SimdSvmSumLinear));
#endif 

        return result;
    }
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_1

TEST_LOG_SS(Info,  "AutoTest1 is started :");
bool result1 = Test::AutoTest1();
TEST_LOG_SS(Info, "AutoTest1 is finished " << (result1 ? "successfully." : "with errors!") << std::endl);
if(!result1)
{
  return 1;
}
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
