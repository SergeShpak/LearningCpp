#ifndef LCPP_INSERTION_SORT_HPP
#define LCPP_INSERTION_SORT_HPP

#include "sort.hpp"

namespace lcpp {
    namespace sort {
        
        class InsertionSort : public virtual SortBase {
        public:
            void Sort(int *&, size_t) override;
        };

    }
}

#endif
