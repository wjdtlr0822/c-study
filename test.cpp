#include <iostream>

template <typename T>
void show_value(T t) {
    std::cout << "�����Ͱ� �ƴϴ� : " << t << std::endl;
}

template <typename T>
void show_value(T* t) {
    std::cout << "������ �̴� : " << *t << std::endl;
}

int main() {
    int x = 3;
    show_value(x);

    int* p = &x;
    show_value(p);
}