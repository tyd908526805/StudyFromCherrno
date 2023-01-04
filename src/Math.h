#include "Log.h"

#define INTEGER int

// if预处理语句可以使包含或排除基于给定条件的代码
// if 1为真 0为假 
// #if 0 的情况下预处理器文件.i中不会生成对应代码
#if 1
INTEGER Multiply(int a, int b)
{
    vLog("Message");
    return a * b;
}
#endif
// 查看生成的.obj或则.o文件时
// 内容为调用这个函数时 CPU将运行的机器代码
