#if 0
#include <iostream>
void Increment(int value)
{
    value++;
}

int main()
{
    // 引用必须引用一个已存在的变量
    // 引用本身并不是一个新的变量
    // 并不占用真正的内存
    // 一旦声明了引用 就不能改变它所引用的对象
    int a = 5;
    int b = 8;

    int* ref = &a;
    *ref = 2;
    ref = &b;
    *ref = 1;
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;
}
#endif

#if 0
// 当你编写一个应用程序并启动它时
// 整个的程序被载入内存
// 在代码中，所有的指令告诉计算机要做什么
// 所有都被加载到内存中
// 这就是CPU访问你的程序并执行指令的
// 当你创建一个变量时
// 当你从硬盘中载入数据时
// 所有东西都会被存储到内存中
// 指针时一个整数 一个数字 存储一个内存地址

int main()
{

    // 创建任何变量都有一个内存地址
    // 需要一个存储该变量的地方
    //int var = 8;

    // 0不是一个有效的内存地址
    //void* ptr = 0;
    // NULL 是一个 #define NULL 0
    // nullptr 是c++11 引入的
    // &var 获取var变量的内存地址
    // 将&var的内存地址赋值给ptr的新变量
    //int* ptr = &var;
    //*ptr = 10;

    // 分配了8个字节的内存
    // 返回一个指向这块内存的开始地址的指针
    // new 数据分配在heap(堆)上
    char* buffer = new char[8];
    // 接受一个指针 指向这块内存的开始处
    // 接受一个值
    // 接受一个大小 填充多少字节
    memset(buffer, 0, 8);

    char** ptr = &buffer;

    // 使用了new[]来分配 使用delete[]来删除
    delete[] buffer;
}
#endif

#if 0
#include <iostream>

//int s_Variable = 10;
// extern 会在另外编译单元里找s_Variable的定义
extern int s_Variable;

struct Entity
{
    int x, y;

    void Print()
    {
        std::cout << x << "," << y << std::endl;
    }
};

int main()
{
    //std::cout << s_Variable << std::endl;
    Entity e;
    e.x = 2;
    e.y = 3;

    Entity e1 = {5, 8};

    e.Print();
    e1.Print();
}
#endif

#if 0
// 预处理
// #符号之后都是预处理语句
// 编译器收到源文件后会先处理预处理语句
// 在实际编译发生前就被处理了
// include 需要找到一个文件
// 然后将文件中的内容拷贝到现在的文件中
// 当预处理语句处理完 文件将被编译
// 所有.cpp文件都会被编译 .h文件不会被编译
// 因为.h文件在预处理时已经被包含进来
// cpp文件被编译时 包含进来的文件一起被编译了
// 每个cpp文件都被编译成了一个object file(目标文件)
// 链接器从.obj或.o文件中拿出对应Log的定义放入二进制文件中
#include "Math.h"

class Log
{
    public:
        enum Level
        {
            Error = 0,
            Warning,
            Info
        };
        const int LogLevelError = 0;
        const int LogLevelWarning = 1;
        const int LogLevelInfo = 2;
    private:
        Level m_LogLevel = LogLevelInfo;
    public:
        void SetLevel(Level level)
        {
            m_LogLevel = level;
        }
        void Error(const char* message)
        {
            if (m_LogLevel >= Error)
                std::cout << "[ERROR]: " << message << std::endl;
        }
        void Warn(const char* message)
        {
            if (m_LogLevel >= Warning)
                std::cout << "[WARNING]: " << message << std::endl;
        }
        void Info(const char* message)
        {
            if (m_LogLevel >= Info)
                std::cout << "[Info]: " << message << std::endl;
        }
};

int main()
{
    Log log;
    //log.SetLevel(Log::Warning);
    log.Error("Hello!");
    log.Warn("Hello!");
    log.Info("Hello!");
}
#endif

#if 0
// 由类类型制成的变量叫做对象
// 新创建对象的过程叫做实例化
class Player
{
    public:
        int x, y;
        int speed;

        void Move(int x, int y)
        {
            player.x += xa * player.speed;
            player.y += ya * player.speed;
        }
};

int main()
{
    Player player;
    player.Move(1, 1);
}
#endif

#if 0
// main 函数 程序入口
int main()
{
    Log("Hello World");
    Multiply(4, 8);
// 因为编译器是打开.h文件并且把所有内容复制过来
// 所以可以编译成功
#include "EndBrace.h"
#endif

#if 0
int main()
{
    int x = 5;
    // 比较整数 其实在获取他们的四个字节的内存
    // 比较每个字节 为了让这两个整数相等 内存的每一位必须相同
    bool comparisonResult = x == 5;
    if (comparisonResult)
        Log("Hello World");
    const char* ptr = "hello";
    // else if 并不是 c++关键字 而是先执行else 再执行if
    if (ptr)
        Log(ptr);
}
#endif

#if 0
int main()
{
    Log("Hello World");
    Multiply(4, 8);
    // int 有符号整数 是传统上为4字节的数据类型 
    // 数据的实际大小取决于编译器 不同的编译器会有所不同
    // 一个字节是8bit的数据 4字节32bit的数据
    // 因为是有符号的数据 所以第一位代表正数还是负数 实际数字剩下31位
    // 取值范围为 -2^31~2^31
    int variable = 8;
    std::cout << variable << std::endl;
    variable = 20;
    std::cout << variable << std::endl;
    // unsigned int 无符号整数 是传统上为4字节的数据类型 
    // 数据的实际大小取决于编译器 不同的编译器会有所不同
    // 一个字节是8bit的数据 4字节32bit的数据
    // 因为是无符号的数据 数字剩下32位
    // 取值范围为 0~2^32
    unsigned int uvariable = 8;
    std::cout << uvariable << std::endl;
    // char 1字节的数据
    // short 2字节的数据
    // long 通常为4字节的数据(取决于编译器)
    // long long 通常为8字节的数据
    // float 浮点数基本上为4字节
    // double 双精度浮点数为8字节
    float var = 5.5f;
    // bool 1字节 代表true(除0之外任何数字)或false(0)
    bool vari = true;
    std::cout << sizeof(bool) << std::endl;
}
#endif
