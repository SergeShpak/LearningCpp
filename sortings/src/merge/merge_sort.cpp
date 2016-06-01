#include "merge_sort.hpp"

namespace sort = lcpp::sort;

static void copy_rest(int *rest, int * & values, 
                        int rest_size, int rest_idx, int values_idx) {
    for (int i = 0; i < rest_size; i++) {
        values[values_idx + i] = rest[rest_idx + i];
    }
}

void sort::MergeSort::Merge(int * & values, int first_start_idx,
                                int second_start_idx, int second_count) {
    int *first_part = new int[second_start_idx - first_start_idx];
    int first_count = second_start_idx - first_start_idx;
    for (int i = 0; i < first_count; i++) {
        first_part[i] = values[first_start_idx + i];
    }
    int *second_part = new  int[second_count];
    for (int i = 0; i < second_count; i++) {
        second_part[i] = values[second_start_idx + i];
    }

    int first_curr_idx = 0, second_curr_idx = 0;
    int original_arr_idx = first_start_idx;
    bool first_not_empty = true, second_not_empty = true;
    while (true) {
        bool is_first_bigger = 
                    first_part[first_curr_idx] > second_part[second_curr_idx];
        if (is_first_bigger) {
            values[original_arr_idx] = second_part[second_curr_idx];
            second_curr_idx++;
        }
        if (!is_first_bigger) {
            values[original_arr_idx] = first_part[first_curr_idx];
            first_curr_idx++;
        } 
        original_arr_idx++;
        if (first_curr_idx == first_count) {
            first_not_empty = false;
            break;
        }
        if (second_curr_idx == second_count) {
            second_not_empty = false;
            break;
        }
    }
    
    int *rest;
    int rest_size, curr_idx;
    if (first_not_empty) {
        rest = first_part;
        rest_size = first_count - first_curr_idx;
        curr_idx = first_curr_idx; 
    }
    if (second_not_empty) {
        rest = second_part;
        rest_size = second_count - second_curr_idx;
        curr_idx = second_curr_idx;
    }
    copy_rest(rest, values, rest_size, curr_idx, original_arr_idx);

    delete[] first_part;
    delete[] second_part;
}

void sort::MergeSort::SortInternal(int * & values, 
                                    int start_idx, int end_idx) {
    if (! (end_idx > start_idx)) {
        return;
    }
    int middle_idx = (start_idx + end_idx) / 2;
    sort::MergeSort::SortInternal(values, start_idx, middle_idx);
    sort::MergeSort::SortInternal(values, middle_idx + 1, end_idx);
    sort::MergeSort::Merge(values, start_idx, middle_idx + 1, 
                          end_idx - middle_idx);
}


void sort::MergeSort::Sort(int * & values, size_t count) {
    sort::MergeSort::SortInternal(values, 0, count - 1);
}
