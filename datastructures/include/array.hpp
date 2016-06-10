#ifndef LCPP_UTILS_DS_ARRAY_HPP
#define LCPP_UTILS_DS_ARRAY_HPP

#include <cstddef>

namespace lcpp {
  namespace datastructures {
    
    template <typename T> class Array {
      private:
        std::size_t elements_count;
        T *elements;
      public:
        Array() = delete;
        Array(std::size_t elements_count);
        ~Array();

        T& operator[] (const std::size_t idx);
        const T& operator[] (const std::size_t idx) const;
    };

  }
}

#include "../src/array.cpp"

#endif
