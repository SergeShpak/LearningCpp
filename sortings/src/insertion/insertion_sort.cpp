#include <cstddef>

#include "insertion_sort.hpp"

namespace sort = lcpp::sort;

void sort::InsertionSort::Sort(int * & values, size_t values_count) {
    for (int i = 1; i < values_count; i++) {
        int current_elem = values[i];
        int j = i - 1;
        while (j >= 0 && values[j] > current_elem) {
            values[j + 1] = values[j];
            j--;
        }
        values[j + 1] = current_elem;    
    }
}
