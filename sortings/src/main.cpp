#include <cstddef>
#include <iostream>
#include <sstream>

#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"

namespace sort = lcpp::sort;

static std::stringstream write_array_to_ss(std::stringstream report_ss, int *array, size_t arr_size) {
    for (int i = 0; i < arr_size; i++) {
        report_ss << array[i] << " ";
    }    
    report_ss << "\n";
}

static std::stringstream report_before(std::stringstream report_ss, char* algorithm_name, int *values, size_t values_count) {
    report_ss << "Trying " << algorithm_name << " algorithm:\n"
                << "\tarray before:\n";
    report_ss = write_array_to_ss(report_ss, values, values_count);
    return report_ss;
}

static void fill_array_randomly(int * & values, size_t values_count) {
     
}

int main(int argc, char* argv[]) {
    std::stringstream report_ss;
    report_ss = report_before(report_ss); 
    sort::SortBase sort_algo = new sort::BubbleSort();
    
}
