#ifndef LCPP_MERGE_SORT_HPP
#define LCPP_MERGE_SORT_HPP

#include <cstddef>

#include "sort.hpp"

namespace lcpp {
    namespace sort {
    
        class MergeSort : public virtual SortBase {
        private:
            void Merge(int * &, int, int, int);
            void SortInternal(int * &, int, int);
        public:
            void Sort(int * &, size_t) override;
        };

    }
}

#endif
