#include <cstddef>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "bubble_sort.hpp"
#include "reporting.hpp"

namespace sort = lcpp::sort;

std::string algo_name;

static void GenerateArrayRandomly(int *values, size_t values_count) {
  std::srand(std::time(NULL));
  for (int i = 0; i <values_count; i++) {
      values[i] = std::rand() % 1000;
    } 
}

int main(int argc, char* argv[]) {
  size_t values_count = 10;
  int *values = new int[values_count];
  GenerateArrayRandomly(values, values_count);
  sort::SortBase *algo = new sort::BubbleSort();
  sort::Reporting *reporting = new sort::Reporting(algo, algo_name);
  std::stringstream *report_ss = reporting->Report(values, values_count);
  std::cout << report_ss->str();
  delete report_ss;
  delete[] values;
  delete reporting;
  delete algo;
}
