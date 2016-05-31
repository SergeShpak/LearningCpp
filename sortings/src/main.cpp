#include <cstddef>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "reporting.hpp"

#ifndef SORTING_ALGO
  #define ERR_MSG "Sorting algoritm must be specified on compilation time \
                  (option -DSORTING_ALGO)"
  #error ERR_MSG
#endif

namespace sort = lcpp::sort;

std::string algo_name;

static void GenerateArrayRandomly(int *values, size_t values_count) {
  std::srand(std::time(NULL));
  for (int i = 0; i <values_count; i++) {
    values[i] = std::rand() % 1000;
  } 
}

static sort::SortBase *GetSortingAlgorithm() {
  #ifdef SORTING_ALGO
    #if SORTING_ALGO==BubbleSort
      algo_name = "BubbleSort";
      return new sort::BubbleSort(); 
    #elif SORTING_ALGO==InsertionSort
      algo_name = "InsertionSort";
      return new sort::InsertionSort();
    #else
      #error "Unknown sorting algoritm specified";
    #endif
  #endif
  #ifndef SORTING_ALGO
    #error "No sorting algorithm specified";
  #endif
}

int main(int argc, char* argv[]) {
  size_t values_count = 10;
  int *values = new int[values_count];
  GenerateArrayRandomly(values, values_count);
  sort::SortBase *algo = GetSortingAlgorithm();
  sort::Reporting *reporting = new sort::Reporting(algo, algo_name);
  std::stringstream *report_ss = reporting->Report(values, values_count);
  std::cout << report_ss->str();
  delete report_ss;
  delete[] values;
  delete reporting;
  delete algo;
}
