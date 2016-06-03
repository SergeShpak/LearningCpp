#include <iostream>

#include "max_subarray.hpp"

namespace chap4 = clrs::chap_4;

int main(int argc, char *argv[]) {
  int vals[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 
                  7};
  chap4::ArrayIndices *ai = chap4::MaxSubarraySolver::Solve(vals, 16);
  std::cout << "Left: " << ai->low() << ";\tRight: " << ai->high() 
            << std::endl;
  delete ai;
  return 0;
}
