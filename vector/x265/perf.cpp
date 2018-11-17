/*****************************************
 * Copyright (C) 2018 Ajay Jain
 *
 * Authors: Ajay Jain <ajayjain@mit.edu>
 * Date: November 2018
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 ****************************************/

#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>
#include <math.h>

#include "common.h"

void sse3_idct32(const int16_t *src, int16_t *dst, intptr_t stride);
void sse3_idct16(const int16_t *src, int16_t *dst, intptr_t stride);
void sse3_idct8(const int16_t *src, int16_t *dst, intptr_t stride);
void ssse3_dct16(const int16_t *src, int16_t *dst, intptr_t stride);
void ssse3_dct32(const int16_t *src, int16_t *dst, intptr_t stride);
void sse41_dequant_scaling(const int16_t* quantCoef, const int32_t *deQuantCoef, int16_t* coef, int num, int per, int shift);

const int iterations = 5000000;
const double variance = 1.0 / sqrt(iterations);

#define SLEEP(MSEC) std::this_thread::sleep_for(std::chrono::milliseconds(MSEC))

#define DEFINE_TEST_WITH_MATRIX(func) \
void test_##func(int W) { \
    int16_t src[W * W]; \
	int16_t dst[W * W]; \
    random_fill(src, W * W); \
    memset(dst, 0, W * W * sizeof(int16_t)); \
    auto t1 = std::chrono::high_resolution_clock::now(); \
    for (int i = 0; i < iterations; ++i) \
        func(src, dst, W); \
	auto t2 = std::chrono::high_resolution_clock::now(); \
    double time_per_iteration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() / (double) iterations; \
	std::cout << #func ", " << time_per_iteration << ", " << time_per_iteration * variance << "\n"; \
}

void random_fill(int16_t *src, size_t length) {
    for (size_t i = 0; i < length; ++i)
        src[i] = (rand() & PIXEL_MAX) - (rand() & PIXEL_MAX);
}

void random_fill(int32_t *src, size_t length) {
    for (size_t i = 0; i < length; ++i)
        src[i] = rand() % PIXEL_MAX;
}

void test_sse41_dequant_scaling(int log2Size, int qp) {
    assert(log2Size <= 5 && log2Size >= 2);
    int width = 1 << log2Size;
    int num = width * width;
    int cmp_size = sizeof(int16_t) * num;

    assert(qp < (QP_MAX_SPEC + QP_BD_OFFSET + 1) && qp >= 0);
    int per = qp / 6;

    int transformShift = MAX_TR_DYNAMIC_RANGE - X265_DEPTH - log2Size;
    int shift = QUANT_IQUANT_SHIFT - QUANT_SHIFT - transformShift;

    int16_t quantCoef[num];
    random_fill(quantCoef, num);

    int32_t dequantCoef[num];
    random_fill(dequantCoef, num);

    int16_t dstCoef[num];
    memset(dstCoef, 0, num * sizeof(int16_t));

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i)
        sse41_dequant_scaling(quantCoef, dequantCoef, dstCoef, num, per, shift);
	auto t2 = std::chrono::high_resolution_clock::now();
    double time_per_iteration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() / (double) iterations;
	std::cout << "sse41_dequant_scaling(num=" << num << "_qp=" << qp << "_shift=" << shift << "), "
              << time_per_iteration << ", " << time_per_iteration * variance << "\n"; \
}

DEFINE_TEST_WITH_MATRIX(sse3_idct32)
DEFINE_TEST_WITH_MATRIX(sse3_idct16)
DEFINE_TEST_WITH_MATRIX(sse3_idct8)
DEFINE_TEST_WITH_MATRIX(ssse3_dct32)
DEFINE_TEST_WITH_MATRIX(ssse3_dct16)

int main() {
    // Seed for random_fill
    srand(124U);

    test_sse3_idct32(32);
    SLEEP(1000);
    test_sse3_idct16(16);
    SLEEP(1000);
    test_sse3_idct8(8);
    SLEEP(1000);

    test_ssse3_dct32(32);
    SLEEP(1000);
    test_ssse3_dct16(16);
    SLEEP(1000);

    for (int qp = 0; qp < QP_MAX_SPEC + QP_BD_OFFSET + 1; qp += 6) {
        test_sse41_dequant_scaling(5, qp);
        SLEEP(1000);
        test_sse41_dequant_scaling(4, qp);
        SLEEP(1000);
        test_sse41_dequant_scaling(3, qp);
        SLEEP(1000);
    }
}

