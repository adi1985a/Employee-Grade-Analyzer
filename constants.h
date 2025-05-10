#pragma once
#include <string>

namespace Constants {
    const int MAX_GRADE = 10;
    const int MIN_GRADE = 0;
    const std::string LOG_FILE = "error_log.txt";
    const std::string DATA_FILE = "grades.txt";
    
    // Console colors
    const std::string RESET = "\033[0m";
    const std::string CYAN = "\033[36m";
    const std::string YELLOW = "\033[33m";
    const std::string GREEN = "\033[32m";
    const std::string MAGENTA = "\033[35m";
}
