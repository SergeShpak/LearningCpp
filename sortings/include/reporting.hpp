#ifndef LCPP_SORITNG_REPORTING_HPP
#define LCPP_SORITNG_REPORTING_HPP

#include <cstddef>
#include <string>
#include <sstream>

#include "sort.hpp"

namespace lcpp {
  namespace sort {
    class Reporting {
    private:
      int * values;
      size_t values_count;
      lcpp::sort::SortBase *algo;
      std::string algo_name;
      std::stringstream *report_ss;
      void ReportInternal(std::string);
      void ReportArray();
      void Sort();
    public:
      Reporting(lcpp::sort::SortBase*, std::string);
      std::stringstream* Report(int *, size_t);
    };
  }
}


#endif
