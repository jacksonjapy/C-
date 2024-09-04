//
// Created by jackson on 2024/8/26.
//
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using std::ifstream;
using std::string;

int main() {
    // 写入文件
    ofstream writeFile("writeTest");
    if (!writeFile) {
        cerr << "写入文件失败！" << endl;
        return 1;
    }
    writeFile << "Hello, I'm Lifu!" << endl;
    writeFile.close();

    // 读取文件
    ifstream inFile("writeTest");
    if (!inFile) {
        cerr << "读取文件失败！" << endl;
        return 1;
    }
    string content;
    while (getline(inFile, content)) {
        cout << content << endl;
    }
    inFile.close();

    return 0;
}