#include <iostream>
#include <string>

// 虚函数可以在子类中重写方法
// 虚函数引入了一种动态分配的方式
// 一般通过虚表(vtable)来实现编译
// 虚表是一个包含类中所有虚函数映射的列表
// 通过虚表可以在运行时找到正确的被重写的函数
// 需要额外的内存来存储虚表
// 基类里面还有一个指针成员指向虚表
// 每次调用虚函数的时候 必须遍历虚表找到最终要运行的函数
#if 0
class Entity
{
    public:
        virtual std::string GetName() { return "Entity"; }
};

class Player: public Entity
{
    private:
        std::string m_Name;
    public:
        Player(const std::string& name)
            : m_Name(name) {}

        // c++11允许给被重写的函数用 override关键字标记
        // 并不是必须的
        std::string GetName() override { return m_Name; }
};

void PrintName(Entity* entity)
{
    std::cout << entity->GetName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("tyd");
    PrintName(p);

    Entity* entity = p; 
    PrintName(entity);
}
#endif
