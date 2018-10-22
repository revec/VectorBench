/*
* Simd Library (http://simd.sourceforge.net).
*
* Copyright (c) 2011-2017 Yermalayeu Ihar,
*               2014-2016 Antonenka Mikhail.
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
#include "Simd/SimdConfig.h"

#if defined(WIN32) && !defined(SIMD_STATIC)

#define SIMD_EXPORTS

#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved)
{
    switch(dwReasonForCall)
    {
    case DLL_PROCESS_DETACH:
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        return TRUE;
    }
    return TRUE;
}
#endif//WIN32

#include "Simd/SimdLib.h"

#include "Simd/SimdMemory.h"
#include "Simd/SimdEnable.h"
#include "Simd/SimdVersion.h"
#include "Simd/SimdConst.h"

#include "Simd/SimdBase.h"
// #include "Simd/SimdSse1.h"
// #include "Simd/SimdSse2.h"
// #include "Simd/SimdSse3.h"
// #include "Simd/SimdSsse3.h"
// #include "Simd/SimdSse41.h"
// #include "Simd/SimdSse42.h"
// #include "Simd/SimdAvx1.h"
// #include "Simd/SimdAvx2.h"
// #include "Simd/SimdVmx.h"
// #include "Simd/SimdVsx.h"
// #include "Simd/SimdNeon.h"

using namespace Simd;

SIMD_API const char * SimdVersion()
{
    return SIMD_VERSION;
}

SIMD_API void * SimdAllocate(size_t size, size_t align)
{
    return Allocate(size, align);
}

SIMD_API void SimdFree(void * ptr)
{
    Free(ptr);
}

SIMD_API size_t SimdAlign(size_t size, size_t align)
{
    return AlignHi(size, align);
}

SIMD_API size_t SimdAlignment()
{
    return Simd::ALIGNMENT;
}

SIMD_API uint32_t SimdCrc32c(const void * src, size_t size)
{
        return Base::Crc32c(src, size);
}

SIMD_API void SimdAbsDifferenceSum(const uint8_t *a, size_t aStride, const uint8_t * b, size_t bStride,
                                   size_t width, size_t height, uint64_t * sum)
{
        Base::AbsDifferenceSum(a, aStride, b, bStride, width, height, sum);
}

SIMD_API void SimdAbsDifferenceSumMasked(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
                                         const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum)
{
        Base::AbsDifferenceSumMasked(a, aStride, b, bStride, mask, maskStride, index, width, height, sum);
}

SIMD_API void SimdAbsDifferenceSums3x3(const uint8_t *current, size_t currentStride, const uint8_t * background, size_t backgroundStride,
                                       size_t width, size_t height, uint64_t * sums)
{
        Base::AbsDifferenceSums3x3(current, currentStride, background, backgroundStride, width, height, sums);
}

SIMD_API void SimdAbsDifferenceSums3x3Masked(const uint8_t *current, size_t currentStride, const uint8_t *background, size_t backgroundStride,
                                             const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sums)
{
        Base::AbsDifferenceSums3x3Masked(current, currentStride, background, backgroundStride, mask, maskStride, index, width, height, sums);
}

SIMD_API void SimdAbsGradientSaturatedSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                          uint8_t * dst, size_t dstStride)
{
        Base::AbsGradientSaturatedSum(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdAddFeatureDifference(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                       const uint8_t * lo, size_t loStride, const uint8_t * hi, size_t hiStride,
                                       uint16_t weight, uint8_t * difference, size_t differenceStride)
{
        Base::AddFeatureDifference(value, valueStride, width, height, lo, loStride, hi, hiStride, weight, difference, differenceStride);
}

SIMD_API void SimdAlphaBlending(const uint8_t *src, size_t srcStride, size_t width, size_t height, size_t channelCount,
                   const uint8_t *alpha, size_t alphaStride, uint8_t *dst, size_t dstStride)
{
        Base::AlphaBlending(src, srcStride, width, height, channelCount, alpha, alphaStride, dst, dstStride);
}

SIMD_API void SimdBackgroundGrowRangeSlow(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                          uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride)
{
        Base::BackgroundGrowRangeSlow(value, valueStride, width, height, lo, loStride, hi, hiStride);
}

SIMD_API void SimdBackgroundGrowRangeFast(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                          uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride)
{
        Base::BackgroundGrowRangeFast(value, valueStride, width, height, lo, loStride, hi, hiStride);
}

SIMD_API void SimdBackgroundIncrementCount(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                           const uint8_t * loValue, size_t loValueStride, const uint8_t * hiValue, size_t hiValueStride,
                                           uint8_t * loCount, size_t loCountStride, uint8_t * hiCount, size_t hiCountStride)
{
        Base::BackgroundIncrementCount(value, valueStride, width, height, loValue, loValueStride, hiValue, hiValueStride, loCount, loCountStride, hiCount, hiCountStride);
}

SIMD_API void SimdBackgroundAdjustRange(uint8_t * loCount, size_t loCountStride, size_t width, size_t height,
                                        uint8_t * loValue, size_t loValueStride, uint8_t * hiCount, size_t hiCountStride,
                                        uint8_t * hiValue, size_t hiValueStride, uint8_t threshold)
{
        Base::BackgroundAdjustRange(loCount, loCountStride, width, height, loValue, loValueStride,
        hiCount, hiCountStride, hiValue, hiValueStride, threshold);
}

SIMD_API void SimdBackgroundAdjustRangeMasked(uint8_t * loCount, size_t loCountStride, size_t width, size_t height,
                                              uint8_t * loValue, size_t loValueStride, uint8_t * hiCount, size_t hiCountStride,
                                              uint8_t * hiValue, size_t hiValueStride, uint8_t threshold, const uint8_t * mask, size_t maskStride)
{
        Base::BackgroundAdjustRangeMasked(loCount, loCountStride, width, height, loValue, loValueStride,
        hiCount, hiCountStride, hiValue, hiValueStride, threshold, mask, maskStride);
}

SIMD_API void SimdBackgroundShiftRange(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                       uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride)
{
        Base::BackgroundShiftRange(value, valueStride, width, height, lo, loStride, hi, hiStride);
}

SIMD_API void SimdBackgroundShiftRangeMasked(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                             uint8_t * lo, size_t loStride, uint8_t * hi, size_t hiStride, const uint8_t * mask, size_t maskStride)
{
        Base::BackgroundShiftRangeMasked(value, valueStride, width, height, lo, loStride, hi, hiStride, mask, maskStride);
}

SIMD_API void SimdBackgroundInitMask(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                     uint8_t index, uint8_t value, uint8_t * dst, size_t dstStride)
{
        Base::BackgroundInitMask(src, srcStride, width, height, index, value, dst, dstStride);
}

SIMD_API void SimdBayerToBgr(const uint8_t * bayer, size_t width, size_t height, size_t bayerStride, SimdPixelFormatType bayerFormat, uint8_t * bgr, size_t bgrStride)
{
    Base::BayerToBgr(bayer, width, height, bayerStride, bayerFormat, bgr, bgrStride);
}

SIMD_API void SimdBayerToBgra(const uint8_t * bayer, size_t width, size_t height, size_t bayerStride, SimdPixelFormatType bayerFormat, uint8_t * bgra, size_t bgraStride, uint8_t alpha)
{
    Base::BayerToBgra(bayer, width, height, bayerStride, bayerFormat, bgra, bgraStride, alpha);
}

SIMD_API void SimdBgraToBayer(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * bayer, size_t bayerStride, SimdPixelFormatType bayerFormat)
{
        Base::BgraToBayer(bgra, width, height, bgraStride, bayer, bayerStride, bayerFormat);
}

SIMD_API void SimdBgraToBgr(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * bgr, size_t bgrStride)
{
        Base::BgraToBgr(bgra, width, height, bgraStride, bgr, bgrStride);
}

SIMD_API void SimdBgraToGray(const uint8_t *bgra, size_t width, size_t height, size_t bgraStride, uint8_t *gray, size_t grayStride)
{
        Base::BgraToGray(bgra, width, height, bgraStride, gray, grayStride);
}

SIMD_API void SimdBgraToYuv420p(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * y, size_t yStride, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::BgraToYuv420p(bgra, width, height, bgraStride, y, yStride, u, uStride, v, vStride);
}

SIMD_API void SimdBgraToYuv422p(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * y, size_t yStride, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::BgraToYuv422p(bgra, width, height, bgraStride, y, yStride, u, uStride, v, vStride);
}

SIMD_API void SimdBgraToYuv444p(const uint8_t * bgra, size_t width, size_t height, size_t bgraStride, uint8_t * y, size_t yStride, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::BgraToYuv444p(bgra, width, height, bgraStride, y, yStride, u, uStride, v, vStride);
}

SIMD_API void SimdBgrToBayer(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * bayer, size_t bayerStride, SimdPixelFormatType bayerFormat)
{
        Base::BgrToBayer(bgr, width, height, bgrStride, bayer, bayerStride, bayerFormat);
}

SIMD_API void SimdBgrToBgra(const uint8_t *bgr, size_t width, size_t height, size_t bgrStride, uint8_t *bgra, size_t bgraStride, uint8_t alpha)
{
        Base::BgrToBgra(bgr, width, height, bgrStride, bgra, bgraStride, alpha);
}

SIMD_API void SimdBgr48pToBgra32(const uint8_t * blue, size_t blueStride, size_t width, size_t height,
    const uint8_t * green, size_t greenStride, const uint8_t * red, size_t redStride, uint8_t * bgra, size_t bgraStride, uint8_t alpha)
{
        Base::Bgr48pToBgra32(blue, blueStride, width, height, green, greenStride, red, redStride, bgra, bgraStride, alpha);
}

SIMD_API void SimdBgrToGray(const uint8_t *bgr, size_t width, size_t height, size_t bgrStride, uint8_t *gray, size_t grayStride)
{
        Base::BgrToGray(bgr, width, height, bgrStride, gray, grayStride);
}

SIMD_API void SimdBgrToHsl(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * hsl, size_t hslStride)
{
    Base::BgrToHsl(bgr, width, height, bgrStride, hsl, hslStride);
}

SIMD_API void SimdBgrToHsv(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * hsv, size_t hsvStride)
{
    Base::BgrToHsv(bgr, width, height, bgrStride, hsv, hsvStride);
}

SIMD_API void SimdBgrToYuv420p(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * y, size_t yStride, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::BgrToYuv420p(bgr, width, height, bgrStride, y, yStride, u, uStride, v, vStride);
}

SIMD_API void SimdBgrToYuv422p(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * y, size_t yStride, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::BgrToYuv422p(bgr, width, height, bgrStride, y, yStride, u, uStride, v, vStride);
}

SIMD_API void SimdBgrToYuv444p(const uint8_t * bgr, size_t width, size_t height, size_t bgrStride, uint8_t * y, size_t yStride, uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::BgrToYuv444p(bgr, width, height, bgrStride, y, yStride, u, uStride, v, vStride);
}

SIMD_API void SimdBinarization(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                  uint8_t value, uint8_t positive, uint8_t negative, uint8_t * dst, size_t dstStride, SimdCompareType compareType)
{
        Base::Binarization(src, srcStride, width, height, value, positive, negative, dst, dstStride, compareType);
}

SIMD_API void SimdAveragingBinarization(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                           uint8_t value, size_t neighborhood, uint8_t threshold, uint8_t positive, uint8_t negative,
                           uint8_t * dst, size_t dstStride, SimdCompareType compareType)
{
        Base::AveragingBinarization(src, srcStride, width, height, value, neighborhood, threshold, positive, negative, dst, dstStride, compareType);
}

SIMD_API void SimdConditionalCount8u(const uint8_t * src, size_t stride, size_t width, size_t height,
                                   uint8_t value, SimdCompareType compareType, uint32_t * count)
{
        Base::ConditionalCount8u(src, stride, width, height, value, compareType, count);
}

SIMD_API void SimdConditionalCount16i(const uint8_t * src, size_t stride, size_t width, size_t height,
                                     int16_t value, SimdCompareType compareType, uint32_t * count)
{
        Base::ConditionalCount16i(src, stride, width, height, value, compareType, count);
}

SIMD_API void SimdConditionalSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                 const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum)
{
        Base::ConditionalSum(src, srcStride, width, height, mask, maskStride, value, compareType, sum);
}

SIMD_API void SimdConditionalSquareSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                       const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum)
{
        Base::ConditionalSquareSum(src, srcStride, width, height, mask, maskStride, value, compareType, sum);
}

SIMD_API void SimdConditionalSquareGradientSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                       const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint64_t * sum)
{
        Base::ConditionalSquareGradientSum(src, srcStride, width, height, mask, maskStride, value, compareType, sum);
}

SIMD_API void SimdConditionalFill(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t threshold, SimdCompareType compareType, uint8_t value, uint8_t * dst, size_t dstStride)
{
		Base::ConditionalFill(src, srcStride, width, height, threshold, compareType, value, dst, dstStride);
}

SIMD_API void SimdCopy(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t pixelSize, uint8_t * dst, size_t dstStride)
{
    Base::Copy(src, srcStride, width, height, pixelSize, dst, dstStride);
}

SIMD_API void SimdCopyFrame(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t pixelSize,
                           size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t * dst, size_t dstStride)
{
    Base::CopyFrame(src, srcStride, width, height, pixelSize, frameLeft, frameTop, frameRight, frameBottom, dst, dstStride);
}

SIMD_API void SimdDeinterleaveUv(const uint8_t * uv, size_t uvStride, size_t width, size_t height,
                    uint8_t * u, size_t uStride, uint8_t * v, size_t vStride)
{
        Base::DeinterleaveUv(uv, uvStride, width, height, u, uStride, v, vStride);
}

SIMD_API void SimdDeinterleaveBgr(const uint8_t * bgr, size_t bgrStride, size_t width, size_t height,
    uint8_t * b, size_t bStride, uint8_t * g, size_t gStride, uint8_t * r, size_t rStride)
{
        Base::DeinterleaveBgr(bgr, bgrStride, width, height, b, bStride, g, gStride, r, rStride);
}

SIMD_API void SimdDeinterleaveBgra(const uint8_t * bgra, size_t bgraStride, size_t width, size_t height,
    uint8_t * b, size_t bStride, uint8_t * g, size_t gStride, uint8_t * r, size_t rStride, uint8_t * a, size_t aStride)
{
        Base::DeinterleaveBgra(bgra, bgraStride, width, height, b, bStride, g, gStride, r, rStride, a, aStride);
}

SIMD_API void * SimdDetectionLoadA(const char * path)
{
    return Base::DetectionLoadA(path);
}

SIMD_API void SimdDetectionInfo(const void * data, size_t * width, size_t * height, SimdDetectionInfoFlags * flags)
{
    Base::DetectionInfo(data, width, height, flags);
}

SIMD_API void * SimdDetectionInit(const void * data, uint8_t * sum, size_t sumStride, size_t width, size_t height,
    uint8_t * sqsum, size_t sqsumStride, uint8_t * tilted, size_t tiltedStride, int throughColumn, int int16)
{
    return Base::DetectionInit(data, sum, sumStride, width, height, sqsum, sqsumStride, tilted, tiltedStride, throughColumn, int16);
}

SIMD_API void SimdDetectionPrepare(void * hid)
{
    Base::DetectionPrepare(hid);
}

SIMD_API void SimdDetectionHaarDetect32fp(const void * hid, const uint8_t * mask, size_t maskStride, 
    ptrdiff_t left, ptrdiff_t top, ptrdiff_t right, ptrdiff_t bottom, uint8_t * dst, size_t dstStride)
{
    size_t width = right - left;
        Base::DetectionHaarDetect32fp(hid, mask, maskStride, left, top, right, bottom, dst, dstStride);
}

SIMD_API void SimdDetectionHaarDetect32fi(const void * hid, const uint8_t * mask, size_t maskStride,
    ptrdiff_t left, ptrdiff_t top, ptrdiff_t right, ptrdiff_t bottom, uint8_t * dst, size_t dstStride)
{
    size_t width = right - left;
        Base::DetectionHaarDetect32fi(hid, mask, maskStride, left, top, right, bottom, dst, dstStride);
}

SIMD_API void SimdDetectionLbpDetect32fp(const void * hid, const uint8_t * mask, size_t maskStride,
    ptrdiff_t left, ptrdiff_t top, ptrdiff_t right, ptrdiff_t bottom, uint8_t * dst, size_t dstStride)
{
    size_t width = right - left;
        Base::DetectionLbpDetect32fp(hid, mask, maskStride, left, top, right, bottom, dst, dstStride);
}

SIMD_API void SimdDetectionLbpDetect32fi(const void * hid, const uint8_t * mask, size_t maskStride,
    ptrdiff_t left, ptrdiff_t top, ptrdiff_t right, ptrdiff_t bottom, uint8_t * dst, size_t dstStride)
{
    size_t width = right - left;
        Base::DetectionLbpDetect32fi(hid, mask, maskStride, left, top, right, bottom, dst, dstStride);
}

SIMD_API void SimdDetectionLbpDetect16ip(const void * hid, const uint8_t * mask, size_t maskStride,
    ptrdiff_t left, ptrdiff_t top, ptrdiff_t right, ptrdiff_t bottom, uint8_t * dst, size_t dstStride)
{
    size_t width = right - left;
        Base::DetectionLbpDetect16ip(hid, mask, maskStride, left, top, right, bottom, dst, dstStride);
}

SIMD_API void SimdDetectionLbpDetect16ii(const void * hid, const uint8_t * mask, size_t maskStride,
    ptrdiff_t left, ptrdiff_t top, ptrdiff_t right, ptrdiff_t bottom, uint8_t * dst, size_t dstStride)
{
    size_t width = right - left;
        Base::DetectionLbpDetect16ii(hid, mask, maskStride, left, top, right, bottom, dst, dstStride);
}

SIMD_API void SimdDetectionFree(void * ptr)
{
    Base::DetectionFree(ptr);
}

SIMD_API void SimdEdgeBackgroundGrowRangeSlow(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                 uint8_t * background, size_t backgroundStride)
{
        Base::EdgeBackgroundGrowRangeSlow(value, valueStride, width, height, background, backgroundStride);
}

SIMD_API void SimdEdgeBackgroundGrowRangeFast(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                 uint8_t * background, size_t backgroundStride)
{
        Base::EdgeBackgroundGrowRangeFast(value, valueStride, width, height, background, backgroundStride);
}

SIMD_API void SimdEdgeBackgroundIncrementCount(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                                  const uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t * backgroundCount, size_t backgroundCountStride)
{
        Base::EdgeBackgroundIncrementCount(value, valueStride, width, height, backgroundValue, backgroundValueStride, backgroundCount, backgroundCountStride);
}

SIMD_API void SimdEdgeBackgroundAdjustRange(uint8_t * backgroundCount, size_t backgroundCountStride, size_t width, size_t height,
                               uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t threshold)
{
        Base::EdgeBackgroundAdjustRange(backgroundCount, backgroundCountStride, width, height, backgroundValue, backgroundValueStride, threshold);
}

SIMD_API void SimdEdgeBackgroundAdjustRangeMasked(uint8_t * backgroundCount, size_t backgroundCountStride, size_t width, size_t height,
                               uint8_t * backgroundValue, size_t backgroundValueStride, uint8_t threshold, const uint8_t * mask, size_t maskStride)
{
        Base::EdgeBackgroundAdjustRangeMasked(backgroundCount, backgroundCountStride, width, height, backgroundValue, backgroundValueStride, threshold, mask, maskStride);
}

SIMD_API void SimdEdgeBackgroundShiftRange(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                              uint8_t * background, size_t backgroundStride)
{
        Base::EdgeBackgroundShiftRange(value, valueStride, width, height, background, backgroundStride);
}

SIMD_API void SimdEdgeBackgroundShiftRangeMasked(const uint8_t * value, size_t valueStride, size_t width, size_t height,
                              uint8_t * background, size_t backgroundStride, const uint8_t * mask, size_t maskStride)
{
        Base::EdgeBackgroundShiftRangeMasked(value, valueStride, width, height, background, backgroundStride, mask, maskStride);
}

SIMD_API void SimdFill(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize, uint8_t value)
{
    Base::Fill(dst, stride, width, height, pixelSize, value);
}

SIMD_API void SimdFillFrame(uint8_t * dst, size_t stride, size_t width, size_t height, size_t pixelSize,
                           size_t frameLeft, size_t frameTop, size_t frameRight, size_t frameBottom, uint8_t value)
{
    Base::FillFrame(dst, stride, width, height, pixelSize, frameLeft, frameTop, frameRight, frameBottom, value);
}

SIMD_API void SimdFillBgr(uint8_t * dst, size_t stride, size_t width, size_t height, uint8_t blue, uint8_t green, uint8_t red)
{
        Base::FillBgr(dst, stride, width, height, blue, green, red);
}

SIMD_API void SimdFillBgra(uint8_t * dst, size_t stride, size_t width, size_t height, uint8_t blue, uint8_t green, uint8_t red, uint8_t alpha)
{
        Base::FillBgra(dst, stride, width, height, blue, green, red, alpha);
}

SIMD_API void SimdGaussianBlur3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                     size_t channelCount, uint8_t * dst, size_t dstStride)
{
		Base::GaussianBlur3x3(src, srcStride, width, height, channelCount, dst, dstStride);
}

SIMD_API void SimdGrayToBgr(const uint8_t * gray, size_t width, size_t height, size_t grayStride, uint8_t * bgr, size_t bgrStride)
{
        Base::GrayToBgr(gray, width, height, grayStride, bgr, bgrStride);
}

SIMD_API void SimdGrayToBgra(const uint8_t * gray, size_t width, size_t height, size_t grayStride, uint8_t * bgra, size_t bgraStride, uint8_t alpha)
{
        Base::GrayToBgra(gray, width, height, grayStride, bgra, bgraStride, alpha);
}

SIMD_API void SimdAbsSecondDerivativeHistogram(const uint8_t *src, size_t width, size_t height, size_t stride, size_t step, size_t indent, uint32_t * histogram)
{
        Base::AbsSecondDerivativeHistogram(src, width, height, stride, step, indent, histogram);
}

SIMD_API void SimdHistogram(const uint8_t *src, size_t width, size_t height, size_t stride, uint32_t * histogram)
{
    Base::Histogram(src, width, height, stride, histogram);
}

SIMD_API void SimdHistogramMasked(const uint8_t *src, size_t srcStride, size_t width, size_t height, 
                                  const uint8_t * mask, size_t maskStride, uint8_t index, uint32_t * histogram)
{
        Base::HistogramMasked(src, srcStride, width, height, mask, maskStride, index, histogram);
}

SIMD_API void SimdHistogramConditional(const uint8_t * src, size_t srcStride, size_t width, size_t height,
    const uint8_t * mask, size_t maskStride, uint8_t value, SimdCompareType compareType, uint32_t * histogram)
{
        Base::HistogramConditional(src, srcStride, width, height, mask, maskStride, value, compareType, histogram);
}

SIMD_API void SimdNormalizeHistogram(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
    Base::NormalizeHistogram(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdHogDirectionHistograms(const uint8_t * src, size_t stride, size_t width, size_t height, 
                                         size_t cellX, size_t cellY, size_t quantization, float * histograms)
{
        Base::HogDirectionHistograms(src, stride, width, height, cellX, cellY, quantization, histograms);
}

SIMD_API void SimdInt16ToGray(const uint8_t * src, size_t width, size_t height, size_t srcStride, uint8_t * dst, size_t dstStride)
{
        Base::Int16ToGray(src, width, height, srcStride, dst, dstStride);
}

SIMD_API void SimdIntegral(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                      uint8_t * sum, size_t sumStride, uint8_t * sqsum, size_t sqsumStride, uint8_t * tilted, size_t tiltedStride,
                      SimdPixelFormatType sumFormat, SimdPixelFormatType sqsumFormat)
{
    Base::Integral(src, srcStride, width, height, sum, sumStride, sqsum, sqsumStride, tilted, tiltedStride, sumFormat, sqsumFormat);
}

SIMD_API void SimdInterferenceIncrement(uint8_t * statistic, size_t stride, size_t width, size_t height, uint8_t increment, int16_t saturation)
{
        Base::InterferenceIncrement(statistic, stride, width, height, increment, saturation);
}

SIMD_API void SimdInterferenceIncrementMasked(uint8_t * statistic, size_t statisticStride, size_t width, size_t height, 
                                              uint8_t increment, int16_t saturation, const uint8_t * mask, size_t maskStride, uint8_t index)
{
        Base::InterferenceIncrementMasked(statistic, statisticStride, width, height, increment, saturation, mask, maskStride, index);
}

SIMD_API void SimdInterferenceDecrement(uint8_t * statistic, size_t stride, size_t width, size_t height, uint8_t decrement, int16_t saturation)
{
        Base::InterferenceDecrement(statistic, stride, width, height, decrement, saturation);
}

SIMD_API void SimdInterferenceDecrementMasked(uint8_t * statistic, size_t statisticStride, size_t width, size_t height, 
                                              uint8_t decrement, int16_t saturation, const uint8_t * mask, size_t maskStride, uint8_t index)
{
        Base::InterferenceDecrementMasked(statistic, statisticStride, width, height, decrement, saturation, mask, maskStride, index);
}

SIMD_API void SimdInterleaveUv(const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride, size_t width, size_t height, uint8_t * uv, size_t uvStride)
{
		Base::InterleaveUv(u, uStride, v, vStride, width, height, uv, uvStride);
}

SIMD_API void SimdInterleaveBgr(const uint8_t * b, size_t bStride, const uint8_t * g, size_t gStride, const uint8_t * r, size_t rStride,
    size_t width, size_t height, uint8_t * bgr, size_t bgrStride)
{
        Base::InterleaveBgr(b, bStride, g, gStride, r, rStride, width, height, bgr, bgrStride);
}

SIMD_API void SimdInterleaveBgra(const uint8_t * b, size_t bStride, const uint8_t * g, size_t gStride, const uint8_t * r, size_t rStride, const uint8_t * a, size_t aStride,
    size_t width, size_t height, uint8_t * bgra, size_t bgraStride)
{
        Base::InterleaveBgra(b, bStride, g, gStride, r, rStride, a, aStride, width, height, bgra, bgraStride);
}

SIMD_API void SimdLaplace(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::Laplace(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdLaplaceAbs(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::LaplaceAbs(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdLaplaceAbsSum(const uint8_t * src, size_t stride, size_t width, size_t height, uint64_t * sum)
{
        Base::LaplaceAbsSum(src, stride, width, height, sum);
}

SIMD_API void SimdLbpEstimate(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::LbpEstimate(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdMeanFilter3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride)
{
		Base::MeanFilter3x3(src, srcStride, width, height, channelCount, dst, dstStride);
}

SIMD_API void SimdMedianFilterRhomb3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride)
{
        Base::MedianFilterRhomb3x3(src, srcStride, width, height, channelCount, dst, dstStride);
}

SIMD_API void SimdMedianFilterRhomb5x5(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride)
{
        Base::MedianFilterRhomb5x5(src, srcStride, width, height, channelCount, dst, dstStride);
}

SIMD_API void SimdMedianFilterSquare3x3(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride)
{
        Base::MedianFilterSquare3x3(src, srcStride, width, height, channelCount, dst, dstStride);
}

SIMD_API void SimdMedianFilterSquare5x5(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride)
{
        Base::MedianFilterSquare5x5(src, srcStride, width, height, channelCount, dst, dstStride);
}

SIMD_API void SimdNeuralConvert(const uint8_t * src, size_t stride, size_t width, size_t height, float * dst, int inversion)
{
        Base::NeuralConvert(src, stride, width, height, dst, inversion);
}

//typedef void(*SimdNeuralProductSumPtr) (const float * a, const float * b, size_t size, float * sum);
//SimdNeuralProductSumPtr simdNeuralProductSum = SIMD_FUNC5(NeuralProductSum, SIMD_AVX2_FUNC, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_VSX_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralProductSum(const float * a, const float * b, size_t size, float * sum)
{
  Base::NeuralProductSum(a, b, size, sum);
}

//typedef void(*SimdNeuralAddVectorMultipliedByValuePtr) (const float * src, size_t size, const float * value, float * dst);
//SimdNeuralAddVectorMultipliedByValuePtr simdNeuralAddVectorMultipliedByValue = SIMD_FUNC4(NeuralAddVectorMultipliedByValue, SIMD_AVX2_FUNC, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralAddVectorMultipliedByValue(const float * src, size_t size, const float * value, float * dst)
{
  Base::NeuralAddVectorMultipliedByValue(src, size, value, dst);
}

//typedef void(*SimdNeuralSigmoidPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralSigmoidPtr simdNeuralSigmoid = SIMD_FUNC0(NeuralSigmoid);

SIMD_API void SimdNeuralSigmoid(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralSigmoid(src, size, slope, dst);
}

//typedef void(*SimdNeuralRoughSigmoidPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralRoughSigmoidPtr simdNeuralRoughSigmoid = SIMD_FUNC4(NeuralRoughSigmoid, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_VSX_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralRoughSigmoid(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralRoughSigmoid(src, size, slope, dst);
}

//typedef void(*SimdNeuralRoughSigmoid2Ptr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralRoughSigmoid2Ptr simdNeuralRoughSigmoid2 = SIMD_FUNC4(NeuralRoughSigmoid2, SIMD_AVX2_FUNC, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralRoughSigmoid2(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralRoughSigmoid2(src, size, slope, dst);
}

//typedef void(*SimdNeuralDerivativeSigmoidPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralDerivativeSigmoidPtr simdNeuralDerivativeSigmoid = SIMD_FUNC3(NeuralDerivativeSigmoid, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralDerivativeSigmoid(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralDerivativeSigmoid(src, size, slope, dst);
}

//typedef void(*SimdNeuralTanhPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralTanhPtr simdNeuralTanh = SIMD_FUNC0(NeuralTanh);

SIMD_API void SimdNeuralTanh(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralTanh(src, size, slope, dst);
}

//typedef void(*SimdNeuralRoughTanhPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralRoughTanhPtr simdNeuralRoughTanh = SIMD_FUNC3(NeuralRoughTanh, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralRoughTanh(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralRoughTanh(src, size, slope, dst);
}

//typedef void(*SimdNeuralDerivativeTanhPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralDerivativeTanhPtr simdNeuralDerivativeTanh = SIMD_FUNC3(NeuralDerivativeTanh, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralDerivativeTanh(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralDerivativeTanh(src, size, slope, dst);
}

//typedef void(*SimdNeuralReluPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralReluPtr simdNeuralRelu = SIMD_FUNC3(NeuralRelu, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralRelu(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralRelu(src, size, slope, dst);
}

//typedef void(*SimdNeuralDerivativeReluPtr) (const float * src, size_t size, const float * slope, float * dst);
//SimdNeuralDerivativeReluPtr simdNeuralDerivativeRelu = SIMD_FUNC3(NeuralDerivativeRelu, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralDerivativeRelu(const float * src, size_t size, const float * slope, float * dst)
{
  Base::NeuralDerivativeRelu(src, size, slope, dst);
}

//typedef void(*SimdNeuralUpdateWeightsPtr) (const float * x, size_t size, const float * a, const float * b, float * d, float * w);
//SimdNeuralUpdateWeightsPtr simdNeuralUpdateWeights = SIMD_FUNC3(NeuralUpdateWeights, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralUpdateWeights(const float * x, size_t size, const float * a, const float * b, float * d, float * w)
{
  Base::NeuralUpdateWeights(x, size, a, b, d, w);
}

//typedef void(*SimdNeuralAdaptiveGradientUpdatePtr) (const float * delta, size_t size, size_t batch, const float * alpha, const float * epsilon, float * gradient, float * weight);
//SimdNeuralAdaptiveGradientUpdatePtr simdNeuralAdaptiveGradientUpdate = SIMD_FUNC3(NeuralAdaptiveGradientUpdate, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralAdaptiveGradientUpdate(const float * delta, size_t size, size_t batch, const float * alpha, const float * epsilon, float * gradient, float * weight)
{
  Base::NeuralAdaptiveGradientUpdate(delta, size, batch, alpha, epsilon, gradient, weight);
}

SIMD_API void SimdNeuralAddConvolution3x3(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride)
{
        Base::NeuralAddConvolution3x3(src, srcStride, width, height, weights, dst, dstStride);
}

SIMD_API void SimdNeuralAddConvolution5x5(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride)
{
        Base::NeuralAddConvolution5x5(src, srcStride, width, height, weights, dst, dstStride);
}

//typedef void(*SimdNeuralAddConvolution3x3BackPtr) (const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);
//SimdNeuralAddConvolution3x3BackPtr simdNeuralAddConvolution3x3Back = SIMD_FUNC3(NeuralAddConvolution3x3Back, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralAddConvolution3x3Back(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride)
{
  Base::NeuralAddConvolution3x3Back(src, srcStride, width, height, weights, dst, dstStride);
}

//typedef void(*SimdNeuralAddConvolution5x5BackPtr) (const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride);
//SimdNeuralAddConvolution5x5BackPtr simdNeuralAddConvolution5x5Back = SIMD_FUNC3(NeuralAddConvolution5x5Back, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdNeuralAddConvolution5x5Back(const float * src, size_t srcStride, size_t width, size_t height, const float * weights, float * dst, size_t dstStride)
{
  Base::NeuralAddConvolution5x5Back(src, srcStride, width, height, weights, dst, dstStride);
}

SIMD_API void SimdNeuralAddConvolution3x3Sum(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums)
{
        Base::NeuralAddConvolution3x3Sum(src, srcStride, dst, dstStride, width, height, sums);
}

SIMD_API void SimdNeuralAddConvolution5x5Sum(const float * src, size_t srcStride, const float * dst, size_t dstStride, size_t width, size_t height, float * sums)
{
        Base::NeuralAddConvolution5x5Sum(src, srcStride, dst, dstStride, width, height, sums);
}

SIMD_API void SimdNeuralMax2x2(const float * src, size_t srcStride, size_t width, size_t height, float * dst, size_t dstStride)
{
        Base::NeuralMax2x2(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdOperationBinary8u(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride,
               size_t width, size_t height, size_t channelCount, uint8_t * dst, size_t dstStride, SimdOperationBinary8uType type)
{
        Base::OperationBinary8u(a, aStride, b, bStride, width, height, channelCount, dst, dstStride, type);
}

SIMD_API void SimdOperationBinary16i(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride,
                                    size_t width, size_t height, uint8_t * dst, size_t dstStride, SimdOperationBinary16iType type)
{
		Base::OperationBinary16i(a, aStride, b, bStride, width, height, dst, dstStride, type);
}

SIMD_API void SimdVectorProduct(const uint8_t * vertical, const uint8_t * horizontal, uint8_t * dst, size_t stride, size_t width, size_t height)
{
        Base::VectorProduct(vertical, horizontal, dst, stride, width, height);
}

SIMD_API void SimdReduceGray2x2(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
                   uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride)
{
        Base::ReduceGray2x2(src, srcWidth, srcHeight, srcStride, dst, dstWidth, dstHeight, dstStride);
}

SIMD_API void SimdReduceGray3x3(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
                   uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride, int compensation)
{
        Base::ReduceGray3x3(src, srcWidth, srcHeight, srcStride, dst, dstWidth, dstHeight, dstStride, compensation);
}

SIMD_API void SimdReduceGray4x4(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
                   uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride)
{
        Base::ReduceGray4x4(src, srcWidth, srcHeight, srcStride, dst, dstWidth, dstHeight, dstStride);
}

SIMD_API void SimdReduceGray5x5(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
                   uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride, int compensation)
{
		Base::ReduceGray5x5(src, srcWidth, srcHeight, srcStride, dst, dstWidth, dstHeight, dstStride, compensation);
}

SIMD_API void SimdReorder16bit(const uint8_t * src, size_t size, uint8_t * dst)
{
        Base::Reorder16bit(src, size, dst);
}

SIMD_API void SimdReorder32bit(const uint8_t * src, size_t size, uint8_t * dst)
{
        Base::Reorder32bit(src, size, dst);
}

SIMD_API void SimdReorder64bit(const uint8_t * src, size_t size, uint8_t * dst)
{
        Base::Reorder64bit(src, size, dst);
}

SIMD_API void SimdResizeBilinear(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
    uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride, size_t channelCount)
{
        Base::ResizeBilinear(src, srcWidth, srcHeight, srcStride, dst, dstWidth, dstHeight, dstStride, channelCount);
}

SIMD_API void SimdSegmentationChangeIndex(uint8_t * mask, size_t stride, size_t width, size_t height, uint8_t oldIndex, uint8_t newIndex)
{
        Base::SegmentationChangeIndex(mask, stride, width, height, oldIndex, newIndex);
}

SIMD_API void SimdSegmentationFillSingleHoles(uint8_t * mask, size_t stride, size_t width, size_t height, uint8_t index)
{
        Base::SegmentationFillSingleHoles(mask, stride, width, height, index);
}

SIMD_API void SimdSegmentationPropagate2x2(const uint8_t * parent, size_t parentStride, size_t width, size_t height, 
                                           uint8_t * child, size_t childStride, const uint8_t * difference, size_t differenceStride, 
                                           uint8_t currentIndex, uint8_t invalidIndex, uint8_t emptyIndex, uint8_t differenceThreshold)
{
        Base::SegmentationPropagate2x2(parent, parentStride, width, height, child, childStride,
        difference, differenceStride, currentIndex, invalidIndex, emptyIndex, differenceThreshold);
}

SIMD_API void SimdSegmentationShrinkRegion(const uint8_t * mask, size_t stride, size_t width, size_t height, uint8_t index,
                                           ptrdiff_t * left, ptrdiff_t * top, ptrdiff_t * right, ptrdiff_t * bottom)
{
        Base::SegmentationShrinkRegion(mask, stride, width, height, index, left, top, right, bottom);
}

SIMD_API void SimdShiftBilinear(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t channelCount,
    const uint8_t * bkg, size_t bkgStride, const double * shiftX, const double * shiftY,
    size_t cropLeft, size_t cropTop, size_t cropRight, size_t cropBottom, uint8_t * dst, size_t dstStride)
{
        Base::ShiftBilinear(src, srcStride, width, height, channelCount, bkg, bkgStride,
        shiftX, shiftY, cropLeft, cropTop, cropRight, cropBottom, dst, dstStride);
}

SIMD_API void SimdSobelDx(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::SobelDx(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdSobelDxAbs(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::SobelDxAbs(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdSobelDxAbsSum(const uint8_t * src, size_t stride, size_t width, size_t height, uint64_t * sum)
{
        Base::SobelDxAbsSum(src, stride, width, height, sum);
}

SIMD_API void SimdSobelDy(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
		Base::SobelDy(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdSobelDyAbs(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::SobelDyAbs(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdSobelDyAbsSum(const uint8_t * src, size_t stride, size_t width, size_t height, uint64_t * sum)
{
		Base::SobelDyAbsSum(src, stride, width, height, sum);
}

SIMD_API void SimdContourMetrics(const uint8_t * src, size_t srcStride, size_t width, size_t height, uint8_t * dst, size_t dstStride)
{
        Base::ContourMetrics(src, srcStride, width, height, dst, dstStride);
}

SIMD_API void SimdContourMetricsMasked(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                       const uint8_t * mask, size_t maskStride, uint8_t indexMin, uint8_t * dst, size_t dstStride)
{
        Base::ContourMetricsMasked(src, srcStride, width, height, mask, maskStride, indexMin, dst, dstStride);
}

SIMD_API void SimdContourAnchors(const uint8_t * src, size_t srcStride, size_t width, size_t height, size_t step, int16_t threshold, uint8_t * dst, size_t dstStride)
{
        Base::ContourAnchors(src, srcStride, width, height, step, threshold, dst, dstStride);
}

SIMD_API void SimdSquaredDifferenceSum(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
                          size_t width, size_t height, uint64_t * sum)
{
        Base::SquaredDifferenceSum(a, aStride, b, bStride, width, height, sum);
}

SIMD_API void SimdSquaredDifferenceSumMasked(const uint8_t *a, size_t aStride, const uint8_t *b, size_t bStride,
                          const uint8_t *mask, size_t maskStride, uint8_t index, size_t width, size_t height, uint64_t * sum)
{
        Base::SquaredDifferenceSumMasked(a, aStride, b, bStride, mask, maskStride, index, width, height, sum);
}

//typedef void (* SimdSquaredDifferenceSum32fPtr) (const float * a, const float * b, size_t size, float * sum);
//SimdSquaredDifferenceSum32fPtr simdSquaredDifferenceSum32f = SIMD_FUNC4(SquaredDifferenceSum32f, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_VSX_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdSquaredDifferenceSum32f(const float * a, const float * b, size_t size, float * sum)
{
  Base::SquaredDifferenceSum32f(a, b, size, sum);
}

//typedef void (* SimdSquaredDifferenceKahanSum32fPtr) (const float * a, const float * b, size_t size, float * sum);
//SimdSquaredDifferenceKahanSum32fPtr simdSquaredDifferenceKahanSum32f = SIMD_FUNC4(SquaredDifferenceKahanSum32f, SIMD_AVX_FUNC, SIMD_SSE_FUNC, SIMD_VSX_FUNC, SIMD_NEON_FUNC);

SIMD_API void SimdSquaredDifferenceKahanSum32f(const float * a, const float * b, size_t size, float * sum)
{
  Base::SquaredDifferenceKahanSum32f(a, b, size, sum);
}

SIMD_API void SimdGetStatistic(const uint8_t * src, size_t stride, size_t width, size_t height,
                  uint8_t * min, uint8_t * max, uint8_t * average)
{
        Base::GetStatistic(src, stride, width, height, min, max, average);
}

SIMD_API void SimdGetMoments(const uint8_t * mask, size_t stride, size_t width, size_t height, uint8_t index,
                uint64_t * area, uint64_t * x, uint64_t * y, uint64_t * xx, uint64_t * xy, uint64_t * yy)
{
		Base::GetMoments(mask, stride, width, height, index, area, x, y, xx, xy, yy);
}

SIMD_API void SimdGetRowSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums)
{
        Base::GetRowSums(src, stride, width, height, sums);
}

SIMD_API void SimdGetColSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums)
{
        Base::GetColSums(src, stride, width, height, sums);
}

SIMD_API void SimdGetAbsDyRowSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums)
{
        Base::GetAbsDyRowSums(src, stride, width, height, sums);
}

SIMD_API void SimdGetAbsDxColSums(const uint8_t * src, size_t stride, size_t width, size_t height, uint32_t * sums)
{
        Base::GetAbsDxColSums(src, stride, width, height, sums);
}

SIMD_API void SimdValueSum(const uint8_t * src, size_t stride, size_t width, size_t height, uint64_t * sum)
{
        Base::ValueSum(src, stride, width, height, sum);
}

SIMD_API void SimdSquareSum(const uint8_t * src, size_t stride, size_t width, size_t height, uint64_t * sum)
{
        Base::SquareSum(src, stride, width, height, sum);
}

SIMD_API void SimdCorrelationSum(const uint8_t * a, size_t aStride, const uint8_t * b, size_t bStride, size_t width, size_t height, uint64_t * sum)
{
        Base::CorrelationSum(a, aStride, b, bStride, width, height, sum);
}

SIMD_API void SimdStretchGray2x2(const uint8_t *src, size_t srcWidth, size_t srcHeight, size_t srcStride,
                    uint8_t *dst, size_t dstWidth, size_t dstHeight, size_t dstStride)
{
        Base::StretchGray2x2(src, srcWidth, srcHeight, srcStride, dst, dstWidth, dstHeight, dstStride);
}

SIMD_API void SimdSvmSumLinear(const float * x, const float * svs, const float * weights, size_t length, size_t count, float * sum)
{
        Base::SvmSumLinear(x, svs, weights, length, count, sum);
}

SIMD_API void SimdTextureBoostedSaturatedGradient(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                     uint8_t saturation, uint8_t boost, uint8_t * dx, size_t dxStride, uint8_t * dy, size_t dyStride)
{
        Base::TextureBoostedSaturatedGradient(src, srcStride, width, height, saturation, boost, dx, dxStride, dy, dyStride);
}

SIMD_API void SimdTextureBoostedUv(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                      uint8_t boost, uint8_t * dst, size_t dstStride)
{
        Base::TextureBoostedUv(src, srcStride, width, height, boost, dst, dstStride);
}

SIMD_API void SimdTextureGetDifferenceSum(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                             const uint8_t * lo, size_t loStride, const uint8_t * hi, size_t hiStride, int64_t * sum)
{
        Base::TextureGetDifferenceSum(src, srcStride, width, height, lo, loStride, hi, hiStride, sum);
}

SIMD_API void SimdTexturePerformCompensation(const uint8_t * src, size_t srcStride, size_t width, size_t height,
                                int shift, uint8_t * dst, size_t dstStride)
{
        Base::TexturePerformCompensation(src, srcStride, width, height, shift, dst, dstStride);
}

SIMD_API void SimdYuv420pToBgr(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                 size_t width, size_t height, uint8_t * bgr, size_t bgrStride)
{
        Base::Yuv420pToBgr(y, yStride, u, uStride, v, vStride, width, height, bgr, bgrStride);
}

SIMD_API void SimdYuv422pToBgr(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                 size_t width, size_t height, uint8_t * bgr, size_t bgrStride)
{
        Base::Yuv422pToBgr(y, yStride, u, uStride, v, vStride, width, height, bgr, bgrStride);
}

SIMD_API void SimdYuv444pToBgr(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                               size_t width, size_t height, uint8_t * bgr, size_t bgrStride)
{
        Base::Yuv444pToBgr(y, yStride, u, uStride, v, vStride, width, height, bgr, bgrStride);
}

SIMD_API void SimdYuv420pToBgra(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                  size_t width, size_t height, uint8_t * bgra, size_t bgraStride, uint8_t alpha)
{
        Base::Yuv420pToBgra(y, yStride, u, uStride, v, vStride, width, height, bgra, bgraStride, alpha);
}

SIMD_API void SimdYuv422pToBgra(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                                size_t width, size_t height, uint8_t * bgra, size_t bgraStride, uint8_t alpha)
{
        Base::Yuv422pToBgra(y, yStride, u, uStride, v, vStride, width, height, bgra, bgraStride, alpha);
}

SIMD_API void SimdYuv444pToBgra(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                  size_t width, size_t height, uint8_t * bgra, size_t bgraStride, uint8_t alpha)
{
        Base::Yuv444pToBgra(y, yStride, u, uStride, v, vStride, width, height, bgra, bgraStride, alpha);
}

SIMD_API void SimdYuv444pToHsl(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                               size_t width, size_t height, uint8_t * hsl, size_t hslStride)
{
    Base::Yuv444pToHsl(y, yStride, u, uStride, v, vStride, width, height, hsl, hslStride);
}

SIMD_API void SimdYuv444pToHsv(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                               size_t width, size_t height, uint8_t * hsv, size_t hsvStride)
{
    Base::Yuv444pToHsv(y, yStride, u, uStride, v, vStride, width, height, hsv, hsvStride);
}

SIMD_API void SimdYuv420pToHue(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                 size_t width, size_t height, uint8_t * hue, size_t hueStride)
{
        Base::Yuv420pToHue(y, yStride, u, uStride, v, vStride, width, height, hue, hueStride);
}

SIMD_API void SimdYuv444pToHue(const uint8_t * y, size_t yStride, const uint8_t * u, size_t uStride, const uint8_t * v, size_t vStride,
                 size_t width, size_t height, uint8_t * hue, size_t hueStride)
{
        Base::Yuv444pToHue(y, yStride, u, uStride, v, vStride, width, height, hue, hueStride);
}



