
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
#undef SIMD_SSE41_ENABLE
#undef SIMD_AVX2_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_AVX2_ENABLE
#include "Test/TestDetection.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && DetectionDetectAutoTest(0, 0, 0, FUNC_D(Simd::Base::DetectionHaarDetect32fp), FUNC_D(SimdDetectionHaarDetect32fp));

#ifdef SIMD_SSE41_ENABLE
        if (Simd::Sse41::Enable)
            result = result && DetectionDetectAutoTest(0, 0, 0, FUNC_D(Simd::Sse41::DetectionHaarDetect32fp), FUNC_D(SimdDetectionHaarDetect32fp));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && DetectionDetectAutoTest(0, 0, 0, FUNC_D(Simd::Avx2::DetectionHaarDetect32fp), FUNC_D(SimdDetectionHaarDetect32fp));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && DetectionDetectAutoTest(0, 0, 0, FUNC_D(Simd::Neon::DetectionHaarDetect32fp), FUNC_D(SimdDetectionHaarDetect32fp));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && DetectionDetectAutoTest(0, 1, 0, FUNC_D(Simd::Base::DetectionHaarDetect32fi), FUNC_D(SimdDetectionHaarDetect32fi));

#ifdef SIMD_SSE41_ENABLE
        if (Simd::Sse41::Enable)
            result = result && DetectionDetectAutoTest(0, 1, 0, FUNC_D(Simd::Sse41::DetectionHaarDetect32fi), FUNC_D(SimdDetectionHaarDetect32fi));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && DetectionDetectAutoTest(0, 1, 0, FUNC_D(Simd::Avx2::DetectionHaarDetect32fi), FUNC_D(SimdDetectionHaarDetect32fi));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && DetectionDetectAutoTest(0, 1, 0, FUNC_D(Simd::Neon::DetectionHaarDetect32fi), FUNC_D(SimdDetectionHaarDetect32fi));
#endif

        return result;
    }
bool AutoTest3()    {
        bool result = true;

        result = result && DetectionDetectAutoTest(1, 0, 0, FUNC_D(Simd::Base::DetectionLbpDetect32fp), FUNC_D(SimdDetectionLbpDetect32fp));

#ifdef SIMD_SSE41_ENABLE
        if (Simd::Sse41::Enable)
            result = result && DetectionDetectAutoTest(1, 0, 0, FUNC_D(Simd::Sse41::DetectionLbpDetect32fp), FUNC_D(SimdDetectionLbpDetect32fp));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && DetectionDetectAutoTest(1, 0, 0, FUNC_D(Simd::Avx2::DetectionLbpDetect32fp), FUNC_D(SimdDetectionLbpDetect32fp));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && DetectionDetectAutoTest(1, 0, 0, FUNC_D(Simd::Neon::DetectionLbpDetect32fp), FUNC_D(SimdDetectionLbpDetect32fp));
#endif

        return result;
    }
bool AutoTest4()    {
        bool result = true;

        result = result && DetectionDetectAutoTest(1, 1, 0, FUNC_D(Simd::Base::DetectionLbpDetect32fi), FUNC_D(SimdDetectionLbpDetect32fi));

#ifdef SIMD_SSE41_ENABLE
        if (Simd::Sse41::Enable)
            result = result && DetectionDetectAutoTest(1, 1, 0, FUNC_D(Simd::Sse41::DetectionLbpDetect32fi), FUNC_D(SimdDetectionLbpDetect32fi));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && DetectionDetectAutoTest(1, 1, 0, FUNC_D(Simd::Avx2::DetectionLbpDetect32fi), FUNC_D(SimdDetectionLbpDetect32fi));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && DetectionDetectAutoTest(1, 1, 0, FUNC_D(Simd::Neon::DetectionLbpDetect32fi), FUNC_D(SimdDetectionLbpDetect32fi));
#endif

        return result;
    }
bool AutoTest5()    {
        bool result = true;

        result = result && DetectionDetectAutoTest(1, 0, 1, FUNC_D(Simd::Base::DetectionLbpDetect16ip), FUNC_D(SimdDetectionLbpDetect16ip));

#ifdef SIMD_SSE41_ENABLE
        if (Simd::Sse41::Enable)
            result = result && DetectionDetectAutoTest(1, 0, 1, FUNC_D(Simd::Sse41::DetectionLbpDetect16ip), FUNC_D(SimdDetectionLbpDetect16ip));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && DetectionDetectAutoTest(1, 0, 1, FUNC_D(Simd::Avx2::DetectionLbpDetect16ip), FUNC_D(SimdDetectionLbpDetect16ip));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && DetectionDetectAutoTest(1, 0, 1, FUNC_D(Simd::Neon::DetectionLbpDetect16ip), FUNC_D(SimdDetectionLbpDetect16ip));
#endif

        return result;
    }
bool AutoTest6()    {
        bool result = true;

        result = result && DetectionDetectAutoTest(1, 1, 1, FUNC_D(Simd::Base::DetectionLbpDetect16ii), FUNC_D(SimdDetectionLbpDetect16ii));

#ifdef SIMD_SSE41_ENABLE
        if (Simd::Sse41::Enable)
            result = result && DetectionDetectAutoTest(1, 1, 1, FUNC_D(Simd::Sse41::DetectionLbpDetect16ii), FUNC_D(SimdDetectionLbpDetect16ii));
#endif

#ifdef SIMD_AVX2_ENABLE
        if (Simd::Avx2::Enable)
            result = result && DetectionDetectAutoTest(1, 1, 1, FUNC_D(Simd::Avx2::DetectionLbpDetect16ii), FUNC_D(SimdDetectionLbpDetect16ii));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && DetectionDetectAutoTest(1, 1, 1, FUNC_D(Simd::Neon::DetectionLbpDetect16ii), FUNC_D(SimdDetectionLbpDetect16ii));
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
