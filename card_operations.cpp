#include "card_operations.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

namespace card {
    void printLine(char c, int len) {
        for (int i = 0; i < len; ++i) {
            std::cout << c;
        }
        std::cout << std::endl;
    }

    void title(const std::string& s) {
        printLine('=');
        std::cout << s << std::endl;
        printLine('=');
    }
}

Card* createCards(int n) {
    if (n <= 0) {
        throw std::invalid_argument("账户数量必须大于 0");
    }
    return new Card[n]();
}

void destroyCards(Card* p) {
    delete[] p;
}

void inputCards(Card* arr, int n) {
    for (int i = 0; i < n; ++i) {
        while (true) {
            try {
                int id = 0;
                std::string name;
                double balance = 0.0;
                if (!(std::cin >> id >> name >> balance)) {
                    throw std::invalid_argument("输入数据格式错误");
                }
                if (balance < 0.0) {
                    throw std::invalid_argument("初始余额不能为负数");
                }
                arr[i].id = id;
                arr[i].name = name;
                arr[i].balance = balance;
                arr[i].transactions = 0;
                break;
            }
            catch (const std::exception& e) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "输入无效：" << e.what() << "，请重新输入该账户。" << std::endl;
            }
        }
    }
}

void deposit(Card& c, double amount, double fee) {
    if (amount <= 0.0) {
        throw std::invalid_argument("充值金额必须大于 0");
    }
    c.balance += amount * (1.0 - fee);
    ++c.transactions;
}

bool spend(Card& c, double cost) {
    if (cost <= 0.0) {
        throw std::invalid_argument("消费金额必须大于 0");
    }
    if (cost > c.balance) {
        throw std::runtime_error("余额不足，消费失败");
    }
    c.balance -= cost;
    ++c.transactions;
    if (c.balance < WARNING_BALANCE) {
        std::cout << "警告：余额已低于警戒值 " << WARNING_BALANCE << std::endl;
    }
    return true;
}

bool spend(Card& c, double cost, const std::string& item) {
    std::cout << "消费项目：" << item << std::endl;
    return spend(c, cost);
}

void showBalance(const Card& c) {
    std::cout << c.name << " 当前余额为：" << c.balance << std::endl;
}

void viewStudentID(const Card* p) {
    std::cout << "账户ID为：" << p->id << std::endl;
}

int toCent(double amount) {
    return static_cast<int>(amount * 100.0 + 0.5);
}

void printReport(const Card* arr, int n) {
    card::printLine('=');
    std::cout << std::left << std::setw(8) << "ID"
              << std::setw(15) << "Name"
              << std::right << std::setw(9) << "Balance"
              << std::setw(14) << "Transactions" << std::endl;
    card::printLine('-');
    for (int i = 0; i < n; ++i) {
        std::cout << std::left << std::setw(8) << arr[i].id
                  << std::setw(15) << arr[i].name
                  << std::right << std::setw(9)
                  << std::fixed << std::setprecision(2) << arr[i].balance
                  << std::setw(14) << arr[i].transactions << std::endl;
    }
    card::printLine('=');
}
