#ifndef COIN_SET_HPP
#define COIN_SET_HPP

#include <cstddef>

class CoinSet {
private:
  int *coin_set;
  size_t coin_set_size;
public:
  CoinSet(const char * const coin_set_file);
  void PrintSet();
  size_t GetSetSize();
  ~CoinSet();
};

#endif
