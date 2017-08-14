
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
#undef SIMD_SSSE3_ENABLE
#undef SIMD_AVX2_ENABLE
#undef SIMD_VMX_ENABLE
#undef SIMD_NEON_ENABLE
#define SIMD_SSE2_ENABLE
#include "Test/TestTexture.h"
//_INSERT_HEADERS_

namespace Test
{

	
bool AutoTest1()    {
        bool result = true;

        result = result && TextureBoostedSaturatedGradientAutoTest(FUNC1(Simd::Base::TextureBoostedSaturatedGradient), FUNC1(SimdTextureBoostedSaturatedGradient));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && TextureBoostedSaturatedGradientAutoTest(FUNC1(Simd::Sse2::TextureBoostedSaturatedGradient), FUNC1(SimdTextureBoostedSaturatedGradient));
#endif 

#ifdef SIMD_SSSE3_ENABLE
        if(Simd::Ssse3::Enable)
            result = result && TextureBoostedSaturatedGradientAutoTest(FUNC1(Simd::Ssse3::TextureBoostedSaturatedGradient), FUNC1(SimdTextureBoostedSaturatedGradient));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && TextureBoostedSaturatedGradientAutoTest(FUNC1(Simd::Avx2::TextureBoostedSaturatedGradient), FUNC1(SimdTextureBoostedSaturatedGradient));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && TextureBoostedSaturatedGradientAutoTest(FUNC1(Simd::Vmx::TextureBoostedSaturatedGradient), FUNC1(SimdTextureBoostedSaturatedGradient));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && TextureBoostedSaturatedGradientAutoTest(FUNC1(Simd::Neon::TextureBoostedSaturatedGradient), FUNC1(SimdTextureBoostedSaturatedGradient));
#endif

        return result;
    }
bool AutoTest2()    {
        bool result = true;

        result = result && TextureBoostedUvAutoTest(FUNC2(Simd::Base::TextureBoostedUv), FUNC2(SimdTextureBoostedUv));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && TextureBoostedUvAutoTest(FUNC2(Simd::Sse2::TextureBoostedUv), FUNC2(SimdTextureBoostedUv));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && TextureBoostedUvAutoTest(FUNC2(Simd::Avx2::TextureBoostedUv), FUNC2(SimdTextureBoostedUv));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && TextureBoostedUvAutoTest(FUNC2(Simd::Vmx::TextureBoostedUv), FUNC2(SimdTextureBoostedUv));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && TextureBoostedUvAutoTest(FUNC2(Simd::Neon::TextureBoostedUv), FUNC2(SimdTextureBoostedUv));
#endif

        return result;
    }
bool AutoTest3()    {
        bool result = true;

        result = result && TextureGetDifferenceSumAutoTest(FUNC3(Simd::Base::TextureGetDifferenceSum), FUNC3(SimdTextureGetDifferenceSum));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && TextureGetDifferenceSumAutoTest(FUNC3(Simd::Sse2::TextureGetDifferenceSum), FUNC3(SimdTextureGetDifferenceSum));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && TextureGetDifferenceSumAutoTest(FUNC3(Simd::Avx2::TextureGetDifferenceSum), FUNC3(SimdTextureGetDifferenceSum));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && TextureGetDifferenceSumAutoTest(FUNC3(Simd::Vmx::TextureGetDifferenceSum), FUNC3(SimdTextureGetDifferenceSum));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && TextureGetDifferenceSumAutoTest(FUNC3(Simd::Neon::TextureGetDifferenceSum), FUNC3(SimdTextureGetDifferenceSum));
#endif

        return result;
    }
bool AutoTest4()    {
        bool result = true;

        result = result && TexturePerformCompensationAutoTest(FUNC4(Simd::Base::TexturePerformCompensation), FUNC4(SimdTexturePerformCompensation));

#ifdef SIMD_SSE2_ENABLE
        if(Simd::Sse2::Enable)
            result = result && TexturePerformCompensationAutoTest(FUNC4(Simd::Sse2::TexturePerformCompensation), FUNC4(SimdTexturePerformCompensation));
#endif 

#ifdef SIMD_AVX2_ENABLE
        if(Simd::Avx2::Enable)
            result = result && TexturePerformCompensationAutoTest(FUNC4(Simd::Avx2::TexturePerformCompensation), FUNC4(SimdTexturePerformCompensation));
#endif 

#ifdef SIMD_VMX_ENABLE
        if(Simd::Vmx::Enable)
            result = result && TexturePerformCompensationAutoTest(FUNC4(Simd::Vmx::TexturePerformCompensation), FUNC4(SimdTexturePerformCompensation));
#endif 

#ifdef SIMD_NEON_ENABLE
		if (Simd::Neon::Enable)
			result = result && TexturePerformCompensationAutoTest(FUNC4(Simd::Neon::TexturePerformCompensation), FUNC4(SimdTexturePerformCompensation));
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
