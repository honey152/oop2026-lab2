#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

struct Record {
    std::string name;
    double scores[3];
    double average;
};

int main() {
    int n = 0;
    if (!(std::cin >> n) || n <= 0) {
        return 0;
    }

    std::vector<Record> records(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> records[i].name;
        for (int j = 0; j < 3; ++j) {
            std::cin >> records[i].scores[j];
        }
        records[i].average =
            (records[i].scores[0] + records[i].scores[1] + records[i].scores[2]) / 3.0;
    }

    int width = 5;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::ostringstream probe;
            probe << std::fixed << std::setprecision(2) << records[i].scores[j];
            width = std::max(width, static_cast<int>(probe.str().size()));
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << records[i].name << ' '
                  << std::fixed << std::setprecision(2)
                  << std::setw(width) << records[i].scores[0] << ' '
                  << std::setw(width) << records[i].scores[1] << ' '
                  << std::setw(width) << records[i].scores[2] << ' '
                  << std::setw(width) << records[i].average;
        if (records[i].average >= 90.0) {
            std::cout << " Excellent";
        }
        std::cout << std::endl;
    }
    return 0;
}
