
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
#include "Test/TestStatistic.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()	{
		bool result = true;

		result = result && GetStatisticAutoTest(FUNC1(Simd::Base::GetStatistic), FUNC1(SimdGetStatistic));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GetStatisticAutoTest(FUNC1(Simd::Sse2::GetStatistic), FUNC1(SimdGetStatistic));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GetStatisticAutoTest(FUNC1(Simd::Avx2::GetStatistic), FUNC1(SimdGetStatistic));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GetStatisticAutoTest(FUNC1(Simd::Vmx::GetStatistic), FUNC1(SimdGetStatistic));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GetStatisticAutoTest(FUNC1(Simd::Neon::GetStatistic), FUNC1(SimdGetStatistic));
#endif

		return result;
	}
bool AutoTest2()    {
        bool result = true;

        result = result && GetMomentsAutoTest(FUNC_M(Simd::Base::GetMoments), FUNC_M(SimdGetMoments));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GetMomentsAutoTest(FUNC_M(Simd::Sse2::GetMoments), FUNC_M(SimdGetMoments));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GetMomentsAutoTest(FUNC_M(Simd::Avx2::GetMoments), FUNC_M(SimdGetMoments));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GetMomentsAutoTest(FUNC_M(Simd::Vmx::GetMoments), FUNC_M(SimdGetMoments));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GetMomentsAutoTest(FUNC_M(Simd::Neon::GetMoments), FUNC_M(SimdGetMoments));
#endif

        return result;
    }
bool AutoTest3()    {
        bool result = true;

        result = result && GetSumsAutoTest(FUNC3(Simd::Base::GetRowSums), FUNC3(SimdGetRowSums), true);

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Sse2::GetRowSums), FUNC3(SimdGetRowSums), true);
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Avx2::GetRowSums), FUNC3(SimdGetRowSums), true);
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Vmx::GetRowSums), FUNC3(SimdGetRowSums), true);
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GetSumsAutoTest(FUNC3(Simd::Neon::GetRowSums), FUNC3(SimdGetRowSums), true);
#endif

        return result;
    }
bool AutoTest4()    {
        bool result = true;

        result = result && GetSumsAutoTest(FUNC3(Simd::Base::GetColSums), FUNC3(SimdGetColSums), false);

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Sse2::GetColSums), FUNC3(SimdGetColSums), false);
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Avx2::GetColSums), FUNC3(SimdGetColSums), false);
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Vmx::GetColSums), FUNC3(SimdGetColSums), false);
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GetSumsAutoTest(FUNC3(Simd::Neon::GetColSums), FUNC3(SimdGetColSums), false);
#endif 

        return result;
    }
bool AutoTest5()    {
        bool result = true;

        result = result && GetSumsAutoTest(FUNC3(Simd::Base::GetAbsDyRowSums), FUNC3(SimdGetAbsDyRowSums), true);

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Sse2::GetAbsDyRowSums), FUNC3(SimdGetAbsDyRowSums), true);
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Avx2::GetAbsDyRowSums), FUNC3(SimdGetAbsDyRowSums), true);
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Vmx::GetAbsDyRowSums), FUNC3(SimdGetAbsDyRowSums), true);
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GetSumsAutoTest(FUNC3(Simd::Neon::GetAbsDyRowSums), FUNC3(SimdGetAbsDyRowSums), true);
#endif

        return result;
    }
bool AutoTest6()    {
        bool result = true;

        result = result && GetSumsAutoTest(FUNC3(Simd::Base::GetAbsDxColSums), FUNC3(SimdGetAbsDxColSums), false);

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Sse2::GetAbsDxColSums), FUNC3(SimdGetAbsDxColSums), false);
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Avx2::GetAbsDxColSums), FUNC3(SimdGetAbsDxColSums), false);
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && GetSumsAutoTest(FUNC3(Simd::Vmx::GetAbsDxColSums), FUNC3(SimdGetAbsDxColSums), false);
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && GetSumsAutoTest(FUNC3(Simd::Neon::GetAbsDxColSums), FUNC3(SimdGetAbsDxColSums), false);
#endif

        return result;
    }
bool AutoTest7()    {
        bool result = true;

        result = result && SumAutoTest(FUNC4(Simd::Base::ValueSum), FUNC4(SimdValueSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Sse2::ValueSum), FUNC4(SimdValueSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Avx2::ValueSum), FUNC4(SimdValueSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Vmx::ValueSum), FUNC4(SimdValueSum));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SumAutoTest(FUNC4(Simd::Neon::ValueSum), FUNC4(SimdValueSum));
#endif

        return result;
    }
bool AutoTest8()    {
        bool result = true;

        result = result && SumAutoTest(FUNC4(Simd::Base::SquareSum), FUNC4(SimdSquareSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Sse2::SquareSum), FUNC4(SimdSquareSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Avx2::SquareSum), FUNC4(SimdSquareSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SumAutoTest(FUNC4(Simd::Vmx::SquareSum), FUNC4(SimdSquareSum));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SumAutoTest(FUNC4(Simd::Neon::SquareSum), FUNC4(SimdSquareSum));
#endif

        return result;
    }
bool AutoTest9()    {
        bool result = true;

        result = result && CorrelationSumAutoTest(FUNC5(Simd::Base::CorrelationSum), FUNC5(SimdCorrelationSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && CorrelationSumAutoTest(FUNC5(Simd::Sse2::CorrelationSum), FUNC5(SimdCorrelationSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && CorrelationSumAutoTest(FUNC5(Simd::Avx2::CorrelationSum), FUNC5(SimdCorrelationSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && CorrelationSumAutoTest(FUNC5(Simd::Vmx::CorrelationSum), FUNC5(SimdCorrelationSum));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && CorrelationSumAutoTest(FUNC5(Simd::Neon::CorrelationSum), FUNC5(SimdCorrelationSum));
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
