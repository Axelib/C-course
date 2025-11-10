#include <string>

namespace log_line {

std::string message(std::string line) {
    size_t pos = line.find(": ");
    if (pos != std::string::npos) {
        return line.substr(pos + 2);
    }
    return "";
}

std::string log_level(std::string line) {
    size_t start = line.find('[');
    size_t end = line.find(']');
    if (start != std::string::npos && end != std::string::npos && end > start) {
        return line.substr(start + 1, end - start - 1);
    }
    return "";
}

std::string reformat(std::string line) {
    std::string msg = message(line);
    std::string level = log_level(line);
    return msg + " (" + level + ")";
}

}  // namespace log_line
