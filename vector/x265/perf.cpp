
#include <iostream>
#include <chrono>
#include <math.h>

void sse3_idct32(const int16_t *src, int16_t *dst, intptr_t stride);
void ssse3_dct16(const int16_t *src, int16_t *dst, intptr_t stride);

const int iterations = 5000000;
const double variance = 1.0 / sqrt(iterations);

//void test_##func(int16_t *src, int16_t *dst, intptr_t stride) { 

#define DEFINE_TEST(func) \
void test_##func(int W) { \
    int16_t src[W * W]; \
	int16_t dst[W * W]; \
    random_init(src, W * W); \
    random_init(dst, W * W); \
    auto t1 = std::chrono::high_resolution_clock::now(); \
    for (int i = 0; i < iterations; ++i) \
        func(src, dst, W); \
	auto t2 = std::chrono::high_resolution_clock::now(); \
    double time_per_iteration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count() / (double) iterations; \
	std::cout << " #func " << time_per_iteration << " us +- " << time_per_iteration * variance << "\n"; \
}

void random_init(int16_t *src, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        src[i] = rand() % 128;
    }
}

DEFINE_TEST(sse3_idct32)
DEFINE_TEST(ssse3_dct16)

int main() {
    test_sse3_idct32(32);
    test_ssse3_dct16(16);
}
