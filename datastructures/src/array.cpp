#include <cstddef>

#include "array.hpp"

namespace structs = lcpp::datastructures;

template <typename T>
structs::Array<T>::Array(std::size_t elements_count) {
  this->elements = new T[elements_count];
  this->elements_count = elements_count;
}

template <typename T>
structs::Array<T>::~Array() {
  delete[] elements;
}

template <typename T>
T& structs::Array<T>::operator[] (const std::size_t idx) {
  T& ref_to_element = this->elements[idx];
  return ref_to_element;
}

template <typename T>
const T& structs::Array<T>::operator[] (const std::size_t idx) const {
  const T& ref_to_element = this->elements[idx];
  return ref_to_element; 
}
