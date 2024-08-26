//
// Created by jackson on 2024/8/26.
//
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 写入文件
    std::ofstream writeFile("writeTest");
    if (!writeFile) {
        std::cerr << "写入文件失败！" << std::endl;
        return 1;
    }
    writeFile << "Hello, I'm Lifu!" << std::endl;
    writeFile.close();

    // 读取文件
    std::ifstream inFile("writeTest");
    if (!inFile) {
        std::cerr << "读取文件失败！" << std::endl;
        return 1;
    }
    std::string content;
    while (std::getline(inFile, content)) {
        std::cout << content << std::endl;
    }
    inFile.close();

    return 0;
}