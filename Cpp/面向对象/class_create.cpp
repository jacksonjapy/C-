//
// Created by jackson on 2024/7/5.
//
#include <iostream>
#include <utility>
#define LOVE_YEARS 3
using std::cout;
using std::endl;
using std::string;
// 创建类
class Animal {
public:
    string type;
    string name;
    int age{};
    float weight{3.0};
    float height{1.0};
    static void eat() {
        cout << "Eating..." << endl;
    }
    static int getLoveYears(int years) {
        if (years == LOVE_YEARS) {
            return cout << "Love years is " << years << endl, LOVE_YEARS;
        }
        else if (years > LOVE_YEARS)
            return cout << "Love years is " << years << endl, years;
        else
            return cout << "Love years is " << LOVE_YEARS << endl, LOVE_YEARS;

    }
};
// 创建子类，继承Animal类
class Cat : public Animal {
public:
    string color;
    string name;
    int age{};
    int legs{};
    // 构造函数
    Cat(string n, int a, int l) : name(std::move(n)), age(a), legs(l) {
        cout << "Cat object is created\t" << "name:" << name << ", age: " << age << ", legs: " << legs << endl;
    }
    void move() const {
        cout << name <<" Cat is moving!" << endl;
    }
    // 析构函数
    ~Cat() {
        cout << "Cat object is destroyed!" << endl;
    }
};

int main() {
    // 创建对象(实例化Animal类)
    Animal Dog;
    Dog.type = "Dog";
    Dog.name = "Spike";
    Dog.age = 3;
    Dog.weight = 10.5;
    Dog.height = 0.5;
    cout << "Dog type: " << Dog.type << endl;
    cout << "Dog name: " << Dog.name << endl;
    cout << "Dog age: " << Dog.age << " years" << endl;
    cout << "Dog weight: " << Dog.weight << " Kg" << endl;
    cout << "Dog height: " << Dog.height << " m" << endl;
    // 调用静态方法
    Animal::eat();
    Animal::getLoveYears(20);
    Cat garfield("Garfield", 3, 4);
    garfield.color = "Orange";
    garfield.move();
    Cat cat("Tom", 3, 4);
    return 0;
}