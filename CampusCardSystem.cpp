#include <iostream>
#include <iomanip>
#include <limits>
#include <new>
#include <stdexcept>

#include "card_operations.h"

int main() {
    std::cout << "==== Campus Card System ====" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    int n = 0;
    while (true) {
        try {
            if (!(std::cin >> n)) {
                throw std::invalid_argument("账户数量输入失败");
            }
            if (n <= 0) {
                throw std::invalid_argument("账户数量必须为正整数");
            }
            break;
        }
        catch (const std::exception& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "输入无效：" << e.what() << "，请重新输入。" << std::endl;
        }
    }

    Card* students = nullptr;
    try {
        students = createCards(n);
    }
    catch (const std::bad_alloc&) {
        std::cout << "内存分配失败，程序安全退出。" << std::endl;
        return 1;
    }

    inputCards(students, n);

    try {
        deposit(students[0], 100.0);
        spend(students[0], 8.5, "食堂午餐");
    }
    catch (const std::exception& e) {
        std::cout << "操作失败：" << e.what() << std::endl;
    }

    showBalance(students[0]);
    viewStudentID(&students[0]);
    std::cout << "换算为分：" << toCent(students[0].balance) << std::endl;
    std::cout << std::endl;

    printReport(students, n);

    destroyCards(students);
    students = nullptr;
    return 0;
}
