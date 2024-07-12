//
// Created by jackson on 2024/7/5.
//
// 内联函数
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

inline int add(int x, int y) {
    return x + y;
}

int main(){
    int a, b;
    cout << "功能：计算两个数的和\n" << "请输入第一个数:";
    cin >> a;
    cout << "请输入第二个数:";
    cin >> b;
    cout << "两个数的和为:" << add(a, b) << endl;
}