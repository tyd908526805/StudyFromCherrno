#include <iostream>
#include <string>

// 纯虚函数允许我们定义一个在基类没有实现的函数
// 强制子类去实现这个函数
// 接口 创建一个只包含未实现方法然后交由子类去实现功能的类
// 一个包含未实现的方法并作为一个模板的类
// 不包含方法实现 无法实例化这个类
class Printable
{
    public:
        virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
    public:
        // =0才是纯虚函数
        // 如果想实例化这个类 必须在子类中实现
        virtual std::string GetName() { return "Entity"; }
        std::string GetClassName() override { return "Entity"; }
};

//class Player : public Entity, Printable
class Player : public Entity
{
    std::string GetName() override { return "Player"; };
    std::string GetClassName() override { return "Player"; }
};

void Print(Printable* obj)
{
    std::cout << obj->GetClassName() << std::endl;
}

#if 0
int main()
{
    //只能实例化一个实现了所有纯虚函数的类
    Entity* e = new Entity();
    Print(e);
    Player* p = new Player();
    Print(p);
}
#endif
