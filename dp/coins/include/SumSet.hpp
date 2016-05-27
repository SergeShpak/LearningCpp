#ifndef SUM_SET_HPP
#define SUM_SET_HPP

#include <string>
#include <array>

struct SumSet {
private:
  static bool initialized;
  static int *set;
  static size_t set_size;
  int *counts;
  int sum;
public:
  static void Initialize(const char * const);
  static size_t GetSetSize();
  SumSet(int sum, int *counts);
  ~SumSet();
  std::string ToString();
  static const int *GetCoinSet();
};

#endif
