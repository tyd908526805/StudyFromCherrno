#include <iostream>
#include <cstring>
// 拷贝指的是要求复制数据 复制内存

struct Vector2
{
    float x, y;
};

class String
{
    private:
        char* m_Buffer; // 字符串缓冲区
        unsigned int m_Size; // 保存字符串的大小
    public:
        String(const char* string)
        {
            m_Size = strlen(string);
            m_Buffer = new char[m_Size + 1];
            /*
            for (int i = 0; i < m_Size; i++)
            {
                m_Buffer[i] = string[i];
            }
            */
            memcpy(m_Buffer, string, m_Size);
            // 可以手动在最后添加自己的空终止符
            m_Buffer[m_Size] = 0;
        }

        // c++会自动为你提供一个拷贝构造函数
        // 它所做的就是内存复制 将other对象的内存
        // 浅拷贝进这些成员变量
        // 例如 
        // String(const String& other)
        //      : m_Buffer(other.m_Buffer), m_Size(other.m_Size)
        // 或
        // String(const String& other)
        // {
        //      memcpy(this, &other, sizeof(String));
        // }
        String(const String& other)
            : m_Size(other.m_Size)
        {
            std::cout << "Copied String!" << std::endl;
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        }

        ~String()
        {
            delete[] m_Buffer;
        }
        char& operator[](unsigned char index)
        {
            return m_Buffer[index];
        }
        
        friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

// 这样会执行拷贝构造函数
// void PrintString(String string)
void PrintString(const String& string)
{
    std::cout << string << std::endl;
}

int main()
{
    // Vector2 a = {2, 3};
    // Vector2 b = a;
    // b.x = 5;
    // a不会改变因为是两端不同的内存地址
    Vector2* a = new Vector2();
    Vector2* b = a;
    b->x = 5;
    // a会改变因为是相同的内存地址
    
    // 当复制引用时 把一个引用赋值给另一个引用 实际上是改变指向
    
    String string = "tang";
    // 浅拷贝 不会去到指针的内容或者指针所指方向的地方 也不会复制它
    // 复制了m_Buffer指针 内存中string 和 second有相同的内存地址
    // 当到达作用域尽头时 两个string都被销毁了
    // 析构函数会被调用 会 delete[] m_Buffer两次
    // 程序会试图释放两次内存块 会导致崩溃
    String second = string;
    second[2] = 'y';
    std::cout << string << std::endl;
    std::cout << second << std::endl;

    // 深拷贝 复制整个对象
    // 拷贝构造函数 当你试图创建一个新的变量并给他分配另一个变量时
    // 和你正在创建的变量有相同的类型 复制这个变量
    
    PrintString(string);
    PrintString(second);
}
