#ifndef LCPP_SORT_ABS_HPP
#define LCPP_SORT_ABS_HPP

#include <cstddef>

namespace lcpp {
    namespace sort {
        
        class SortBase {
            public:
                static void swap(int & first, int & second) {
                    int tmp = first;
                    first = second;
                    second = tmp;
                }
                virtual void Sort(int * &, size_t) = 0;    
        };

    }    
}

#endif
