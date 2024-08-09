//
// Created by jackson on 2024/7/4.
//
// 变量和字符串的遍历
#include <iostream>
#include <cstring>
#include <string>
#define MAX_ARRAY_LENGTH 100
using std::cout;
using std::cin;
using std::string;
using std::endl;

int main() {
    /* 使用 `char` 数组创建的字符串是固定大小的，一旦初始化，其分配的内存空间大小不可改变。
       这意味着字符串的实际长度（内容长度）可以改变，但数组的容量保持不变，可能导致越界问题。
       另外，`char` 数组不会自动释放，需手动管理内存，避免内存泄漏。
    */
    // char a[30] = "Why would I like you so much?"; // 这是C风格的字符串，需要手动指定长度
    string a = "Why would I like you so much?"; // 这是C++风格的字符串，不需要手动指定长度
    // char b[32] = "IF you like me,I just like you!";
    string b = "IF you like me,I just like you!";
    char you = 'y', me = 'm';
    string str = "I love C++!";
    bool c = true;
    cout << c << '\t' << you << '\t' << me << '\n';

    // 这是C风格的字符串遍历
    // if(strlen(a) != MAX_ARRAY_LENGTH && strlen(b) != MAX_ARRAY_LENGTH) {
    //     // 判断字符串是否遍历结束应该以'\0'作为终结符
    //     for (int i = 0; a[i] != '\0'; i++) {
    //         cout << a[i];
    //     }
    //     cout << '\n';
    //     for (int j = 0; b[j] != '\0';j++){
    //         cout << b[j];
    //     }
    //     cout << '\n';
    //     for (int k = 0; str[k] != '\0'; k++) {
    //         cout << str[k];
    //     }
    //     cout << '\n';
    //     cout << strlen(a) << '\n' << strlen(b) << endl;
    // }

    // 这是C++风格的字符串遍历
    if (a.length() != MAX_ARRAY_LENGTH && b.length() != MAX_ARRAY_LENGTH) {
        for (char i : a) {
                cout << i;
        }
        cout << '\n';
        for (char j : b) {
            cout << j;
        }
        cout << '\n';
        for (char k : str) {
            cout << k;
        }
        cout << '\n';
        cout << a.length() << '\n' << b.length() << endl;
    }

    // 使用string 类创建的字符串可以自动管理内存，不需要手动释放
    string c1;
    cout << "please input the string: ";
    getline(cin, c1, '\n');
    // 或者，如果你确实只想用cin读取不带空格的字符串，则保持下面这行
    // cin >> c1;

    // 打印输入的字符串确认（可选）
    cout << "You entered: " << c1 << endl;
    return 0;
}