//
// Created by jackson on 2024/7/5.
//
// 多态
#include <iostream>
using std::cout;
using std::endl;

class Animal {
public:
    // 虚函数
    virtual void makeSound() {
        cout << "Some sound" << endl;
    }
};

class Dog : public Animal {
public:
    // 重写makeSound函数
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};
int main() {
    Animal *animal = new Dog();
    animal->makeSound(); // Output: Woof!
    delete animal;
    return 0;
}