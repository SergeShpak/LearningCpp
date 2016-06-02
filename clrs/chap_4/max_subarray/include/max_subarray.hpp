#ifndef MAX_SUBARRAY_HPP
#define MAX_SUBARRAY_HPP

#include <cstddef>

namespace clrs {
  namespace chap_4 {

    struct ArrayIndices {
    private:
      int low_;
      int high_;
      int sum_;
    public:
      ArrayIndices() = delete;
      ArrayIndices(int, int, int);
      const int low();
      const int high();
      const int sum();
    };

    class MaxSubarraySolver {
    private:
      static void FindMaxSubarray(int*, int, int, int&, int&);
      static void FindMaxCrossingSubarray(int*, int, int, int, int&, int&);
      static int FindSum(int*, int, int);
    public:
     static ArrayIndices *Solve(int *values, size_t values_count);
    };

  }
}



#endif
