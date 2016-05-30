#ifndef LCPP_UTILS_IO_HPP
#define LCPP_UTILS_IO_HPP

#include <cstddef>

namespace lcpp {
    namespace utils {   
        class IO {
        public:
            static size_t ReadIntsFromFile(char *, int * &);
            static size_t ReadIntsFromFile(std::string, int * &);
        };
    }
}


#endif
