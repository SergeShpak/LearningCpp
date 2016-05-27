#ifndef __DSTRUCT_ARRAY_HPP
#define __DSTUCT_ARRAY_HPP

#include <cstddef>

namespace dstructures
{
  template<typename T> class Array
  {
  private:
    size_t size;
  public:
    Array(size_t);
  };
}

#endif
