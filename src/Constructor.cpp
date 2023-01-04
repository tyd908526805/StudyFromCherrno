#include <iostream>

class Entity
{
    public:
        float X, Y;

        // 构造函数命名必须和类名一样
        // 没有返回值
        // 即使不指定构造函数
        // 仍然拥有一个构造函数
        // 叫做默认构造函数(default constructor)
        // 类似 Entity() {}
        // 不会在没有实例化对象的时候运行
        // 如果只是使用类的静态方法 构造函数不会执行
        Entity()
        {
            X = 0.0f;
            Y = 0.0f;
        }
        // 函数重载
        // 相同的函数有不同的参数的不同版本函数
        Entity(float x, float y)
        {
            X = x;
            Y = y;
        }

        /*
        void Init()
        {
            x = 0.0f;
            y = 0.0f;
        }
        */
        void Print()
        {
            std::cout << "x: " << X << " y: " << Y << std::endl;
        }
};

#if 0
class Log
{
    private:
        // 将构造函数设为私有
        // 可以避免在外界调用
        Log();
    public:
        // 删除默认构造函数
        // 可以避免在外界调用
        Log() = delete;
}

int main()
{
    Log l;
    Entity e(10.0f, 5.0f);
    std::cout << "e.x: " << e.X << " e.y: " << e.Y << std::endl;
    e.Print();
}
#endif
