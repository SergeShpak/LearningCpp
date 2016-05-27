#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "SumSet.hpp"

bool SumSet::initialized = false;
int *SumSet::set = NULL;
size_t SumSet::set_size = 0;

static void check_for_duplicates(int *coin_set, size_t size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i+1; j < size; j++) {
      if (coin_set[i] == coin_set[j]) {
        throw std::invalid_argument("Duplicates were found in a set file");
      }
    }
  }  
}

static size_t SplitCoinSetString(std::string coin_set_line, int * &coin_set) {
  std::string::iterator it;
  char delim = ' ';
  int previous_delim_idx = 0;
  int current_idx = 0;
  std::vector<std::string> coins_values;
  for (it = coin_set_line.begin(); it != coin_set_line.end();
        it++, current_idx++) {
    if (delim != *it) { 
      continue;
    } 
    std::string current_token = 
      coin_set_line.substr(previous_delim_idx, 
                            current_idx - previous_delim_idx);
    coins_values.push_back(current_token);
    previous_delim_idx = current_idx;
  }
  std::string last_token = 
    coin_set_line.substr(previous_delim_idx, current_idx - previous_delim_idx);
  coins_values.push_back(last_token);
  size_t coin_set_size = coins_values.size();
  coin_set = new int[coin_set_size];
  for (int i = 0; i < coin_set_size; i++) {
    std::istringstream is(coins_values[i]);
    int value;
    if (! (is >> value)) {
      std::stringstream exception_msg_ss;
      exception_msg_ss << "Input file seems to be malformatted";
      throw std::invalid_argument(exception_msg_ss.str());
    }
    coin_set[i] = value;
  }
  check_for_duplicates(coin_set, coin_set_size);
  return coin_set_size;  
}

static size_t ReadCoinSet(const char * const coin_set_file, int * &coin_set) {
  std::ifstream coin_fstream;
  coin_fstream.open(coin_set_file, std::ifstream::in);
  if (!coin_fstream.is_open()) {
    std::stringstream exception_msg_ss;
    exception_msg_ss << "File " << coin_set_file << " cannot be opened";
    throw std::invalid_argument(exception_msg_ss.str());
  }
  std::string line;
  std::getline(coin_fstream, line);
  size_t set_size = SplitCoinSetString(line, coin_set); 
  return set_size; 
}

void SumSet::Initialize(const char * const coin_set_file) {
  int *pset;
  size_t set_size = ReadCoinSet(coin_set_file, pset);
  SumSet::set = pset;
  SumSet::set_size = set_size; 
  SumSet::initialized = true;
}

size_t SumSet::GetSetSize() {
  if (! SumSet::initialized) {
    throw std::runtime_error("SumSet is not initialized yet");
  }
  return SumSet::set_size;
}

SumSet::SumSet(int sum, int *counts) {
  if (! SumSet::initialized) {
    throw std::runtime_error("SumSet is not initialized yet");
  }
  this->sum = sum;
  this->counts = new int[SumSet::set_size];
  for (int i = 0; i < set_size; i++) {
    this->counts[i] = counts[i];
  }
}

std::string SumSet::ToString() {
  size_t set_size = SumSet::GetSetSize();
  std::stringstream ss;
  ss << "Denomination\t\tValue\n";
  for (int i = 0; i < set_size; i++) {
    ss << this->set[i] << "\t-\t" << this->counts[i] << "\n"; 
  }
  ss << "Sum: " << this->sum << std::endl;
  return ss.str();
}

SumSet::~SumSet() {
  if (this->counts) {
    delete[] this->counts;
  }
}

const int *SumSet::GetCoinSet() {
  return SumSet::set;
}
