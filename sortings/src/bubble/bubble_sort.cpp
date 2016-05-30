#include "bubble_sort.hpp"

namespace sort = lcpp::sort;

void sort::BubbleSort::Sort(int * &values, size_t values_count) {
    for (int i = 0; i < values_count; i++) {
        for (int j = 0; j < values_count - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                sort::BubbleSort::swap(values[j], values[j + 1]);
            }
        }
    }
}
