#include <iostream>

#include "CoinSet.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Too few arguments" << std::endl;
    return 1;
  }
  CoinSet *set = new CoinSet(argv[1]);
  std::cout << "Set size: " << set->GetSetSize();
  set->PrintSet();
  return 0;
}
