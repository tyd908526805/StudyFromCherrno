#include <iostream>
#include <string>
// 栈对象有一个自动的声明周期
// 生命周期是由它声明地方的作用域决定的
// 一旦超出了这个作用域 内存就会被释放掉
// 当作用域结束时 栈会弹出 这个作用域所有东西会被释放

// 在堆上分配一个对象
// 创建了一个一直存在的对象
// 直到手动释放

using String = std::string;

class Entity
{
    private:
        String  m_Name;
    public:
        Entity() : m_Name("Unknown") {}
        Entity(const String& name) : m_Name(name) {}

        const String& GetName() const { return m_Name; }
};

void Function()
{
    Entity entity = Entity("Tang");
    // 到达}位置时 entity 会从内存中销毁 
    // 调用Function时 函数创建了一个有生命周期的所有局部变量的栈结构
    // 函数结束时 栈结构也会被销毁
}

#if 0
int main()
{
    // 在栈上创建
    Entity entity;
    std::cout << entity.GetName() << std::endl;

    Entity* pE;
    // 在堆上创建
    Entity* pEntity = new Entity("Tang");

    pE = pEntity;

    std::cout << (*pE).GetName() << std::endl;
    std::cout << pE->GetName() << std::endl;

    // 在堆上分配比在栈上花费更多的时间
    // 需要手动去释放在堆上分配的内存
    delete pE;
    std::cout << pEntity->GetName() << std::endl;
}
#endif
