#include "array.hpp"

namespace ds = dstructures;

template<typename T>
ds::Array<T>::Array(size_t elems_count) {
  this->size = elems_count; 
}
