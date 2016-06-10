#include <gtest/gtest.h> 
#include <limits>

#include "array.hpp" 
namespace structs = lcpp::datastructures;

TEST(ArrayTest, shouldAllocateMaxSizeTSpace) {
  size_t max_size_t = std::numeric_limits<size_t>::max();
  structs::Array<int> arr = structs::Array<int>(max_size_t);
}
