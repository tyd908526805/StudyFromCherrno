#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

#if 0 
int main()
{
    if (s_Level > 5)
        s_Speed  = 10;
    else
        s_Speed  = 5;

    // 不会产生临时的变量浪费内存
    s_Speed = s_Level > 5 ? 10 : 5;

    s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;

    std::cout << s_Speed  << std::endl;
}
#endif
