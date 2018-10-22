
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
#undef SIMD_VMX_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_VMX_ENABLE
#include "Test/TestSegmentation.h"
#undef SIMD_SSE2_ENABLE
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && SegmentationShrinkRegionAutoTest(FUNC_SR(Simd::Base::SegmentationShrinkRegion), FUNC_SR(SimdSegmentationShrinkRegion));

#ifdef SIMD_SSE41_ENABLE
        if(Simd::Sse41::Enable)
            result = result && SegmentationShrinkRegionAutoTest(FUNC_SR(Simd::Sse41::SegmentationShrinkRegion), FUNC_SR(SimdSegmentationShrinkRegion));
#endif

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SegmentationShrinkRegionAutoTest(FUNC_SR(Simd::Avx2::SegmentationShrinkRegion), FUNC_SR(SimdSegmentationShrinkRegion));
#endif

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SegmentationShrinkRegionAutoTest(FUNC_SR(Simd::Vmx::SegmentationShrinkRegion), FUNC_SR(SimdSegmentationShrinkRegion));
#endif

#ifdef SIMD_NEON_ENABLE
        if (Simd::Neon::Enable)
            result = result && SegmentationShrinkRegionAutoTest(FUNC_SR(Simd::Neon::SegmentationShrinkRegion), FUNC_SR(SimdSegmentationShrinkRegion));
#endif

        return result;    
    }
bool AutoTest2()    {
        bool result = true;

        result = result && SegmentationFillSingleHolesAutoTest(FUNC_FSH(Simd::Base::SegmentationFillSingleHoles), FUNC_FSH(SimdSegmentationFillSingleHoles));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && SegmentationFillSingleHolesAutoTest(FUNC_FSH(Simd::Sse2::SegmentationFillSingleHoles), FUNC_FSH(SimdSegmentationFillSingleHoles));
#endif

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SegmentationFillSingleHolesAutoTest(FUNC_FSH(Simd::Avx2::SegmentationFillSingleHoles), FUNC_FSH(SimdSegmentationFillSingleHoles));
#endif

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SegmentationFillSingleHolesAutoTest(FUNC_FSH(Simd::Vmx::SegmentationFillSingleHoles), FUNC_FSH(SimdSegmentationFillSingleHoles));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SegmentationFillSingleHolesAutoTest(FUNC_FSH(Simd::Neon::SegmentationFillSingleHoles), FUNC_FSH(SimdSegmentationFillSingleHoles));
#endif

        return result;    
    }
bool AutoTest3()    {
        bool result = true;

        result = result && SegmentationChangeIndexAutoTest(FUNC_CI(Simd::Base::SegmentationChangeIndex), FUNC_CI(SimdSegmentationChangeIndex));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && SegmentationChangeIndexAutoTest(FUNC_CI(Simd::Sse2::SegmentationChangeIndex), FUNC_CI(SimdSegmentationChangeIndex));
#endif

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SegmentationChangeIndexAutoTest(FUNC_CI(Simd::Avx2::SegmentationChangeIndex), FUNC_CI(SimdSegmentationChangeIndex));
#endif

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SegmentationChangeIndexAutoTest(FUNC_CI(Simd::Vmx::SegmentationChangeIndex), FUNC_CI(SimdSegmentationChangeIndex));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SegmentationChangeIndexAutoTest(FUNC_CI(Simd::Neon::SegmentationChangeIndex), FUNC_CI(SimdSegmentationChangeIndex));
#endif

        return result;    
    }
bool AutoTest4()    {
        bool result = true;

        result = result && SegmentationPropagate2x2AutoTest(FUNC_P(Simd::Base::SegmentationPropagate2x2), FUNC_P(SimdSegmentationPropagate2x2));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && SegmentationPropagate2x2AutoTest(FUNC_P(Simd::Sse2::SegmentationPropagate2x2), FUNC_P(SimdSegmentationPropagate2x2));
#endif

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && SegmentationPropagate2x2AutoTest(FUNC_P(Simd::Avx2::SegmentationPropagate2x2), FUNC_P(SimdSegmentationPropagate2x2));
#endif

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && SegmentationPropagate2x2AutoTest(FUNC_P(Simd::Vmx::SegmentationPropagate2x2), FUNC_P(SimdSegmentationPropagate2x2));
#endif

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && SegmentationPropagate2x2AutoTest(FUNC_P(Simd::Neon::SegmentationPropagate2x2), FUNC_P(SimdSegmentationPropagate2x2));
#endif

        return result;    
    }
//_AUTO_TEST_		
	
  String ROOT_PATH = "..";
}

int main(int argc, char* argv[])
{

//_TESTS_4

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
//_RUN_CODE_
    
#ifdef TEST_PERFORMANCE_TEST_ENABLE
    TEST_LOG_SS(Info, Test::PerformanceMeasurerStorage::s_storage.Report(false, false));
#endif

    return 0;
}
