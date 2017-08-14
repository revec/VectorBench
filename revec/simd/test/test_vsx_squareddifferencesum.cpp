
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
#define SIMD_VSX_ENABLE
#include "Test/TestDifferenceSum.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && DifferenceSum32fAutoTest(EPS, FUNC_F(Simd::Base::SquaredDifferenceSum32f), FUNC_F(SimdSquaredDifferenceSum32f));

#ifdef SIMD_SSE_ENABLE
        if(Simd::Sse::Enable)
            result = result && DifferenceSum32fAutoTest(EPS, FUNC_F(Simd::Sse::SquaredDifferenceSum32f), FUNC_F(SimdSquaredDifferenceSum32f));
#endif 

#ifdef SIMD_AVX_ENABLE
        if(Simd::Avx::Enable)
            result = result && DifferenceSum32fAutoTest(EPS, FUNC_F(Simd::Avx::SquaredDifferenceSum32f), FUNC_F(SimdSquaredDifferenceSum32f));
#endif

#ifdef SIMD_VSX_ENABLE
        if(Simd::Vsx::Enable)
            result = result && DifferenceSum32fAutoTest(EPS, FUNC_F(Simd::Vsx::SquaredDifferenceSum32f), FUNC_F(SimdSquaredDifferenceSum32f));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && DifferenceSum32fAutoTest(EPS, FUNC_F(Simd::Neon::SquaredDifferenceSum32f), FUNC_F(SimdSquaredDifferenceSum32f));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && DifferenceSum32fAutoTest(EPS*EPS, FUNC_F(Simd::Base::SquaredDifferenceKahanSum32f), FUNC_F(SimdSquaredDifferenceKahanSum32f));

#ifdef SIMD_SSE_ENABLE
        if(Simd::Sse::Enable)
            result = result && DifferenceSum32fAutoTest(EPS*EPS, FUNC_F(Simd::Sse::SquaredDifferenceKahanSum32f), FUNC_F(SimdSquaredDifferenceKahanSum32f));
#endif 

#ifdef SIMD_AVX_ENABLE
        if(Simd::Avx::Enable)
            result = result && DifferenceSum32fAutoTest(EPS*EPS, FUNC_F(Simd::Avx::SquaredDifferenceKahanSum32f), FUNC_F(SimdSquaredDifferenceKahanSum32f));
#endif

#ifdef SIMD_VSX_ENABLE
        if(Simd::Vsx::Enable)
            result = result && DifferenceSum32fAutoTest(EPS*EPS, FUNC_F(Simd::Vsx::SquaredDifferenceKahanSum32f), FUNC_F(SimdSquaredDifferenceKahanSum32f));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && DifferenceSum32fAutoTest(EPS*EPS, FUNC_F(Simd::Neon::SquaredDifferenceKahanSum32f), FUNC_F(SimdSquaredDifferenceKahanSum32f));
#endif 

		return result;
    }
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_2

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
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
