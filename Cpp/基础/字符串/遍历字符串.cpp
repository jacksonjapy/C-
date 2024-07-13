//
// Created by jackson on 2024/7/12.
//
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test(const string& string1){
    if (string1.empty()) {
        cout << "空字符串！" << endl;
    }
    else if (!string1.empty()){
        cout << "字符串长度为：" << string1.length() << endl;
    }
}

int main(){
    string str = "Hello, I'm Lifu!\n";
    for(char c : str){
        cout << c;
    }
    test(str);
    return 0;
}