#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
// 字符串本质是一组字符
// C++中处理字符的方式是一个字符占一个字节(ASCII)
// 1字节是8bit 有2的8次方 256种可能
// 字符串从指针的内存地址开始 直到0结束

// 创建了这个对象的一个拷贝传给这个函数
// 拷贝这个字符串还会在堆上动态地创建全新的char数组
// 来存储我们之前已经得到的完全相同的文本
void PrintString(std::string string)
{
    std::cout << string << std::endl;
}

#if 0
int main()
{
    const char* name = "Tang";
    // string 其实是const char数组
    std::string aname = "tang";
    // string库重载了+=
    aname += "yan"; 
    // name.find() 返回的是文本位置
    bool contains = aname.find("no") != std::string::npos;

    const char bname[8] = "ta\0ng";
    // 查看字符串长度
    // strlen 只计算到\0之间的字符
    // 它一旦遇到0就认为是字符串的结尾
    // 所以去除\0后 strlen(bname) = 4 而不是8
    std::cout << strlen(bname) << std::endl;

    // 需要在前面加一个大写的L
    // 表示接下来的字符串是由宽字符组成
    const wchar_t* lname = L"Tang";

    // 一个字符占两个字节
    const char16_t* uname = u"Tang";

    // 一个字符占四个字节
    const char32_t* Uname = U"Tang";

    using namespace std::string_literals;
    std::wstring wname = L"Tang"s + L"hello";
    std::u32string u32name = U"Tang"s + U"hello";

    const char* example = R"(line1
    line2
    line3
    line4)";
    const char* example2 = "line1\n"
        "line2\n"
        "line3\n";
}
#endif
