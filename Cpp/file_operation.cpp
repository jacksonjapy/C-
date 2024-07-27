//
// Created by jackson on 2024/7/27.
//
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    string str = "hello world";
    ofstream ofs("test.txt");
    if (ofs.is_open()) {
        // 使用 << 运算符将字符串写入文件
        ofs << str;

        // 关闭文件
        ofs.close();

        cout << "字符串已成功写入文件。\n" << endl;
    } else {
        cerr << "无法打开文件。\n" << endl;
    }
    return 0;
}