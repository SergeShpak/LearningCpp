#ifndef LCPP_SORT_BUBBLE_HPP
#define LCPP_SORT_BUBBLE_HPP

#include <cstddef>

#include "sort.hpp"

namespace lcpp {
    namespace sort {
        
        class BubbleSort : public virtual SortBase {
        public:
            void Sort(int *&, size_t) override;
        };    
    }
}

#endif
