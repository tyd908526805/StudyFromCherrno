#include <iostream>
#include <string>

class Entity
{
    private:
        int m_x, m_y;
        int* x, * y;
        // 即使在const方法中也可以修改
        mutable int c;
    public:
        // 不会进行更改类 只是只读的方法
        int GetX() const
        {
            c = 2;
            return m_x;
        }
        // 返回一个不能修改的指针
        const int* GetXX()
        {
            return x;
        }
        // 指针的内容不能被修改
        int* const GetXXX()
        {
            return x;
        }
        // 返回一个不能修改的指针
        // 指针的内容不能被修改
        // 不会修改类
        const int* const GetXXXX() const
        {
            return x;
        }

        int GetXXXX()
        {
            return m_x;
        }
};

void PrintA(const Entity* e)
{
    // 可以修改e的指向
    e = nullptr;
    std::cout << e->GetX() << std::endl;
}

void PrintB(const Entity& e)
{
    // 不能重新分配 
    // e = Entity();
    std::cout << e.GetX() << std::endl;
    // 不能调用GetXXXX()
    // 因为e 是不能被修改的
    // GetXXXX() 存在修改函数的可能
}

#if 0
int main()
{
    // const 表明声明一个不会改变的常量
    const int MAX_AGE = 90;

    // 不能改变指针指向的内容(指针指向的内存地址的内容)
    const int* a = new int;
    // 效果一样 问题只存在于 const 在*前面还是后面
    int const* c = new int;

    //可以改变指针指向的内容 但是不能把指针自身重新赋值让他指向其他东西
    int* const b = new int;

    // 要让指针变成常量 不能被重新分配 要把const 放在 * 后面 变量名之前
    
    // 既不能改变指针的内容 也不能改变指针本身让他指向别处
    const int* const c = new int;
}
#endif 
