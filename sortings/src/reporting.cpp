#include <cstddef>
#include <string>
#include <sstream>

#include "reporting.hpp"

namespace sort = lcpp::sort;

sort::Reporting::Reporting(sort::SortBase *algo, std::string algo_name) {
  this->algo = algo;
  this->algo_name = algo_name;
}

std::stringstream *sort::Reporting::Report(int *values, size_t values_count) {
  this->values = values;
  this->values_count = values_count;
  std::stringstream *report_ss = new std::stringstream();
  this->report_ss = report_ss;
  ReportInternal(std::string("Array before " + algo_name));
  Sort();
  ReportInternal(std::string("Array after " + algo_name));
  *report_ss << std::endl;
  return report_ss;
}

void sort::Reporting::Sort() {
  algo->Sort(values, values_count);
}

void sort::Reporting::ReportArray() {
  for (int i = 0; i < values_count; i++) {
    *report_ss  << values[i] << " ";
  }
  *report_ss << "\n";
}

void sort::Reporting::ReportInternal(std::string msg) {
  *report_ss << msg << ":\n\t";
  this->ReportArray();
  *report_ss << "\n";
}
