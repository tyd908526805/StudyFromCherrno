// 析构函数在销毁一个对象时进行  
// 当一个对象被销毁时 析构函数会被调用
// 使用new关键字创建一个对象(存在于堆上)
// 然后使用delete 析构函数会被调用
// 如果只有基于栈的对象 当跳出作用域时候这个对象会被删除
// 析构函数也会被调用
#include <iostream>

class Entity
{
    public:
        float X, Y;

        Entity()
        {
            X = 0;
            Y = 0;
            std::cout << "Created Entity!" << std::endl;
        }

        // 析构函数前有~
        // 然后是类名
        // 手动在堆上分配了任何类型的内存空间
        // 需要手动的进行清除
        // 析构函数调用后 对象就不存在了
        ~Entity()
        {
            std::cout << "Destory Entity!" << std::endl;
        }

        Entity(float x, float y)
        {
            X = x;
            Y = y;
        }

        void Print()
        {
            std::cout << "x: " << X << " y: " << Y << std::endl;
        }
};

#if 0
void Function()
{
    // 因为这是栈分配的
    // 所以在作用域执行完 析构函数就会被调用
    Entity e;
    e.Print();
}

int main()
{
    Function();
}
#endif 
