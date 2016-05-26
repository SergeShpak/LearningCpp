#include <fstream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

#include "CoinSet.hpp"


static void check_for_duplicates(int *coin_set, size_t size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i+1; j < size; j++) {
      if (coin_set[i] == coin_set[j]) {
        throw std::invalid_argument("Duplicates were found in a set file");
      }
    }
  }
}

static size_t SplitCoinSetString(std::string coin_set_line, int* & coin_set) {
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

static size_t ReadCoinSet(const char * const coin_set_file, int * & coin_set) {
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

CoinSet::CoinSet(const char * const coin_set_file) {  
  int *coin_set;
  size_t coin_set_size = ReadCoinSet(coin_set_file, coin_set);
  this->coin_set = coin_set;
  this->coin_set_size = coin_set_size; 
}

CoinSet::~CoinSet() {
  if (this->coin_set) {
    delete[] this->coin_set;
  }
}

void CoinSet::PrintSet() {
  std::stringstream is;
  for (int i = 0; i < this->GetSetSize(); i++) {
    is << this->coin_set[i] << " ";
  }  
  is << std::endl;
  std::cout << is.str() << std::endl;
}

size_t CoinSet::GetSetSize() {
  size_t set_size = this->coin_set_size;
  return set_size;
}
