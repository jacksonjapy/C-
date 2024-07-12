//
// Created by jackson on 2024/7/5.
//
// 函数重载
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void print(int a) {
    cout << "整数: " << a << endl;
}

void print(double b) {
    cout << "浮点数: " << b << endl;
}

void print(const string& s) {
    cout << "字符串: " << s << endl;
}

int main(){
    print(10);
    print(10.0);
    print("Hello World!");
}
   