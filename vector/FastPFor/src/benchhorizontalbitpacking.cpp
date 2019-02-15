#include <exception>
#include <iostream>
#include <iomanip>
#include <vector>
#include "util.h"
#include "bitpackinghelpers.h"
#include "rolledbitpacking.h"
#include "synthetic.h"
#include "ztimer.h"
//#include "horizontalbitpacking.h"

using namespace std;
using namespace FastPForLib;

namespace FastPForLib {
void simdhunpack(const uint8_t * in, uint32_t * out, uint32_t bit);
}

void maskfnc(vector<uint32_t, cacheallocator> &out, const uint32_t L) {
  if (L == 32)
    return;
  for (auto i = out.begin(); i != out.end(); ++i) {
    *i = *i % (1U << L);
  }
}

void horizontalunpack(const vector<uint32_t, cacheallocator> &data,
                      vector<uint32_t, cacheallocator> &out,
                      const uint32_t bit) {
  const size_t N = out.size();
  for (size_t k = 0; k < N / 128; ++k) {
    simdhunpack(reinterpret_cast<const uint8_t *>(&data[0] + 4 * bit * k),
                &out[0] + 128 * k, bit);
  }
}

void pack(const vector<uint32_t, cacheallocator> &data,
          vector<uint32_t, cacheallocator> &out, const uint32_t bit) {
  const size_t N = data.size();
  for (size_t k = 0; k < N / 32; ++k) {
    pack<true>(&data[0] + 32 * k, &out[0] + bit * k, bit);
  }
}

template <class container32bit>
bool equalOnFirstBits(const container32bit &data,
                      const container32bit &recovered, uint32_t bit) {
  if (bit == 32) {
    return data == recovered;
  }
  for (size_t k = 0; k < data.size(); ++k) {
    if (data[k] % (1U << bit) != recovered[k] % (1U << bit)) {
      cout << " They differ at k = " << k << " data[k]= " << data[k]
           << " recovered[k]=" << recovered[k] << endl;
      return false;
    }
  }
  return true;
}

void simplebenchmark(string label, uint32_t N = 1U << 16, uint32_t T = 1U << 9, uint32_t R = 1) {
  T = T + 1; // we have a warming up pass
  vector<uint32_t, cacheallocator> data = generateArray32(N);
  vector<uint32_t, cacheallocator> compressed(N, 0);
  vector<uint32_t, cacheallocator> recovered(N, 0);
  WallClockTimer z;
  uint64_t packtime, packtimewm, unpacktime;
  uint64_t simdpacktime, simdpacktimewm, simdunpacktime;
  uint64_t horizontalunpacktime;

  uint64_t horizontalunpacktimes[32] = {0};

  //cout << "#million of integers per second: higher is better" << endl;
  //cout << "#bit, pack, pack without mask, unpack" << endl;

  for (uint32_t repeat = 1; repeat <= R; ++repeat) {
    cout << label << endl;

    for (uint32_t bitindex = 0; bitindex < 32; ++bitindex) {
      uint32_t bit = 32 - bitindex;
      maskfnc(data, bit);
      horizontalunpacktime = 0;

      for (uint32_t t = 0; t < T; ++t) {
        compressed.clear();
        compressed.resize(N * bit / 32, 0);
        recovered.clear();
        recovered.resize(N, 0);

        pack(data, compressed, bit);

        z.reset();
        horizontalunpack(compressed, recovered, bit);
        if (t > 0)
          horizontalunpacktime += z.split();

        if (!equalOnFirstBits(data, recovered, bit)) {
          cout << " Bug1!" << endl;
          return;
        }
      }

      horizontalunpacktimes[bitindex] += horizontalunpacktime;

      cout << bit << "\t" << N * (T - 1) * repeat / double(horizontalunpacktimes[bitindex]) << "\t\t";
      cout << endl;
    }
  }
}

int main() {
  simplebenchmark("# cache-to-cache", 1U << 16, 1U << 10, 1U << 6);
  cout << endl;
  simplebenchmark("# ram-to-ram", 1U << 25, 1U << 0, 1U << 3);

  return 0;
}
