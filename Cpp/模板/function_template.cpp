//
// Created by jackson on 2024/7/5.
//
#include <iostream>
using std::cout;
using std::endl;

// 模板函数
// 可以使用class 或 typename关键字来声明模板类型
// template <class T>
template <typename T>
T add(T x, T y) {
    return x + y;
}

int main(){
    cout << add(1, 2) << endl;
    cout << add(1.2, 2.3) << endl;
    return 0;
}