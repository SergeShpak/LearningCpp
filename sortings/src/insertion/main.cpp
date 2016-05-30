#include <iostream>

#include "insertion_sort.hpp"

namespace sort = lcpp::sort;

static void PrintArray(int *values, size_t values_count) {
    for (int i = 0; i < values_count; i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    int *vals = new int[4];
    for(int i = 0; i < 4; i++) {
        vals[i] = 4 - i;
    }
    std::cout << "Array before sorting:" << std::endl;
    PrintArray(vals, 4);
    sort::InsertionSort *bs = new sort::InsertionSort();
    bs->Sort(vals, 4);
    std::cout << "Array after sorting:" << std::endl;
    PrintArray(vals, 4);
    return 0;
}
