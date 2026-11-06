#include <iostream>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap(int& x, int& y) {
    swap(&x, &y);
}

int main() {
    int x = 0;
    int y = 0;
    if (!(std::cin >> x >> y)) {
        return 0;
    }

    std::cout << "Before swap: x=" << x << ", y=" << y << std::endl;
    swap(x, y);
    std::cout << "After  swap: x=" << x << ", y=" << y << std::endl;
    return 0;
}
