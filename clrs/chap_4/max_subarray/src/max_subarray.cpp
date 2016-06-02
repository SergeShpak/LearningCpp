#include "max_subarray.hpp"

namespace chap4 = clrs::chap_4;

chap4::ArrayIndices::ArrayIndices(int low, int high, int sum) {
  this->low_ = low;
  this->high_ = high;
  this->sum_ = sum;
}

const int chap4::ArrayIndices::sum() {
  return sum_;
}

const int chap4::ArrayIndices::high() {
  return high_;
}

const int chap4::ArrayIndices::low() {
  return low_;
}

chap4::ArrayIndices *chap4::MaxSubarraySolver::Solve(
                                          int *values, size_t values_count) {
  int low_found, high_found;
  FindMaxSubarray(values, 0, values_count - 1, low_found, high_found); 
  const int sum = FindSum(values, low_found, high_found);
  ArrayIndices *ai = new ArrayIndices(low_found, high_found, sum);
  return ai;
}

void chap4::MaxSubarraySolver::FindMaxSubarray(int *values, 
                        int low, int high, int& low_found, int& high_found) {
  if (high <= low) {
    high_found = low;
    low_found = low;
    return;
  }
  int mid = (high + low) / 2;
  int left_low, left_high;
  FindMaxSubarray(values, low, mid - 1, left_low, left_high);
  const int left_sum = FindSum(values, left_low, left_high);
  int mid_low, mid_high;
  FindMaxCrossingSubarray(values, low, mid, high, mid_low, mid_high);
  const int middle_sum = FindSum(values, mid_low, mid_high);
  int right_low, right_high;
  FindMaxSubarray(values, mid + 1, high, right_low, right_high);
  const int right_sum = FindSum(values, right_low, right_high);
  if (left_sum >= middle_sum && left_sum >= right_sum) {
    low_found = left_low;
    high_found = left_high;
  }
  if (middle_sum >= left_sum && middle_sum >= right_sum) {
    low_found = mid_low;
    high_found = mid_high;
  }
  if (right_sum >= left_sum && right_sum >= middle_sum) {
    low_found = right_low;
    high_found = right_high;
  }
}

void chap4::MaxSubarraySolver::FindMaxCrossingSubarray (int *values, 
                int low, int mid, int high, int& low_found, int& high_found) {
  int current_sum = values[mid];
  int left_max_index = mid; 
  for (int i = mid - 1; i >= low; i++) {
    int new_sum = current_sum + values[i];
    if (new_sum >= current_sum) {
      left_max_index = i;
    }
    current_sum = new_sum;
  } 
  current_sum = values[mid];
  int right_max_index = mid;
  for (int i = mid + 1; i <= high; i++) {
    int new_sum = current_sum + values[i];
    if (new_sum >= current_sum) {
      right_max_index = i; 
    }
    current_sum = new_sum;
  }
  low_found = left_max_index;
  high_found = right_max_index;
}

int chap4::MaxSubarraySolver::FindSum(int *values, int low, int high) {
  int sum = 0;
  for (int i = low; i <= high; i++) {
    sum += values[i];
  }
  return sum;
}

int main(int argc, char* argv[]) {
  return 0;
}
