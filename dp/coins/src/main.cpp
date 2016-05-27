#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

#include "SumSet.hpp"

static const int UNREACHABLE = -1;

static SumSet **sets;

static void InitializeSets(std::vector<int> sums) {
  std::vector<int>::iterator max_it;
  max_it = std::max_element(sums.begin(), sums.end());
  const int *coin_set = SumSet::GetCoinSet();
  const size_t set_size = SumSet::GetSetSize();
  int max_element = *max_it;
  for (int i = 0; i < set_size; i++) {
    if (coin_set[i] > max_element) {
      max_element = coin_set[i];
    } 
  }
  sets = new SumSet*[max_element - 1]();
  for (int i = 0; i < set_size; i++) {
    int *counts = new int[set_size]();
    counts[i] = 1;
    int coin_nominal = coin_set[i];
    sets[coin_nominal - 1] = new SumSet(coin_nominal, counts);
    delete[] counts;
  }
} 

static void CalculateSet(int i) {
  int sum_to_calculate = i + 1;

}

static std::vector<int> ReadSums(const char * const sums_file) {
  std::ifstream sums_fs;
  sums_fs.open(sums_file, std::ifstream::in);
  if (!sums_fs.is_open()) {
    std::stringstream exception_msg_ss;
    exception_msg_ss << "File " << sums_file << " cannot be opened";
    throw std::invalid_argument(exception_msg_ss.str());
  }
  int value;
  std::vector<int> sums_values;
  while(sums_fs >> value) {
    sums_values.push_back(value); 
  }
  return sums_values;
}

static int *FindSumSet(int sum) {
  const int *coin_set = SumSet::GetCoinSet();
  const size_t set_size = SumSet::GetSetSize();
  std::vector<int*> possible_counts;
  for (int i = 0; i < set_size; i++) {
    int current_nominal = coin_set[i];
    int *counts = CalculateCounts(sum, current_nominal);
    if (NULL == counts) {
      continue;
    }
    possible_counts.push_back(counts);
  } 
  for (int i = 0; i < sum - 1; i++) {
    if (NULL == sets[i]) {
      CalculateSet(i);
    }
  }
  return NULL;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Too few arguments" << std::endl;
    return 1;
  }
  SumSet::Initialize(argv[1]); 
  std::vector<int> sums_to_find = ReadSums(argv[2]);
  std::vector<int>::iterator it;
  InitializeSets(sums_to_find);
  return 0;
}
