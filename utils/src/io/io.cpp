#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cstddef>

#include "io.hpp"

namespace utils = lcpp::utils;

size_t utils::IO::ReadIntsFromFile(char *file_name, int * &values) {
    std::ifstream fs;
    fs.open(file_name);
    if (!fs.is_open()) {
        std::stringstream msg_ss;
        msg_ss << "File \"" << file_name << "\" cannot be opened for reading" << std::endl;
        throw std::runtime_error(msg_ss.str());
    }
    int value;
    std::vector<int> values_v;
    while (fs >> value) {
        values_v.push_back(value); 
    }
    size_t values_count = values_v.size();
    values = new int[values_count];
    for (int i = 0; i < values_count; i++) {
        values[i] = values[i];
    }
    return values_count;
}

size_t utils::IO::ReadIntsFromFile(std::string file_name, int * &values) {
    return utils::IO::ReadIntsFromFile(file_name.c_str(), values);
}
