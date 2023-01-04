#include <iostream>

class Singleton
{
    private:
        static Singleton* s_Instance;
    public:
        static Singleton& Get() { return *s_Instance; }
        void Hello() { std::cout << "S" << std::endl; }
};
Singleton* Singleton::s_Instance = NULL;

class SingletonNew
{
    public:
        // 如果没有static SingletonNew实例会在站上创建
        // 跳出函数作用域时会被销毁
        // 加上static后 生命周期变成永久
        // 第一次调用Get()将会创建一个SingletonNew类的实例
        // 之后所有的调用都会返回这个存在的实例
        static SingletonNew& Get()
        {
            static SingletonNew instance;
            return instance;
        }
        void Hello() { std::cout << "S" << std::endl; }
};

#if 0
void Function()
{
    // 当我第一次调用这个函数时
    // 值被初始化为0
    // 后续调用不会再创建一共新的变量
    static int i = 0;
    i++;
    std::cout << "i: " << i << std::endl;
}
int main()
{
    /*
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    */
    Singleton::Get().Hello();
    SingletonNew::Get().Hello();
}
#endif
