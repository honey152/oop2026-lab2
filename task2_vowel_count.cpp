#include <iostream>
#include <string>

int countVowels(const char* p) {
    int count = 0;
    while (*p != '\0') {
        switch (*p) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
        case 'A': case 'E': case 'I': case 'O': case 'U':
            ++count;
            break;
        default:
            break;
        }
        ++p;
    }
    return count;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::cout << "Number of vowels: " << countVowels(line.c_str()) << std::endl;
    return 0;
}
